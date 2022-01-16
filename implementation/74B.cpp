#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    string direction, state;
    cin.get();
    getline(cin, direction);
    getline(cin, state);
    bool tmp = true;
    if (direction != "to head")
        tmp = false;
    for (int i = 0; i < state.size(); i++)
    {
        if (state[i] == '0')
        {
            if (m < k)
            {
                if (m > 1)
                    m--;
            }
            else if (m > k)
            {
                if (m < n)
                    m++;
            }
        }
        else
        {
            if (tmp == true)
                m = n;
            if (tmp == false)
                m = 1;
        }
        if (tmp)
        {
            if (k > 1)
                k--;
            if (k == 1)
                tmp = false;
        }
        else
        {
            if (k < n)
                k++;
            if (k == n)
                tmp = true;
        }
        if (k == m)
        {
            cout << "Controller " << i + 1 << endl;
            return 0;
        }
    }
    cout << "Stowaway" << endl;
    return 0;
}
