int motorPin1 = 11;
int motorPin2 = 10;
int buzzer = 12;
int state = 0;
int level = 0;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(motorPin1,OUTPUT);
pinMode(motorPin2,OUTPUT);
pinMode(buzzer,OUTPUT);
digitalWrite(buzzer,LOW);
digitalWrite(motorPin1,LOW);
digitalWrite(motorPin2,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
   state = Serial.read();
  }
if(state == 'a' && flag == 1){
  analogWrite(motorPin1,0);
  analogWrite(motorPin2,0);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  delay(500);
  level = 0;
  flag = 0;
}
if(state == 'o' && flag == 0){
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
if(state == 'u' && flag == 1){
  if((level+20) < 255){
      level+=20;
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

 if(state == 'd'  && flag == 1){
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
  state = 0;
}
