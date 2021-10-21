#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int n = 0, v = 0;
    cin >> n >> v;
    int ans   = 0;
    int rest  = 0;
    int to_go = n - 1;
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            rest--;
        }
        int capacity = v - rest;
        if (capacity <= to_go) {
            ans += capacity * i;
            rest = v;
            to_go -= capacity;
        }
        else {
            ans += to_go * i;
            to_go = 0;
            rest += to_go;
        }
    }
    cout << ans;
    system("pause");
    return 0;
}
