

#include <bits/stdc++.h>
using namespace std;

int a[100][100] = {{0, 2, 0, 6, 0},
				   {2, 0, 3, 8, 5},
				   {0, 3, 0, 0, 7},
				   {6, 8, 0, 0, 9},
				   {0, 5, 7, 9, 0}}
, n = 5;
void PRIM(int a[100][100], int u)
{

	int e[n], key[n];
	bool vs[n];

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, vs[i] = false;

	key[0] = 0;
	e[0] = -1;

	for (int count = 0; count < n - 1; count++)
	{
		int min = INT_MAX;

		for (int v = 0; v < n; v++)
			if (vs[v] == false && key[v] < min)
				min = key[v], u = v;

		vs[u] = true;

		for (int v = 0; v < n; v++)
			if (a[u][v] && vs[v] == false && a[u][v] < key[v])
				e[v] = u, key[v] = a[u][v];
	}

	cout << "E \tW\n";
	for (int i = 1; i < n; i++)
		cout << e[i] << " - " << i << " \t" << a[i][e[i]] << " \n";
}

int main()
{

	PRIM(a, 0);

	return 0;
}
