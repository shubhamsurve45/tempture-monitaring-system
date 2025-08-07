COMPANY : CODETECH IT SOLUTION

NAME : SHUBHAM DATTATRAY SURVE

INTERN ID : CT08DH2161

DOMAIN : EMBEDDED SYSTEM

DURATION : 8 WEEKS

MENTOR : NEELA SANTOSH KUMAR

This system continuously monitors the surrounding temperature using a temperature sensor (likely LM35 or DHT11) and displays the real-time value on an I2C LCD display. An additional soil moisture sensor is also used to show environmental humidity or soil conditions. A buzzer is included to alert the user when a certain temperature or moisture level is exceeded.

🔩 Components Used:

1. Arduino Uno – The main microcontroller board.
2. I2C 16x2 LCD Display – To show temperature and/or moisture level.
3. LM35 Temperature Sensor – Measures ambient temperature (or DHT11 in some cases).
4. Soil Moisture Sensor – Reads soil moisture data.
5. Buzzer – Alerts when a threshold is reached.
6. 10k Potentiometer – Controls contrast of LCD.
7. Breadboard and Jumper Wires – For circuit connections.
8. USB Cable / Adapter – For powering the Arduino.


⚙️ Working Principle:

The temperature sensor reads the real-time temperature.
Analog signal from the sensor is sent to Arduino (A0 or other analog pin).
Arduino processes this signal and sends output to I2C LCD, displaying the temperature.
The soil moisture sensor checks the water content in the soil and gives output to another analog pin.
If temperature or soil dryness goes beyond a certain limit, buzzer gives a warning.
The LCD gives live feedback.

⚡ Applications:

Used in greenhouse monitoring
Home gardening and smart agriculture
Lab/industrial temperature monitoring
Educational projects for IoT/Embedded Systems learners

🧪 Output (Expected Result):

LCD displays:
Temp: 30°C
Moisture: Dry/Wet
Buzzer beeps if:
Temperature > threshold (e.g. 35°C)
Moisture too low


Real-time monitoring on LCD

Optional: You can log data to serial monitor as well
