#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    int n0 = 1, n1 = 1, n = 0;
    cin >> n;
    if (n == 1)
        cout << 1;
    else {
        int cnt = 1;
        while (1) {
            n0 += n1;
            cnt++;
            if (cnt == n) { cout << n0; }
            n1 += n0;
            cnt++;
            if (cnt == n) { cout << n1; }
        }
    }
    system("pause");
    return 0;
}
