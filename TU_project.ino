const int pumpPin = 7;
int digitalIR = 2;
int analogIR = A0;
int digitalvalue = 0;
int analogvalue = 0;
bool stopped = false;
unsigned long previousMillis = 0;
unsigned long interval = 300;

//MOTOR1,2 PINS
int ena = 5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int enb = 10;

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(digitalIR, INPUT);
  pinMode(analogIR, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  digitalWrite(pumpPin, LOW);
  Serial.begin(9600);
}

void loop() {
  //water pump code
  /*digitalWrite(pumpPin, HIGH);
  delay(3000);
  digitalWrite(pumpPin, LOW);
  delay(2000);*/
  //flame sensor module
  if (millis() - previousMillis > interval) {
    previousMillis += interval;
    digitalvalue = digitalRead(digitalIR);
    analogvalue = analogRead(analogIR);
  }
  if (digitalvalue == HIGH && analogvalue <= 300) {
    Serial.println("Flame detected");
    stopped = true;
    Serial.println(analogvalue);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(ena, 255);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enb, 255);
  }
  else if (stopped == true) {
    Serial.println("Flame stopped");
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    stopped = false;
  }
}