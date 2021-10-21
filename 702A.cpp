#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    vector<int> arr(size);
    vector<int> dp(size);
    dp[0] = 1;
    for (int i = 0; i < size; i++) { cin >> arr[i]; }
    int max_len = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            if (dp[i] > max_len) { max_len = dp[i]; }
        }
        else {
            dp[i] = 1;
        }
    }
    cout << max_len;
    system("pause");
    return 0;
}
