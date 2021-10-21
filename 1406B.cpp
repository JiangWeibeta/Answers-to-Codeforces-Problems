#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    long long cnt = 0;
    cin >> cnt;
    for (long long i = 0; i < cnt; i++)
    {
        long long size = 0;
        cin >> size;
        vector<long long> vc(size);
        for (long long j = 0; j < size; j++)
        {
            cin >> vc[j];
        }
        sort(vc.begin(), vc.end());
        long long ans = -9223372036854775807;
        for (long long i = 0; i < 5; i++)
        {
            long long a1 = 1;
            for (long long j = 0; j < i; j++)
            {
                a1 *= vc[j];
            }
            for (long long j = vc.size() - 1; j >= size - 5 + i; j--)
            {
                a1 *= vc[j];
            }
            if (a1 > ans)
                ans = a1;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
