# 🌱 Agro Smart Fertilizer System

<p align="center">
  <img src="https://img.shields.io/badge/Platform-ESP32-blue?style=for-the-badge&logo=espressif" />
  <img src="https://img.shields.io/badge/IDE-Arduino-teal?style=for-the-badge&logo=arduino" />
  <img src="https://img.shields.io/badge/IoT-Blynk-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" />
</p>

<p align="center">
  An ESP32-based IoT solution for intelligent, automated fertilizer management in agriculture — featuring real-time sensor monitoring, threshold-based dispensing, and remote control via the Blynk IoT platform.
</p>

---

## 📌 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [System Architecture](#-system-architecture)
- [Hardware Components](#-hardware-components)
- [Circuit Diagram](#-circuit-diagram)
- [Software Requirements](#-software-requirements)
- [Getting Started](#-getting-started)
- [Working Principle](#-working-principle)
- [Project Images](#-project-images)
- [Applications](#-applications)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

---

## 🔍 Overview

The **Agro Smart Fertilizer System** is an embedded IoT project that automates the fertilizer dispensing process in agricultural fields. Built around the **ESP32 microcontroller**, the system continuously monitors environmental and soil conditions using sensors and makes intelligent decisions about fertilizer application — without manual intervention.

Data is pushed to the **Blynk IoT cloud platform**, enabling farmers and researchers to remotely track field conditions and system status in real time.

> ⚡ Designed to reduce fertilizer wastage, improve crop yield, and make precision agriculture accessible.

---

## ✨ Features

| Feature | Description |
|---|---|
| 🌡️ Real-Time Monitoring | Continuously reads environmental sensor data |
| 🤖 Automated Dispensing | Relay-controlled fertilizer pump activated on thresholds |
| 📡 Remote Access | Live dashboard on Blynk IoT mobile/web app |
| 📶 Wireless Connectivity | Wi-Fi enabled via ESP32 onboard module |
| ⚙️ Threshold-Based Logic | Configurable decision conditions in firmware |
| 🔋 Efficient Operation | Optimized sensor polling to reduce power consumption |

---

## 🏗️ System Architecture
<img width="1448" height="840" alt="image" src="https://github.com/user-attachments/assets/db68bd31-0dac-43b4-8bdf-523105be43d2" />


**Data Flow:**
`Sensor Input → ESP32 Processing → Threshold Check → Relay Trigger → Blynk Upload`

---

## 🔧 Hardware Components

| # | Component | Purpose | Quantity |
|---|-----------|---------|----------|
| 1 | **ESP32 Dev Board** | Main microcontroller & Wi-Fi module | 1 |
| 2 | **Soil Moisture Sensor** | Measures soil water content | 1 |
| 3 | **DHT11 / DHT22** | Temperature & Humidity monitoring | 1 |
| 4 | **Relay Module (5V)** | Controls fertilizer pump on/off | 1 |
| 5 | **Mini Water/Fertilizer Pump** | Dispenses liquid fertilizer | 1 |
| 6 | **Jumper Wires** | Circuit connections | As needed |
| 7 | **Breadboard / PCB** | Circuit mounting | 1 |
| 8 | **5V Power Supply / USB** | System power | 1 |

---

## 🗺️ Circuit Diagram

> 📁 Full circuit diagram available in [`images/circuit_diagram.png`](images/circuit_diagram.png)

**Quick Pin Reference (ESP32):**

| ESP32 Pin | Connected To |
|-----------|-------------|
| GPIO 34 | Soil Moisture Sensor (Analog Out) |
| GPIO 4 | DHT Sensor (Data Pin) |
| GPIO 26 | Relay Module (IN) |
| 3.3V / GND | Sensor VCC / GND |
| VIN / GND | Relay VCC / GND |

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.x or v2.x)
- **ESP32 Board Package** — Add via Board Manager:
  ```
  https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
  ```
- **Blynk IoT Library** — Install via Library Manager
- **DHT Sensor Library** — by Adafruit
- **Blynk Account** — [blynk.cloud](https://blynk.cloud) (free tier available)

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/JeraldJaxon/Agro-Smart-Fertilizer-System.git
cd Agro-Smart-Fertilizer-System
```

### 2. Configure Blynk Credentials

Open `code/AgroSmartFertilizer.ino` and update these lines:

```cpp
#define BLYNK_TEMPLATE_ID     "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME   "AgroSmartFertilizer"
#define BLYNK_AUTH_TOKEN      "YOUR_AUTH_TOKEN"

char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";
```

### 3. Set Threshold Values (Optional)

```cpp
#define MOISTURE_THRESHOLD   40    // % — below this, pump activates
#define TEMP_MAX_THRESHOLD   35    // °C — alert if exceeded
```

### 4. Upload to ESP32

- Select board: `ESP32 Dev Module`
- Select correct COM port
- Click **Upload**

### 5. Monitor via Blynk

Open the **Blynk IoT** app, add your device using the Auth Token, and configure widgets for real-time data.

---

## ⚙️ Working Principle

```
1. 🌱 Sensors continuously measure soil moisture, temperature, and humidity
2. 📥 ESP32 reads analog/digital sensor values every few seconds
3. 🔍 Firmware compares readings against predefined thresholds
4. 💧 If conditions require fertilizer → Relay activates → Pump dispenses
5. ☁️  All sensor values are pushed to Blynk cloud via Wi-Fi
6. 📱 User monitors field status remotely on Blynk dashboard
7. 🔄 Cycle repeats at defined intervals
```

---

## 📸 Project Images

### Hardware Setup
![Hardware Setup]
<img width="1064" height="636" alt="Screenshot 2026-06-05 093637" src="https://github.com/user-attachments/assets/8d1d6425-f1f8-419f-9459-8ac88c92d42c" />

### Circuit Diagram
![Circuit Diagram](images/circuit_diagram.png)

### Blynk Dashboard
![Blynk Dashboard]
<img width="244" height="350" alt="Screenshot 2026-06-05 094145" src="https://github.com/user-attachments/assets/70ab2600-7b18-4d2b-9c1a-6596cfca10a7" />

---

## 🌾 Applications

- 🌿 **Smart Agriculture** — Automated nutrient delivery for crops
- 🏡 **Greenhouse Management** — Controlled environment farming
- 🎯 **Precision Farming** — Sensor-driven fertilizer optimization
- 🏫 **Educational Projects** — IoT + Embedded systems learning
- 🔬 **Research Prototyping** — Agriculture automation research

---

## 🔮 Future Improvements

- [ ] **ML-Based Prediction** — Forecast fertilizer needs using historical data
- [ ] **Multi-Zone Control** — Independent dispensing for multiple field sections
- [ ] **Solar Power Integration** — Off-grid sustainable operation
- [ ] **Custom Mobile App** — React Native / Flutter app with analytics
- [ ] **Cloud Data Analytics** — Dashboards with trend analysis and alerts
- [ ] **NPK Sensor Integration** — Measure specific nutrient levels

---

## 🛠️ Technologies Used

![ESP32](https://img.shields.io/badge/ESP32-Espressif-red?style=flat-square)
![C++](https://img.shields.io/badge/Language-Embedded_C-blue?style=flat-square)
![Arduino](https://img.shields.io/badge/IDE-Arduino-teal?style=flat-square)
![Blynk](https://img.shields.io/badge/IoT-Blynk_Cloud-green?style=flat-square)
![WiFi](https://img.shields.io/badge/Connectivity-Wi--Fi-orange?style=flat-square)

---

## 📁 Repository Structure

```
Agro-Smart-Fertilizer-System/
│
├── README.md                        ← You are here
├── LICENSE
│
├── code/
│   └── AgroSmartFertilizer.ino      ← Main Arduino sketch
│
├── images/
│   ├── hardware_setup.jpg
│   ├── circuit_diagram.png
│   └── dashboard.jpg
│
└── docs/
    └── Project_Report.pdf
```

---

## 👨‍💻 Author

**Jerald Jaxon**

B.Tech — Electronics & Communication Engineering

*Embedded Systems & IoT Enthusiast*

<p>
  <a href="https://github.com/JeraldJaxon">
    <img src="https://img.shields.io/badge/GitHub-JeraldJaxon-black?style=flat-square&logo=github" />
  </a>
  &nbsp;
  <a href="https://www.linkedin.com/in/jeraldjaxon">
    <img src="https://img.shields.io/badge/LinkedIn-Connect-blue?style=flat-square&logo=linkedin" />
  </a>
</p>

---

<p align="center">
  ⭐ If you found this project useful, please consider giving it a star!<br/>
  Made with ❤️ for Smart Agriculture
</p>
