#include <iostream>
#include <string>

using namespace std;

int main() {
	double A, B;
	cin >> A >> B;
	cout << fixed;
	cout.precision(15);
	cout << A / B;

	return 0;
}