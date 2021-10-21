#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n = 0, k = 0;
    cin >> k >> n;
    string str;
    cin >> str;
    map<char, bool> can_use;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        can_use[ch] = true;
    }
    long long left = -1;
    long long ans  = 0;
    str += ' ';
    for (long long i = 0; i < str.size(); i++)
    {
        if (!can_use[str[i]])
        {
            ans += (i - left) * (i - left - 1) / 2;
            left = i;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
