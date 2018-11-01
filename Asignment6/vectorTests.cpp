#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::max_element;
using std::endl;

char* strcpy(char* dest, char* source){

	while(*source++ = *dest++);
	return dest;

}

int main() {

	char des[] = "world";
	char succ[] = "IDIED";
	vector<int> tresz {3, 4 ,5};
	vector<int> qutro {1, 2};
	vector<int> set;

	set.insert(set.end(), qutro.begin(), qutro.end());

	cout << strcpy(succ, des);

	return 0;
}
