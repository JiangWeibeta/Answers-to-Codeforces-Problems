#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*
    字符串循环节
    前缀和
*/

using namespace std;

string pattern[6] = {"abc", "acb", "cba", "cab", "bac", "bca"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    string str;
    cin >> str;

    vector<vector<int>> arr(6, vector<int>(str.size() + 1, 0));
    for (int i = 0; i < 6; i++)
    {
        int tmp = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (pattern[i][j % 3] != str[j])
                tmp++;
            arr[i][j + 1] = tmp;
        }
    }
    while (m--)
    {
        int l = 0, r = 0;
        cin >> l >> r;
        int ans = 0x3FFFFFFF;
        for (int i = 0; i < 6; i++)
        {
            ans = min(ans, arr[i][r] - arr[i][l - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
