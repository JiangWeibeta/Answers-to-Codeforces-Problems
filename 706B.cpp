#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int len = 0;
    cin >> len;
    vector<int> vc(len);
    for (int i = 0; i < len; i++)
    {
        cin >> vc[i];
    }
    sort(vc.begin(), vc.end());
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int tmp = 0;
        cin >> tmp;
        int left = 0, right = len;
        int ans = 0;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (vc[mid] <= tmp)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        ans = left;
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
