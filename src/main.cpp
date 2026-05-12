#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

// Hardware Serial 2 pins for ESP32
#define RXD2 16
#define TXD2 17

DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(115200);
  
  // Initialize HardwareSerial2 at 9600 baud
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  
  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(Serial2)) {
    Serial.println("Unable to begin. Check connections and SD card.");
    while(true);
  }

  Serial.println("DFPlayer Mini online.");
  myDFPlayer.volume(20); // 0-30
  myDFPlayer.play(1);    // Play 0001.mp3
}

void loop() {
  
  myDFPlayer.play(2); // Play 0002.mp3
  delay(13000); // Setfor how long the first track will play before the next one starts
  myDFPlayer.play(1); // Play 0001.mp3
  delay(8000); // Set for how long the second track will play before the next one starts
}
