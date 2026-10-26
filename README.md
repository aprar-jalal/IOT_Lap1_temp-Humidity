# ESP32 Temperature and Humidity Monitoring with ThingSpeak

## Project Description
This project uses an ESP32 microcontroller and a DHT22 sensor to monitor temperature and humidity. The ESP32 connects to Wi-Fi and uploads readings to a ThingSpeak channel approximately every 20 seconds. ThingSpeak displays the measurements on two publicly accessible time-series charts.

The project is simulated using **Wokwi**. An optional LED connected to GPIO 23 turns on when the temperature exceeds 30°C.

## Student Information
- **Full name:** [Enter your full name]
- **University ID:** 12324682

## Components and Software
- ESP32 development board (Wokwi simulation)
- DHT22 temperature and humidity sensor
- LED and current-limiting resistor (optional feature)
- Wokwi online simulator
- ThingSpeak IoT platform
- Arduino libraries: `WiFi.h`, `ThingSpeak.h`, `DHT.h`

## Wiring

| Component | ESP32 connection |
| --- | --- |
| DHT22 VCC | 3.3V |
| DHT22 GND | GND |
| DHT22 DATA | GPIO 15 |
| LED anode (+) | GPIO 23 |
| LED cathode (-) | GND through a current-limiting resistor |

The full circuit schematic is available in the Wokwi project below. The LED is an extra feature, not a requirement for the sensor upload.

## Project Links
- **Wokwi simulation:** https://wokwi.com/projects/478788292885916673
- **Public ThingSpeak channel:** https://thingspeak.com/channels/3549623
- **ThingSpeak Channel ID:** `3549623`

The ThingSpeak channel is configured for public viewing.

## ThingSpeak Fields
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)

## How It Works
1. The ESP32 connects to the simulated Wi-Fi network `Wokwi-GUEST`.
2. The DHT22 sensor measures temperature in Celsius and relative humidity as a percentage.
3. The readings are printed to the Serial Monitor along with the university ID.
4. The ESP32 sends temperature to ThingSpeak Field 1 and humidity to Field 2 using the ThingSpeak library.
5. The upload repeats approximately every 20 seconds.
6. The optional LED turns on if the measured temperature is greater than 30°C; otherwise it stays off.

## Observed Results
During testing, the Serial Monitor displayed:

```text
Status: Connected
Temperature: 18.20
Humidity: 40.00
Data Sent to ThingSpeak
University ID:12324682
```

ThingSpeak showed both temperature and humidity charts with multiple entries over time. The values may remain constant until the simulated DHT22 readings are changed.

## Screenshots
Add the required screenshots to the `screenshots/` folder before submission:

- `screenshots/wokwi-circuit.png` — ESP32 and DHT22 wiring diagram
- `screenshots/serial-monitor.png` — successful Wi-Fi connection, readings, and upload status
- `screenshots/thingspeak-charts.png` — public ThingSpeak channel showing both live charts and the timeline

## How to Run
1. Open the [Wokwi project](https://wokwi.com/projects/478788292885916673).
2. Ensure the `ThingSpeak` and `DHT sensor library` libraries are installed.
3. Set the ThingSpeak Channel ID and your **Write API Key** in the sketch. Keep the key private and do not commit it to a public GitHub repository.
4. Start the Wokwi simulation.
5. Check the Serial Monitor for temperature, humidity, and a successful upload message.
6. Open the [public ThingSpeak channel](https://thingspeak.com/channels/3549623) to see the charts update.

## Security Note
The ThingSpeak **Write API Key** is a secret credential. Do not publish a real key in `sketch.ino`, screenshots, or GitHub. Use a placeholder such as `YOUR_WRITE_API_KEY` in public source code, and replace it locally when running the simulation. Regenerate any key that was previously shared publicly.
