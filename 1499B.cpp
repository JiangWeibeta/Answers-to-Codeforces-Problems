#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        string str;
        cin >> str;
        bool one_one = false;
        bool can     = true;
        for (int j = 0; j + 1 < str.size(); j++)
        {
            if (str[j] == '1' && str[j + 1] == '1')
            {
                one_one = true;
            }
            if (str[j] == '0' && str[j + 1] == '0' && one_one)
            {
                can = false;
            }
        }
        if (can)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}
