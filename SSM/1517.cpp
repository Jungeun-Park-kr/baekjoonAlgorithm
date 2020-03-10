#include <iostream>
#include <cstring>

using namespace std;

int arr[500002];
int arr2[500002];

long long check(int start, int end) {
	if (start == end) {
		return 0;
	}

	int mid = (end + start) / 2;

	long long result = check(start, mid) + check(mid + 1, end);

	int i = start, j = mid + 1, k = start, tmp;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || arr[i] <= arr[j]))
			arr2[k++] = arr[i++];
		else
		{
			result += mid - (long long)i + 1;
			arr2[k++] = arr[j++];
		}
	}

	for (i = start; i <= end; i++) {
		arr[i] = arr2[i];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long result = check(0, n - 1);
	cout << result;
	return 0;
}