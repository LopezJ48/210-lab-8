#include <iostream>
#include <map>
#include <string>
# include <random>

using namespace std;

void simulateInventory(map<string, int>& inventoryData, int days); //runs simulation of stock through days
void displayInventory(map<string, int>& inventoryData); //display stock of items in store

void simulateInventory(map<string, int>& inventoryData){
    for (int day = 0; day < days; ++day){
        cout << "Day" << day + 1 << endl; // will run through days with stock of items such as foods,drinks,goods
        for (auto& [category, stock] : inventoryData){
            int change = ()
        }
    }
}

int main(){
    
}