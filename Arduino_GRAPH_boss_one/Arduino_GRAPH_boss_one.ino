#include<SoftwareSerial.h>

#define RXa 10
#define TXa 11
#define RXb 12
#define TXb 13
#define MY_NAME 60 //Имнеа начинаются с 60
#define ARE_YOU_HERE 255
#define CONNECTED 253

SoftwareSerial mySerialA(RXa,TXa);
SoftwareSerial mySerialB(RXb,TXb);

byte level = 0;
bool branch_A = false;
bool branch_B = false;
byte name_A = 0;
byte name_B = 0;


void connectionCheck();
//void roleSwitch(char branch);

void setup() {
  Serial.begin(9600);
  mySerialA.begin(9600);
  mySerialB.begin(9600);
  delay(1000); // Ждем пока все включатся
}

void loop() {
  connectionCheck();
  if (Serial.available()){
    while (Serial.available()) Serial.read();
    connectionCheck();
    name_A = 0;
    name_B = 0;
  }

}


void connectionCheck()
{
  mySerialA.listen();
  delay(1);
  mySerialA.write(ARE_YOU_HERE);
  mySerialA.write(MY_NAME);
  delay(10);
  if (mySerialA.available())
  {
    name_A = mySerialA.read();
    int m = mySerialA.read();
    Serial.print(name_A);
    Serial.println(m);
  }
  //delay(10);
  //}
  mySerialB.listen();
  delay(1);
  mySerialB.write(ARE_YOU_HERE);
  mySerialB.write(MY_NAME);
  delay(10);
  //mySerialB.write(MY_NAME);
  //delay(50);
  if (mySerialB.available())
  {
    name_B = mySerialB.read();
    Serial.print(name_B);
    Serial.println(mySerialB.read());
  }
}


/*void roleSwitch()
{
  if(branch_A)
  {
    mySerialA.listen();
    mySerialA.write(CONNECTED);
    delay(50);
  }
  if(branch_B)
  {
    mySerialB.listen();
    mySerialB.write(CONNECTED);
    delay(50);
  }
}//*/
