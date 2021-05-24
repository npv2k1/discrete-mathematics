

#include <bits/stdc++.h>
using namespace std;

#define V 5

void primMST(int graph[n][n])
{

	int e[n];

	int key[n];

	bool vs[n];

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, vs[i] = false;

	key[0] = 0;
	e[0] = -1;

	for (int count = 0; count < n - 1; count++)
	{
		int min = INT_MAX, u = 0;

		for (int v = 0; v < n; v++)
			if (vs[v] == false && key[v] < min)
				min = key[v], u = v;
		if (u == 0)
		{
			cout << "Khong co cay khung" << endl;
			return;
		}

		vs[u] = true;

		for (int v = 0; v < n; v++)

			if (graph[u][v] && vs[v] == false && graph[u][v] < key[v])
				e[v] = u, key[v] = graph[u][v];
	}

	cout << "Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout << e[i] << " - " << i << " \t" << graph[i][e[i]] << " \n";
}

int main()
{
	int graph[n][n] = {{0, 2, 0, 6, 0},
					   {2, 0, 3, 8, 5},
					   {0, 3, 0, 0, 7},
					   {6, 8, 0, 0, 9},
					   {0, 5, 7, 9, 0}};

	primMST(graph);

	return 0;
}
