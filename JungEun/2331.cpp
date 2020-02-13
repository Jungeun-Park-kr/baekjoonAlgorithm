#include <iostream>
#include <cmath>
#define MAX 500001

using namespace std;
void dfs(int, int);

int visited[MAX];

void dfs(int tmp, int P) {
	int num=0;

	visited[tmp]++;
	if (visited[tmp] == 3){
		return;
	}

	while (tmp > 0) {
		num += pow(tmp % 10, P);
		tmp /= 10;
	}

	dfs(num, P);
	return;
}

int main(){
	int A, P, result = 0;
	cin >> A >> P;

	dfs(A, P);

	for (int i = 0; i < MAX; ++i) {
		if (visited[i] ==1) {
			++result;
		}
	}
	
	cout << result;
	return 0;
}