/**
 * @file dfct.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021
 * Thuật toán DSF bằng đệ quy
 */

// G cho bởi ma trận kề a[i][j]
#include <bits/stdc++.h>


using namespace std;


const int MAX = 1000;
int a[1000][1000], n, u, vs[1000]; //e[100];
void DfsDequy(int u)
{
    int v;
    // In đỉnh được thăm
    cout << u << " ";
    // Đánh dấu đỉnh đó đã dùng
    vs[u] = 1;

    // Tìm cạch kề với u
    for (v = 1; v <= n; v++)
        if (vs[v] == 0 && a[u][v] == 1)
        {
            // e[v] = u;
            DfsDequy(v);
        }
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int V;
        cin >> n >> V >> u;
        for (int i = 1; i <= 9; i++)
        {

            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }
        DfsDequy(u);
        cout << endl;
    }
}
/*
INPUT
1
6 9 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6
OUTPUT
5 3 1 2 4 6
*/
// !11/5/2021