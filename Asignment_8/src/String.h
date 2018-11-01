#ifndef STRING_H_
#define STRING_H_
#include <stdio.h>
#include <string.h>

class String {
public:
	String() :
			buffer_('\0') {
		size_ = 0;
	}
	explicit String(char* user) :
			buffer_(user) {
		size_ = strlen(user) + 1;
	}
	~String() {
		delete[] buffer_;
	}
	inline int length() {
		return size_;
	}
	inline char* c_str() {
		return buffer_;
	}
	void clear();
	void replace(const char i, const char m, String & s2);
	inline char operator[](int indx) {
		return *(buffer_ + indx);
	}
private:
	char* buffer_;
	int size_;
};

#endif /* STRING_H_ */
