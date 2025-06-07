# NXC-Library
Diese Biblioheken erleichtern die Verwendung von speziellen Sensoren mit dem Lego Mindstorms NXT.    
> [!IMPORTANT]
> Damit die Bibliotheken vom Präprozessor gefunden werden können, müssen die Header-Dateien im gleichen Ordner wie das NXC-File abgelegt werden, sie müssen sich also im Projektordner befinden.

## HiTechnic IR Seeker
> Der Sensor hat sieben interne IR-Sensoren, sodass sowohl die Signalstärke, als auch die Richtung des Signals bestimmt werden kann.

Import der Bibliothek:
```C
#include "RocciIR.h"
```
Initialisierung des Sensors an **Port 1 (S1)** des NXT als I2C-Device:
```C
SetSensorLowspeed(S1);
```
Auslesen des internen Sensors mit der höchsten Signalstärke über `index = 0`:
```C
int ballrichtung = SensorIR(S1, 0);
```
Auslesen der Signalstärke eines einzelnen internen Sensor über `index = 1...7`:
```C
int sensor_index = 1; // 1-7
int ballrichtung = SensorIR(S1, sensor_index);
```

## HiTechnic Compass Sensor
> Der Sensor gibt die Ausrichtung von 0-359 Grad zurück.

Import der Bibliothek:
```C
#include "RocciCompass.h"
```
Initialisierung des Sensors an **Port 1 (S1)** des NXT als I2C-Device:
```C
SetSensorLowspeed(S1);
```
Auslesen des Kompasswertes:
```C
int ausrichtung_roh = Sensor(S1);
```
Auslesen des Kompasswertes mit vorheriger Kalibrierung:
```C
// ...
int kompass_offset = Sensor(S1);
// ...
while (true) {
// ...
int ausrichtung = CompassDirection(Sensor(S1), kompass_offset);
// ...
}
```
