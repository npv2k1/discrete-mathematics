#include <limits.h>
#include <bits/stdc++.h>

using namespace std;
int a[100][100], n = 5;
void DIJKSTRA(int u)
{
    int d[n];
    bool vs[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = a[u][i], vs[i] = false;
    }
    d[u] = 0;
    vs[u] = 1;

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

        vs[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!vs[v] && a[u][v] != INT_MAX && d[u] != INT_MAX && d[u] + a[u][v] < d[v])
            {
                d[v] = d[u] + a[u][v];
            }
        }
    }
    printf("v \t\t d[v]\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i + 1, d[i]);
}

int main()
{

    cout << INT_MAX << endl;
    dijkstra(0);

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