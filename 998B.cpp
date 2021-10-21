#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int bitcoin = 0;
    int odd     = 0;
};

bool cmp(node& a, node& b)
{
    if (a.bitcoin != b.bitcoin)
        return a.bitcoin < b.bitcoin;
    else
        return a.odd < b.odd;
}

int main()
{
    int n = 0, b = 0;
    cin >> n >> b;
    vector<int>  vc(n);
    vector<node> arr;
    int          odd_num  = 0;
    int          even_num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (vc[i] % 2)
            odd_num++;
        else
            even_num++;
        if (odd_num == even_num)
        {
            node tmp;
            tmp.odd   = odd_num;
            tmp.bitcoin = abs(vc[i + 1] - vc[i]);
            arr.push_back(tmp);
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        tmp += arr[i].bitcoin;
        if (tmp > b)
            break;
        else
            ans++;
    }
    cout << ans;
    system("pause");
    return 0;
}
