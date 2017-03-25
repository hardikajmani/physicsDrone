int motor1 = 11;      // 11,10,9,6 are pwm pins
int motor2 = 10;
/*int motor3 = 9;      //Motors 3 and 4 are commented evrywhere as 
int motor4 = 6;        // I m assuming that we will connect two motors two one pin*/   
int buzz = 13;
int flag = 0;
int n = 10;      // assuming tht quadcopter doesn't fly in this value

int c = 0;
String comm,readString;

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
 /* if(Serial.available()>0){
      comm = Serial.readString();   // this will read string the string from the user
      Serial.println(comm);
    }
  checkComm(comm);      //calling the check command function  */
  /*while (Serial.available()) {
    delay(10);  //small delay to allow input buffer to fill

    char c = Serial.read();  //gets one byte from serial buffer
    Serial.write(c);
    readString += c; 
  } //makes the string readString  

  if (readString.length() >0) {
    Serial.println(readString); //prints string to serial port out

    readString=""; //clears variable for new input*/
    if(Serial.available()>0){
      c = Serial.read();
      checkComm(c);
      c=0;
    }
    

}


int checkCode(String a){

    if(a == "ON") return 1;
    else if(a == "OFF") return 2;
          else if(a == "UP") return 3;
                else if(a == "DOWN") return 4;
                      else return 0;
  }

void checkComm(int a){

  
    
    switch(a){

        case 1:    on();  // on function is called
                  // Serial.println("Device is ON!") ;
                        break;
        case 2:   off();
                 // Serial.println("Device is OFF!") ;
                        break;
        case 3:    up();
                        break;
        case 4:  down();
                        break;
       default :       Serial.println("Error!");
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

void off(){
  /*while(n>10){
      analogWrite(motor1,n);
      analogWrite(motor2,n);
      n-=15;
    }*/
   digitalWrite(motor1,LOW);
   digitalWrite(motor2,LOW);
   sound();
   flag = 0;
   n=10;
  }

void on(){

  sound();       //calling the beep function 
  digitalWrite(motor1,HIGH);
  digitalWrite(motor2,HIGH);
  analogWrite(motor1,10);
  analogWrite(motor2,10);
  flag = 1;
  }

void up(){
  
  if(n+33 < 208){        // assuming 208 as the highest pole point
    n+=33;
    analogWrite(motor1,n);
    analogWrite(motor2,n);
  }
  else  sound();             //give a beep
} 

void down(){
  
  if(n-33 > 10){
    n-=33;
    analogWrite(motor1,n);
    analogWrite(motor2,n);
  }
  else sound();                // give a beep
}
  
