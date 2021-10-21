#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int k = 0;
    cin >> k;
    int cnt = 0;
    int i = 19;
    for (; ; i++)
    {
        int sum = 0;
        int tmp = i;
        while (tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum == 10)
        {
            cnt++;
            if (cnt == k)
            {
                break;
            }
        }
    }
    cout << i;
    system("pause");
    return 0;
}
