#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct juice
{
    int    price = 0;
    string vitamin;
};

int main()
{
    int num = 0;
    cin >> num;
    vector<juice> vc(num);
    for (int i = 0; i < num; i++)
    {
        cin >> vc[i].price >> vc[i].vitamin;
    }
    long long min_cost = 223372036854775807;
    for (int i = 1; i < (1 << num); i++)
    {
        int  cost = 0;
        bool a    = false;
        bool b    = false;
        bool c    = false;
        for (int j = 0; j < num; j++)
        {
            if (i & (1 << j))
            {
                cost += vc[j].price;
                for (int k = 0; k < vc[j].vitamin.size(); k++)
                {
                    if (vc[j].vitamin[k] == 'A')
                        a = true;
                    else if (vc[j].vitamin[k] == 'B')
                        b = true;
                    else
                        c = true;
                }
                if (a && b && c)
                    break;
            }
        }
        if (cost < min_cost && a && b && c)
            min_cost = cost;
    }
    if (min_cost != 223372036854775807)
        cout << min_cost;
    else
        cout << -1;
    system("pause");
    return 0;
}
