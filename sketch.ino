#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define TRIG_PIN 14
#define ECHO_PIN 13
#define GREEN_LED 2
#define RED_LED 4

const int OCCUPIED_DISTANCE = 100; // cm — anything closer than this means a car is parked

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);   

}

void loop() {
  long distance = getDistanceCM();
  Serial.println("Distance: " + String(distance) + " cm");

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(20, 30);

  if (distance > 0 && distance < OCCUPIED_DISTANCE) {
    display.println("OCCUPIED");
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    display.println("FREE");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }

  display.display();
  delay(500);
}

// Sends an ultrasonic pulse and measures how long it takes to bounce back
long getDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH); // time in microseconds for echo to return
  long distance = duration * 0.034 / 2;    // convert time to distance in cm (speed of sound formula)
  return distance;
}
