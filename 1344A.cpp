#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(bool** graph, int n)
{
    queue<int> qq;
    qq.push(1);
    bool* visited = new bool[n + 1];
    fill(visited, visited + n + 1, false);
    int* time = new int[n + 1];
    fill(time, time + n + 1, 0);
    visited[1] = true;
    while (!qq.empty()) {
        int tmp = qq.front();
        qq.pop();
        for (int i = 1; i < n + 1; i++) {
            if (graph[tmp][i] && !visited[i]) {
                qq.push(i);
                time[i] = time[tmp] + 1;
                visited[i] = true;
            }
        }
    }
    if (time[n]) cout << time[n];
    else
        cout << -1;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    bool** graph_rail = new bool*[n + 1];
    bool** graph_road = new bool*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        graph_rail[i] = new bool[n + 1];
        graph_road[i] = new bool[n + 1];
        fill(graph_rail[i], graph_rail[i] + n + 1, false);
        fill(graph_road[i], graph_road[i] + n + 1, true);
    }
    for (int i = 0; i < m; i++) {
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        graph_rail[v1][v2] = true;
        graph_rail[v2][v1] = true;
        graph_road[v1][v2] = false;
        graph_road[v2][v1] = false;
    }
    if (graph_rail[1][n]) { bfs(graph_road, n); }
    else {
        bfs(graph_rail, n);
    }
    system("pause");
    return 0;
}
