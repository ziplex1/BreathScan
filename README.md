# BreathScan

```markdown
# Smoke Detector with ESP32, MQ-135, LCD, and Buzzer

This project is an implementation of a smoke detector using an ESP32, an MQ-135 gas sensor, a 16x2 LCD display, and a piezo buzzer. The system reads the smoke level from the MQ-135 sensor, displays the reading on the LCD, and sounds an alarm when the smoke level exceeds a predefined threshold.

## Components Used

- ESP32
- MQ-135 Gas Sensor
- 16x2 I2C LCD Display
- Piezo Buzzer
- Connecting Wires
- Breadboard

## How to Use

1. Connect the components.
2. Upload the code to your ESP32 using the Arduino IDE.
3. Open the Serial Monitor to view the sensor readings.
4. The LCD will display the smoke level reading.
5. If the smoke level exceeds the threshold of 2000, the buzzer will sound, and a "Not Safe!" message will be displayed on the LCD.

## References

- [ESP32 with Piezo Buzzer](https://esp32io.com/tutorials/esp32-piezo-buzzer)
- [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)

## License

This project is open source and available under the [MIT License](LICENSE).
