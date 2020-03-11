#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int penalty, time;

int main() {
	vector <pair<int, int>> prob;
	int d, v;
	int i;

	for (i = 0; i < 11; i++) {
		cin >> d >> v;
		prob.push_back(make_pair(d, v));
	}

	vector <pair<int, int>>::iterator iter;
	sort(prob.begin(), prob.end());

	int pen_time = 0;
	for (iter = prob.begin(); iter != prob.end(); ++iter) {

		int pen_num = 0;
		time = time + iter->first;
		if (time <= 300) {
			//cout << "f:" << iter->first << endl;
			//pen(iter->first, iter->second);
			pen_time += iter->first;
			pen_num = iter->second * 20;
		}
		penalty = penalty + pen_time + pen_num;

	}
	cout << penalty;

	return 0;
}