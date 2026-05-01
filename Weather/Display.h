#ifndef DISPLAY_H
#define DISPLAY_H
#include "WeatherData.h"
#include <vector>

using namespace std;

class DisplayConditions : public Observer {
public:
    void update(double temperature, double humidity, double pressure) override;
};

class DisplayStatistiques : public Observer {
private:
    vector<double> temperatures;
public:
    void update(double temperature, double humidity, double pressure) override;
};

class DisplayPrevisions : public Observer {
private:
    vector<double> temperatures;
public:
    void update(double temperature, double humidity, double pressure) override;

};

#endif