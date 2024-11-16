#include <ctime>
#include <deque>
#include <iostream>
#include <iomanip>
#include "Car-1.h"

using namespace std;

const int INITIAL_SIZE_QUEUE = 2;
const int PAY_CHANCE = 55;
const int JOIN_CHANCE = 45;


void displayQueue(deque<Car>& queue){
    if(queue.empty()){
        cout << "queue is empty\n";
    }
    else{
        cout << endl << "queue: \n";
        for (auto& car : queue)
        car.print();
    }
}

int main(){
    srand(static_cast<int>(time(nullptr)));
    deque<Car> queue;

    for(int i = 0;i < INITIAL_SIZE_QUEUE; i++){
        queue.push_back(Car());
    }
    cout << "Starting Queue: ";
    displayQueue(queue);

    int time = 1;
    while (!queue.empty()){
        int action = rand() % 100;
        if (action < PAY_CHANCE){
            cout << "Car paid: ";
            queue.front().print();
            queue.pop_front();
        }
        else (action > JOIN_CHANCE){
            Car newCar;
            queue.push_back(newCar);
            cout << "joined lane: ";
            newCar.print();
        }
        displayQueue(queue);
    }
}