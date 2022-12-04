#include <stdio.h>
#include <stdlib.h>

int * blah(int val) {
	int x;
	int * pointer = &x;
	x = val*val;
	return pointer;
}

int main(int argc, char **argv) {
	int * c = something(7);
	printf("%d.\n", *c);
	return 0;
}
