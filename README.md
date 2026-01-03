ESP32 Web Server Security Audit (Attack & Defense)
📌 Objective

To host an HTTP web server on an ESP32 microcontroller and evaluate its behavior under high request load, followed by implementation of defensive mechanisms to maintain system stability.

⚙️ System Overview

ESP32 acts as a lightweight HTTP server

Clients on the same local network send requests

Excessive requests simulate a DDoS-like condition

🌐 Web Server Functionality

Runs on port 80

Responds to HTTP GET requests

Logs incoming requests via Serial Monitor

⚔️ Attack Simulation

A controlled request flood is generated from a single authorized device on the same network using rapid browser refreshes or scripted HTTP requests.

Purpose:

Observe server degradation

Test ESP32 resource limits

🛡️ Defense Mechanisms

Rate Limiting using time-based request filtering

HTTP 429 Too Many Requests for excessive traffic

Server remains responsive under load

🧪 Results
Scenario	Observation
Normal traffic	Stable responses
Flood without defense	Lag / instability
Flood with defense	Requests rejected
System stability	Maintained
📂 Project Structure
src/main.cpp
platformio.ini
README.md

✅ Conclusion

This experiment demonstrates how simple defensive techniques significantly improve the resilience of embedded web servers against excessive traffic conditions.

This project is intended strictly for educational use in a controlled lab environment.