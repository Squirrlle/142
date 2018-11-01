#ifndef TERMINAL_H_
#define TERMINAL_H_
#include "Buffer.h"
#include <iostream>
using std::string;

class Terminal {
public:
	Terminal(){}
	void startNewSeason();
	void addPlayer();
	void searchPlayer();
	void editPlayer();
	void getStats();
	void deletePlayer();
	void produceFile();

private:
	Buffer buffer_ = Buffer();
};


#endif
