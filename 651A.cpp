#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

void cal(int& a1, int& a2)
{
    a2 -= 2;
    a1 += 1;
}

int main()
{
    int a1 = 0, a2 = 0;
    cin >> a1 >> a2;
    if (a1 < a2)
        swap(a1, a2);
    int time = 0;
    if (a1 < 2 && a2 < 2)
    {
        cout << 0;
        return 0;
    }
    while (a1 > 0 && a2 > 0)
    {
        if (a2 > 2)
            cal(a1, a2);
        else
        {
            swap(a1, a2);
            cal(a1, a2);
        }
        time++;
    }
    cout << time;
    system("pause");
    return 0;
}
