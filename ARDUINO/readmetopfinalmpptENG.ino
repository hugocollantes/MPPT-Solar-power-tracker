#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Pines
const int pinVoltaje = A5;     // Divider input
const int pinCorriente = A1;   // Sensor Hall output
const int pinPWM = 6;          // PWM to the gate of the MOSFET

// Parámetros del sistema
const float VREF = 4.5;                 // Real voltage measured in Arduino (adjustable)
const float factorDivisor = 2.0;        // R1 = R2 → divide by 2 and after multiply by 2 
const float offsetCorriente = 2.22;    // Voltage without current (adjusted with multimeter if necessary)
const float sensibilidad = 0.185;       // V/A to ACS712-5A (used 0.100 to 20A, 0.066 to 30A)
float Vprev = 0, Pprev = 0;
int duty = 30;  // PWM inicial  80% (255 * 0.8)
int step = .  ;    // Step to adjust the duty
int dutyLCD= 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(pinVoltaje, INPUT);
  pinMode(pinCorriente, INPUT);
  pinMode(pinPWM, OUTPUT);

  analogWrite(pinPWM, duty);  // 80% of 255
  lcd.setCursor(0, 0);
  lcd.print("PWM Activo");
  delay(2000);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  float I = leerCorrientePromediada();
  float V= leerVoltajePromediado();
  float dutyPct = (duty / 255.0) * 100.0;
  Serial.println(V);
  if (abs(I) < 0.005) I = 0;  // Filter of low noise
  float P = V * I;
  ajustarPWMporMPPT(V, I);
  dutyLCD=100-duty;
  Serial.println(dutyLCD);


  // Showing on LCD
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(V, 2);
  lcd.print(" I:");
  lcd.print(I * 1000, 0);
  lcd.print("mA");

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(P, 2);
  lcd.print("W DC:"); // fills until the end
  lcd.print((int)dutyPct);
  lcd.print("%");

  delay(500);
}

// ------------ FUNCTIONS ------------

float leerVoltajePromediado() { //function for the voltage
  long suma = 0;
  const int muestras = 200;
  for (int i = 0; i < muestras; i++) { //we take 200 samples maximum
    suma += analogRead(pinVoltaje);
    delayMicroseconds(100);
  }
  float promedio = suma / float(muestras);
  float volt = promedio * (VREF / 1023.0);
  float out=volt * 3.2;
  return out;
}


float leerCorrientePromediada() { //function for the current
  long suma = 0;
  const int muestras = 200;
  for (int i = 0; i < muestras; i++) {
    suma += analogRead(pinCorriente);
    delayMicroseconds(100);
  }
  float promedio = suma / float(muestras); //the average value is obtained
  float volt = promedio * (VREF / 1023.0);
  float corriente = (volt - offsetCorriente) / sensibilidad; //sensor´s sensibility taken into account
  return corriente;
}

void ajustarPWMporMPPT(float Vactual, float Iactual) { //looking for the MPPT
  float Pactual = Vactual * Iactual;

  if (Pactual > Pprev) {  //previous power is compared to the new one.
    duty += (Vactual > Vprev) ? step : -step;
  } else {
    duty -= (Vactual > Vprev) ? step : -step;
  }

  duty = constrain(duty, 30, 200);  // Avoid extremes that cut the system
  analogWrite(pinPWM, duty);

  // Updates values for next interaction
  Vprev = Vactual;
  Pprev = Pactual;

}                                                                                                                                                                                     