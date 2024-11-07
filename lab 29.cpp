#include <iostream>
#include <map>
#include <string>
# include <random>

using namespace std;

void simulateInventory(map<string, int>& inventoryData){
    for (int day = 0; day < days; ++day){
        cout << "Day" << day + 1 << endl; // will run through days with stock of items such as foods,drinks,goods
        for (auto& [category, stock] : inventoryData){
            int change = (rand() % 11) - 10;
            stock += change;
            if (stock < 0) stock = 0;
            cout << category << "Instore: " << stock << endl;
        }
        cout << endl;
    }
}

void displayInventory(map<string, int>& inventoryData){
    cout << "Inventory check " << endl;
    for(const auto& [category, stock] : inventoryData){
        cout << category << "Instore: " << stock << endl;
    }
}

int main(){
int days = 5

}