#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
bool bfs(int Gf[MAX][MAX], int s, int t, int e[])
{
    bool *visited = new bool[n];
    queue<int> q;
    q.push(s);
    visited[s] = true;
    e[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && Gf[u][v] > 0)
            {

                if (v == t)
                {
                    e[v] = u;
                    return true;
                }
                q.push(v);
                e[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int fordFulkerson(int G[MAX][MAX], int s, int t)
{
    int u, v, max_flow = 0;

    int flow[MAX][MAX] = {0}, Gf[MAX][MAX] = {0};

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            Gf[u][v] = G[u][v];

    int e[n];

    while (bfs(Gf, s, t, e))
    {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = e[v])
        {
            u = e[v];
            path_flow = min(path_flow, Gf[u][v]);
        }

        for (v = t; v != s; v = e[v])
        {
            u = e[v];
            Gf[u][v] -= path_flow;
            Gf[v][u] += path_flow;

            flow[u][v] += path_flow;
        }

        max_flow += path_flow;
    }

    ofstream outData("DT.OUT");
    outData << max_flow << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            outData << flow[i][j] << ' ';
        }
        outData << endl;
    }
    outData.close();
    return max_flow;
}

int main()
{

    ifstream inData("DT.INP");
    inData >> n;
    cout << n;
    int G[MAX][MAX] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inData >> G[i][j];
        }
    }
    fordFulkerson(G, 0, n - 1);
    return 0;
}
