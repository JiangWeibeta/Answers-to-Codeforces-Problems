#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int max_flick(vector<char>& s, vector<char>& m)
{
    int i = 0, j = 0, ans = 0;
    while (i < s.size() && j < m.size())
    {
        if (s[i] < m[j])
        {
            i++;
            j++;
            ans++;
        }
        else
            j++;
    }
    return ans;
}

int min_flick(vector<char> s, vector<char> m, int n)
{
    vector<char> left_s, left_m;
    int         i = 0, j = 0, ans = 0;
    while (i < n && j < n)
    {
        if (s[i] == m[j])
        {
            s[i] = ' ';
            m[j] = ' ';
            i++;
            j++;
        }
        else if (s[i] < m[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (char& ch : s)
        if (ch != ' ')
            left_s.push_back(ch);
    for (char& ch : m)
        if (ch != ' ')
            left_m.push_back(ch);
    return left_s.size() - max_flick(left_s, left_m);
}

int main()
{
    int n = 0;
    cin >> n;
    vector<char> s(n), m(n);
    for (char& ch : s)
        cin >> ch;
    for (char& ch : m)
        cin >> ch;
    sort(s.begin(), s.end());
    sort(m.begin(), m.end());
    cout << min_flick(s, m, n) << endl;
    cout << max_flick(s, m);
    system("pause");
    return 0;
}
