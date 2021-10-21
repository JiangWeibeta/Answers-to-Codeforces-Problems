#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[1]   = 0;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++) { dp[i] = dp[i - 2] * 2; }
    cout << dp[n];
    system("pause");
    return 0;
}
