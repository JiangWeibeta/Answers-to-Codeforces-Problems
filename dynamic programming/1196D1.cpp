#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        string str;
        cin >> str;
        string      rgb = "RGB";
        string      gbr = "GBR";
        string      brg = "BRG";
        vector<int> dpr(str.size(), 0);
        vector<int> dpg(str.size(), 0);
        vector<int> dpb(str.size(), 0);
        if (str[0] == 'R')
            dpr[0] = 1;
        else if (str[0] == 'G')
            dpg[0] = 1;
        else
            dpb[0] = 1;
        for (int i = 1; i < str.size(); i++)
        {
            int m = i % 3;
            if (str[i] == rgb[m])
            {
                dpr[i] = dpr[i - 1] + 1;
                dpg[i] = dpg[i - 1];
                dpb[i] = dpb[i - 1];
            }
            else if (str[i] == gbr[m])
            {
                dpg[i] = dpg[i - 1] + 1;
                dpb[i] = dpb[i - 1];
                dpr[i] = dpr[i - 1];
            }
            else
            {
                dpb[i] = dpb[i - 1] + 1;
                dpg[i] = dpg[i - 1];
                dpr[i] = dpr[i - 1];
            }
        }
        int ans = k;
        for (int i = 0; i + k - 1 < str.size(); i++)
        {
            if (i == 0)
            {
                ans = min(k - dpr[i + k - 1], ans);
                ans = min(k - dpg[i + k - 1], ans);
                ans = min(k - dpb[i + k - 1], ans);
            }
            else
            {
                ans = min(k - dpr[i + k - 1] + dpr[i - 1], ans);
                ans = min(k - dpg[i + k - 1] + dpg[i - 1], ans);
                ans = min(k - dpb[i + k - 1] + dpb[i - 1], ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
