#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        string str = to_string(n);
        int    even = 0, odd = 0;
        for (int i = 0; i < str.size(); i += 2)
            even = even * 10 + str[i] - '0';
        for (int i = 1; i < str.size(); i += 2)
            odd = odd * 10 + str[i] - '0';
        cout << (even + 1) * (odd + 1) - 2 << endl;
    }
    system("pause");
    return 0;
}
