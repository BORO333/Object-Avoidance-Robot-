int trigPin = 3;
int echoPin = 2;
long duration;
long distance;
int ena = 10;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enb = 5;
int i = 0;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(duration);
  Serial.print("Distance: ");
  Serial.print(distance);  
  Serial.println(" cm");
  if(distance <= 27){
    while (i <=300){
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    i++;
    }
    i = 0;
    delay(100);
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }else {
    analogWrite(ena, 255);
    analogWrite(enb, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}
