# RTOS-Style LED Task Scheduler Demo

**Author:** Marc Dugas  
**Purpose:** Demonstrate non-blocking task scheduling on Arduino using `millis()`.  
**Skills Demonstrated:** Embedded C/C++, non-blocking scheduling, PWM, multitasking, Arduino programming, serial communication.

## Project Overview

This project simulates a simple **RTOS-style scheduler** using an Arduino.  
Three LEDs perform independent tasks:

- **LED1 (green):** Blinks every 500ms
- **LED2 (blue):** Fades in/out smoothly using PWM
- **LED3 (red):** Blinks every 1 second while incrementing a counter printed to the Serial Monitor

The project uses `millis()` for non-blocking timing instead of `delay()`, allowing multiple tasks to run independently, similar to an RTOS environment.

## Components Needed

- Arduino Uno R3
- 3 LEDs (green, blue, red)
- 3 resistors (220Ω or 330Ω)
- Jumper wires
- Breadboard


### LED Pin Mapping

| LED  | Arduino Pin | Color |
|------|-------------|-------|
| LED1 | 8           | Green |
| LED2 | 9           | Blue  |
| LED3 | 10          | Red   |

## How to Run

1. Open `RTOS_LED_Scheduler.ino` in Arduino IDE.
2. Connect Arduino via USB.
3. Select Arduino Uno board and correct COM port.
4. Upload the sketch.
5. Open Serial Monitor (9600 baud) to see LED3 counter.

---

## Notes

- LED2 uses PWM for smooth fading.
- Tasks run independently without blocking delays.
- This project demonstrates basic multitasking on a microcontroller.
