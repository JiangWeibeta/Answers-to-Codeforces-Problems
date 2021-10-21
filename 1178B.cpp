#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int start = 0;
    for (; start < str.size(); start++)
        if (str[start] != 'o')
            break;
    vector<long long> vc;
    vector<long long> zc;
    long long         v_num = 0;
    int cnt = 0;
    for (int i = start; i < str.size(); i++)
    {
        if (str[i] == 'v')
            v_num++;
        else
        {
            if (cnt == 0 && v_num > 1)
            {
                start = i;
                cnt++;
            }
            if (v_num > 1)
                vc.push_back(v_num - 1);
            else
            {
                if (str[i - 1] == 'v')
                    str[i - 1] = ' ';
            }
            v_num = 0;
        }
    }
    long long z_num = 0;
    for (int i = start; i < str.size(); i++)
    {
        if (str[i] == 'o')
            z_num++;
        else if (str[i] == 'v')
        {
            if (z_num)
            {
                zc.push_back(z_num);
                z_num = 0;
            }
        }
    }
    if (v_num - 1 > 0)
        vc.push_back(v_num - 1);
    vector<long long> cv;
    long long         sum = 0;
    for (int j = vc.size() - 1; j >= 0; j--)
    {
        sum += vc[j];
        cv.push_back(sum);
    }
    long long ans = 0;
    if (!cv.empty() && !zc.empty())
    {
        reverse(cv.begin(), cv.end());
        for (int j = 1; j < vc.size(); j++)
            vc[j] += vc[j - 1];
        for (int i = 0; i < vc.size() - 1; i++)
        {
            ans += vc[i] * cv[i + 1] * zc[i];
        }
    }
    cout << ans;
    return 0;
}
