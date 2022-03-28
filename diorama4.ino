// Pulp Fiction Dance Scene Diorama
// Art and illustrations Adriana Fainstein IG @ojoquepiensa
// Circuits and code Roni Bandini IG @RoniBandini 
// Argentina, March 2022

#include <Servo.h>

int pulsoMin = 160;  
int pulsoMax = 1850; 

Servo myServo1;
Servo myServo2;
Servo myServo3;

int pinServo1=2;
int pinServo2=3;
int pinServo3=4;
int pinLaser=10;

int lightOn=0;
int umaMove=0;
int travoltaMove=0;

void ball(){
  Serial.println("Ball"); 
  myServo3.writeMicroseconds(1500);
}

void ballStop(){
  Serial.println("Ball stop"); 
  myServo3.writeMicroseconds(300);  
}

  
void light(){

  if (lightOn==0){
    digitalWrite(pinLaser, HIGH);     
    lightOn=1;

    }
  else
  {
    digitalWrite(pinLaser, LOW);  
    lightOn=0;
    }
  
}

void uma(){

  Serial.println("Uma"); 
    
  if (umaMove==0){
      myServo2.write(0);  
      umaMove=1;
      }
    else
    { 
      myServo2.write(30);  
      umaMove=0;
      }   

}

void travolta(){

  Serial.println("Travolta"); 
    
  if (travoltaMove==0){      
      myServo1.write(70);                
      travoltaMove=1;
      }
    else
    { 
      myServo1.write(90);  
      travoltaMove=0;
      }   

}

void setup() {

  // regular
  myServo1.attach(pinServo1);
  myServo2.attach(pinServo2);

  pinMode(pinLaser, OUTPUT);
  
  // 360 servo  
  myServo3.attach(pinServo3, pulsoMin, pulsoMax);

  Serial.begin(115200);      
  Serial.println("Diorama started"); 
  Serial.println(""); 

  ballStop();  
  
  // light on off
  light();
  delay(200);    
  light();
  delay(200); 
  light();
  delay(200);    
  light();
  delay(200);  
  
  // Uma 
  uma();
  delay(800);
  uma();
  delay(800);
  uma();
  delay(800);
  uma();
  delay(800);

  // Travolta
  travolta();  
  delay(800); 
  travolta();
  delay(800); 
  travolta();
  delay(800); 
  travolta();
  delay(800);

  // start ball
  ball();
  delay(1500);
  
}



void loop() {

  ballStop();
  
  travolta(); 
  delay(400); 
  travolta();  
 
  light();
  delay(100);
  light();
  delay(100);
  
  uma();
  delay(400); 
  uma(); 
  delay(200); 

  ball();
  
  // laser
  light();
  delay(100);
  light();
  delay(100);
  
  
  // Sequence 1
  ballStop();
  travolta();    
  uma();   
  light(); 
  ball();
  delay(800);      
  travolta();      
  uma();   
  light(); 
  delay(400); 

  // Sequence 2
  ballStop();
  travolta();      
  light(); 
  ball();
  delay(400);      
  travolta();        
  light(); 
  delay(200); 

  // Sequence 3
  ballStop();
  uma();      
  light(); 
  delay(200);      
  ball();
  uma();        
  light(); 
  delay(400);

  // Sequence 4
  ballStop();
  light();  
  uma(); 
  delay(400);
  ball();
  uma(); 
  delay(400);
  travolta();     
  delay(200); 
  uma(); 
  delay(200);
  uma(); 
  delay(200);
  travolta();     
  delay(200);       
  light(); 
 
}
