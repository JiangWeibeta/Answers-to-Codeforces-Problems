#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int len = 0;
    cin >> len;
    string str;
    cin >> str;
    int r_num = 0, g_num = 0, b_num = 0;
    for (auto& ch : str)
    {
        if (ch == 'R')
            r_num++;
        else if (ch == 'G')
            g_num++;
        else
            b_num++;
    }
    if ((b_num && g_num == 0 && r_num == 0) || (b_num == 0 && g_num == 1 && r_num == 1))
        cout << 'B';
    else if ((g_num && b_num == 0 && r_num == 0) || (g_num == 0 && b_num == 1 && r_num == 1))
        cout << 'G';
    else if ((r_num && g_num == 0 && b_num == 0) || (r_num == 0 && g_num == 1 && b_num == 1))
        cout << 'R';
    else if ((b_num == 1 && r_num == len - 1) || (g_num == 1 && r_num == len - 1))
        cout << "BG";
    else if ((b_num == 1 && g_num == len - 1) || (r_num == 1 && g_num == len - 1))
        cout << "BR";
    else if ((g_num == 1 && b_num == len - 1) || (r_num == 1 && b_num == len - 1))
        cout << "GR";
    else
        cout << "BGR";
    system("pause");
    return 0;
}
