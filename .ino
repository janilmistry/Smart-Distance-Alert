#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define trigPin 9
#define echoPin 8
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define redPin 5
#define greenPin 6
#define bluePin 7
#define buzzerPin 10

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  float duration;
  float distance_cm;
  float distance_in;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance_cm = (duration / 2) / 29.1;
  distance_in = (duration / 2) / 73.914;

  display.setCursor(30, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Range Finder");

  display.setCursor(10, 20);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(distance_cm);
  display.setCursor(90, 20);
  display.setTextSize(2);
  display.println("cm");

  display.setCursor(10, 45);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println(distance_in);
  display.setCursor(90, 45);
  display.setTextSize(2);
  display.println("in");
  display.display();

  delay(500);
  display.clearDisplay();

  Serial.println(distance_cm);
  Serial.println(distance_in);

  if (distance_cm < 20) {
    setColor(255, 0, 0);
  } else if (distance_cm < 50) {
    setColor(0, 0, 255);
  } else if (distance_cm < 100) {
    setColor(0, 255, 0);
  } else {
    setColor(0, 0, 0);
  }

  if (distance_cm < 20) {
    tone(buzzerPin, 1000);
  } else if (distance_cm < 50) {
    for (int i = 0; i < 2; i++) {
      tone(buzzerPin, 1000);
      delay(500);
      noTone(buzzerPin);
      delay(500);
    }
  } else if (distance_cm < 90) {
    tone(buzzerPin, 1000);
    delay(1000);
    noTone(buzzerPin);
    delay(1000);
  } else {
    noTone(buzzerPin);
  }
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
