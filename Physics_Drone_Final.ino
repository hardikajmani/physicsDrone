/* This is the code for controlling a quadcopter using an arduino command prompt application in phone connected to arduino via bluetooth using bluetooth module.
 * Presently using this code we can switch on,off,increase and decrease the speed of all motors together.
 * conditions given here are:-
                    'o' for on
                    'a' for off
                    'u' to increase the speed
                    'd' to decrease the speed
 * There is a buzzer over here which will ring whenever the 'on' or 'off' command is sent.
 * It will also ring whenever the quadcopter has reached its max or min limit.
 */






int motorPin1 = 11;             //PWM pins
int motorPin2 = 10;             //Each pin will be connected to two motors
int buzzer = 12;                // The buzzer pin
int state = 0;
int level = 0;                  //Variable to keep track of motor's pwm value
int flag = 0;

void setup() {
 
pinMode(motorPin1,OUTPUT);
pinMode(motorPin2,OUTPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(buzzer,LOW);
digitalWrite(motorPin1,LOW);
digitalWrite(motorPin2,LOW);
Serial.begin(9600);              //to begin the communication
}

void loop() {
  
if(Serial.available()){
   state = Serial.read();
  }
if(state == 'a' && flag == 1){           //  off condition 
  analogWrite(motorPin1,0);              // flag = 1 states that quadcopter has been switched on and 0 for off. 
  analogWrite(motorPin2,0);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  delay(500);                           // This delay is to give code suffiient time to re read the command sent
  level = 0;
  flag = 0;
}
if(state == 'o' && flag == 0){         //  on condition
analogWrite(motorPin1,50);
analogWrite(motorPin2,50);
digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);
delay(100);
delay(500);
level = 50;
flag = 1;
}
if(state == 'u' && flag == 1){           // increase the speed of all motors by 20 units
  if((level+20) < 255){
      level+=20;
      analogWrite(motorPin1,level);
      analogWrite(motorPin2,level);
  }
  else{                                 // else give a buzz indicating the max speed is reached
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    }
  delay(500);
  }

 if(state == 'd'  && flag == 1){       //decrease the speed of all motors by 20 units
  if((level-20)>20){
    level-=20;
    analogWrite(motorPin1,level);
    analogWrite(motorPin2,level);
  }
  else{
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
  }
  delay(500);
  }
  state = 0;                                                                                        //Hardik Ajmani
}
