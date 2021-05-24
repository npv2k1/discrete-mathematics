
// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include <fstream>
using namespace std;

// Number of vertices in given graph
#define V 8

/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(int rGraph[n][n], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
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

    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[n][n], int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    int rGraph[n]
              [n]; // Residual graph where rGraph[i][j]
                   // indicates residual capacity of edge
                   // from i to j (if there is an edge. If
                   // rGraph[i][j] is 0, then there is not)
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    int parent[n]; // This array is filled by BFS and to
                   // store path
    int flow[n][n] = {0};
    int max_flow = 0; // There is no flow initially

    // Augment the flow while tere is path from source to
    // sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;

            flow[u][v] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << flow[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "=====================================" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << rGraph[i][j] << ' ';
        }
        cout << endl;
    }

    return max_flow;
}

// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    // int graph[V][V] = {{0, 16, 0, 10, 5, 0, 0, 0},
    // 				   {0, 0, 12, 4, 0, 0, 0, 0},
    // 				   {0, 0, 0, 7, 0, 0, 0, 5},
    // 				   {0, 0, 0, 0, 4, 0, 25, 0},
    // 				   {0, 0, 0, 0, 0, 20, 0, 0},
    // 				   {0, 0, 0, 8, 0, 0, 4, 9},
    // 				   {0, 0, 0, 0, 0, 0, 0, 17},
    // 				   {0, 0, 0, 0, 0, 0, 0, 0}};

    ifstream inData("DT.INP");

    int n;
    inData >> n;
    cout << n;
    int graph[n][n] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inData >> graph[i][j];
        }
    }

    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 7);
    // fordFulkerson(graph, 0, 7);

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