#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

constexpr int inf = INT_MAX / 2;

int m, n, k;
int matrix[1001][1001];

void solve()
{
    int xc = (k + 1) / 2, yc = (k + 1) / 2;
    int sum = inf;
    int x = -1, yl = 0, yr = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j + m - 1 <= k; j++)
        {
            int  tmp = 0;
            bool can = true;
            for (int t = 0; t < m; t++)
            {
                if (matrix[i][j + t] == 1)
                {
                    can = false;
                    break;
                }
                tmp += abs(i - xc) + abs(j + t - yc);
            }
            if (can)
            {
                if (sum > tmp)
                {
                    sum = tmp;
                    x   = i;
                    yl  = j;
                    yr  = j + m - 1;
                }
            }
        }
    }
    if (x != -1)
    {
        cout << x << " " << yl << " " << yr << endl;
        for (int i = yl; i <= yr; i++)
            matrix[x][i] = 1;
    }
    else
        cout << x << endl;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        solve();
    }
    return 0;
}
