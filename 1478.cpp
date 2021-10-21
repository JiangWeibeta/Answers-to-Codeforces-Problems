#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

bool check(int t, int q)
{
    if (t >= q * 10)
    {
        return true;
    }
    else
    {
        while (t >= 0)
        {
            t -= q;
            if (t % 10 == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int size = 0, d = 0;
        cin >> size >> d;
        for (int j = 0; j < size; j++)
        {
            int t = 0;
            cin >> t;
            if (check(t, d))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
             }
        }
    }
    system("pause");
    return 0;
}
