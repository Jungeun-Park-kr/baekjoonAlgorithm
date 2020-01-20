#include <stdio.h>

int main(void)
{
	int H, W, N;
	int cnt=0;
	int floor=0, room=0;
	int howMany;

	scanf("%d", &howMany);

	for (int k = 1; k <= howMany; k++) 
	{
		floor = 0;
		room = 0;
		cnt = 0;

		scanf("%d %d %d", &H, &W, &N);

		for (int i = 1; i <= W; i++)
		{
			for (int j = 1; j <= H; j++)
			{
				cnt++;
				if (cnt == N)
				{
					floor = j;
					break;
				}

			}
			if (cnt == N)
			{
				room = i;
				break;
			}

		}

		//printf("%02d%02d\n", floor, room);
		printf("%d\n", 100 * floor + room);
	}
	return 0;

}

