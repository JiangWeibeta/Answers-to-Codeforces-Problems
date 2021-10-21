#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> dp(str.size() + 1);
    dp[1] = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
        {
            dp[i + 1] = dp[i] + 1;
        }
        else
        {
            dp[i + 1] = dp[i];
        }
    }
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int left = 0, right = 0;
        cin >> left >> right;
        cout << dp[right] - dp[left] << endl;
    }
    system("pause");
    return 0;
}
