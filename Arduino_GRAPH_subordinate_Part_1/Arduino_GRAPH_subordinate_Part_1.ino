#include<SoftwareSerial.h>

#define RXa 10
#define TXa 11
#define RXb 12
#define TXb 13
#define MY_NAME 62 //имена начинаются с 60

SoftwareSerial mySerialA(RXa,TXa);
SoftwareSerial mySerialB(RXb,TXb);

byte level = 0;
bool branch_A = false;
bool branch_B = false;
bool branch_C = false;
bool branch_D = false;
bool initializer = false;

bool connection();

void setup() 
{
  Serial.begin(9600);
  mySerialA.begin(9600);
  mySerialB.begin(9600);
}

void loop() 
{
  connection();
}

bool connection()
{
  byte message = 0;
  byte pin = 0;
  if(Serial.available() > 0)
  {
    message = Serial.read();
    pin = 1;
  }
  mySerialA.listen();
  delay(2);
  if(mySerialA.available() > 0)
  {
    message = mySerialA.read();
    pin = 2;
  }
  mySerialB.listen();
  delay(2);
  if(mySerialB.available() > 0)
  {
    message = mySerialB.read();
    pin = 3;
  }
  if (message == 255)
  {
    switch(pin)
    {
      case 1:
      Serial.write(MY_NAME);
      return true;
      case 2:
      mySerialA.listen();
      mySerialA.write(MY_NAME);
      return true;
      case 3:
      mySerialB.listen();
      mySerialB.write(MY_NAME);
      return true;
    }
  }
  else
  {
    Serial.write(0);
    return false;
  }      
}
