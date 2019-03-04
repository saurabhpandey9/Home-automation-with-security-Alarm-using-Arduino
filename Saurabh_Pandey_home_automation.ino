//This aurdino project is being made by Saurabh Pandey as their first IT Workshop Project
//if facing any difficult just Mail me on saurabh17100@gmail.com
#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;               
SoftwareSerial mySerial(rxPin, txPin);

int ac=4;
int light=5;
int fan=6;
int light2=7;
String data;

void setup() 
{
   Serial.begin(9600);
   mySerial.begin(9600);
   
   pinMode(ac, OUTPUT);
   pinMode(light, OUTPUT);
   pinMode(fan, OUTPUT);
   pinMode(light2, OUTPUT);
 
   digitalWrite(ac, HIGH);
   digitalWrite(light, HIGH);
   digitalWrite(fan, HIGH);
   digitalWrite(light2, HIGH);
}

void loop() 
{
    int i=0;
    char ch=0;
    data="";
    while(1)
    { 
      while(mySerial.available()<=0);
      ch = mySerial.read();
      if(ch=='#')
      break;
      data+=ch;
    }
   Serial.println(data);
    
    if(data=="*ac on")
    { 
      digitalWrite(ac,LOW);
      Serial.println("ac on");
    }
    else if(data=="*ac off")
    {
      digitalWrite(ac,HIGH);
      Serial.println("ac off");
    }
    else if(data=="*light on")
    {
      digitalWrite(light,LOW);
      Serial.println("light on");
    }
    else if(data=="*light off")
    {
      digitalWrite(light,HIGH);
      Serial.println("light off");
    }
    else if(data=="*fan on")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan on");
    }
    else if(data=="*fan of")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan off");
    }
    else if(data=="*second light on")
    {
      digitalWrite(light2,LOW);
      Serial.println("light2");
    }
    else if(data=="*second light off")
    {
      digitalWrite(light2,HIGH);
      Serial.println("tv off");
    }
    else if(data=="*all off")
    {
      digitalWrite(ac,HIGH);
      digitalWrite(light,HIGH);
      digitalWrite(fan,HIGH);
      digitalWrite(light2,HIGH);
      Serial.println("all off");
    }
    else if(data=="*all on")
    {
      digitalWrite(ac,LOW);
      digitalWrite(light,LOW);
      digitalWrite(fan,LOW);
      digitalWrite(light2,LOW);
      Serial.println("all on");
    
    }
     else if(data=="*lights on")
     {
      digitalWrite(light2,LOW);
      Serial.println("ac on");
      digitalWrite(light,LOW);
      Serial.println("light on");
     }
     else if(data=="*lights off")
   
    {
      digitalWrite(light2,HIGH);
      digitalWrite(light,HIGH);
      Serial.println("light on");
       Serial.println("ac on");
      
      
    }
}
