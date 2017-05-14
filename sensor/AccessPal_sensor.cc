//AccessPal Sensor for monitoring of accesibility points
#define TRIGGER 4  
#define ECHO    5

const int pinLedG = 13; //green
const int pinLedR = 15; //red
const int pinLedB = 14; //blue
WiFiClient client;
const char* ssid = "Smart City";
char server[] = "http://122.173.212.219/";

void setup() { 
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT); 
  pinMode(ECHO, INPUT); 
  pinMode(pinLedG,OUTPUT); 
  pinMode(pinLedR,OUTPUT); 
  pinMode(pinLedB,OUTPUT); 
  delay(10);
  
  WiFi.begin(ssid);
 }

void loop() {
  int obstacle = 0;
  int rampID = 5023;
  client.connect(server,80);
  client.println("GET /sensor? HTTP/1.1");
  
  client.println("obstacle=");
  client.print(obstacle);
  client.println("&rampID=");
  client.print(rampID);
  
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
  obstacle = 1;
  }else{
    digitalWrite(pinLedR, LOW);
    digitalWrite(pinLedG, HIGH);
  obstacle = 0;
  }

if(obstacle > 0){
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
  
  client.stop();
  delay(1000);
}