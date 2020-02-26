#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void dfs(int root, int cnt);
vector<pair<int, int>> node[100001];
bool parentVisited[100001] = { 0 };

int cntMax = 0;
int point = 0;

int main() {
	int vertexAmt, vertexNum1, vertexNum2, distance;

	int i, j;
	cin >> vertexAmt;

	
	for (i = 1; i <= vertexAmt; i++)
	{
		cin >> vertexNum1;

		while (true)
		{
			cin >> vertexNum2;
			if (vertexNum2 == -1)
				break;
			cin >> distance;

			node[vertexNum1].push_back(make_pair(vertexNum2, distance));
			node[vertexNum2].push_back(make_pair(vertexNum1, distance));
		}
	}


	dfs(1, 0);

	//cout << "point:" << point<<endl;

	memset(parentVisited, false, 100001);
	cntMax = 0;

	dfs(point, 0);
	//cout << "point:" << point << endl;
	cout << cntMax;


	return 0;
}

void dfs(int root, int cnt)//1,0
{
	if (parentVisited[root] != false)
		return;

	parentVisited[root] = true;

	if (cntMax < cnt)
	{
		cntMax = cnt;
		point = root;
	}


	//cout << "cntMax: "<<cntMax <<endl ;

	for (int i = 0; i < node[root].size(); i++) //모든 자식에 접근
		dfs(node[root][i].first, cnt + node[root][i].second);

}