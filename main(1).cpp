#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
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
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();



    return 0;
}
