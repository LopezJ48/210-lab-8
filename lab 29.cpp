#include <iostream>
#include <map>
#include <string>
# include <random>
// will include file handleing and data structure headers
using namespace std;

//define file to be loaded 
    // open file 
    // go over each level of items in stock from stock file
    // close file 

void simulateInventory(map<string, int>& inventoryData, int days){ // will show inventory changes throughout the days
    for (int day = 0; day < days; ++day){
        cout << "Day" << day + 1 << endl; // will run through days with stock of items such as foods,drinks,goods
        for (auto& [category, stock] : inventoryData){
            int change = (rand() % 11) - 10;
            stock += change;
            if (stock < 0) stock = 0;
            cout << category << "Instore: " << stock << endl; // show updated stock after changes
        }
        cout << endl;
    }
}
// add different functions to add events such as stealing or popular items
    //randomly decide to increase or decrease stock by a huge number
    // ensure stock hits 0 
    // doesnt go below zero
    // print new data for stock

// add a function to handle the events of stealing or the poplarity 
    // will choose an event to apply 
    
void displayInventory(map<string, int>& inventoryData){
    cout << "Inventory check " << endl;
    for(const auto& [category, stock] : inventoryData){
        cout << category << "Instore: " << stock << endl;
    }
}
// Initialize a map to store information of categories for drinks, foods, goods

int main(){
int days = 5;
    map<string, int> inventoryData = {
        {"Food", 50},
        {"drinks", 80},
        {"goods", 6}
    };
    displayInventory(inventoryData);
    simulateInventory(inventoryData, days);
    return 0;

}