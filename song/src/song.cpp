#include "song.h"
using std::ostream;
using std::istream;
using std::getline;
using std::string;

inline ostream & operator<<(ostream & out, const Song & s) {
	out << s.title() << endl;
	out << s.artist() << endl;
	return out;
}

inline void Song::set(string title, string artist) {
	title_ = title;
	artist_ = artist;
}

inline istream & operator>>(istream & in, Song & s) {
	string a,t;
	getline(in, t);
	getline(in, a);
	if (t.empty() || a.empty()){
		throw SongError("Empty Argument\n");
	}
	else{
		s.title_ = t;
		s.artist_ = a;
	}
	return in;
}

inline bool operator==(const Song & s1, const Song & s2) {
	return (s1.artist_ == s2.artist_) && (s1.title_ == s2.title_);
}

inline bool operator<(const Song & s1, const Song & s2) {
	if (s1.title_ != s2.title_)
		return s1.title_ < s2.title_;
	else
		return s1.artist_ < s2.artist_;
}

inline void Song::set_artist(string artist) {
	artist_ = artist;
}

inline void Song::set_title(string title) {
	title_ = title;
}
