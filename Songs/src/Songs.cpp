#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::getline;
using std::endl;
using std::getline;
using std::cin;

//creates a type Song that has a title and artist
class Song {

public:
	//Constructors
	Song(const string & t, const string & a) :
			title_(t), artist_(a) {
	}
	Song() :
			Song("Invalid", "Invalid") {
	}
	Song(string t) :
			Song(t, "Unknown") {
	}

	//Methods
	void print(ostream & out) const;
	void read(istream & in);
	bool is_equal(const Song & song2) const;
	void set_titie(string title);
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

inline void Song::print(ostream & out) const {
	out << title_ << endl;
	out << artist_ << endl;
}

inline void Song::set(string title, string artist) {
	title_ = title;
	artist_ = artist;
}

inline void Song::set_artist(string artist) {
	artist_ = artist;
}

inline void Song::set_titie(string title) {
	title_ = title;
}

inline void Song::read(istream & in) {
	getline(in, title_);
	getline(in, artist_);
}

inline bool Song::is_equal(const Song & song2) const {

	return (artist_ == song2.artist()) && (title_ == song2.title());
}

int main() {

	//Variables
	Song invalid;
	Song two("Song 2", "Blur");
	Song good("Good Song");

	//First output
	cout << "Current songs" << "\n\n";
	invalid.print(cout);
	cout << endl;
	two.print(cout);
	cout << endl;
	good.print(cout);
	cout << endl;

	//User variables
	Song user1;
	Song user2;

	//User input
	cout << "Add 2 new songs. Format :\nTitle\nArtist" << endl << "\nSong 1: "
			<< endl;
	user1.read(cin);
	cout << endl << "Song 2: " << endl;
	user2.read(cin);
	cout << endl;

	//Checks if equal
	if (user1.is_equal(user2)) {
		cout << "The two songs are the same so only one was added:" << endl;
		user1.print(cout);
	}

	else {
		user1.print(cout);
		cout << endl;
		user2.print(cout);
	}

	return 0;
}
