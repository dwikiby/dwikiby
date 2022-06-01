int echo_pin = D6;
int trig_pin = D7;
long echotime; 
float distance;

int redPin = D2;
int greenPin = D3;
int bluePin = D4;
int interval;

void setup() {
  pinMode(trig_pin, OUTPUT); 
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime= pulseIn(echo_pin, HIGH);
  distance= 0.0001*((float)echotime*340.0)/2.0;
  //Serial.println(distance);
  
  if (distance<10){
    setColor(255, 0, 0); // Red Color
  }
  else if(distance<30){ 
    if(distance>70)interval=distance*3;
    else interval=distance;  
    setColor(255, 50, 0); // Yellow
    delay(1000);
  }
  else {    
    setColor(0, 255, 0); // Green Color
  }
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
