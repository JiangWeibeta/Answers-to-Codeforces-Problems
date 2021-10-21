#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    if (n == 1) { cout << 1; }
    else if (n == 2) {
        cout << 5;
    }
    else {
        int* dp = new int[n + 1];
        dp[1]   = 1;
        dp[2]   = 5;
        for (int i = 3; i < n + 1; i++) { dp[i] = dp[i - 1] + 4 * (i - 1); }
        cout << dp[n];
    }
    return 0;
}
