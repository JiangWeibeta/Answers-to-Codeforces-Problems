#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> arr(n);
        vector<int> tmp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            tmp[i] = arr[i];
        }
        sort(tmp.begin(), tmp.end());
        double ans    = 0;
        bool   sorted = true;
        int    len    = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tmp[i] != arr[i])
            {
                sorted = false;
                len    = i;
                break;
            }
        }
        double last = 1;
        for (int i = 0; i < m; i++)
        {
            int    idx  = 0;
            double prob = 0;
            cin >> idx >> prob;
            idx--;
            if (idx >= len)
            {
                ans += prob * last;
                last = (1 - prob) * last;
            }
        }
        if (sorted)
            ans = 1;
        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}
