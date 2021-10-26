#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int>> vc(m + 1);
    for (auto& v : vc)
    {
        v = vector<int>(n + 1);
        fill(v.begin(), v.end(), 0);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> vc[i][j];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vc[i][j] = max(vc[i - 1][j], vc[i][j - 1]) + vc[i][j];
        }
        cout << vc[i][n] << " ";
    }
    system("pause");
    return 0;
}
