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
        get<0>(pair.second) << ","
        << get<1>(pair.second) << ","
        << get<2>(pair.second) << endl;
    }
}
void addVillager(map<string, VillagerData>& villagerData){
    string name, species, catchphrase;
    int friendship;
    cout << "Villager name: " << endl;
    cin >> ws;
    getline(cin, name);
    cout << "Friendship level (0-10): " << endl;
    cin >> friendship;
    cout << "Villager species: " << endl;
    cin >> ws;
    getline(cin, species);
    cout << "Catchphrase: " << endl;
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
        cout << name << "friendship has gone up to" << friendship << endl;
        }else {
                cout << name <<" was not found." << endl;
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
        << get<0>(it->second) << ","
        << get<1>(it->second) << ","
        << get<2>(it->second) << endl;
       } 
        else{
            cout << name << "was not found.";
        }
}



int main() {
    // declarations
    map<string, VillagerData> villagerData;
    int choice;

    do{
        cout << "Please pick an option:"<< endl;
        cout << "1. Add Villager\n" << endl;
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search for Villager\n";
        cout << "6. Exit";
        cin >> choice;

        switch (choice){
            case 1:
            addVillager(villagerData);
            break;
            case 2:
            deleteVillager(villagerData);
            break;
            case 3:{
            string name;
            cout << "Pick a villager to increase friendship";
            cin >> ws;
            getline(cin,name);
            modifyFriendship(villagerData,name, 1);
            break;
            }
            case 4:{
            string name;
            cout << "Pick a villager to decrease friendship";
            cin >> ws;
            getline(cin,name);
            modifyFriendship(villagerData,name, -1);
            break;
            }
            case 5:
                searchVillager(villagerData);
                break;
            case 6:
                cout << "Exiting";
                break;
            default:
            cout << "invalid option try again.";
        }
        displayVillagers(villagerData);
    }
    while (choice !=6);
    return 0;
}