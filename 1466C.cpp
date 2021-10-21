#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        string str;
        int    ans = 0;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] != ' ')
            {
                if (j + 1 < str.size() && str[j] == str[j + 1])
                {
                    ans++;
                    str[j + 1] = ' ';
                }
                if (j + 2 < str.size() && str[j] == str[j + 2])
                {
                    ans++;
                    str[j + 2] = ' ';
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
