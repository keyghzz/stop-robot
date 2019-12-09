//check https://www.teachmemicro.com/use-l298n-motor-driver/ for setup.
// motor B was used

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(7, OUTPUT); //IN3
  pinMode(6, OUTPUT); //IN4
}

void goStraight()   //run both motors in the same direction
{
// turn on motor B
digitalWrite(7, HIGH);
digitalWrite(6, LOW);
// set speed to 150 out 255
// uncomment and remove jumper
// analogWrite(EnB, 200);
// now turn off motors
digitalWrite(7, LOW);
digitalWrite(6, LOW);
Serial.println("ran");
delay(1000);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(inches > 10.0)
  {
    goStraight();
  }
}
