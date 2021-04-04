/*
Author:  Ali Kerem Yıldız
ID : 150170013
*/
/*
you must compile : g++ -std=c++11 *.cpp
*/

#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include "Taxi.h"
#include <vector>
class MinHeap
{
private:
    int _size{};
    vector<Taxi> TaxiVect = {Taxi(0, 0)};

    int p(int i) { return i >> 1; };       //  p = floor(i/2).  gives parent index, bitwise shift right operaiton means divide it by 2.
    int l(int i) { return i << 1; };       //  l = 2i           gives left child index, bitwise shift left operaiton means multiply it by 2.
    int r(int i) { return (i << 1) + 1; }; // r = 2i+1    bitwise left and +1 gives right child index.

public:
    int getSize() { return _size; };
    bool isEmpty() const { return _size == 0; };
    Taxi getNearestTaxi() const { return TaxiVect[1]; }; // return nearest taxi to hotel
    void insertTaxi(Taxi &newTaxi);                      // insert new taxi to heap
    void shiftUp(int i);
    Taxi extractNearestTaxi();
    void heapify(int i);
    void print();
    void updateTaxiLocation(int i);
};
#endif