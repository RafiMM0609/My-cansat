# My-cansat
Used for temperature monitoring, vehicle attitude monitoring including roll pitch yaw, and vehicle altitude monitoring in the air.
In this project I used **ESP32** for the microcontroller, **BMP388** for barometer reading, **MPU9250** for vehicle attitude reading for example gyro x, y, z and accel x, y, z. The value of the sensor can be monitored in real time with **XBEE S2C** which transmits data to GCS.
## ESP32
I wanted to use Teensy 4.0 but I'm not familiar with Teensy 4.0, at that time I had little research time so I chose to use ESP 32. Actually, ESP32 is enough to be used as a microcontroller in this project.
- ESP32 
  - 240MHz processor speed
  - 4 x SPI, 2 x I2C, 3 x UART
- Teensy 4.0 
  - 600Mhz processor speed
  - 7 x UART, 3 x I2C, 3 x SPI.
## Project Schema
I connect MPU950, SHT 31, and BMP38 to ESP32 to send sensor data and sort it so that later ESP32 will send sorted data to Ground Station via XBee transmission media. I use I2C data interface to connect those 3 sensors with ESP32, I2C stands for Inter-Integrated Circuit. It is a bus interface connection protocol incorporated into devices for serial communication. With I2C we can save more pin in ESP32, for 3 sensor we just need 2 pin ford sda and scl then 2 pin for power and ground. This's my wiring diagram
![wiring_diagram.jpeg](https://github.com/RafiMM0609/My-cansat/blob/main/Picture/wiring_diagram.jpeg)<br>
From the picture above, we can see if I combined the SCL of many sensors and also for SDA, GND, and Power, the goal is to simplify wiring, so when there is damage or error we can more easily fix it and also we can save more space in the PCB. You can setup..
- SDA to ESP32 pin 33
- SCL to ESP32 pin 32
- GND to GND
- MPU9250 5V
- BMP388 3.3V
> for the SCL and SDA you can change it according to your needs.
## How to Work
First before you run all programs you need to test your sensor is working porperly or not, i advise you to use project board and jumper wires so that you can easily connect the sensors and change them if the sensor isn't correct. You can setup..
- MPU 9250
  - SDA ---> 33
  - SCL ---> 32
  - GND to GND
  - Vin ---> 5V
### 1. Find out sensor address
If we use I2C we need to know the address of the sensor first, different when we use analog or digital pins we only need to state which pin we will use. When we use I2C we just need to state 2 pins which one for SCL and SDA. you can run **I2C_scanner.ino** and open the serial monitor to get sensor address
### 2. Run MPU950 
If you didn't have the MPU9250 library you can download it and include the library to arduino ide, and run the code. ***dont forget to fill mpu.setup() with the sensor address***
> MPU9250 https://www.arduino.cc/reference/en/libraries/mpu9250/ <br> BMP388 https://www.arduino.cc/reference/en/libraries/107-arduino-bmp388/ 

in serial monitor you must get the value of the sensor, if you didn't get it you must check **your wiring** or change the sensor.Repeat this step for other sensor
### 3. Combine all componen
After make sure that the sensors are running properly, we need to combine all the sensors with the ESP32 and Combine the code too. You can run **MyCansat.ino** <br>
## Data Communication
After all of the value from the sensor appear, if you want to show the realtime data when the vehicle in the air we need to setup the data communication for ESP32 to GCS with XBEE S2C. Before we start using XBee in our ESP32, we need to pair 2 XBee first one for the vehicle and GCS. You can setup
- XBEE S2C to ESP32
  - TX --> RX
  - RX --> TX
  - Vin --> 5V
  - GND --> GND
For the experiment we must have XCTU software on laptop / PC to see data sent by ESP32. After we have done setup we need test if the ESP32 and PC connected correctly. You can run 
