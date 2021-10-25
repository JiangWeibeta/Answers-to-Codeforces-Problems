#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<string> vc(n);
    for (auto& s : vc)
        cin >> s;
    bool can = true;
    int ans = 0x3FFFFFFF;
    for (int i = 0; i < n; i++)
    {
        string tmp = vc[i] + vc[i];
        int    sum = 0;
        vector<int> idx;
        for (int j = 0; j < n; j++)
        {
            if (tmp.find(vc[j]) != tmp.npos)
            {
                idx.push_back(tmp.find(vc[j]));
            }
            else
            {
                can = false;
                break;
            }
        }
        int max_num = 0;
        for (auto& i : idx)
            if (i > max_num)
                max_num = i;
        for (auto& i : idx)
            sum += (max_num - i);
        ans = min(ans, sum);
    }
    cout << (can ? ans : -1);
    system("pause");
    return 0;
}
