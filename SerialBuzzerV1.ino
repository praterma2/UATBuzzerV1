/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

// the setup routine runs once when you press reset:
int sensorValue = 0;
int buzzer1 = 15;
int buzzer2 = 19;
int buzzer3 = 4;
int buzzer4 = 5;
int reset1 = 18;
//int QuestNum = 0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(buzzer1, INPUT_PULLUP);
  pinMode(buzzer2, INPUT_PULLUP);
  pinMode(buzzer3, INPUT_PULLUP);
  pinMode(buzzer4, INPUT_PULLUP);
  pinMode(reset1, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  delay(500);
//  char buf[10];
//  sprintf(buf, "Qnum %d", sensorValue);
//  Serial.println(buf);
  int currPin = 0;
  
  Serial.print("question# ");
  Serial.println(sensorValue);
  while(currPin == 0){
    bool buzz1 = digitalRead(buzzer1);
    bool buzz2 = digitalRead(buzzer2);
    bool buzz3 = digitalRead(buzzer3);
    bool buzz4 = digitalRead(buzzer4);
    if(buzz1 == 0){
      currPin = 1;
      Serial.println("pin 1");
    }
    if(buzz2 == 0){
      currPin = 2;
      Serial.println("pin 2");
    }
    if(buzz3 == 0){
      currPin = 3;
      Serial.println("pin 3");
    }
    if(buzz4 == 0){
      currPin = 4;
      Serial.println("pin 4");
    }
  }
  bool res1 = 1;
  while(res1 == 1){
    res1 = digitalRead(reset1);
  }
  sensorValue++;
  delay(10);        // delay in between reads for stability
}
