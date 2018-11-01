#include "song.cpp"
#include <iostream>
#include <cstring>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

void print_double_spaced_cs(const char cstr[]) {
	for (int i = 0; i < strlen(cstr); i++) {
		cout << cstr[i];
		cout << " ";
	}
}

inline void append(const vector<int> & v1, vector<int> & v2) {
	v2 = v1;
}

int main() {

	//Variables
	char cstr[] = "good songs";
	vector<int> firstSet { 4, 5, 22, 42, 8 };
	vector<int> secondSet;
	print_double_spaced_cs(cstr);
	cout << "\nCurrent songs" << "\n\n";

	try {
		Song invalid("", "");
		cout << invalid;
		cout << endl;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}

	try {
		Song two("Song 2", "Blur");
		cout << two;
		cout << endl;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}

	try {
		Song good("Good Song");
		cout << good;
		cout << endl;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}

	Song temp("Temp", "Temp");
	cout << temp << endl;

	cout << "Replace this track with a new one:";
	try {
		cin >> temp;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}

	cout << temp << endl;

	//User variables
	Song user1;
	Song user2;

	cout << "Track numbers";
	append(firstSet, secondSet);
	for (int i : secondSet) {
		cout << i << " ";
	}
	cout << endl;

	//User input
	cout << "Add 2 new songs. Format :\nTitle\nArtist" << endl << "\nSong 1: "
			<< endl;
	try {
		cin >> user1;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}
	cout << endl << "Song 2: " << endl;
	try {
		cin >> user2;
	} catch (const SongError & se) {
		cout << se.getDescription() << endl;
	}
	cout << endl;

	//Checks if equal
	if (user1 == user2) {
		cout << "The two songs are the same so only one was added:" << endl;
		cout << user1;
	}

	else {

		if (user1 < user2) {
			cout << "The first song was greater" << endl;
			cout << user1;
			cout << endl;
			cout << user2;
		}

		else {
			cout << "The second song was greater" << endl;
			cout << user2;
			cout << endl;
			cout << user1;
		}
	}

	return 0;
}
