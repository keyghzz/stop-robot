//check https://www.teachmemicro.com/use-l298n-motor-driver/ for setup.
// motor B was used
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
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
//analogWrite(EnB, 200);
delay(2000);
// now turn off motors
digitalWrite(7, LOW);
digitalWrite(6, LOW);
Serial.println("ran");
}
void loop() {
// put your main code here, to run repeatedly:
goStraight();
delay(1000);
}
