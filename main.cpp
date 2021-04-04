/*
Author:  Ali Kerem Yıldız
ID : 150170013
*/
/*
you must compile : g++ -std=c++11 *.cpp
*/


#include <iostream>
#include <fstream> // for file handling
#include <cstdlib> // for srand
#include <time.h>  // for time selection for randomizing numbers and calculating running time
#include "Taxi.h"
#include "Minheap.h"
using namespace std;

int main(int argc, char **argv)
{

    int m = atoi(argv[1]);
    double p = atof(argv[2]);
    ifstream file;
    file.open("locations.txt");

    if (!file)
    {
        cerr << "File cannot be opened!";
        exit(1);
    }

    string line;

    getline(file, line); // header line

    MinHeap *PriorityQueue = new MinHeap();

    int count_update = 0;
    int count_addition = 0;
    int count_update_empty_heap = 0; // counting to attemp number of updating empty heap
    srand(time(0));
    vector<long double> extractedTaxiDistances; // this vector will store distances of extracted taxis for printing them
    bool flag = false;                          // flag is for trying to update empty heap condition
    clock_t t;
    t = clock();
    for (int i = 1; i < m + 1; i++)
    {

        if (i % 100 == 0) // every 100 operation
        {
            extractedTaxiDistances.push_back(PriorityQueue->getNearestTaxi().get_distance()); // distance of nearest taxi stores on extractedTaxiDistances vector
            PriorityQueue->extractNearestTaxi();                                              // nearest taxi extracted from heap
        }
        else
        {
            bool isUpdate = rand() % 100 < 100 * p;
            if (isUpdate) // update operation
            {
                if (PriorityQueue->getSize() == 0)
                {
                    count_update_empty_heap++;
                    flag = true; // trying to update empty heap
                }
                else
                {
                    count_update++;
                    int i = rand() % PriorityQueue->getSize(); // index of taxi that going to update distance (decreased by 0.01)
                    PriorityQueue->updateTaxiLocation(i);
                }
            }
            else // addition a new taxi
            {
                count_addition++;
                string str_longitude;
                getline(file, str_longitude, ' ');
                string str_latitude;
                getline(file, str_latitude, '\n');
                long double longitude = stold(str_longitude.c_str());
                long double latitude = stold(str_latitude.c_str());
                Taxi newTaxi = Taxi(longitude, latitude);
                PriorityQueue->insertTaxi(newTaxi);
            }
        }
    }
    t = clock() - t;

    for (int i = 0; i < extractedTaxiDistances.size(); i++)
    {
        cout << "A new taxi has been called. It's distance is: " << extractedTaxiDistances[i] << endl;
    }
    cout << "Total number of addition operation: " << count_addition << endl;
    cout << "Total number of update operation: " << count_update << endl;
    cout << "Total running time is: " << ((float)t) * 1000 / CLOCKS_PER_SEC << " miliseconds" << endl;
    //cout << "Total number of update empty heap attempts: " << count_update_empty_heap << endl;

    return 0;
}