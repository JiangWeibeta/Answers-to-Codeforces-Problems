#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        if (k == n - 1 + n * (m - 1) || k == m - 1 + m * (n - 1)) { cout << "YES" << endl; }
        else {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}
