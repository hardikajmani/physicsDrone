int motor1 = 11;      // 11,10,9,6 are pwm pins
int motor2 = 10;
/*int motor3 = 9;      //Motors 3 and 4 are commented evrywhere as 
int motor4 = 6;        // I m assuming that we will connect two motors two one pin*/   
int buzz = 13;

String comm;

void checkComm( String a);      //switch case
int checkCode(String a);        // as switch accepts only int
void sound();                   // beep function
void on();
void off(int &n);               //call by reference so that the value of pwm changes with evry function
void up(int &n);
void down(int &n);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
 /* pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);*/
  pinMode(buzz,OUTPUT);

  digitalWrite(motor1,LOW); //setting default values of the pin as low that is off
  digitalWrite(motor2,LOW);
 /* digitalWrite(motor3,LOW);
  digitalWrite(motor4,LOW);*/
  digitalWrite(buzz,LOW);

  Serial.begin(9600);   //setting baud rate at 9600 for bluetooth module to communicate
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
      comm = Serial.readString();   // this will read string the string from the user
    }
  checkComm(comm);      //calling the check command function  

}


int checkCode(String a){

    if(a == "ON") return 1;
    else if(a == "OFF") return 2;
          else if(a == "UP") return 3;
                else if(a == "DOWN") return 4;
                      else return 0;
  }

void checkComm(String a){

    int motorLevel = 10;   //assuming that out of 255 quadcopter will not fly at it
    
    switch(checkCode(a)){

        case 1:    on();  // on function is called
                        break;
        case 2:   off(motorLevel);
                        break;
        case 3:    up(motorLevel);
                        break;
        case 4:  down(motorLevel);
                        break;
        default :       Serial.println("Command doesn't exist or use all commands in CAPS!");
                        break;
                       
      }
  }

void sound(){
    digitalWrite(buzz,HIGH);
    delay(200);
    analogWrite(buzz,124);
    delay(200);
    analogWrite(buzz,255);
    delay(200);
    digitalWrite(buzz,LOW);
  }

void off(int &n){
  while(n>10){
      analogWrite(motor1,n);
      analogWrite(motor2,n);
      n-=15;
    }
   digitalWrite(motor1,LOW);
   digitalWrite(motor2,LOW);
   sound();
   n=10;
  }

void on(){

  sound();       //calling the beep function 
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,HIGH);
  analogWrite(motor1,10);
  analogWrite(motor2,10);
  }

void up(int &n){
  
  if(n+33 < 208){        // assuming 208 as the highest pole point
    n+=33;
    analogWrite(motor1,n);
    analogWrite(motor2,n);
  }
  else  sound();             //give a beep
} 

void down(int &n){
  
  if(n-33 > 10){
    n-=33;
    analogWrite(motor1,n);
    analogWrite(motor2,n);
  }
  else sound();                // give a beep
}
  
