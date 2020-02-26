#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int>> node[10001];
void dfs(int root, int cnt);

bool parentVisited[10001] = { 0 };
int cntMax = 0;
int point = 0;

int main(void)
{
	int vertexAmt;
	int parent, child, value;
	int cnt = 0;

	cin >> vertexAmt;

	while (--vertexAmt)
	{
		cin >> parent >> child >> value;

		node[parent].push_back(make_pair(child, value)); //보고 알게 됨
		node[child].push_back(make_pair(parent, value)); //보고 알게 됨
	}
	
	dfs(1,0);

	//cout << "point:" << point<<endl;

	memset(parentVisited, false, 10001);
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
		cntMax=cnt;
		point = root;
	}
		

	//cout << "cntMax: "<<cntMax <<endl ;

	for (int i = 0; i < node[root].size(); i++) //모든 자식에 접근
		dfs(node[root][i].first, cnt+node[root][i].second);

}