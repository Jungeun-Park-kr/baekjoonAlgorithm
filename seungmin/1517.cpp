#include <iostream>
#include <algorithm>


using namespace std;
int N;
int origin[500001];
int cnt = 0;
int devide(int start, int end);
int merge(int start, int end);
void count(int start, int end);
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> origin[i];

	devide(0, N-1);
}

int devide(int start, int end)
{
	int cmp1, cmp2;

	if (start == end)
		return origin[start];

	int cut = (start + end) / 2; //홀수면 앞에게 긺 짝수면 반.

	cmp1=devide(start, cut); //01 //00
	cmp2=devide(cut + 1, end);//22 //11

	if (cmp1 > cmp2)
	{
		int tmp = origin[start];
		origin[start] = origin[end];
		origin[end] = tmp;
		cnt++;
	}
	/*cout << cnt << '\n';*/

	if ((start == 0) && (end == N - 1))
		merge(start, end);
	else
		return 0;

}

int merge(int start, int end)
{
	/*for (int i = start; i <= end; i++)
		cout << origin[i];
	cout << '\n';*/
	int cut = (start + end) / 2;
	
	
	count(start, cut);//0,1
	count(cut + 1, end);//2,2

	/*for (int i = start; i <= end; i++)
		cout << origin[i];
	cout << '\n';*/
	
	count(start, end);
	cout << cnt << '\n';
	return 0;
}

void count(int start, int end)
{//내왼쪽에 나보다 큰것의 개수

	for (int i = start; i <= end; i++)
	{
		for (int j = start; j < i; j++)
		{
			if (origin[j] > origin[i])
				cnt++;
		}
	}
	//cout << cnt << '\n';

	sort(origin+start, origin + end+1);

	/*for (int i = start; i <= end; i++)
		cout << origin[i];
	cout <<'\n';*/
	return;
}