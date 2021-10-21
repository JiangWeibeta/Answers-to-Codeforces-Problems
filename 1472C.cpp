#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int size = 0;
        cin >> size;
        vector<int> vc(size + 1);
        for (int j = 1; j <= size; j++)
        {
            cin >> vc[j];
        }
        for (int j = size; j >= 1; j--)
        {
            if (j + vc[j] <= size)
            {
                vc[j] += vc[j + vc[j]];
            }
        }
        int maxn = 0;
        for (int j = 1; j <= size; j++)
        {
            if (vc[j] > maxn)
            {
                maxn =vc[j];
            }
        }
        cout << maxn << endl;
    }
    system("pause");
    return 0;
}
