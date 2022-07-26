# My-cansat
Used for temperature monitoring, vehicle attitude monitoring including roll pitch yaw, and vehicle altitude monitoring in the air.
In this project I used **ESP32** for the microcontroller, **BMP380** for barometer reading, **MPU9250** for vehicle attitude reading for example gyro x, y, z and accel x, y, z
## ESP32
I wanted to use Teensy 4.0 but I'm not familiar with Teensy 4.0, at that time I had little research time so I chose to use ESP 32. Actually, ESP32 is enough to be used as a microcontroller in this project.
- ESP32 
  - 240MHz processor speed
  - 4 x SPI, 2 x I2C, 3 x UART
- Teensy 4.0 
  - 600Mhz processor speed
  - 7 x UART, 3 x I2C, 3 x SPI.
## Skema Project
I connect MPU950, SHT 31, and BMP38 to ESP32 to send sensor data and sort it so that later ESP32 will send sorted data to Ground Station via XBee transmission media. I use I2C data interface to connect those 3 sensors with ESP32, I2C stands for Inter-Integrated Circuit. It is a bus interface connection protocol incorporated into devices for serial communication. With I2C we can save more pin in ESP32, for 3 sensor we just need 2 pin ford sda and scl then 2 pin for power and ground. This's my wiring diagram
<Picture [Diagram ESP 32 and another sensor]>
From the picture above, we can see if I combined the SCL of many sensors and also for SDA, GND, and Power, the goal is to simplify wiring, so when there is damage or error we can more easily fix it and also we can save more space in the PCB. You can setup..
-SCL
