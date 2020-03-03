#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Point {
	int first, second;
};

struct Comp {
	bool comp_in_x;
	Comp(bool b) : comp_in_x(b) {}
	bool operator()(Point &p, Point &q) {
		return (this->comp_in_x ? p.first < q.first : p.second < q.second);
	}
};
int dist_calc(Point &d1, Point &d2) {
	int dx = d1.first - d2.first;
	int dy = d1.second - d2.second;
	return dx * dx + dy * dy;
}
int dist(vector<Point>::iterator iter, int n) {
	if (n == 2)
		return dist_calc(iter[0], iter[1]);
	if (n == 3)
		return min({ dist_calc(iter[0], iter[1]), dist_calc(iter[1], iter[2]), dist_calc(iter[2], iter[0]) });


	int mid = (iter[n / 2 - 1].first + iter[n / 2].first) / 2;
	int d = min(dist(iter, n / 2), dist(iter + n / 2, n - n / 2));
	vector<Point> midV;
	midV.reserve(n);

	for (int i = 0; i < n; i++) {
		int tmp = mid - iter[i].first;
		if (tmp*tmp < d) {
			midV.push_back(iter[i]);
		}
	}
	sort(midV.begin(), midV.end(), Comp(false));
	int size = midV.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size && (midV[j].second - midV[i].second)*(midV[j].second - midV[i].second) < d; ++j) {
			d = min(d, dist_calc(midV[i], midV[j]));
		}
	}
	return d;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;

	cin >> n;
	vector<Point> dots(n);

	for (auto it = dots.begin(); it != dots.end(); it++)
		cin >> it->first >> it->second;

	sort(dots.begin(), dots.end(), Comp(true));

	cout << dist(dots.begin(), n);


	return 0;
}