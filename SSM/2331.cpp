#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int addPart(int a, int p) {
	int mod, sum = 0;
	while (a > 0) {
		mod = a % 10;
		a /= 10;
		sum += pow(mod, p);
	}
	return sum;
}

int main() {
	vector<int> visited;
	int repeat, howMany, a, p, cursor, cnt;
	cin >> a >> p;
	cnt = 0;
	visited.clear();
	visited.push_back(a);
	cursor = addPart(a, p);
	while (std::find(visited.begin(), visited.end(), cursor) == visited.end()) {
		visited.push_back(cursor);
		cursor = addPart(cursor, p);
	}
	visited.erase(std::find(visited.begin(), visited.end(), cursor), visited.end());
	cout << visited.size();
	return 0;
}