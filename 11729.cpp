#include <iostream>
#include <cmath>


using namespace std;

void hanoi(int start, int end, int num) {
	
	if (num > 1) {
		hanoi(start, 6-start-end, num - 1);
		cout << start << " " << end << "\n";
		hanoi(6 - start - end, end, num - 1);
	}
	else if(num==1) {
		cout << start << " " << end << "\n";
	}
	return;
}
int main() {
	int N ;
	cin >> N;
	cout << ((int)pow(2, N) - 1)<<'\n';

	hanoi(1, 3, N);


	return 0;
}