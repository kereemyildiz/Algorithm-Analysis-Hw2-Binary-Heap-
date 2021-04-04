/*
Author:  Ali Kerem Yıldız
ID : 150170013
*/
/*
you must compile : g++ -std=c++11 *.cpp
*/


#ifndef _TAXI_
#define _TAXI_
#define HOTEL_LONGITUDE 33.40819
#define HOTEL_LATITUDE 39.19001
#include "Taxi.h"
#include <math.h>
Taxi::Taxi(long double longitude, long double latitude)
{
    this->longitude = longitude;
    this->latitude = latitude;
    calculate_distance();
}

void Taxi::calculate_distance()
{
    long double x = this->longitude - HOTEL_LONGITUDE;
    long double y = this->latitude - HOTEL_LATITUDE;

    set_distance(sqrt(pow(x, 2) + pow(y, 2)));
}
#endif