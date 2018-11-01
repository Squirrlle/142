#include "meme.h"
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main() {

	int x = 13;

	swap(x, x);

	cout << (x);

	return 0;
}
