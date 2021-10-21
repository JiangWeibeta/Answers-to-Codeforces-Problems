#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

const int inf = 0x3FFFFFFF;

int main()
{
    int num = 0;
    cin >> num;
    vector<int> dp(8);
    fill(dp.begin(), dp.end(), inf);
    dp[0] = 0;
    for (int i = 0; i < num; i++)
    {
        int price = 0;
        string vitamin;
        cin >> price >> vitamin;
        int juice = 0;
        for (int j = 0; j < vitamin.size(); j++)
        {
            juice |= (1 << (vitamin[j] - 'A'));
        }
        for (int j = 0; j < 8; j++)
        {
            dp[j | juice] = min(dp[j | juice], dp[j] + price);
        }
    }
    cout << ((dp[7] == inf) ? -1 : dp[7]);
    system("pause");
    return 0;
}
