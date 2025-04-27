# Cahyo Lampu 💡⚙️

**Cahyo Lampu** is a simple automatic lamp project that turns on or dims based on the surrounding light intensity. This project uses a light sensor (LDR) and an LED, and is illustrated with a miniature cardboard house.

## Features
- Turns on in the dark and dims in bright light automatically
- Uses an LDR (Light Dependent Resistor) sensor
- Visual representation with a cardboard house
- Includes code explanation and logic simulation

## Basic Components
- LDR (analog light sensor)
- LED
- Resistors
- [Arduino UNO/NANO/MEGA](https://www.arduino.cc/) (or similar microcontroller)
- Jumper wires
- Liquid Crystal I2C (Optional)
- Cardboard (for the miniature house)

## How It Works
The LDR sensor reads the light intensity and adjusts the LED output:
- When it's dark (high LDR value), the LED lights up brightly
- When it's bright (low LDR value), the LED dims or turns off

## Sample Code
```cpp
int ldrPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int brightness = map(ldrValue, 0, 1023, 255, 0); 
  analogWrite(ledPin, brightness);
  delay(200);
}
```


To see a more complete and interactive project demo, visit this project's online prototype on [Wokwi](https://wokwi.com/projects/415244886912403457).


--


Made with ❤️ in "Java Island"


MIT © [Raul Maulidhino](https://rauldev.my.id)
