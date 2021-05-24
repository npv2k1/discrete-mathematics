/*
Viết hàm có tên là int TPLT_DFS(int a[ ] [ ]) trên C/C++ tìm số thành phần liên thông của đồ thị G = <V, E> được biểu diễn dưới dạng ma trận kề a[ ] [ ] bằng cách sử dụng hàm DFS(int u) đã biết mô tả thuật toán duyệt theo chiều sâu các đỉnh của đồ thị G.
*/
#include <bits/stdc++.h>
using namespace std;
int a[100][100], lt[100], n, k=0;

int u, vs[1000]; //e[100];
void DfsDequy(int u)
{
    int v;
    // In đỉnh được thăm
    // cout << u << " ";
    // Đánh dấu đỉnh đó đã dùng
    lt[u] = k;

    // Tìm cạch kề với u
    for (v = 1; v <= n; v++)
        if (lt[v] == 0 && a[u][v] == 1)
        {
            // e[v] = u;
            DfsDequy(v);
        }
}
// ok
int tpltDfs()
{
    // Khởi tạo đỉnh u và số thành phần liên thông ban đầu k=0
    int u;
    // Gán lt=0
    for (u = 1; u <= n; u++)
        lt[u] = 0;
    // Duyệt tất cả đỉnh
    for (u = 1; u <= n; u++){
        if (lt[u] == 0)
        {
            cout << u << "____";
            k++;
            DfsDequy(u);
        }
    }
    cout<<"k=> "<<k<<endl;
    return k;
}
int32_t main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    tpltDfs();
}