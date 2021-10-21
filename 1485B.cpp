#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, q = 0, k = 0;
    cin >> n >> q >> k;
    vector<int> vc(n + 2);
    vc[0]     = 1;
    vc[n + 1] = k;
    for (int i = 1; i < n + 1; i++)
        cin >> vc[i];
    for (int i = 0; i < q; i++)
    {
        int l = 0, r = 0, ans = 0;
        cin >> l >> r;
        if (l != r)
            for (int j = l; j <= r; j++)
            {
                if (j != l && j != r)
                    ans += vc[j + 1] - vc[j - 1] - 2;
                else if (j == l)
                    ans += vc[j + 1] - 2;
                else
                    ans += k - vc[j - 1] - 1;
            }
        else
            ans = k - 1;
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
