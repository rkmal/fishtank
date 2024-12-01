// TDS Sensor Example Code

const int TDS_PIN = A0; // TDS Sensor is connected to Analog Pin A0
const float VREF = 5.0; // Voltage Reference of the Arduino (usually 5.0V)
const float ADC_RESOLUTION = 1024.0; // 10-bit ADC resolution (2^10 = 1024)

// Calibration values
const float TDS_FACTOR = 0.5; // Conversion factor to get ppm
const float TEMPERATURE = 25.0; // Default water temperature in °C (adjust if needed)

void setup() {
  Serial.begin(9600); // Start the Serial Monitor
  Serial.println("TDS Meter Sensor Test");
}

void loop() {
  // Read the analog value from the TDS sensor
  int sensorValue = analogRead(TDS_PIN);

  // Convert the analog value to voltage
  float voltage = sensorValue * (VREF / ADC_RESOLUTION);

  // Calculate the TDS value (ppm)
  float tdsValue = (voltage / TDS_FACTOR) * 1000;

  // Compensate for temperature if necessary (basic example)
  tdsValue = tdsValue / (1.0 + 0.02 * (TEMPERATURE - 25.0));

  // Print the readings to the Serial Monitor
  Serial.print("Raw ADC Value: ");
  Serial.print(sensorValue);
  Serial.print("\tVoltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V\tTDS: ");
  Serial.print(tdsValue, 2);
  Serial.println(" ppm");

  delay(1000); // Wait for 1 second before the next reading
}

