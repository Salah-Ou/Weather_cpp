#include "WeatherData.h"
#include "Display.h"
#include "Station.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string Time() {
    time_t now = time(NULL);
    tm *local = localtime(&now);
    return asctime(local);
}

int main() {
    clear_screen();
    string current_time = Time();
    cout << "\n\n\t\t\t\033[1;37m Current Time's : \033[1;36m" << current_time << "\033[1;37m";
    WeatherData WeatherData;

    DisplayConditions display1;
    DisplayStatistiques display2;
    DisplayPrevisions display3;

    WeatherData.addObserver(&display1);
    WeatherData.addObserver(&display2);
    WeatherData.addObserver(&display3);

    WeatherStation station(WeatherData);
    station.Simulation(3, 3);  

    return 0;
}