#include <limits.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define n 5

int minDistance(int d[], bool vs[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (vs[v] == false && d[v] <= min)
			min = d[v], min_index = v;

	return min_index;
}

void printSolution(int d[])
{
	printf("nertex \t\t Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i, d[i]);
}

void dijkstra(int graph[n][n], int u)
{
	// Mảng d chứa độ dài từ đỉnh u
	int d[n];

	// mảng đánh dấu vs
	bool vs[n];

	// Khởi tạo độ dài đường đi ban đầu
	for (int i = 0; i < n; i++)
	{
		d[i] = graph[u][i], vs[i] = false;
	}

	// Khởi tạo độ dài từ u bằng 0
	d[u] = 0;
	vs[u]=1;

	for (int count = 0; count < n - 1; count++)
	{

		int min = INT_MAX;

		for (int v = 0; v < n; v++)
		{
			if (vs[v] == false && d[v] <= min)
			{
				min = d[v], u = v;
			}
		}

		// int u = minDistance(d, vs);

		vs[u] = true;

		for (int v = 0; v < n; v++)
		{
			if (!vs[v]&& graph[u][v]!=INT_MAX && d[u] != INT_MAX && d[u] + graph[u][v] < d[v])
			{
				d[v] = d[u] + graph[u][v];
				// cout << graph[u][v] << endl;
			}
		}
	}

	printf("nertex \t\t Distance from Source\n");
	for (int i = 0; i < n; i++)
		printf("%d \t\t %d\n", i+1, d[i]);
}

int main()
{
	/* Let us create the example graph discussed above */
	int graph[n][n] = { {0, 7, 5, 8, 2},
						{INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 1, 0, 1, INT_MAX},
						{INT_MAX, 1, INT_MAX, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 1, 0} };
	cout<<INT_MAX<<endl;
	dijkstra(graph, 0);

	return 0;
}
/*
nertex           Distance from Source
1                0
2                4
3                5
4                3
5                2
*/