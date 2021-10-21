#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, q = 0;
    string str;
    cin >> n >> q >> str;
    int* arr = new int[n + 1];
    arr[0] = 0;
    int  ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ans += (str[i] - 'a' + 1);
        arr[i + 1] = ans;
    }
    for (int i = 0; i < q; i++) {
        int l = 0, r = 0;
        cin >> l >> r;
        cout << arr[r] - arr[l - 1] << endl;
    }
    system("pause");
    return 0;
}
