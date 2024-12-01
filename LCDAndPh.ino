{\rtf1\ansi\ansicpg1252\cocoartf2761
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red96\green126\blue3;\red255\green255\blue255;\red61\green73\blue78;
\red9\green74\blue76;\red131\green148\blue149;\red199\green63\blue5;\red52\green62\blue66;\red17\green134\blue139;
}
{\*\expandedcolortbl;;\cssrgb\c44706\c55686\c0;\cssrgb\c100000\c100000\c100000;\cssrgb\c30588\c35686\c38039;
\cssrgb\c0\c36078\c37255;\cssrgb\c58431\c64706\c65098;\cssrgb\c82745\c32941\c0;\cssrgb\c26275\c30980\c32941;\cssrgb\c0\c59216\c61569;
}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 #include\cf4 \strokec4  \cf5 \strokec5 <SPI.h>\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 #include\cf4 \strokec4  \cf5 \strokec5 <Adafruit_GFX.h>\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 #include\cf4 \strokec4  \cf5 \strokec5 <Adafruit_RA8875.h>\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6 // Define RA8875 pins\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf7 \strokec7 RA8875_CS\cf4 \strokec4  \cf5 \strokec5 10\cf6 \strokec6   // Chip Select\cf4 \cb1 \strokec4 \
\cf2 \cb3 \strokec2 #define\cf4 \strokec4  \cf7 \strokec7 RA8875_RST\cf4 \strokec4  \cf5 \strokec5 9\cf6 \strokec6   // Reset\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6 // Create the RA8875 object\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3 Adafruit_RA8875 tft = \cf7 \strokec7 Adafruit_RA8875\cf8 \strokec8 (\cf4 \strokec4 RA8875_CS, RA8875_RST\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf9 \cb3 \strokec9 void\cf4 \strokec4  \cf7 \strokec7 setup\cf8 \strokec8 ()\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 begin\cf8 \strokec8 (\cf5 \strokec5 9600\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "RA8875 Example!"\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Initialize the RA8875 display\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf2 \strokec2 if\cf4 \strokec4  \cf8 \strokec8 (\cf4 \strokec4 !\cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 begin\cf8 \strokec8 (\cf4 \strokec4 RA8875_800x480\cf8 \strokec8 ))\cf4 \strokec4  \cf8 \strokec8 \{\cf6 \strokec6   // Change resolution if necessary\cf4 \cb1 \strokec4 \
\cb3     \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "RA8875 not found ... check your wiring!"\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3     \cf2 \strokec2 while\cf4 \strokec4  \cf8 \strokec8 (\cf5 \strokec5 1\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf8 \strokec8 \}\cf4 \cb1 \strokec4 \
\cb3   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "RA8875 found!"\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Set up the display\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 displayOn\cf8 \strokec8 (\cf5 \strokec5 true\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6     // Turn on the display\cf4 \cb1 \strokec4 \
\cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 GPIOX\cf8 \strokec8 (\cf5 \strokec5 true\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6         // Enable TFT GPIO\cf4 \cb1 \strokec4 \
\cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 PWM1config\cf8 \strokec8 (\cf5 \strokec5 true\cf4 \strokec4 , RA8875_PWM_CLK_DIV1024\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6   // Configure backlight\cf4 \cb1 \strokec4 \
\cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 PWM1out\cf8 \strokec8 (\cf5 \strokec5 255\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6        // Set backlight brightness (0-255)\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Clear the screen\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 fillScreen\cf8 \strokec8 (\cf4 \strokec4 RA8875_BLACK\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Draw some shapes for testing\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 fillRect\cf8 \strokec8 (\cf5 \strokec5 50\cf4 \strokec4 , \cf5 \strokec5 50\cf4 \strokec4 , \cf5 \strokec5 200\cf4 \strokec4 , \cf5 \strokec5 100\cf4 \strokec4 , RA8875_RED\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 fillCircle\cf8 \strokec8 (\cf5 \strokec5 400\cf4 \strokec4 , \cf5 \strokec5 200\cf4 \strokec4 , \cf5 \strokec5 50\cf4 \strokec4 , RA8875_GREEN\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 drawLine\cf8 \strokec8 (\cf5 \strokec5 0\cf4 \strokec4 , \cf5 \strokec5 0\cf4 \strokec4 , \cf5 \strokec5 800\cf4 \strokec4 , \cf5 \strokec5 480\cf4 \strokec4 , RA8875_WHITE\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "Shapes drawn!"\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Touchscreen initialization\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 touchEnable\cf8 \strokec8 (\cf5 \strokec5 true\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3   \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "Touchscreen enabled."\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb3 \strokec8 \}\cf4 \cb1 \strokec4 \
\
\pard\pardeftab720\partightenfactor0
\cf9 \cb3 \strokec9 void\cf4 \strokec4  \cf7 \strokec7 loop\cf8 \strokec8 ()\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6   // Check for touchscreen input\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3   \cf2 \strokec2 if\cf4 \strokec4  \cf8 \strokec8 (\cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 touched\cf8 \strokec8 ())\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6     //CalculatePH\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3     \cf9 \strokec9 int\cf4 \strokec4  sensorValue = \cf7 \strokec7 analogRead\cf8 \strokec8 (\cf4 \strokec4 A0\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6  // Read the analog value from Po\cf4 \cb1 \strokec4 \
\cb3     \cf9 \strokec9 float\cf4 \strokec4  voltage = sensorValue * \cf8 \strokec8 (\cf5 \strokec5 5.0\cf4 \strokec4  / \cf5 \strokec5 1023.0\cf8 \strokec8 )\cf4 \strokec4 ;\cf6 \strokec6  // Convert to voltage\cf4 \cb1 \strokec4 \
\cb3     \cf9 \strokec9 float\cf4 \strokec4  pH = voltage * \cf5 \strokec5 3.5\cf4 \strokec4 ;\cf6 \strokec6  // Example conversion factor, adjust based on calibration\cf4 \cb1 \strokec4 \
\
\cb3     \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "Screen touched!"\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3     \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 "ReadingPH: "\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3     \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf4 \strokec4 pH\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3     \cf9 \strokec9 uint16_t\cf4 \strokec4  x, y;\cb1 \
\cb3     \cf2 \strokec2 if\cf4 \strokec4  \cf8 \strokec8 (\cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 touchRead\cf8 \strokec8 (\cf4 \strokec4 &x, &y\cf8 \strokec8 ))\cf4 \strokec4  \cf8 \strokec8 \{\cf4 \cb1 \strokec4 \
\cb3       \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 "Touch coordinates: X = "\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3       \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf4 \strokec4 x\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3       \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 ", Y = "\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3       \cf7 \strokec7 Serial\cf4 \strokec4 .\cf7 \strokec7 println\cf8 \strokec8 (\cf4 \strokec4 y\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb3 \strokec6       // Draw a small circle where the screen is touched\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf4 \cb3       \cf7 \strokec7 tft\cf4 \strokec4 .\cf7 \strokec7 fillCircle\cf8 \strokec8 (\cf4 \strokec4 x, y, \cf5 \strokec5 10\cf4 \strokec4 , RA8875_BLUE\cf8 \strokec8 )\cf4 \strokec4 ;\cb1 \
\cb3     \cf8 \strokec8 \}\cf4 \cb1 \strokec4 \
\cb3   \cf8 \strokec8 \}\cf4 \cb1 \strokec4 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb3 \strokec8 \}\cf4 \cb1 \strokec4 \
\
}