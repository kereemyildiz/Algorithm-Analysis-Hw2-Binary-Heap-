/*
Author:  Ali Kerem Yıldız
ID : 150170013
*/
/*
you must compile : g++ -std=c++11 *.cpp
*/

#ifndef _MINHEAP_
#define _MINHEAP_
#include <iostream>
#include "Minheap.h"
using namespace std;

void MinHeap::insertTaxi(Taxi &newTaxi)
{
    if (_size + 1 >= TaxiVect.size())
    {
        TaxiVect.push_back(Taxi(0, 0)); // randomly added taxi from hotel to last element, it is like placeholder, we reassign it after with proper value
    }
    TaxiVect[++_size] = newTaxi;
    shiftUp(_size);
    return;
}

void MinHeap::shiftUp(int i) 
{
    if (i == 1 || i > _size) //unshiftable conditions : if index i has root, it has not a parent, so we cannot check and size control
    {
        return;
    }
    if (TaxiVect[i].get_distance() < TaxiVect[p(i)].get_distance()) // parent has larger value
    {
        swap(TaxiVect[p(i)], TaxiVect[i]); //since parent more far than child to hotel, they are swapepd
    }
    shiftUp(p(i));
}
void MinHeap::heapify(int i)
{
    int smallest = i; // at first place assume that parent is smaller than both child
    if (i > _size)    // checking index i is in bound
    {
        return;
    }
    if (l(i) <= _size && TaxiVect[l(i)].get_distance() < TaxiVect[smallest].get_distance())
    {
        smallest = l(i);
    }
    if (r(i) <= _size && TaxiVect[r(i)].get_distance() < TaxiVect[smallest].get_distance())
    {
        smallest = r(i);
    }
    if (smallest != i)
    {
        swap(TaxiVect[i], TaxiVect[smallest]);
        heapify(smallest);
    }
    return;
}

Taxi MinHeap::extractNearestTaxi()
{
    if (_size < 1)
    {
        throw "No element to extract";
    }
    Taxi nearestTaxi = TaxiVect[1];
    swap(TaxiVect[1], TaxiVect[_size--]);
    heapify(1);
    return nearestTaxi;
}
void MinHeap::print()
{
    for (int iter = 0; iter < TaxiVect.size(); iter++)
    {
        cout << TaxiVect[iter].get_longitude() << " , " << TaxiVect[iter].get_latitude() << " , " << TaxiVect[iter].get_distance() << endl;
    }
}
void MinHeap::updateTaxiLocation(int i)
{

    long double currentDistance = TaxiVect[i].get_distance(); // get distance of taxi update taxi
    TaxiVect[i].set_distance(currentDistance - 0.01); // 0.01 subtracted from distance of taxi

    while (i > 1 && TaxiVect[p(i)].get_distance() > TaxiVect[i].get_distance()) // if parent is greater than recently updated child's value we make a swap operation
    {
        swap(TaxiVect[i], TaxiVect[p(i)]);
        i = p(i);
    }
    
}
#endif