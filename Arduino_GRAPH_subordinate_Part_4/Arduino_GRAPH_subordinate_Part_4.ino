#include<SoftwareSerial.h>

#define RXa 10
#define TXa 11
#define RXb 12
#define TXb 13
#define MY_NAME 62 //имена начинаются с 60
#define NOT_CONNECTED 254
#define CONNECTED 253

SoftwareSerial mySerialA(RXa,TXa);
SoftwareSerial mySerialB(RXb,TXb);

byte level;
bool branch_A = false;
bool branch_B = false;
bool start = false;
byte name_A = 0;
byte name_B = 0;
bool initializer = false;
bool flag = false;

void connection();

void setup() 
{
  Serial.begin(9600);
  mySerialA.begin(9600);
  mySerialB.begin(9600);
}

void loop() 
{
    /*if(Serial.available())
    {
      while(Serial.available())
      Serial.read();
      flag = true;
      Serial.println("Ready");
    }//*/
    //if(flag)
      connection();
}

void connection()
{
  byte message = 0;
  byte pin = 0;
  mySerialA.listen();
  delay(1);
  if(mySerialA.available())
  {
    byte a[2];
    mySerialA.readBytes(a, 2);
    message = a[0];
    name_A = a[1];
    pin = 1;
    Serial.print(message);
    Serial.println(name_A);
  }
  mySerialB.listen();
  delay(1);
  if(mySerialB.available())
  {
    byte b[2];
    mySerialB.readBytes(b, 2);
    message = b[0];
    name_B = b[1];
    pin = 2;
    Serial.print(message);
    Serial.println(name_B); 
  }

  if (message == 255)
  {
    switch(pin)
    {
      case 1:
      mySerialA.listen();
      delay(1);
      mySerialA.write(MY_NAME);
      mySerialA.write(NOT_CONNECTED);
      flag = false;
      return;
      case 2:
      mySerialB.listen();
      delay(1);
      mySerialB.write(MY_NAME);
      mySerialB.write(NOT_CONNECTED);
      flag = false;
      return;
    }
  }
}
