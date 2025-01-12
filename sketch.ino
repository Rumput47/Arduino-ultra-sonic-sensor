/*
VCC to +5V
GND to ground
TRIG to digital pin 3
ECHO to digital pin 5
*/
 
const int TRIG_PIN = 3;
const int ECHO_PIN = 5;
 
void setup() 
{
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop()
{
  long duration, distanceCm, distanceIn;
 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // convert the time into a distance
  distanceCm = duration / 29.1 / 2;
  distanceIn = duration / 74 / 2;
 
  if (distanceCm <= 0)
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distanceIn);
    Serial.print("in: ");
    Serial.print(distanceCm);
    Serial.print("cm");
    Serial.println();
  }
  delay(1000);
}
