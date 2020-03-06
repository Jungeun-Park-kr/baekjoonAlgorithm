#include <iostream>
#include <cstring>

using namespace std;
int origin[500001];
int cpy[500001];
long long cnt = 0;
long long devide(int start, int end);
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> origin[i];

	devide(0, N - 1);
	cout << cnt;
	return 0;
}

long long devide(int start, int end)
{
	if (start == end)
		return 0;

	int cut = (start + end) / 2; //È¦¼ö¸é ¾Õ¿¡°Ô ±ç Â¦¼ö¸é ¹Ý.

	cnt=devide(start, cut)+devide(cut + 1, end);
	
	int i = start;
	int j = cut + 1;
	int index = 0;

	while (i <= cut || j <= end)
	{
		if (i <= cut && (j > end || origin[i] <= origin[j]))
			cpy[index++] = origin[i++];
		else
		{
			cnt += cut - (long long)i + 1;
			cpy[index++] = origin[j++];
		}
	}

	for (int k = start; k <= end; k++)
		origin[k] = cpy[k - start];

	return cnt;

}