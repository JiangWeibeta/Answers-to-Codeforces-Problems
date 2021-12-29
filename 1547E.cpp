#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

constexpr ll inf = INT64_MAX / 2;

int main()
{
    int q = 0;
    cin >> q;
    while (q--)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<ll> arr(n + 1, inf);
        vector<ll> front(n + 2, inf);
        vector<ll> back(n + 2, inf);
        vector<ll> position(k);
        for (auto& p : position)
            cin >> p;
        for (int i = 0; i < k; i++)
            cin >> arr[position[i]];
        front[1] = arr[1] - 1;
        back[n] = arr[n] + n;
        for (int i = n - 1; i > 0; i--)
            back[i] = min(back[i + 1], arr[i] + i);
        for (int i = 2; i < n + 1; i++)
            front[i] = min(front[i - 1], arr[i] - i);
        for (int i = 1; i <= n; i++)
        {
            cout << min(min(front[i - 1] + i, back[i + 1] - i), arr[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}
