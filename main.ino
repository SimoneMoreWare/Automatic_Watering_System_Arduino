#define WET_PIN A0
#define RELAY_PIN 12 

void misure_wet(){
  int SensorValue = analogRead(WET_PIN); //take a sample
  //Serial.print(SensorValue); Serial.print(" - ");
  digitalWrite(RELAY_PIN, LOW);
  
  if(SensorValue >= 600) {
   //Serial.println("Sensor is not in the Soil or DISCONNECTED");
    digitalWrite(RELAY_PIN, HIGH);
    delay(5000);
    digitalWrite(RELAY_PIN, LOW);
  }else{
   //Serial.println("Soil is HUMID"); 
   digitalWrite(RELAY_PIN,LOW);
  }
  
  delay(50);
}
void setup() {
  // initialize digital pin as an output.
  //Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(WET_PIN, INPUT);
}

// the code in loop function is executed repeatedly infinitely
void loop() {
  misure_wet();
}
