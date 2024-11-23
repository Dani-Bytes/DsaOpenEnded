#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class Player {
private:
    string name;
    int odiMatches;
    int t20Matches;
    int testMatches;

public:
    Player* next;
    Player* prev;

    Player(string name, int odi, int t20, int test) {
        this->name = name;
        this->odiMatches = odi;
        this->t20Matches = t20;
        this->testMatches = test;
        this->next = nullptr;
        this->prev = nullptr;
    }

    void display() {
        cout << "Player: " << name << endl;
        cout << "ODI Matches: " << odiMatches << endl;
        cout << "T20 Matches: " << t20Matches << endl;
        cout << "Test Matches: " << testMatches << endl;
    }


    void saveToFile() {
        ofstream file(name + ".txt");
        if (file.is_open()) {
            file << "Player: " << name << endl;
            file << "ODI Matches: " << odiMatches << endl;
            file << "T20 Matches: " << t20Matches << endl;
            file << "Test Matches: " << testMatches << endl;
            file.close();
        }
        else {
            cout << "Error: Unable to open file to save data." << endl;
        }
    }


    string getName() { return name; }
    int getOdiMatches() { return odiMatches; }
    int getT20Matches() { return t20Matches; }
    int getTestMatches() { return testMatches; }


    void setOdiMatches(int odi) { odiMatches = odi; }
    void setT20Matches(int t20) { t20Matches = t20; }
    void setTestMatches(int test) { testMatches = test; }
};

