#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        bool found = false;
        for (int j = 0; j < s1.size(); j++)
        {
            int len = 0;
            for (len = 0; len < s2.size() && len < s1.size(); len++)
            {
                if (s1[j + len] != s2[len])
                    break;
                int _len = len + 1;
                for (int k = j + _len - 2; k >= 0 && _len < s2.size(); k--, _len++)
                {
                    if (s1[k] != s2[_len])
                        break;
                }
                if (_len == s2.size())
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    system("pause");
    return 0;
}
