#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool can = false;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += arr[j];
            }
            else
            {
                sum -= arr[j];
            }
        }
        if (sum % 360 == 0)
        {
            can = true;
            break;
        }
    }
    if (can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    system("pause");
    return 0;
}
