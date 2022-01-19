#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (k == 0)
    {
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                tmp++;
            else
                tmp = 0;
            ans = max(tmp, ans);
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    else
    {
        int i = 0, j = 0, ans = 1, zero = 0;
        int l = 0, r = 0;
        if (arr[0] == 0)
            zero++;
        while (1)
        {
            while (j + 1 < n)
            {
                if (arr[j + 1] == 1)
                    j++;
                else
                {
                    if (zero < k)
                    {
                        zero++;
                        j++;
                    }
                }
                if (j - i + 1 > ans)
                {
                    ans = j - i + 1;
                    l   = i;
                    r   = j;
                }
                if (arr[j + 1] == 0 && zero == k)
                    break;
            }
            while (zero == k)
            {
                if (arr[i] == 0)
                    zero--;
                i++;
            }
            if (zero < k && j == n - 1)
                break;
        }
        cout << ans << endl;
        for (int i = l; i <= r; i++)
            arr[i] = 1;
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    return 0;
}
