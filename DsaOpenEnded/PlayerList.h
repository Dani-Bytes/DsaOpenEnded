#pragma once
#include"Player.h"
class PlayerList {
private:
    Player* head;

public:
    PlayerList() : head(nullptr) {}


    void addPlayer(string name, int odi, int t20, int test) {
        Player* newPlayer = new Player(name, odi, t20, test);
        newPlayer->saveToFile();

        if (head == nullptr) {
            head = newPlayer;
        }
        else {
            Player* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newPlayer;
            newPlayer->prev = temp;
        }
        cout << "Player added successfully!" << endl;
    }


    void removePlayer(string name) {
        Player* temp = head;
        while (temp != nullptr) {
            if (temp->getName() == name) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                if (temp == head) {
                    head = temp->next;
                }
                delete temp;
                cout << "Player " << name << " removed successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Player not found." << endl;
    }


    void updatePlayer(string name, int odi, int t20, int test) {
        Player* temp = head;
        while (temp != nullptr) {
            if (temp->getName() == name) {
                temp->setOdiMatches(odi);
                temp->setT20Matches(t20);
                temp->setTestMatches(test);
                temp->saveToFile();
                cout << "Player " << name << " updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Player not found." << endl;
    }


    void displayPlayers() {
        Player* temp = head;
        if (temp == nullptr) {
            cout << "No players found." << endl;
            return;
        }
        while (temp != nullptr) {
            temp->display();
            cout << "------------------------------" << endl;
            temp = temp->next;
        }
    }


    ~PlayerList() {
        Player* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

