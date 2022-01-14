#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> vc(n);
    for (auto& v : vc)
        cin >> v;
    vector<vector<int>> mark(n, vector<int>(3, m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isdigit(vc[i][j]))
                mark[i][0] = min(mark[i][0], min(j, m - j));
            else if (vc[i][j] >= 'a' && vc[i][j] <= 'z')
                mark[i][1] = min(mark[i][1], min(j, m - j));
            else
                mark[i][2] = min(mark[i][2], min(j, m - j));
        }
    }
    int ans = 0x3FFFFFFF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k)
                {
                    ans = min(ans, mark[i][0] + mark[j][1] + mark[k][2]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
