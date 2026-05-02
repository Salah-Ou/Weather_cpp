# 🌦️ Weather Station Simulator — C++

A C++ simulation of a real-time weather monitoring system built around the **Observer design pattern**. The station generates randomized weather data and pushes live updates to multiple independent display modules.

---

## 📐 Architecture — Observer Pattern

The project is a textbook implementation of the **Observer (Publish/Subscribe)** pattern:

- **Subject** → `WeatherData`: holds current measurements and maintains a list of observers. Notifies all of them whenever data changes.
- **Observer** → `Observer` (abstract base class): defines the `update(temperature, humidity, pressure)` interface.
- **Concrete Observers** → the three display classes, each reacting to updates in their own way.

```
WeatherStation
     │
     ▼
WeatherData ──── notifyObservers() ────► DisplayConditions
  (Subject)                          ►  DisplayStatistiques
                                     ►  DisplayPrevisions
```

---

## 📁 Project Structure

```
.
├── main.cpp            # Entry point — wires everything together
├── WeatherData.h/cpp   # Subject + Observer base class
├── Display.h/cpp       # Three concrete observer displays
├── Station.h/cpp       # Simulation engine (random data generator)
```

---

## 🧩 Components

### `WeatherData` — The Subject
Stores the three core measurements (`temperature`, `humidity`, `pressure`) and owns the observer list. Calling `updateMeasurements()` sets new values and immediately triggers `notifyObservers()`.

### `WeatherStation` — The Simulator
Drives the simulation loop. `Simulation(iterations, seconds)` generates random readings within realistic ranges and feeds them to `WeatherData` with a configurable pause between each cycle:
- Temperature: **−5.0 °C → 44.9 °C**
- Humidity: **30.0% → 90.0%**
- Pressure: **980 hPa → 1050 hPa**

### `DisplayConditions` — Current Conditions
Prints live temperature, humidity, and pressure. Temperature is **color-coded** in the terminal:
| Range | Color |
|:---:|:---:|
| < 25 °C | 🔵 Blue (cool) |
| 25–35 °C | 🟡 Orange (warm) |
| > 35 °C | 🔴 Red (hot) |

### `DisplayStatistiques` — Statistics
Accumulates all temperature readings across the session and displays running **average**, **maximum**, and **minimum** after each update.

### `DisplayPrevisions` — Simple Forecast
Produces a plain-language forecast based on the current temperature:
| Temperature | Forecast |
|:---:|:---:|
| < 17 °C | Rain possible |
| 17–30 °C | Beautiful weather |
| ≥ 30 °C | Heat wave |

---

## 🚀 Build & Run

### Requirements
- C++11 or later
- A standard C++ compiler (`g++`, `clang++`, MSVC)

### Compile
```bash
g++ -std=c++11 main.cpp WeatherData.cpp Display.cpp Station.cpp -o weather_station
```

### Run
```bash
./weather_station
```

The default simulation runs **3 iterations** with a **3-second** pause between each one (configurable in `main.cpp`):
```cpp
station.Simulation(3, 3);  // (iterations, seconds between updates)
```

---

## 🖥️ Sample Output

```
         Current Time's : Fri May  1 10:42:00 2026

        --- Actual Conditions ---
        Temperature : 38.4 °C        ← displayed in red
        Humidity    : 67.2 %
        Pressure    : 1013.5 hPa

        --- Statistiques (temperature) ---
        Average : 31.6 °C | Max : 38.4 °C | Min : 24.8 °C

        --- Simple Forecast ---
        Temperature Trend : heat wave
```

---

## 🔧 Extending the Project

Adding a new display is straightforward thanks to the Observer pattern — no existing code needs to change:

1. Create a class that inherits from `Observer`.
2. Implement the `update(double temperature, double humidity, double pressure)` method.
3. Register an instance with `WeatherData::addObserver()` in `main.cpp`.

---

## 📝 Notes

- `temerature` in `WeatherData.h/cpp` is a known typo (missing an `p`) — safe to rename to `temperature` across both files.
- The forecast in `DisplayPrevisions` currently ignores humidity and pressure; these could be incorporated for a more accurate prediction model.
- `using namespace std;` is used in header files — considered bad practice in larger projects; moving it to `.cpp` files only would be a clean improvement.

<video controls width="800">
  <source src="2025-10-13 16.58.10.mp4" type="video/mp4">
</video>

  [Click here to watch the demo] (https://drive.google.com/file/d/1P9PnpIx7vrSUR77MCwp3Akl2hWxTgwG8/view?usp=sharing)
