#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        double size = 0;
        cin >> size;
        map<ll, ll> mm;
        vector<ll>    vc(size);
        double        sum = 0;
        for (auto& l : vc)
        {
            cin >> l;
            sum += l;
            mm[l]++;
        }
        double avg = sum / size;
        ll    ans = 0;
        if (avg - int(avg) != 0.5 && avg - int(avg) != 0)
        {
            cout << ans << endl;
        }
        else
        {
            for (auto it = mm.begin(); it != mm.end(); it++)
            {
                int l = it->first;
                if (mm[l])
                {
                    if (l != avg)
                        ans += (mm[2 * avg - l] * mm[l]);
                    else
                        ans += (mm[l] * (mm[l] - 1));
                }
            }
            cout << ans / 2 << endl;
        }
    }
    system("pause");
    return 0;
}
