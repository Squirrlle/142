#include "Buffer.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::string;
using std::ifstream;
using std::find;
using std::endl;

void Buffer::display() const {
	int ix_stop_line_ = ix_top_line_ + window_height_;
	for (int i = ix_top_line_; i < ix_stop_line_; ++i) {
		if (i < v_lines_.size())
			cout << std::setw(6) << i + 1 << "  " << v_lines_[i];
		cout << '\n';
	}
}

bool Buffer::search(const string & s) {

	for (int i = ix_top_line_; i < v_lines_.size(); ++i) {

		if (v_lines_[i].find(s) != string::npos) {
			ix_top_line_ = i;
			return true;
		}

	}

	return false;

}

bool Buffer::open(const string & new_file_name) {
	ifstream file(new_file_name);
	if (!file)
		return false;

	v_lines_.clear();

	string line;
	while (getline(file, line))
		v_lines_.push_back(line);

	file_name_ = new_file_name;
	ix_top_line_ = 0;
	return true;
}
