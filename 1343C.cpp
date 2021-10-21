#include <algorithm>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef long long ll;

struct ans
{
    ll len          = 0;
    ll  sum          = 0;
    ll last_element = 0;
};

void solve()
{
    int size = 0;
    cin >> size;
    ans         p_start, n_start;
    vector<ll> vc(size + 1);
    for (int i = 1; i < size + 1; i++)
    {
        cin >> vc[i];
    }
    int p = 0, n = 0;
    for (int i = 1; i < size + 1; i++)
    {
        if (vc[i] > 0)
        {
            p_start.len          = 1;
            p_start.sum          = vc[i];
            p_start.last_element = vc[i];
            p                    = i;
            break;
        }
    }
    for (int i = 1; i < size + 1; i++)
    {
        if (vc[i] < 0)
        {
            n_start.len          = 1;
            n_start.sum          = vc[i];
            n_start.last_element = vc[i];
            n                    = i;
            break;
        }
    }
    for (int j = p + 1; j < size + 1; j++)
    {
        if (vc[j] * p_start.last_element < 0)
        {
            p_start.len++;
            p_start.sum += vc[j];
            p_start.last_element = vc[j];
        }
        else
        {
            if (vc[j] > p_start.last_element)
            {
                p_start.sum          = p_start.sum - p_start.last_element + vc[j];
                p_start.last_element = vc[j];
            }
        }
    }
    for (int j = n + 1; j < size + 1; j++)
    {
        if (vc[j] * n_start.last_element < 0)
        {
            n_start.len++;
            n_start.sum += vc[j];
            n_start.last_element = vc[j];
        }
        else
        {
            if (vc[j] > n_start.last_element)
            {
                n_start.sum          = n_start.sum - n_start.last_element + vc[j];
                n_start.last_element = vc[j];
            }
        }
    }
    if (p_start.len > n_start.len)
    {
        cout << p_start.sum << endl;
    }
    else
    {
        cout << n_start.sum << endl;
    }
}

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        solve();
    }
    system("pause");
    return 0;
}
