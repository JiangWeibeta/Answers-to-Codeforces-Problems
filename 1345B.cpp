#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

int arr[25821];

void cal(int tmp, int& ans)
{
    if (tmp <= 1)
        return;
    int lo = 1, hi = 25821;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] <= tmp && arr[mid + 1] > tmp)
        {
            ans++;
            cal(tmp - arr[mid], ans);
            break;
        }
        else if (arr[mid] > tmp)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
}

int main()
{
    arr[1] = 2;
    for (int i = 2; i < 25821; i++)
    {
        arr[i] = arr[i - 1] + 3 * i - 1;
    }
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int tmp = 0;
        cin >> tmp;
        int ans = 0;
        cal(tmp, ans);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
