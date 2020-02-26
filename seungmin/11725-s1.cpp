#include <iostream>
using namespace std;

int main(void)
{
	int howMany;
	int input1;
	int input2;
	int* parent;

	//ют╥б
	cin >> howMany;
	
	parent = (int*)calloc(howMany + 1, sizeof(int));

	parent[1] = 1;

	for (int i = 1; i < howMany; i++) {
		cin >> input1 >> input2;
		if (parent[input1] == 0)
			parent[input1] = input2;
		else
			parent[input2] = input1;
	}

	for (int i = 2; i <= howMany; i++)
		cout << parent[i] << endl;

	return 0;
}