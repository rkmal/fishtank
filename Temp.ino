{\rtf1\ansi\ansicpg1252\cocoartf2761
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red61\green73\blue78;\red96\green126\blue3;\red255\green255\blue255;
\red9\green74\blue76;\red131\green148\blue149;\red199\green63\blue5;\red52\green62\blue66;\red17\green134\blue139;
}
{\*\expandedcolortbl;;\cssrgb\c30588\c35686\c38039;\cssrgb\c44706\c55686\c0;\cssrgb\c100000\c100000\c100000;
\cssrgb\c0\c36078\c37255;\cssrgb\c58431\c64706\c65098;\cssrgb\c82745\c32941\c0;\cssrgb\c26275\c30980\c32941;\cssrgb\c0\c59216\c61569;
}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf2 \expnd0\expndtw0\kerning0
\outl0\strokewidth0 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 #include\cf2 \strokec2  \cf5 \strokec5 <OneWire.h>\cf2 \cb1 \strokec2 \
\cf3 \cb4 \strokec3 #include\cf2 \strokec2  \cf5 \strokec5 <DallasTemperature.h>\cf2 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6 // Data wire is conntec to the Arduino digital pin 4\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf3 \cb4 \strokec3 #define\cf2 \strokec2  \cf7 \strokec7 ONE_WIRE_BUS\cf2 \strokec2  \cf5 \strokec5 4\cf2 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6 // Setup a oneWire instance to communicate with any OneWire devices\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4 OneWire \cf7 \strokec7 oneWire\cf8 \strokec8 (\cf2 \strokec2 ONE_WIRE_BUS\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6 // Pass our oneWire reference to Dallas Temperature sensor \cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4 DallasTemperature \cf7 \strokec7 sensors\cf8 \strokec8 (\cf2 \strokec2 &\cf8 \strokec8 oneWire)\cf2 \strokec2 ;\cb1 \
\
\pard\pardeftab720\partightenfactor0
\cf9 \cb4 \strokec9 void\cf2 \strokec2  \cf7 \strokec7 setup\cf8 \strokec8 (\cf9 \strokec9 void\cf8 \strokec8 )\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb4 \strokec8 \{\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6   // Start serial communication for debugging purposes\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 begin\cf8 \strokec8 (\cf5 \strokec5 9600\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6   // Start up the library\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4   \cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 begin\cf8 \strokec8 ()\cf2 \strokec2 ;\cb1 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb4 \strokec8 \}\cf2 \cb1 \strokec2 \
\
\pard\pardeftab720\partightenfactor0
\cf9 \cb4 \strokec9 void\cf2 \strokec2  \cf7 \strokec7 loop\cf8 \strokec8 (\cf9 \strokec9 void\cf8 \strokec8 )\{\cf2 \strokec2  \cb1 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6   // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4   \cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 requestTemperatures\cf8 \strokec8 ()\cf2 \strokec2 ; \cb1 \
\cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 "Device Count: "\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 println\cf8 \strokec8 (\cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 getDeviceCount\cf8 \strokec8 ())\cf2 \strokec2 ;\cb1 \
\cb4   \cb1 \
\cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 "Celsius temperature: "\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\pard\pardeftab720\partightenfactor0
\cf6 \cb4 \strokec6   // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf2 \cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 print\cf8 \strokec8 (\cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 getTempCByIndex\cf8 \strokec8 (\cf5 \strokec5 0\cf8 \strokec8 ))\cf2 \strokec2 ; \cb1 \
\cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 print\cf8 \strokec8 (\cf5 \strokec5 " - Fahrenheit temperature: "\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\cb4   \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 println\cf8 \strokec8 (\cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 getTempFByIndex\cf8 \strokec8 (\cf5 \strokec5 0\cf8 \strokec8 ))\cf2 \strokec2 ;\cb1 \
\cb4   \cf7 \strokec7 delay\cf8 \strokec8 (\cf5 \strokec5 1000\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\cb4   \cf9 \strokec9 float\cf2 \strokec2  tempC = \cf7 \strokec7 sensors\cf2 \strokec2 .\cf7 \strokec7 getTempCByIndex\cf8 \strokec8 (\cf5 \strokec5 0\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\cb4   \cf3 \strokec3 if\cf2 \strokec2  \cf8 \strokec8 (\cf2 \strokec2 tempC == DEVICE_DISCONNECTED_C\cf8 \strokec8 )\cf2 \strokec2  \cf8 \strokec8 \{\cf2 \cb1 \strokec2 \
\cb4     \cf7 \strokec7 Serial\cf2 \strokec2 .\cf7 \strokec7 println\cf8 \strokec8 (\cf5 \strokec5 "ERROR: Could not read temperature data"\cf8 \strokec8 )\cf2 \strokec2 ;\cb1 \
\cb4   \cf8 \strokec8 \}\cf2 \cb1 \strokec2 \
\pard\pardeftab720\partightenfactor0
\cf8 \cb4 \strokec8 \}\cf2 \cb1 \strokec2 \
\
\
}