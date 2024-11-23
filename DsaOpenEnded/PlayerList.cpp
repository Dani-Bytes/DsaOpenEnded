#include "PlayerList.h"
int getMenuChoice() {
    int choice;
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Player" << endl;
        cout << "2. Remove Player" << endl;
        cout << "3. Update Player" << endl;
        cout << "4. Display Players" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, please enter a number between 1 and 5." << endl;
        }
        else {
            break;
        }
    }
    return choice;
}

void getPlayerInfo(string& name, int& odi, int& t20, int& test) {
    cin.ignore();
    cout << "Enter player name: ";
    getline(cin, name);
    cout << "Enter number of ODI matches: ";
    cin >> odi;
    cout << "Enter number of T20 matches: ";
    cin >> t20;
    cout << "Enter number of Test matches: ";
    cin >> test;
}

int main() {
    PlayerList playerList;
    int choice;

    while (true) {
        choice = getMenuChoice();

        switch (choice) {
        case 1: {

            string name;
            int odi, t20, test;
            getPlayerInfo(name, odi, t20, test);
            playerList.addPlayer(name, odi, t20, test);
            break;
        }
        case 2: {

            string name;
            cout << "Enter the player name to remove: ";
            cin.ignore();
            getline(cin, name);
            playerList.removePlayer(name);
            break;
        }
        case 3: {

            string name;
            int odi, t20, test;
            cout << "Enter the player name to update: ";
            cin.ignore();
            getline(cin, name);
            getPlayerInfo(name, odi, t20, test);
            playerList.updatePlayer(name, odi, t20, test);
            break;
        }
        case 4: {

            playerList.displayPlayers();
            break;
        }
        case 5: {

            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

