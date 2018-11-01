#include "Buffer.h"

Buffer::Buffer(const string & fn) : fileName(fn) {
    inFile.open(fileName);
    outFile.open(fileName);
}


void Buffer::addPlayer(const Player &newPlayer) {
    int age = year - newPlayer.yearOfBirth;
    int category = U17;
    for(int i = U6; i < U17; ++i) {
        if(age < i) {
            category = i-1;
            break;
        }
    }
    playerMap[category][newPlayer.name] = newPlayer;
    outFile << newPlayer.print() << endl;
}

Player & Buffer::lookUp(const string &name) const {
    for(int i = U6; i <= U17; ++i) {
        if(playerMap[i][name].name != "INVALID") {
            return playerMap[i][name];
        }
    }
}

void Buffer::deletePlayer(const string &name) {
    Player p = lookUp(name);
    auto mp = playerMap[p.category];
    mp[name] = Player();
    outFile.open(fileName);
    for(int i = U6; i <= U17; ++i) {
        for(Player pl : playerMap[i]) {
            outFile << pl.print() << endl;
        }
    }
}

void Buffer::produceFile(int category) const {
    stringstream fname("");
    fname << category << ".txt";
    ofstream theFile(fname.str());
    if(category != -1) {
        for (Player p : playerMap[category]) {
            theFile << p.print();
        }
        return;
    }
    for(int i = U6; i <= U17; ++i) {
        for(Player p : playerMap[i]) {
            theFile << p.print();
        }
    }
}

string Buffer::getStats() const {
    //Total / Registered / Total / Registered / ...
    stringstream toReturn;
    for(int i = U6; i <= U17; ++i) {
        int reg = 0;
        int total = 0;
        for(Player p : playerMap[i]) {
            ++total;
            if(p.registration) ++reg;
        }
        toReturn << "Total for category " << i << ": " << total << endl;
        toReturn << "Registered for category " << i << ": " << reg << endl;
    }
    return toReturn.str();
}

void Buffer::readFile(const string &fname) {
    fileName = fname;
    inFile.open(fileName);
    string name;
    int YOB;
    int category;
    bool reg;
    if(!inFile) throw "Shit's fukked";
    while(inFile >> name) {
        inFile >> YOB >> category;
        string temp;
        inFile >> temp;
        reg = temp == "Registered";
        playerMap[category][name] = new Player(name,YOB,category,reg);
    }
}

void Buffer::deleteAll() {
    outFile.open(fileName);
    for(int i = U6; i <= U17; ++i) {
        playerMap[i].clear();
    }
}
