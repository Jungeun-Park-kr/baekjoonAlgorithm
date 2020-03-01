#include <iostream>
#include <cstring>

using namespace std;

char all[3073][6145];

float dx[3]= { 0.5,-0.5,0};
float dy[3] = {0,0 ,0.5 };


void partition(int length, int y, int x) {//12 24 36
	//cout <<length <<' '<<x << ' ' << y << '\n';
	int yGoUp = 0;
	if (length > 3) {
		for (int i = y; i > y-length/2; i--) //12 //24~18
		{
			
			for (int j = x - yGoUp; j <= x + yGoUp; j++) //24 //
			{
				//cout << i << ' ' << j << '\n';
				all[i][j] = ' ';
			}
			yGoUp++;
				
		}

		for (int i = 0; i < 3; i++)
			partition(length / 2, y - (float)length * dy[i], x + (float)length * dx[i]);

	}
	else
		all[y - 1][x] = ' ';
	
}

int main() {
	int i, j, k, n;

	//입력
	cin >> n;

	memset(all, ' ', sizeof(all));

	for (int i = 1; i <= n; i++)
	{
		for (int j = n-(i-1); j <=n+(i-1); j++)
			all[i][j] = '*';
	}

	

	//재귀
	partition(n, n, n); //y,x


	//출력
	for (int i = 1; i <= n; i++, cout << '\n') {
		for (int j = 1; j <= 2*n; j++) {
				cout << all[i][j];
		}
	}
}