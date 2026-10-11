Built my 3rd embedded systems project: a Smart Parking Slot Detector 🅿️

The problem: manually checking for free parking slots wastes time — the same basic sensing principle used in real smart-parking systems at malls and campuses.
## Components
- Arduino / ESP32 (simulated in Wokwi)
- HC-SR04 Ultrasonic Sensor
- SSD1306 OLED Display (I2C)
- Red + Green LED

## Circuit Diagram
![Circuit Diagram](https://github.com/jahnaviroutu/parking-slot-monitoring-system/blob/799fe992ee1e2742e1ffce5bf83d7a26e39b456f/Parking%20slot%20monitoring%20sysytem-circuit%20diagram.png)

What I built: an ultrasonic sensor (HC-SR04) measures distance in real time. If something’s within 100cm, the slot is marked OCCUPIED; otherwise FREE — shown live on an OLED display with LED indicators.

## How it works:
1. Based on the distance of the car the output will be decided.
2. **Decide the status** — If the calculated distance is less than 100 cm, the code assumes something is parked in the slot (**OCCUPIED** and red led glows) .
 
  ![working if vehicle is present](https://github.com/jahnaviroutu/parking-slot-monitoring-system/blob/5ba2cfebf32af5dbd8a730343464023a9e1392e4/working%20picture-1.png)

3.   Otherwise, the slot is considered **FREE** and green led glows.

 ![working if vehicle is not present](https://github.com/jahnaviroutu/parking-slot-monitoring-system/blob/3e68a509e5fe487d4e1b0b2f0838b8f817b89d54/working%20picture-2.png)

4. **Show the result** — The status is printed on the OLED display using the Adafruit_GFX/SSD1306 libraries, and the matching LED (red for occupied, green for free) is switched on.

5. **Repeat continuously** — This entire cycle runs every 500 milliseconds inside `loop()`, so the display and LEDs update in near real-time as objects move in and out of range.

New things I learned this project:
→ Ultrasonic distance sensing (TRIG/ECHO pins, timing sound waves to calculate distance)
→ I2C communication — how a display can talk to a microcontroller using just 2 wires (SDA/SCL)
→ Debugging a real issue: my OLED stayed completely blank even though the code ran fine — turned out I forgot to set a text color, so the display was drawing invisible text the whole time. A good reminder that “no error” doesn’t always mean “working correctly.”

## Try it live:
— [Click here to simulate —](https://wokwi.com/projects/477577904547926017)

#EmbeddedSystems #Arduino #ESP32 #ECE #IoT
