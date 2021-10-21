#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    int         ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i) {
            if (arr[i] + arr[i - 1] < k) {
                ans += k - arr[i] - arr[i - 1];
                arr[i] = k - arr[i - 1];
            }
        }
    }
    cout << ans << endl;
    for (int v : arr) { cout << v << " "; }
    system("pause");
    return 0;
}
