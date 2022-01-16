#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
constexpr int mod = 1e9 + 7;
 
ll arr[10][200001];
 
void init()
{
    for (int i = 0; i < 200001; i++)
    {
        for (int j = 0; j < 10; j++)
            arr[j][i] = 1;
        if (i)
        {
            for (int j = 9; j >= 0; j--)
            {
                if (j == 9)
                    arr[j][i] = arr[0][i - 1] + arr[1][i - 1];
                else
                    arr[j][i] = arr[j + 1][i - 1];
                arr[j][i] %= mod;
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    init();
    while (t--)
    {
        string n;
        int    m = 0;
        cin >> n >> m;
        ll ans = 0;
        for (auto& c : n)
        {
            ans += arr[c - '0'][m];
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}
