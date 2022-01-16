#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0, z = 0;
        cin >> n >> k >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum   = 0;
        int front = 0;
        int mx = 0;
        for (int i = 0; i < k + 1; i++)
        {
            mx = max(mx, arr[i] + arr[i + 1]);
            front += arr[i];
            sum = max(sum, front + min((k - i) / 2, z) * mx);
        }
        cout << sum << endl;
    }
    return 0;
}
