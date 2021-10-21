#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int solve(vector<int>& vc, vector<vector<int>>& list, int& n, int start)
{
    int max_sum = 0;
    for (int i = start; i < n; i++)
    {
        int tmp = vc[i];
        for (int j = 0; j < list[i].size(); j++)
        {
            int sum = solve(vc, list, n, list[i][j] + 1);
            if (sum + vc[i] - vc[list[i][j]] > tmp)
                tmp = sum + vc[i] - vc[list[i][j]];
        }
        if (tmp > max_sum)
            max_sum = tmp;
    }
    return max_sum;
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n = 0, q = 0;
        cin >> n >> q;
        vector<int> vc(n);
        for (auto& v : vc)
            cin >> v;
        vc.push_back(0);
        int                 ans = 0;
        vector<vector<int>> list(n + 1);
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n + 1; k++)
            {
                if (vc[j] > vc[k])
                    list[j].push_back(k);
            }
        }
        cout << solve(vc, list, n, ans) << endl;
    }
    system("pause");
    return 0;
}
