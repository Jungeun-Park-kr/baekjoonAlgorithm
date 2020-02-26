#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sizeA, sizeB;
	int* A;
	int* B;
	int cursorA=0;
	int cursorB=0;

	cin >> sizeA >> sizeB;

	A = new int[sizeA];
	B = new int[sizeB];

	for (int i = 0; i < sizeA; i++)
		cin >> A[i];

	for (int i = 0; i < sizeB; i++)
		cin >> B[i];

	
	while (!((cursorA==sizeA)||(cursorB==sizeB))) 
	{
		if (A[cursorA] < B[cursorB])
		{
			cout << A[cursorA] <<" ";
			cursorA++;
		}
		else
		{
			cout << B[cursorB] << " ";
			cursorB++;
		}
	}
	

	if (cursorA != sizeA)
	{
		for (int i = cursorA; i < sizeA; i++)
			cout << A[i] << " ";
	}

	else
	{
		for (int i = cursorB; i < sizeB; i++)
			cout << B[i] << " ";
	}
		

	return 0;
}

