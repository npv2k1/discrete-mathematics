#include <bits/stdc++.h>
using namespace std;
int a[100][100], n, u = 1, vs[100], e[100], ce[10000], k;
void DfsDequy(int u)
{
    int v;
    //    cout << u << " ";

    vs[u] = 1;
    for (v = 1; v <= n; v++)
        if (vs[v] == 0 && a[u][v] == 1)
        {
            // e[v] = u;
            DfsDequy(v);
        }
}
int kt(int a[100][100], int n)
{
    int v;
    for (v = 1; v <= n; v++)
    {
        vs[v] = 0;
        e[v] = 0;
    }
    DfsDequy(1);
    int ok = 1;
    for (v = 1; v <= n; v++)
    {
        if (vs[v] == 0)
        {
            ok = 0;
            break;
        }
    }
    cout << "ok: " << ok << endl;
    if (ok == 0)
        return 0;

    int bl = 0;
    for (v = 1; v <= n; v++)
    {
        int deg = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[v][i] == 1)
            {
                deg++;
            }
        }
        cout << "deg " << v << ": " << deg << endl;
        if (deg % 2 == 1)
        {
            bl++;
            if (bl > 2)
            {
                return 0;
            }
            if (bl == 1)
            {
                u = v;
                ok = 2;
            }
        }
    }
    return ok;
}
void ceu(int a[100][100], int n, int u)
{
    int v;
    stack<int> s;
    s.push(u); // Cho đỉnh u vào stack
    k = 0;
    // lặp tới khi stack giỗng
    while (!s.empty())
    {
        int v = s.top(); // lấy đỉnh v ở đầu stack
        cout << "Canh: " << v << endl;

        int ok = 1;
        for (int x = 1; x <= n; x++)
        {
            if (a[v][x] == 1)
            {
                s.push(x);
                ok = 0;
                // xoá cạnh nối v,x
                a[v][x] = 0;
                a[x][v] = 0;
                break;
            }
        }
        if (ok == 1)
        {
            k++, ce[k] = v;
            s.pop();
        }
    }
    for (v = k; v > 0; v--)
    {
        cout << ce[v] << " ";
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int res = kt(a, n);
    cout << res << endl;

    ceu(a, n, 1);
}

/*
! input
13
0	1	0	0	0	1	0	0	0	0	0	0	0
1	0	1	0	1	1	0	0	0	0	0	0	0
0	1	0	1	1	0	0	0	0	0	1	0	0
0	0	1	0	0	0	1	1	0	0	1	0	0
0	1	1	0	0	1	1	0	0	0	0	0	0
1	1	0	0	1	0	1	0	0	0	0	0	0
0	0	0	1	1	1	0	1	0	0	0	0	0
0	0	0	1	0	0	1	0	1	1	0	0	0
0	0	0	0	0	0	0	1	0	1	0	1	1
0	0	0	0	0	0	0	1	1	0	1	1	0
0	0	1	1	0	0	0	0	0	1	0	1	0
0	0	0	0	0	0	0	0	1	1	1	0	1
0	0	0	0	0	0	0	0	1	0	0	1	0

! output
1 2 3 4 7 5 2 6 5 3 11 4 8 9 10 11 12 9 13 12 10 8 7 6 1
*/