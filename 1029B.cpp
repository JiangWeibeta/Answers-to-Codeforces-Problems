#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    vector<int> dp(n);
    fill(dp.begin(), dp.end(), 1);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vc[i] * 2 >= vc[j] && dp[i] + 1 > dp[j])
            {
                dp[j] = dp[i] + 1;
                if (dp[j] > ans)
                {
                    ans = dp[j];
                }
                break;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

