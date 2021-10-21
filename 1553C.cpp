#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        vector<char> vc(10);
        for (int j = 0; j < 10; j++)
        {
            cin >> vc[j];
        }
        int f1 = 0, s1 = 0, rf1 = 5, rs1 = 5, ans1 = 0;
        int f2 = 0, s2 = 0, rf2 = 5, rs2 = 5, ans2 = 0;
        int ans = 0;
        for (int j = 0; j < 10; j++)
        {
            if (j % 2 == 0)
            {
                if (vc[j] == '1')
                {
                    f1++;
                    f2++;
                }
                else if (vc[j] == '?')
                {
                    f1++;
                }
                rf1--;
                rf2--;
            }
            else
            {
                if (vc[j] == '1')
                {
                    s1++;
                    s2++;
                }
                else if (vc[j] == '?')
                {
                    s2++;
                }
                rs2--;
                rs1--;
            }
            if (s1 + rs1 < f1 || f2 + rf2 < s2)
            {
                ans = j + 1;
                break;
            }
        }
        if (ans)
            cout << ans << endl;
        else
            cout << 10 << endl;
    }
    system("pause");
    return 0;
}
