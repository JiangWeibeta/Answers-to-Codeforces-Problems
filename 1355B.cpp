#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;
        vector<int> arr(n + 1);
        arr[0] = 0;
        for (int j = 1; j < n + 1; j++)
        {
            cin >> arr[j];
        }
        int cnt = 0, ans = 0;
        sort(arr.begin(), arr.end());
        for (int j = 1; j < n + 1; j++)
        {
            cnt++;
            if (cnt >= arr[j])
            {
                ans++;
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
