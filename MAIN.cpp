#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string [], string []);
void display_trip(set<Goat> trip);

void add_goat(set<Goat> &trip, string names[], string colors[]){
    string name = names[rand() % SZ_NAMES];
    string color = colors[rand() % SZ_COLORS];
    int age = rand() % MAX_AGE;
    Goat new_goat(name, age, color);

    auto result = trip.insert(new_goat);
    if (result.second){
        cout << "added " << name << "("<<age << color << ")" << endl;
    } else {
        cout << "Goat" << name << "already is in" << endl;
    }
}

void delete_goat(set<Goat>&trip){
    if(trip.empty()){
        cout << "No goats to delete" << endl;
        return;
    }
    int choice = select_goat(trip);
    if (choice < 0 || choice >= trip.size()){
        cout << "invalid choice!" << endl;
    return;
    }
 auto it = trip.begin();
 advance(it, choice);
 trip.erase(it);
 cout << "Deleted goat" << endl;
}

void display_trip(set<Goat> trip){
    int index = 1;
    for(const auto &goat : trip){
        cout << index++ << goat.get_name()
        << goat.get_age() << goat.get_color() << endl;
    }
}

int select_goat(set<Goat>trip){
    display_trip(trip);
    int choice;
    cout << "pick a goat to delete";
    cin >> choice;
    return choice - 1;
}

int main_menu(){
    int choice;
    cout<< "** GOAT MANAGER 3001 **" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] delete a goat" << endl;
    cout << "[3] list goats" << endl;
    cout << "[4] Add a goat" << endl;
    cout << "Choice ->" << endl;
    cin >> choice;
    while ( choice < 1 || choice > 4){
        cout << "Invalid option please pick 1,2,3,4 ";
        cin >> choice;
    }
    return choice;
}

int main() {
    srand(time(0));
    string names[SZ_NAMES], colors[SZ_COLORS];
    set<Goat>trip;
    
    while(true) {
        int choice = main_menu();

        switch(choice){
            case 1:
            add_goat(trip,names,colors);
            break;
            case 2:
            delete_goat(trip);
            break;
            case 3:
            display_trip(trip);
            break;
            case 4:
            cout << "Quit" << endl;
            return 0;
        }
    }
}