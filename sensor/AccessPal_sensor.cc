//AccessPal Sensor for monitoring of accesibility points
#define TRIGGER 4  
#define ECHO    5

const int pinLedG = 13; //green
const int pinLedR = 15; //red
const int pinLedB = 14; //blue
WiFiClient client;

void setup() { 
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT); 
  pinMode(ECHO, INPUT); 
  pinMode(pinLedG,OUTPUT); 
  pinMode(pinLedR,OUTPUT); 
  pinMode(pinLedB,OUTPUT); 
  delay(10);
 }

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println("Centimeter:");
  
  if(distance <10){
    digitalWrite(pinLedR, HIGH);
    digitalWrite(pinLedG, LOW);
  }
  else{
    digitalWrite(pinLedR, LOW);
    digitalWrite(pinLedG, HIGH); 
  }

if(distance <10){
  digitalWrite(pinLedB, HIGH);
  delay(100);
  digitalWrite(pinLedB, LOW);
  delay(100);
  digitalWrite(pinLedB, HIGH);
  delay(100);
  digitalWrite(pinLedB, LOW);
  delay(100);
  digitalWrite(pinLedB, HIGH);
  delay(100);
  digitalWrite(pinLedB, LOW);
}
  

  delay(1000);
}