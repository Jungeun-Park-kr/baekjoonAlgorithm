#include <iostream>
#include <cstring>

using namespace std;

char all[3073][6145];

float dx[3] = { 1 / 2,-(1 / 4),0 };
float dy[3] = { 0,0 ,1 / 2 };


void partition(int length, int y, int x) {
	if (length > 3) {
		partition(length / 2, y, x + (int)(length * 0.5));//¿À
		partition(length / 2, y, x + (int)(length * -0.5));//¿Þ
		partition(length / 2, y - (int)(length * 0.5), x);//À§
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = x - (2 - i); j <= x + (2 - i); j++)
				all[y - i][j] = '*';
		}
		all[y - 1][x] = ' ';
	}
}

int main() {
	int i, j, k, n;

	//ÀÔ·Â
	cin >> n;

	memset(all, ' ', sizeof(all));

	//Àç±Í
	partition(n, n, n); //y,x


	//Ãâ·Â
	for (int i = 1; i <= n; i++, cout << '\n') {
		for (int j = 1; j <= 2 * n; j++) {
			cout << all[i][j];
		}
	}
}