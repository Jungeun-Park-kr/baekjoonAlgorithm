#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#define max 10000
using namespace std;

pair<int, int> tree[max + 1];
bool isParent[max + 1];
vector<int> widthAtDepth[max + 1];
int x = 1;
int deepest = 0;

void dfs(int node, int depth) {
	if (deepest < depth) deepest = depth;
	if (tree[node].first != -1) dfs(tree[node].first, depth + 1);
	widthAtDepth[depth].push_back(x);
	x++;
	if (tree[node].second != -1) dfs(tree[node].second, depth + 1);
}

int main() {
	int n, node, left, right, root = 0;
	cin >> n;

	//입력
	for (int i = 0; i < n; i++) {
		cin >> node >> left >> right;
		tree[node] = make_pair(left, right);
		isParent[node] = true;
	}

	//루트찾기
	for (int i = 1; i <= max; i++) {
		if (tree[i].first != 0) {
			if (tree[i].first != -1)
				isParent[tree[i].first] = false;
			if (tree[i].second != -1)
				isParent[tree[i].second] = false;
		}
		else isParent[i] = false;
	}

	for (int i = 1; i <= max; i++) {
		if (isParent[i] == true) {
			root = i;
			break;
		}
	}
	//cout << "root : " << root << '\n';
	//dfs로 좌표구하기
	dfs(root, 1);

	//width and height 구하기 , 너비같으면 위쪽 고르기
	int minX = max, maxX = 0, maxW = 0, maxLevel = 0, tmp;
	for (int i = 1; i <= deepest; i++) {
		minX = max, maxX = 0;
		for (int j = 0; j < widthAtDepth[i].size(); j++) {
			if (minX > widthAtDepth[i][j]) minX = widthAtDepth[i][j];
			if (maxX < widthAtDepth[i][j]) maxX = widthAtDepth[i][j];
		}
		tmp = maxX - minX + 1;
		if (tmp > maxW) {
			maxW = tmp;
			maxLevel = i;
		}
	}

	//출력
	cout << maxLevel << ' ' << maxW;

	return 0;
}