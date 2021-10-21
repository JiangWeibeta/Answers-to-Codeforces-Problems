#include <algorithm>
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
    fill(dp.begin(), dp.end(), 1);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (i)
        {
            if (arr[i] >= arr[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < size; i++)
    {
        if (dp[i] > max_len)
        {
            max_len = dp[i];
        }
    }
    cout << max_len;
    system("pause");
    return 0;
}
