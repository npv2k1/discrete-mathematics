#include<bits/stdc++.h>
using namespace std;
int a[100][100], n, u, vs[100], e[100], q[100];
void Bfs(int u)
{
    int v, dq = 1, cq = 0;
    cq++;
    q[cq] = u;
    vs[u] = 1;
    while (dq <= cq)
    {
        v = q[dq];
        dq++;
        cout << v << " ";
        for (int i = 1; i <= n; i++)
            if (vs[i] == 0 && a[v][i] == 1)
            {
                cq++;
                q[cq] = i;
                vs[i] = 1;
                e[i] = v;
            }
    }
}
int main(){
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= n; j++)
       {
           cin>>a[i][j];
       }
       
    }
    Bfs(1);
    
}
/*
6
0 1 1 0 0 0 
1 0 0 1 1 0
1 0 0 1 0 0 
0 1 1 0 1 1
0 1 0 1 0 1
0 0 0 1 1 0
1 2 3 4 5 6
*/
// BFS queue