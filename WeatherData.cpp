#include "WeatherData.h"
#include <iostream>

using namespace std;

WeatherData::WeatherData() : temerature(0.0) , humidity(0.0) , pressure(0.0){}

void WeatherData::addObserver(Observer* obs){
    observers.push_back(obs);
}

void WeatherData::notifyObservers(){
    for (Observer* obs : observers){
        obs->update(temerature , humidity , pressure);
    }
}

void WeatherData::updateMeasurements(double temp , double hum , double press){
    temerature = temp ;
    humidity = hum ;
    pressure = press ;
    notifyObservers();
}