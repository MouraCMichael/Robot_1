/*
  DC Motor Control with H-Bridge
 
 Controls the direction with two pins
 
 The circuit:
 * L298N Board
   IN1 connected to  pin 7
   IN2 connected to pin 8
   EN1 connected to pin 9
 * Motor connected to M1 on L298N Board

 created 18 Feb. 2017
 by Nicholas Baine
 
 This example code is in the public domain.
 
 */
int motor_speed();
int motor_direction();


void setup() {
  // initialize serial communications at 9600 bps:
     
      Serial.begin(9600);
      
      pinMode(1,OUTPUT);    //assign pins motor 1  
      pinMode(2,OUTPUT);
      pinMode(3,OUTPUT);
      
      pinMode(7,OUTPUT);    //assign pins motor 2
      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);
      
      Serial.println("Speed is between 0 and 255");
      
}

void loop() {

 int Speed;
 int speed_return;
   
    
    (motor_speed());   //calls motor speed function
    
    //Serial.print("Your motors' speed is:");
    //Serial.print("speed_return");
    
   
   //motor_direction();   //calls motor direction function
      //Serial.print("please enter direction");
      //Serial.read();

                  
}
int motor_speed()   //motor speed program
{

    int Speed; //Set the speed, value between 0-255
    int speed_return;
    { 
        
        if (Serial.available())
        {
          int Speed = Serial.read();
          if (Speed >= 0 && Speed <= 255)
          {
            analogWrite(3, Speed);
          }
        }
     } 
            
} 
 
    //Speed = Serial.read(); 
    //analogWrite(Speed, speed_return);
     
    //Serial.print("please enter a speed between the numbers 0-9");   //prompts user    Serial.scanf();    //stores user input
    //Serial.read();
    //Speed = Serial.read(); 
    
    //analogWrite(9, Speed); //Controls a PWM signal on pin 9
//}

int motor_direction()
{

  
      //Set direction "Forward"
    Serial.println("Forward");    
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(5000); //wait a sec
    
      //Set direction "Backward"
    Serial.println("Backward");
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    delay(5000); //wait a sec
    
      //STOP Motor
      // The motor can be stopped by setting the speed to zero 
      //  or both direction pins to LOW
    analogWrite(9,0);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(1000); //wait a sec
 
 
 //Motor 2   
    
    Serial.println("Forward");
      digitalWrite(1,HIGH);
      digitalWrite(2,LOW);
      delay(5000); //wait a sec
    //Set direction "Backward"
    Serial.println("Backward");
      digitalWrite(1,LOW);
      digitalWrite(2,HIGH);
      delay(5000); //wait a sec
    
      //STOP Motor
      // The motor can be stopped by setting the speed to zero 
      //  or both direction pins to LOW
    analogWrite(3,0);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    delay(1000); //wait a sec
}
