#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> color(n + 1);
    vector<int> u(n - 1);
    vector<int> v(n - 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i];
    }
    for (int i = 1; i < n + 1; i++)
        cin >> color[i];
    int num = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (color[u[i]] != color[v[i]])
        {
            num++;
            degree[u[i]]++;
            degree[v[i]]++;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (degree[i] == num)
        {
            cout << "YES" << endl << i;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
