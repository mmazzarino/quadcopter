#include "CONFIGURACAO.h"

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0); 
  Wire.endTransmission(true);

}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true); 

  ax1=Wire.read()<<8|Wire.read();      
  ay1=Wire.read()<<8|Wire.read();  
  az1=Wire.read()<<8|Wire.read();    
  gx1=Wire.read()<<8|Wire.read();  
  gy1=Wire.read()<<8|Wire.read();  
  gz1=Wire.read()<<8|Wire.read();  

  ax = ((ax1*GRAVI)/CALIB);
  ay = ((ay1*GRAVI)/CALIB);
  az = ((az1*GRAVI)/CALIB);

  ax2 = (atan2(ax1, sqrt(pow(ay1,2) + pow(az1,2)))*180) / 3.14; 
  ay2 = (atan2(ay1, sqrt(pow(ax1,2) + pow(az1,2)))*180) / 3.14; 
  az2 = (atan2(az1, sqrt(pow(ax1,2) + pow(ay1,2)))*180) / 3.14; 

  gx2 = gx1 * G_GAIN; 
  gy2 = gy1 * G_GAIN; 
  gz2 = gz1 * G_GAIN; 

  gx= ((0.98 *((gx + gx2) * dt))) + (0.02 * ax2)) * 100;
  gy= ((0.98 *((gy + gy2) * dt)) + (0.02 * ay2)) * 100;
  gz= ((0.98 *((gz + gz2) * dt)) + (0.02 * az2)) * 100;


  
}

}
