#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int a[1000][1000], n, u, vs[1000], e[100];
void DfsDequy(int u)
{
    int v;
    // In đỉnh được thăm
    // cout << u << " ";
    // Đánh dấu đỉnh đó đã dùng
    vs[u] = 1;

    // Tìm cạch kề với u
    for (v = 1; v <= n; v++)
        if (vs[v] == 0 && a[u][v] == 1)
        {
            e[v] = u;
            DfsDequy(v);
        }
}

void TreeDfs(int u)
{
    int v;
    for (v = 1; v <= n; v++)
        vs[v] = 0;
    DfsDequy(u);
    // cout<<endl;
    int dem = 0;
    for (v = 1; v <= n; v++)
        if (vs[v] == 1)
            dem++;
    if (dem == n)
    {
        for (v = 1; v <= n; v++)
            if (e[v] != 0)
                cout << v << " "<< e[v] << endl;
    }
    else
        cout << "Khong co Cay khung";
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    TreeDfs(1);
}
/*
! input
6
0 1 1 0 0 0 
1 0 0 1 1 0 
1 0 0 1 0 0 
0 1 1 0 1 1 
0 1 0 1 0 1
0 0 0 1 1 0

! output
1 2 4 3 5 6 
2 1
3 4
4 2
5 4
6 5
*/