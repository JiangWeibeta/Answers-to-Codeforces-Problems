//
// Created by 姜伟 on 2022/2/2.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> front(n, 0), back(n, 0);
    int         height = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > height)
            front[i] = ++height;
        else
        {
            height = min(front[i - 1], arr[i]) - 1;
            if (arr[i] > height)
            {
                front[i] = ++height;
            }
        }
    }
    height = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > height)
            back[i] = ++height;
        else
        {
            height = min(back[i + 1], arr[i]) - 1;
            if (arr[i] > height)
            {
                back[i] = ++height;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, min(front[i], back[i]));
    }
    cout << ans << endl;
    return 0;
}
