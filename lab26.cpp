#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

using VillagerData = tuple<int, string, string>;

void displayVillagers(const map<string, VillagerData>& villagerData){
    cout << "Villager details: " << endl;
    for (const auto& pair : villagerData){
        cout << pair.first <<
        get<0>(pair.second) <<
        get<1>(pair.second) <<
        get<2>(pair.second) << endl;
    }
}

void addVillager(map<string, VillagerData>& villagerData){
    string name, species, catchphrase;
    int friendship;
    cout << "Villager name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Friendship level (0-10): ";
    cin >> friendship;
    cout << "Villager species: ";
    cin >> ws;
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    villagerData[name] = make_tuple(friendship, species, catchphrase);
    cout << name << "has been added.";
}

void deleteVillager(map<string, VillagerData>& villagerData){
    string name;
    cout << "Pick a villager to delete: " << endl;
    cin >> ws;
    if (villagerData.erase(name)){
        cout << name << "has been deleted.";
        }
        else {
            cout << name << "was not found.";
        }
}

void modifyFriendship(map<string, VillagerData>& villagerData,const string& name, int change){
    auto it = villagerData.find(name);
    if (it != villagerData.end()){
        int& friendship = get<0>(it->second);
        friendship = max(0, min(10, friendship + change));
        cout << name << "friendship has gone up to" << friendship << endl;{

        }else {
                cout << name <<" was not found." << endl;
            }
        }
    }
}

void searchVillager(map<string, VillagerData>& villagerData){
    string name;
    cout << "Enter villager name";
    cin >> ws;
    getline(cin, name);
    auto it = villagerData.find(name);
    if (it != villagerData.end()) {
        cout << name << "found: "
        << get<0>(it->second)
        << get<1>(it->second)
        << get<2>(it->second) << endl;
       } 
        else{
            cout << name << "was not found.";
        }
}



int main() {
    // declarations
    map<string, vector<string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}