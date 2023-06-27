#include<SoftwareSerial.h>

#define RXa 10
#define TXa 11
#define RXb 12
#define TXb 13
#define MY_NAME 60 //Имена начинаются с 60
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
}

void loop() 
{
  connectionCheck();
  //if (Serial.available()){
    //while (Serial.available()) Serial.read();
    //connectionCheck();
    //Serial.println(name_A);
    //Serial.println(name_B);
    name_A = 0;
    name_B = 0;
    //roleSwitch();
    /*if (branch_A)
      roleSwitch("A");
    delay(100);
    if (branch_B)
      roleSwitch("B");//*/
  
  

}

void connectionCheck()
{
  mySerialA.listen();
  delay(1);
  mySerialA.write(ARE_YOU_HERE);
  mySerialA.write(MY_NAME);
  delay(10);
  if (mySerialA.available() > 0)
  {
    name_A = mySerialA.read();
    Serial.print(name_A);
    Serial.println(mySerialA.read());
    /*if(name_A > 60 && name_A  < 80) 
      branch_A = true;
    else 
      name_A = 0;//*/
  }

  mySerialB.listen();
  delay(1);
  mySerialB.write(ARE_YOU_HERE);
  mySerialB.write(MY_NAME);
  delay(10);
  if (mySerialB.available() > 0)
  {
    name_B = mySerialB.read();
    Serial.print(name_B);
    Serial.println(mySerialB.read());
    /*if(name_B > 60 && name_B  < 80) 
      branch_B = true;
    else 
      name_B = 0;*/
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
