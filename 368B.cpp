#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int arr[100001];

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> vc(n + 1);
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = 1; i <= n; i++) { cin >> vc[i]; }
    arr[vc[n]] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (arr[vc[i]]) { dp[i] = dp[i + 1]; }
        else {
            dp[i]      = dp[i + 1] + 1;
            arr[vc[i]] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
    system("pause");
    return 0;
}
