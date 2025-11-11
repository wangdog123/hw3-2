/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/digital/Button/
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int led = 3;    // the number of the LED pin
int mode = 0;
bool buttonpressed = false;
float blinkTimer = 0;
bool blinkOn = true;

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(led, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(4800);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW && buttonpressed == false) {
    // turn LED on:
    buttonpressed = true;
    mode += 1;
    delay(50);
  }
  if(buttonState == HIGH && buttonpressed == true)
    buttonpressed = false;  
  if (mode >3 )
    mode = 0;
  switch(mode)
  {
    case 0:
      digitalWrite(led, HIGH);
      Serial.print("const");
      break;
    case 1:
      blink(2,led);
      break;
    case 2:
      blink(1,led);
      break;
    case 3:
      blink(0.5,led); 
      break;
  }
  Serial.print("mode:");
  Serial.println(mode);
}
void blink(float interval, int led)
{
  unsigned long currentTime = millis();
  if(currentTime - blinkTimer > interval*1000){
    blinkOn = !blinkOn;
    blinkTimer = currentTime;
  }
  if(blinkOn)
  {
    digitalWrite(led, HIGH);
  }
  else
    digitalWrite(led, LOW);
}
