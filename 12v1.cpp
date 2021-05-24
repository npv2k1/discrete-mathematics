

#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <fstream>
using namespace std;

#define V 8
int n;
bool bfs(int rGraph[100][100], int s, int t, int parent[])
{

    bool visited[n];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {

                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[100][100], int s, int t)
{
    int u, v;

    int rGraph[100][100] = {0};

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    int parent[n];

    int flow[100][100] = {0};
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent))
    {

        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;

            flow[u][v] += path_flow;
        }

        max_flow += path_flow;
    }
    cout << "Max Flow: " << max_flow << endl;
    cout << "==================FLOW================" << endl;
    ofstream outData("DT.OUT");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            outData << flow[i][j] << ' ';
        }
        outData << endl;
    }
    cout << "=====================================" << endl;
    outData.close();
    return max_flow;
}

int main()
{

    ifstream inData("DT.INP");
    inData >> n;
    cout << n;
    int graph[100][100] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inData >> graph[i][j];
        }
    }
    fordFulkerson(graph, 0, n - 1);

    return 0;
}
/*
0 16 0 10 5 0 0 0
0 0 12 4 0 0 0 0
0 0 0 7 0 0 0 5
0 0 0 0 4 0 17 0
0 0 0 0 0 9 0 0
0 0 0 0 0 0 0 9
0 0 0 0 0 0 0 17
0 0 0 0 0 0 0 0
=====================================
0 0 0 0 0 0 0 0
16 0 0 0 0 0 0 0
0 12 0 0 0 0 0 0
10 4 7 0 0 0 8 0
5 0 0 4 0 11 0 0
0 0 0 8 9 0 4 0
0 0 0 17 0 0 0 0
0 0 5 0 0 9 17 0
31
*/