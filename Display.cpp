#include "Display.h"
#include <iostream>
#include <numeric>

#define ORANGE "\033[1;33m" 
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define GRAY "\033[1;30m"

using namespace std;

void DisplayConditions::update(double temperature, double humidity, double pressure) {
    cout << ORANGE << "\n\t\t--- Actual Conditions ---" << RESET << endl;
    if(temperature > 35)
        cout << GRAY << "\t\tTemperature : " << RED << temperature << " °C" << RESET << endl;
    else if(temperature < 25)
        cout << GRAY << "\t\tTemperature : " << BLUE << temperature << " °C" << RESET << endl;
    else if(temperature >= 25 && temperature <= 35)
        cout << GRAY << "\t\tTemperature : " << ORANGE << temperature << " °C" << RESET << endl;
    cout << GRAY << "\t\tHumidity    : " << RESET << humidity << " %" << endl;
    cout << GRAY << "\t\tpressure    : " << RESET << pressure << " hPa" << endl;
}

void DisplayStatistiques::update(double temperature, double humidity, double pressure) {
    temperatures.push_back(temperature);
    double sum = accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double avg = sum / temperatures.size();
    double max = *max_element(temperatures.begin(), temperatures.end());
    double min = *min_element(temperatures.begin(), temperatures.end());

    cout << GREEN << "\n\t\t--- Statistiques (temperature) ---" << RESET << endl;
    if(temperatures.size() > 1){
        cout << "\t\tAverage : " << ORANGE << avg << RESET << 
                " °C | Max : " << RED << max << RESET << 
                " °C | Min : " << BLUE << min << RESET << " °C" << endl;
    } 
    else{
        cout << "\t\tAverage : " << avg << " °C | Max : " << max << " °C | Min : " << min << " °C" << endl;
    }
}

void DisplayPrevisions::update(double temperature , double humidity, double pressure) {
    string prevision;
    temperatures.push_back(temperature);
    if (temperatures.size() < 2) {
        prevision = "stable";
    } else {
        if (temperatures.back() > 17 && temperatures.back() < 30)
            prevision = "beautiful weather";
        else if (temperatures.back() < 17)
            prevision = "rain possible";
        else if (temperatures.back() >= 30)
            prevision = "heat wave";
        else
            prevision = "stable";
    }
    cout << RED << "\n\t\t--- Simple Forecast ---" << endl;
    cout << GRAY << "\t\tTemperature Trend : " << RESET << prevision << endl;
}