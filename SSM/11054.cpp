#include <iostream>
#include <string>

using namespace std;

int maximum(int a, int b) {
	int max = a;
	if (max < b) max = b;
	return max;
}
int maximum(int a, int b, int c) {
	int max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	return max;
}

int main() {

	cout << "\\    /\\\n )  ( ')\n(  /  )\n	\\(__) \| ";

	return 0;
}