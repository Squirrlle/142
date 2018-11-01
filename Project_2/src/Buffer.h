#ifndef PROJECT2_BUFFER_H
#define PROJECT2_BUFFER_H
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <string>
using std::string;
using std::to_string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <sstream>
using std::stringstream;

enum categories {U6,U8,U10,U12,U14,U17};

struct Player {
    string name;
    int yearOfBirth;
    int category;
    bool registration;

    Player() : name("INVALID"){}
    Player(string n, int y, int c, bool r) : name(n), yearOfBirth(y), category(c), registration(r){}

    string print() const{
        stringstream toPrint("");
        toPrint << name << "\n" << to_string(yearOfBirth) << "\n" << to_string(category) << "\n" << (registration ? "Registered" : "Not Registered");
        return (string) toPrint.str();
    }

};

class Buffer {

    friend class Terminal;

public:
    Buffer() = default;
    Buffer(const string & fileName);
    void readFile(const string & fname);
    void addPlayer(const Player & newPlayer);
    Player & lookUp(const string & name) const;
    void deletePlayer(const string & name);
    void produceFile(int category) const;
    void deleteAll();
    string getStats() const;
private:
    int year;
    string fileName;
    vector<int,map<string,Player>> playerMap;
    ifstream inFile;
    ofstream outFile;

};


#endif
