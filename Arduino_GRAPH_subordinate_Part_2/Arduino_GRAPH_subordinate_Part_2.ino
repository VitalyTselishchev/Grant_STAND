#include<SoftwareSerial.h>

#define RXa 10
#define TXa 11
#define RXb 12
#define TXb 13
#define MY_NAME 62 //имена начинаются с 60
#define NOT_CONNECTED 254

SoftwareSerial mySerialA(RXa,TXa);
SoftwareSerial mySerialB(RXb,TXb);

byte level;
bool branch_A = false;
bool branch_B = false;
bool start = false;
byte name_A = 0;
byte name_B = 0;
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
  //if(!start)
    connection();
    /*Serial.println(name_A);
    Serial.println(name_B);
    Serial.println(" ");
    delay(500);//*/
}

bool connection()
{
  //start = true;
  byte message = 0;
  byte pin = 0;
  /*if(Serial.available())
  {
    message = Serial.read();
    pin = 1;
  }//*/
  mySerialA.listen();
  delay(2);
  if(mySerialA.available() > 0)
  {
    message = mySerialA.read();
    name_A = mySerialA.read();
    pin = 2;
    /*Serial.println(message);
    Serial.println(" ");
    delay(500);//*/
  }
  mySerialB.listen();
  delay(2);
  if(mySerialB.available() > 0)
  {
    message = mySerialB.read();
    name_B = mySerialB.read();
    pin = 3;
  }
  //Serial.println(message);
    Serial.println(" ");
    
  if (message == 255)
  {
    switch(pin)
    {
      /*case 1:
      Serial.write(MY_NAME);
      Serial.write(NOT_CONNECTED);
      return true;//*/
      case 2:
      mySerialA.listen();
      delay(2);
      mySerialA.write(MY_NAME);
      mySerialA.write(NOT_CONNECTED);
      return true;
      case 3:
      mySerialB.listen();
      delay(2);
      mySerialB.write(MY_NAME);
      mySerialA.write(NOT_CONNECTED);
      return true;
    }
  }
  else
  {
    Serial.write(0);
    return false;
  }      
}
