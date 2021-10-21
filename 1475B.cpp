#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num = 0;
        cin >> num;
        int n1 = num % 2020;
        int n2 = num / 2020;
        if (n1 <= n2) { cout << "YES" << endl; }
        else {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}
