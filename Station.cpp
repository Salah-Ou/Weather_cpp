#include "Station.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

WeatherStation::WeatherStation(WeatherData& wd) : weatherData(wd) {
    srand(time(nullptr));
}

void WeatherStation::Simulation(int iterations, int secondes) {
    for (int i = 0; i < iterations; ++i) {
        double temp = -5 + (rand() % 500) / 10.0;   // -5.0 à 44.9
        double hum = 30 + (rand() % 600) / 10.0;    // 30.0 à 90.0
        double press = 980 + (rand() % 700) / 10.0; // 980 à 1050

        weatherData.updateMeasurements(temp, hum, press);

        if (i < iterations - 1)
            this_thread::sleep_for(chrono::seconds(secondes));
    }
}