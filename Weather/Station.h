#ifndef STATION_H
#define STATION_H
#include "WeatherData.h"

class WeatherStation {
    private : 
        WeatherData& weatherData;
    public :
        WeatherStation(WeatherData& wd);
        void Simulation(int iterations , int secondes);
};

#endif