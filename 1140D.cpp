#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int ans = 6;
    for (int i = 4; i <= n; i++)
    {
        ans += i * (i - 1);
    }
    cout << ans;
    system("pause");
    return 0;
}
