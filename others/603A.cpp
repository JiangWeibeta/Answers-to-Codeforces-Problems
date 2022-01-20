#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
            cnt++;
    }
    if (cnt + 2 < n)
        cout << cnt + 2;
    else
        cout << n;
    return 0;
}
