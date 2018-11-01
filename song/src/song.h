#ifndef SONG_H_
#define SONG_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::ostream;
using std::string;
using std::istream;
using std::cout;
using std::getline;
using std::endl;
using std::getline;
using std::cin;
using std::vector;

class SongError {
public:

	SongError(const string & d) :
			des(d) {
	}
	inline string getDescription() const {
		return des;
	}

private:
	string des;
};

//creates a type Song that has a title and artist
class Song {

	friend ostream & operator<<(ostream & out, const Song & s);
	friend bool operator==(const Song & s1, const Song & s2);
	friend bool operator<(const Song & s1, const Song & s2);
	friend istream & operator>>(istream & in, Song & s);

public:
	//Constructors
	Song(const string & t, const string & a) :
			title_(t), artist_(a) {
		if (title_ == "" || artist_ == "")
			throw SongError("Empty Argument\n");

	}
	Song() :
			Song("Invalid", "Invalid") {
	}
	Song(string t) :
			Song(t, "Unknown") {
	}

	//Methods
	void set_title(string title);
	void set_artist(string artist);
	void set(string title, string artist);

	//getters
	string title() const {
		return title_;
	}
	string artist() const {
		return artist_;
	}

private:
	string title_;
	string artist_;
};
#endif /* SONG_H_ */
