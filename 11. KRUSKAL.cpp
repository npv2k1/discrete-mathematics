

#include <bits/stdc++.h>
using namespace std;

int n = 5;
int a[100][100] = {
	{INT_MAX, 2, INT_MAX, 6, INT_MAX},
	{2, INT_MAX, 3, 8, 5},
	{INT_MAX, 3, INT_MAX, INT_MAX, 7},
	{6, 8, INT_MAX, INT_MAX, 9},
	{INT_MAX, 5, 7, 9, INT_MAX},
};
int e[100];

int find(int i)
{
	while (e[i] != i)
		i = e[i];
	return i;
}

void KRUSKAL(int a[100][100])
{
	int mincost = 0;

	for (int i = 0; i < n; i++)
		e[i] = i;

	int edge_count = 0;
	while (edge_count < n - 1)
	{
		int min = INT_MAX, x = -1, y = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (find(i) != find(j) && a[i][j] < min)
				{
					min = a[i][j];
					x = i;
					y = j;
				}
			}
		}
		x = find(x);
		y = find(y);
		e[x] = y;
		printf("E %d:(%d, %d) W:%d \n", edge_count++, x, y, min);
		mincost += min;
	}
	printf("\n WT= %d \n", mincost);
}

int main()
{


	KRUSKAL(a);

	return 0;
}