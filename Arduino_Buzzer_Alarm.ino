#include <pitches.h>

#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Pins for the LCD screen

const int trigPin = 3; // Module and components pin initializations and declarations to avoid magic numbers.
const int echoPin = 2;
int greenLed = 5;
int redLed = 4;
int buzzerPin = 13;
float duration, distance;
int frequencyTone = 440; // In hertz
void setup() {
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  lcd.begin(16, 2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.print("Distance: ");

}

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  objectClose(distance); // Turn on an LED if an object is detectd to be within range.

  
  Serial.println(distance);
  lcd.setCursor(10, 0); // Prints to the tenth column of the first row.
  lcd.print(distance);
}


void objectClose(float distance)
{
  
 if(distance > 30)
 {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed,LOW);
 }
 else if(distance <= 30)
 {
  while(1) // Continuously sound of the buzzer until reset or powered down.
  { 
    tone(buzzerPin, frequencyTone, 100);
    digitalWrite(greenLed,LOW);
    digitalWrite(redLed, HIGH);
  }
 }
   delay(100);
}
