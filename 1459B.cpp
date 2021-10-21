#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    if (n % 2 == 0)
        cout << (n / 2 + 1) * (n / 2 + 1);
    else
        cout << 2 * (n / 2 + 1) * (n / 2 + 2);
    system("pause");
    return 0;
}
