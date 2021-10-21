#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    int** graph = new int*[n + 2];
    for (int i = 0; i < n + 2; i++)
    {
        graph[i] = new int[m + 2];
        fill(graph[i], graph[i] + m + 2, 0);
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j])
            {
                graph[i][m + 1]++;
                graph[n + 1][j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (graph[i][j] == 0)
                ans += (graph[i][m + 1] + graph[n + 1][j]);
        }
    }
    cout << ans;
    system("pause");
    return 0;
}
