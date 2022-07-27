#include "MPU9250.h"
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h" 
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Servo.h>
SoftwareSerial zigbee(1,3);
unsigned long myTime;
Adafruit_BMP3XX bmp; 
MPU9250 mpu;
float temperature, pressure, altitude,ketinggian;

float vol = random(4.9,5.7);
int err = random(4,9);
int temp = 0;
int menit = 0;
int jam = 0;
int x = 1;
int y = 0;
int z = 1;
int i = 0;
int g = 1;
int pos = 0;
int packet_count = 0;
float yer = 0;
float yval = 0;

void setup() {
    Serial.begin(115200);
    Wire.begin(33, 22);
    delay(2000);
    MPUsetup();
    BMPsetup();
}

void loop(){
  Packetcount();
  Serial.print("1067");
  Serial.print(",");
  Timemission();
  Serial.print(",");
  Serial.print(packet_count);
  Serial.print(",");
  Serial.print("T");
  Serial.print(",");
  BMPprint();
  Serial.print(vol);
  Serial.print(",");
  MPUprint();
  Yawpointing();
  //Serial.print(err);
  Serial.print(",");
  Serial.println("R");
  delay(250);
}

void Timemission(){
  myTime = millis();
  temp = myTime/1000;
  menit = temp/60;
  jam = menit/60;
  Serial.print(jam);  
  Serial.print(":");
  Serial.print(menit);
  Serial.print(":");
  Serial.print(temp%60); // prints time since program started
}

void Packetcount(){
  int y = x++;
  packet_count = z++;
}

void MPUsetup(){
  if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
}

void MPUprint(){
    if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            MPUdata();
            prev_ms = millis();
      }
   }
}

void BMPsetup(){
  while (!Serial);
  Serial.println("Adafruit BMP388 / BMP390 test");
  if (!bmp.begin_I2C(0x77)) {   // hardware I2C mode, can pass in address & alt Wire 
    Serial.println("Could not find a valid BMP3 sensor, check wiring!");
    while (1);
  }
  // Set up oversampling and filter initialization
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

void MPUdata() {
    mpu.update();
    //Serial.print("Yaw, Pitch, Roll: ");
    //Serial.print(mpu.getYaw(), 2);
    //Serial.print(", ");
    //Serial.print(mpu.getPitch(), 2);
    //Serial.print(", ");
    //Serial.println(mpu.getRoll(), 2);
    //Serial.print("Gyro : ");
    Serial.print(mpu.getGyroX(), 1);
    Serial.print(",");
    Serial.print(mpu.getGyroY(), 1);
    Serial.print(",");
    Serial.print(mpu.getGyroZ(), 1);
    Serial.print(",");
    //Serial.print("Accel : ");
    Serial.print(mpu.getAccX(), 2);
    Serial.print(",");
    Serial.print(mpu.getAccY(), 2);
    Serial.print(",");
    Serial.print(mpu.getAccZ(), 2);
    Serial.print(",");
    //Serial.print("Mag : ");
    Serial.print(mpu.getMagX(), 2);
    Serial.print(",");
    Serial.print(mpu.getMagY(), 2);
    Serial.print(",");
    Serial.print(mpu.getMagZ(), 2);
    Serial.print(",");
}

void Yawpointing(){
  yer = mpu.getYaw(), 2;
  yval = 0-yer;
  Serial.print(yval);
  }

void BMPprint(){
  BMP_calibraton_timee();
  if (! bmp.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;   
  }
  if (i <= 10){
    altitude = bmp.pressure / 100.00;
    }
    else {
    Serial.print("");
      }
  Serial.print(bmp.readAltitude(altitude));
  Serial.print(",");
  Serial.print(bmp.temperature);
  Serial.print(",");
    }

void BMP_calibraton_timee(){
  i = g++;
  }

void servo_setup(){
  myservo.attach(9); //9 bs dignti nmr pin esp32
  }

void east_camera(){
  yer = mpu.getYaw(), 2;
  yval = 0-yer;

  if (yval >= 3) {
    for (pos = 0; pos <=180; pos +=1){
      mysevo.write(pos);
      delay(15);
      }
    }
    else if (yval <= -3){
      for (pos = 180; pos >=0; pos -=1){
        myservo.write(pos);
        delay(15);
        }
      }
  }
