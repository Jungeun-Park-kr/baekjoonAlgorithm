#include <iostream>
#include <vector>
using namespace std;
?
vector <int> P;
void dfs(int, bool*);
?
void dfs(int start, bool* visited) {
	if (visited[P.at(start)] == false) {
		visited[P.at(start)] = true;
		//vector<int>::iterator j =P.erase(P.begin);
		dfs(P.at(start), visited);
	}
}
?
int main() {
	int repeat, howMany, num, cnt;
	bool visited[1001];
	cin >> repeat;
	?
		?
		while (repeat--) {
			cnt = 0;
			cin >> howMany;
			?
				for (int i = 0; i <= howMany; i++) {
					visited[i] = false;
					P.clear();
				}
			P.push_back(0);
			for (int i = 1; i <= howMany; i++) {
				cin >> num;
				P.push_back(num);
			}
			?
				for (int i = 1; i <= howMany; i++) {
					if (visited[i] == false) {
						++cnt;
						dfs(i, visited);

					}

				}
			cout << cnt << '\n';
		}
	return 0;
}