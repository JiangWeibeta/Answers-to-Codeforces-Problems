#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n   = 0;
    int ans = 1;
    cin >> n;
    vector<int>   arr(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(arr[n] + 1, 1);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 2 * arr[i]; j <= arr[n]; j += arr[i])
        {
            dp[j] = max(dp[j], dp[arr[i]] + 1);
        }
        ans = max(ans, dp[arr[i]]);
    }
    cout << ans << endl;
    return 0;
}
