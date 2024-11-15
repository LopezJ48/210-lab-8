#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE_DEQUE = 2;


void displayQueue(deque<Car>& queue){
    if(queue.empty()){
        cout << "queue is empty\n";
    }
    else{
        cout << "queue: \n";
        for (const auto& car : queue)
        car.print();
    }
}