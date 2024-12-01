#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_RA8875.h>

// Define RA8875 pins
#define RA8875_CS 10  // Chip Select
#define RA8875_RST 9  // Reset

// Create the RA8875 object
Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RST);

void setup() {
  Serial.begin(9600);
  Serial.println("RA8875 Example!");

  // Initialize the RA8875 display
  if (!tft.begin(RA8875_800x480)) {  // Change resolution if necessary
    Serial.println("RA8875 not found ... check your wiring!");
    while (1);
  }
  Serial.println("RA8875 found!");

  // Set up the display
  tft.displayOn(true);    // Turn on the display
  tft.GPIOX(true);        // Enable TFT GPIO
  tft.PWM1config(true, RA8875_PWM_CLK_DIV1024);  // Configure backlight
  tft.PWM1out(255);       // Set backlight brightness (0-255)

  // Clear the screen
  tft.fillScreen(RA8875_BLACK);

  // Draw some shapes for testing
  tft.fillRect(50, 50, 200, 100, RA8875_RED);
  tft.fillCircle(400, 200, 50, RA8875_GREEN);
  tft.drawLine(0, 0, 800, 480, RA8875_WHITE);
  Serial.println("Shapes drawn!");

  // Touchscreen initialization
  tft.touchEnable(true);
  Serial.println("Touchscreen enabled.");
}

void loop() {
  // Check for touchscreen input
  if (tft.touched()) {
    //CalculatePH
    int sensorValue = analogRead(A0); // Read the analog value from Po
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    float pH = voltage * 3.5; // Example conversion factor, adjust based on calibration

    Serial.println("Screen touched!");
    Serial.print("ReadingPH: ");
    Serial.println(pH);
    uint16_t x, y;
    if (tft.touchRead(&x, &y)) {
      Serial.print("Touch coordinates: X = ");
      Serial.print(x);
      Serial.print(", Y = ");
      Serial.println(y);

      // Draw a small circle where the screen is touched
      tft.fillCircle(x, y, 10, RA8875_BLUE);
    }
  }
}

