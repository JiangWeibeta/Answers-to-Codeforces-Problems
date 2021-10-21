#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    vector<int>         vc(size + 1);
    vector<vector<int>> dp;
    int                 sum = 0;
    int                 max_sum = 0;
    for (int i = 0; i < size + 1; i++)
    {
        vector<int> tmp(size + 1);
        dp.push_back(tmp);
    }
    for (int i = 1; i < size + 1; i++)
    {
        cin >> vc[i];
        sum += vc[i];
    }
    for (int i = 1; i < size + 1; i++)
    {
        dp[i][i] = sum + 1 - 2 * vc[i];
        if (dp[i][i] > max_sum)
        {
            max_sum = dp[i][i];
        }
    }
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = i + 1; j < size + 1; j++)
        {
            dp[i][j] = dp[i][j - 1] + 1 - 2 * vc[j];
            if (dp[i][j] > max_sum)
            {
                max_sum = dp[i][j];
            }
        }
    }
    cout << max_sum;
    system("pause");
    return 0;
}
