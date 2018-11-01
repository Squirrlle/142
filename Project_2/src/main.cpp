#include "Terminal.h"
#include "Buffer.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

	char operation;
	bool again = true;
	Terminal t = Terminal();

	do {

		cout << "What operation do you want to do?" << endl;
		cout << "start a new season (s), add a player (a), find a player (f)"
				<< "edit a player (e), get stats (g), delete a player (d)"
				<< "produce a file (p), quit (q)";
		cin >> operation;
		switch (operation) {
		case 's':
			t.startNewSeason();
			break;
		case 'a':
			t.addPlayer();
			break;
		case 'f':
			t.searchPlayer();
			break;
		case 'e':
			t.editPlayer();
			break;
		case 'g':
			t.getStats();
			break;
		case 'd':
			t.deletePlayer();
			break;
		case 'p':
			t.deletePlayer();
			break;
		default:
			again = false;
			break;
		}

	} while (again);

	return 0;
}
