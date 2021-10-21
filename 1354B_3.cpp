#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void solve()
{
    string str;
    cin >> str;
    int    arr[4] = {0, 0, 0, 0};
    int    i = 0, j = 0;
    int    ans = 0x3FFFFFFF;
    while (j < str.size())
    {
        arr[str[j] - '0']++;
        if (arr[1] && arr[2] && arr[3])
        {
            for (; i <= j - 2; i++)
            {
                if (arr[str[i] - '0'] == 1)
                {
                    if (ans > j - i + 1)
                        ans = j - i + 1;
                    break;
                }
                else
                {
                    arr[str[i] - '0']--;
                }
            }
        }
        j++;
    }
    if (ans != 0x3FFFFFFF)
        cout << ans << endl;
    else
        cout << 0 << endl;
}

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        solve();
    }
    system("pause");
    return 0;
}
