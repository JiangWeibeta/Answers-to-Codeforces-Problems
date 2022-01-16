#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        if (v1 > v2)
            swap(v1, v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vector<int> dp(n + 1, 1);
    ll          ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ans = max(ans, ll(graph[i].size()));
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] > i)
            {
                dp[graph[i][j]] = max(dp[graph[i][j]], dp[i] + 1);
                ans             = max(ans, dp[graph[i][j]] * ll(graph[graph[i][j]].size()));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
