#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (auto& mm : matrix)
        for (auto& i : mm)
            cin >> i;
    int tmp = 0;
    for (auto& mm : matrix)
        tmp ^= mm[0];
    if (tmp)
    {
        cout << "TAK" << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != matrix[i][0])
                {
                    cout << "TAK" << endl;
                    for (int k = 0; k < i; k++)
                        cout << 1 << " ";
                    cout << j + 1 << " ";
                    for (int k = i + 1; k < n; k++)
                        cout << 1 << " ";
                    return 0;
                }
            }
        }
    }
    cout << "NIE" << endl;
    return 0;
}
