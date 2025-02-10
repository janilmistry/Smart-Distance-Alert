# Ultrasonic Range Finder with OLED Display & Alerts

This project is a simple **ultrasonic range finder** system built using an **ultrasonic sensor (HC-SR04)**, an **OLED display**, an **RGB LED**, and a **buzzer** to provide real-time distance measurements and visual/audio feedback. The system uses the ultrasonic sensor to measure the distance to an object and displays the value on an OLED screen in both **centimeters** and **inches**. Additionally, the RGB LED color changes based on the distance, and the buzzer provides audible feedback with varying patterns depending on the measured range.

## Features

- **Real-time Distance Measurement:** Displays the distance to an object on an OLED screen in both centimeters and inches.
- **RGB LED Feedback:** The RGB LED changes color based on the measured distance:
  - **Red** for objects closer than 20 cm
  - **Blue** for objects between 20 cm and 50 cm
  - **Green** for objects between 50 cm and 100 cm
  - **Off** for objects further than 100 cm
- **Audible Alerts:** The buzzer generates different sound patterns based on proximity:
  - Continuous tone for close objects (< 20 cm)
  - Short bursts for medium-range objects (20 - 50 cm)
  - Long tone with a pause for farther objects (50 - 90 cm)
  - No sound for objects further than 90 cm
- **User-friendly Interface:** Simple, clear display with adjustable settings for various distance ranges.

## Hardware Required

- **Ultrasonic Sensor (HC-SR04):** For measuring the distance to an object.
- **OLED Display (SSD1306):** For displaying the measured distance and range.
- **RGB LED:** To provide visual feedback based on the proximity of the object.
- **Buzzer:** For providing audible feedback based on distance thresholds.
- **Arduino or Compatible Microcontroller:** To run the code and control the hardware components.

## Connections

- **Ultrasonic Sensor (HC-SR04):**
  - `Trig Pin` → Pin 9
  - `Echo Pin` → Pin 8
- **RGB LED:**
  - `Red Pin` → Pin 5
  - `Green Pin` → Pin 6
  - `Blue Pin` → Pin 7
- **Buzzer:**
  - `Buzzer Pin` → Pin 10
- **OLED Display:**
  - `SCL` → SCL pin (A5 on Arduino Uno)
  - `SDA` → SDA pin (A4 on Arduino Uno)
  - `VCC` → 3.3V or 5V (depending on your OLED model)
  - `GND` → GND

## Software Required

- **Arduino IDE:** To upload the code to the microcontroller.
- **Adafruit SSD1306 Library:** For the OLED display.
- **Adafruit GFX Library:** For graphics support on the OLED.
- **SPI and Wire Libraries:** For communication with the OLED display.

## How to Use

1. Clone this repository or download the code files.
2. Connect the hardware components as described in the "Connections" section.
3. Open the **Arduino IDE** and upload the code to your Arduino board.
4. Open the **Serial Monitor** to view the distance measurements in real-time.
5. The OLED screen will display the distance in both centimeters and inches, while the RGB LED and buzzer will provide feedback based on the proximity of objects.

## License

This project is open-source and available under the **MIT License**.

## Acknowledgements

- **Adafruit** for the **SSD1306** and **GFX** libraries.
- **Arduino community** for valuable resources and support.
- **HC-SR04** for providing accurate distance measurement at an affordable cost.

---

Feel free to modify this README to suit your needs or add more details as necessary! Let me know if you need further help.
