/*
Author:  Ali Kerem Yıldız
ID : 150170013
*/
/*
you must compile : g++ -std=c++11 *.cpp
*/


#ifndef _TAXI_H_
#define _TAXI_H_

#define HOTEL_LONGITUDE 33.40819
#define HOTEL_LATITUDE 39.19001

using namespace std;

class Taxi
{
private:
    long double longitude;
    long double latitude;
    long double distance;

public:
    Taxi(long double longitude, long double latitude);
    long double get_longitude() { return longitude; };
    long double get_latitude() { return latitude; };
    long double get_distance() { return distance; };
    void set_longitude(long double longitude) { this->longitude = longitude; };
    void set_latitude(long double latitude) { this->latitude = latitude; };
    void set_distance(long double distance) { this->distance = distance; };
    void calculate_distance();
};
#endif