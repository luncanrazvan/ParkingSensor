//alegem pinii
const int trigPin=6;
const int echoPin=7;
const int led1=12;
const int led2=10;
const int led3=5;
const int led4=4;
const int buzzer=11;

//definim variabilele
long duration;
int distance;


void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
//  pinMode(led5,OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); //aici incepe comunicarea seriala

}

void loop() {
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
   
  //Reads the echoPin, returns the sound wave travel time in microseconds
  duration=pulseIn(echoPin,HIGH);

  //calculam distanta
  distance=duration*0.034/2;

  if(distance<=5){
     tone(buzzer, 50);
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
     Serial.println("Too Close!");
  }else if(distance<=11){
    noTone(buzzer);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }else if(distance<=19){
    noTone(buzzer);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);;
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }else if(distance<=33){
    noTone(buzzer);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }else{
    noTone(buzzer);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
}
