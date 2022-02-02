#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<char>& ch, int m, char c)
{
    int i = 1, j = 1;
    int tmp = 0;
    int ans = 0;
    if (ch[j] != c)
        tmp = 1;
    while (1)
    {
        while (tmp <= m)
        {
            if (tmp == m)
            {
                if (j + 1 < ch.size() && ch[j + 1] == c)
                    j++;
                else
                    break;
            }
            else
            {
                if (j + 1 < ch.size())
                {
                    j++;
                    if (ch[j] != c)
                        tmp++;
                }
            }
            if (j == ch.size() - 1)
                break;
        }
        ans = max(ans, j - i + 1);
        while (tmp == m)
        {
            if (ch[i] != c)
                tmp--;
            i++;
        }
        if (j == ch.size() - 1)
            break;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    vector<char> ch(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> ch[i];
    }
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int  m = 0;
        char c;
        cin >> m >> c;
        cout << solve(ch, m, c) << endl;
    }
    return 0;
}
