#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

struct node
{
    int odd  = 0;
    int even = 0;
};

int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    map<int, node> mm;
    mm[0].even = 1;
    int tmp    = 0;
    long long ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        tmp ^= arr[i];
        if (i % 2)
        {
            ans += mm[tmp].odd;
            mm[tmp].odd++;
        }
        else
        {
            ans += mm[tmp].even;
            mm[tmp].even++;
        }
    }
    cout << ans << endl;
    return 0;
}
