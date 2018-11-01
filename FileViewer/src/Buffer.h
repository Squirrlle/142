#include <vector>
#include <string>
using std::string;
using std::vector;

class Buffer {

public:
	void display() const;
	const string & file_name() const {
		return file_name_;
	}
	void move_to_next_page();
	void move_to_previous_page();
	bool open(const string & file_name);
	bool search(const string & s);
	void set_window_height(int h) {
		window_height_ = h;
	}

private:
	vector<string> v_lines_;
	int ix_top_line_ = 0;
	string file_name_;
	int window_height_;
};

inline void Buffer::move_to_next_page() {
	if (ix_top_line_ + window_height_ < v_lines_.size())
		ix_top_line_ += window_height_;
}

inline void Buffer::move_to_previous_page() {
	if (ix_top_line_ > 0)
		ix_top_line_ -= window_height_;
}
