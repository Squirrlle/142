#include "String.h"
#include <stdio.h>
#include <string.h>

void String::clear(){
	delete[] buffer_;
	buffer_ = '\0';
	size_ = 0;
}

void String::replace(const char i, const char m, String & s2){

	for(auto y = s2.c_str(); y < s2.c_str() + s2.length(); ++y){
		if(y == i)
			y = m;
	}

}
