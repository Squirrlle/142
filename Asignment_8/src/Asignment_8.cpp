#include <iostream>
#include<map>
#include <fstream>
using std::map;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::getline;

struct Book {

	string author;
	int yearPublished;

};

typedef map<string, Book> BookMap;

void read_books(BookMap m_books,const string file_name){

	string title, authors;
	int year;
	ifstream in (file_name);

	while(getline(in, title)){
		Book b;
		getline(in, authors);
		in >> year;
		b.author = authors;
		b.yearPublished = year;
		m_books[title] = b;
	}
}

void print_recent(BookMap m_books, int year){

	for(auto itr = m_books.begin(); itr != m_books.end(); ++itr){
		if(itr->second.yearPublished >= year){
			cout << itr->first;
		}
	}

}

template<typename T, class List>
void print(List ls, T n) {
	if (n > ls.size) {
		for (T o : ls) {
			cout << o << endl;
		}
	} else {

		for (auto itr = ls.begin(); itr < ls.begin() + n; itr++) {
			cout << itr << endl;
		}

	}
}
;

int main() {
	return 0;
}