#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;
const int MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double* prices;
public:
//Contstructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) + 3;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double) 100;
        }
    }

    Chair(int l, double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // Setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }

    ~Chair() {
        delete[] prices;
    }
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);
    Chair* chairPtr = new Chair;
    chairPtr->print();

    double livingChairPrices[SIZE] = {692.50, 694.34, 545.55}; 
    Chair* livingChair = new Chair(3, livingChairPrices); 
    livingChair->print();
    delete livingChair;
  
    Chair* collection = new Chair[SIZE]; 
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }
    return 0;
}
