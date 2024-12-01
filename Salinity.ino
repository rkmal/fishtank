{\rtf1\ansi\ansicpg1252\cocoartf2761
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red131\green148\blue149;\red255\green255\blue255;\red61\green73\blue78;
\red17\green134\blue139;\red9\green74\blue76;\red199\green63\blue5;\red52\green62\blue66;}
{\*\expandedcolortbl;;\cssrgb\c58431\c64706\c65098;\cssrgb\c100000\c100000\c100000;\cssrgb\c30588\c35686\c38039;
\cssrgb\c0\c59216\c61569;\cssrgb\c0\c36078\c37255;\cssrgb\c82745\c32941\c0;\cssrgb\c26275\c30980\c32941;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 // TDS Sensor Example Code\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf5 \cb3 \strokec5 const\cf4 \strokec4  \cf5 \strokec5 int\cf4 \strokec4  TDS_PIN = A0;\cf2 \strokec2  // TDS Sensor is connected to Analog Pin A0\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 const\cf4 \strokec4  \cf5 \strokec5 float\cf4 \strokec4  VREF = \cf6 \strokec6 5.0\cf4 \strokec4 ;\cf2 \strokec2  // Voltage Reference of the Arduino (usually 5.0V)\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 const\cf4 \strokec4  \cf5 \strokec5 float\cf4 \strokec4  ADC_RESOLUTION = \cf6 \strokec6 1024.0\cf4 \strokec4 ;\cf2 \strokec2  // 10-bit ADC resolution (2^10 = 1024)\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2 // Calibration values\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf5 \cb3 \strokec5 const\cf4 \strokec4  \cf5 \strokec5 float\cf4 \strokec4  TDS_FACTOR = \cf6 \strokec6 0.5\cf4 \strokec4 ;\cf2 \strokec2  // Conversion factor to get ppm\cf4 \cb1 \strokec4 \
\cf5 \cb3 \strokec5 const\cf4 \strokec4  \cf5 \strokec5 float\cf4 \strokec4  TEMPERATURE = \cf6 \strokec6 25.0\cf4 \strokec4 ;\cf2 \strokec2  // Default water temperature in \'b0C (adjust if needed)\cf4 \cb1 \strokec4 \
\
\cf5 \cb3 \strokec5 void\cf4 \strokec4  \cf7 \strokec7 setup\cf8 \strokec8 ()\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 begin\cf8 \strokec8 (\cf6 \strokec6 9600\cf8 \strokec8 )\cf4 \strokec4 ;\cf2 \strokec2  // Start the Serial Monitor\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf6 \strokec6 "TDS Meter Sensor Test"\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb3 \strokec8 \}\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf5 \cb3 \strokec5 void\cf4 \strokec4  \cf7 \strokec7 loop\cf8 \strokec8 ()\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2   // Read the analog value from the TDS sensor\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   \cf5 \strokec5 int\cf4 \strokec4  sensorValue = \cf7 \strokec7 analogRead\cf8 \strokec8 (\cf4 \strokec4 TDS_PIN\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2   // Convert the analog value to voltage\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   \cf5 \strokec5 float\cf4 \strokec4  voltage = sensorValue * \cf8 \strokec8 (\cf4 \strokec4 VREF / ADC_RESOLUTION\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2   // Calculate the TDS value (ppm)\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   \cf5 \strokec5 float\cf4 \strokec4  tdsValue = \cf8 \strokec8 (\cf4 \strokec4 voltage / TDS_FACTOR\cf8 \strokec8 )\cf4 \strokec4  * \cf6 \strokec6 1000\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2   // Compensate for temperature if necessary (basic example)\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   tdsValue = tdsValue / \cf8 \strokec8 (\cf6 \strokec6 1.0\cf4 \strokec4  + \cf6 \strokec6 0.02\cf4 \strokec4  * \cf8 \strokec8 (\cf4 \strokec4 TEMPERATURE - \cf6 \strokec6 25.0\cf8 \strokec8 ))\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2   // Print the readings to the Serial Monitor\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf6 \strokec6 "Raw ADC Value: "\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf4 \strokec4 sensorValue\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf6 \strokec6 "\\tVoltage: "\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf4 \strokec4 voltage, \cf6 \strokec6 2\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf6 \strokec6 " V\\tTDS: "\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf4 \strokec4 tdsValue, \cf6 \strokec6 2\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\cf4 \cb3 \strokec4   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf6 \strokec6 " ppm"\cf8 \strokec8 )\cf4 \strokec4 ;\cf4 \cb1 \strokec4 \
\
\cf4 \cb3 \strokec4   \cf7 \strokec7 delay\cf8 \strokec8 (\cf6 \strokec6 1000\cf8 \strokec8 )\cf4 \strokec4 ;\cf2 \strokec2  // Wait for 1 second before the next reading\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb3 \strokec8 \}\cf4 \cb1 \strokec4 \
\
}