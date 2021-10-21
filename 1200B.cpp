#include <cmath>
#include <cstdint>
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
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        vector<int> vc(n);
        for (int j = 0; j < n; j++)
            cin >> vc[j];
        bool can = true;
        for (int j = 0; j < n - 1; j++)
        {
            int lo = max(vc[j + 1] - k, 0);
            if (vc[j] >= lo)
                m += vc[j] - lo;
            else
            {
                if (vc[j] + m >= lo)
                    m = m - lo + vc[j];
                else
                {
                    can = false;
                    break;
                }
            }
        }
        cout << (can ? "YES" : "NO") << endl;
    }
    system("pause");
    return 0;
}
