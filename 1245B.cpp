#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int n, a, b, c = 0;
        cin >> n >> a >> b >> c;
        string bob;
        cin >> bob;
        int br = 0, bp = 0, bs = 0;
        for (auto ch : bob)
        {
            if (ch == 'R')
                br++;
            else if (ch == 'S')
                bs++;
            else
                bp++;
        }
        int ans = min(br, b) + min(bs, a) + min(bp, c);
        if (ans >= int(n / 2.0 + 0.5))
        {
            cout << "YES" << endl;
            vector<char> vc(n);
            fill(vc.begin(), vc.end(), ' ');
            for (int k = 0; k < n; k++)
            {
                if (bob[k] == 'R' && b)
                {
                    b--;
                    vc[k] = 'P';
                }
                if (bob[k] == 'S' && a)
                {
                    a--;
                    vc[k] = 'R';
                }
                if (bob[k] == 'P' && c)
                {
                    c--;
                    vc[k] = 'S';
                }
            }
            for (int k = 0; k < n; k++)
            {
                if (vc[k] == ' ')
                {
                    if (a)
                    {
                        vc[k] = 'R';
                        a--;
                    }
                    else if (b)
                    {
                        b--;
                        vc[k] = 'P';
                    }
                    else
                    {
                        c--;
                        vc[k] = 'S';
                    }
                }
                cout << vc[k];
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}
