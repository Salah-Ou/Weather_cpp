#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
    public : 
        virtual void update(double temperature , double humidity , double pressure) = 0;
        virtual ~Observer(){}
};

class WeatherData {
    private : 
        double temerature , humidity , pressure ;
        vector<Observer*> observers ;

    public : 
        WeatherData();
        void addObserver(Observer* obs);
        void notifyObservers();
        void updateMeasurements(double temp , double hum , double press);
};

#endif