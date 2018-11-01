#include "queue.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	queue* list = new queue();
	    for (int i = 0; i < 100; ++i)
	    {
	        list->push(rand() % 100);
	    }

	    delete list;
}
