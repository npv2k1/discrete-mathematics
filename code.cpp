
// Simple C++ implementation for Kruskal's
// algorithm
#include <bits/stdc++.h>
using namespace std;

// int n = 4, d[100][100], e[100][100];
// int a[100][100] = {{0, 4, 3, INT_MAX}, {INT_MAX, 0, 2, INT_MAX}, {INT_MAX, 0, 2, INT_MAX}, {1, INT_MAX, INT_MAX, 0}};

#define n 4

#define INF 99999
int a[100][100],int n;
void floydWarshall(int a[100][100])
{
	int d[n][n], i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			d[i][j] = a[i][j];

	for (k = 0; k < n; k++)
	{

		for (i = 0; i < n; i++)
		{

			for (j = 0; j < n; j++)
			{

				if (d[i][j] > (d[i][k] + d[k][j]) && (d[k][j] != INF && d[i][k] != INF))
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] == INF)
				cout << "INF" << '\t';
			else
				cout << d[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{

	int graph[n][n] = {{0, 4, 3, INF}, {INF, 0, 2, INF}, {INF, INF, 0, 2}, {1, INF, INF, 0}};

	floydWarshall(graph);
	return 0;
}
