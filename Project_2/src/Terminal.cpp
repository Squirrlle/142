#include "Terminal.h"
#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void Terminal::searchPlayer() {
	string name;
	cout << "Enter a player name to search: ";
	getline(cin, name);

	buffer_.lookUp(name);

}

void Terminal::addPlayer() {
	Player p;

	cout << "Enter the player's name: ";
	getline(cin, p.name);

	cout << "Enter the player's birth year: ";
	cin >> p.yearOfBirth;

	cout << "Enter the player's section: U";
	cin >> p.category;

	cout << "Is the player registered : (y/n)";
	char check;
	cin >> check;

	if (check == 'y')
		p.registration = true;

	buffer_.addPlayer(p);
}

void Terminal::deletePlayer() {
	string name;
	cout << "Enter the player name you want deleted: ";
	getline(cin, name);
	buffer_.deletePlayer(name);
}

void Terminal::editPlayer() {
	string name;
	cout << "Enter the player name you want to edit: ";
	getline(cin, name);
	buffer_.deletePlayer(name);
	addPlayer();
}

void Terminal::produceFile() {
	int catagory;
	cout << "Enter the section you want " << endl;
	cout << "(-1-all, 0-U6, 1-U8, 2-U10, 3-U12, 4-U14, 5-U17): ";
	cin >> catagory;
	buffer_.produceFile(catagory);
}


void Terminal::getStats() {
	cout << buffer_.getStats();
}

void Terminal::startNewSeason() {
	int year;
	char confirm;
	string fileName;

	cout
			<< "Are you sure you want to start a new season, this will delete the current season and players: (y/n)";
	cin >> confirm;

	if (confirm == 'y') {
		buffer_.deleteAll();

		cout << "Enter the year of this season: ";
		cin >> year;
		try {
			if (cin.fail()) {
				throw "error";
			}
			else{
				buffer_.year = year;
				cout << "Enter the name of the file with this season's players on it; ";
				getline(cin, fileName);
				buffer_.readFile(fileName);
			}

		} catch (char* error) {
			cout << error << endl;
			break;
		}

	}

}
