# MPPT Solar Power Tracker  

**Intelligent Maximum Power Point Tracking (MPPT) System** for photovoltaic panels.  
Designed with **Arduino**, **Hall-effect current sensing**, and **real-time PWM control**, this project focuses on achieving optimal energy extraction from small-scale solar systems through an efficient and adaptive control algorithm.  

---

## Project Overview  

The system dynamically adjusts the load of a solar panel to operate at its **maximum power point (MPP)**, ensuring that the extracted power remains optimal under varying illumination and temperature conditions.  
It combines precise analog sensing, real-time power computation, and pulse-width modulation control in a compact, low-cost implementation.  

Developed using a **SYP-505V5W (5 V / 5 W)** solar cell and a **Hall-effect current sensor**, the setup performs continuous current and voltage monitoring, applying offset correction and closed-loop feedback to maximize efficiency.  

---

## Repository Contents  

| File | Description |
|------|--------------|
| **readmetopfinalmmptENG.ino** | Full Arduino sketch implementing the MPPT algorithm, current offset calibration, and PWM control logic. |
| **SolarPowerTracker.pdf** | Concise visual summary of the system’s architecture, control flow, and experimental performance. |
| **premioposter.jpg** | Photograph of the award and recognition ceremony from the engineering school. |

> The repository includes both the implementation code and the accompanying poster for reference.  
> The visual document illustrates the control process, component selection, and real-world test results.

---

## Award & Recognition  

This project was **awarded by the Director of the School of Engineering (UPNA)** for its technical merit, precision in measurement, and experimental validation.  
It was highlighted as an example of *hardware-based innovation in renewable energy systems*.  

---

## Key Features  

- Accurate **current and voltage sensing** with analog offset calibration.  
- **Real-time power calculation** and closed-loop control for maximum power tracking.  
- **PWM-based load modulation** using MOSFET IRLZ44N.  
- **Dynamic feedback system** for stability under changing solar conditions.  
- Optional **visual and acoustic indicators** for energy-level feedback.  

---

## Skills & Tools Demonstrated  

| Category | Skills |
|-----------|--------|
| **Embedded Control** | Arduino IDE programming, real-time loop design, PWM signal generation |
| **Sensing & Measurement** | Hall-effect current sensing, voltage divider design, signal filtering |
| **Power Electronics** | MOSFET driver circuits, DC load control, power efficiency optimization |
| **Algorithm Design** | Incremental Conductance and Perturb & Observe hybrid logic |
| **Testing & Analysis** | Real-time data logging, performance evaluation under variable light |
| **Documentation** | Technical report and award poster summarizing results and methodology |

---

## Technical Stack  

`Arduino · PWM · Hall-Effect Sensor · IRLZ44N MOSFET · Voltage Divider · DC Load Control · Power Measurement · Embedded C/C++ · Data Logging`

---

## System Applications  

This MPPT prototype serves as a **low-cost, scalable foundation** for:  
- Renewable energy education  
- Off-grid solar management systems  
- Smart IoT-integrated power devices  
- Real-time efficiency optimization research  

---

## Short Abstract  

> **MPPT Solar Power Tracker** demonstrates how precise analog sensing and adaptive PWM control can dramatically improve energy extraction in small-scale solar systems.  
> It bridges renewable energy, control engineering, and embedded design — an ideal foundation for sustainable power solutions.  

