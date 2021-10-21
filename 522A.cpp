#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& graph, int idx, int len)
{
    int max_len = len;
    for (int i = 0; i < graph[idx].size(); i++)
    {
        int l = dfs(graph, graph[idx][i], len + 1);
        if (l > max_len)
            max_len = l;
    }
    return max_len;
}

int main()
{
    int cnt = 0;
    cin >> cnt;
    vector<vector<int>> graph(2 * cnt + 1);
    int rank = 1;
    map<string, int> get_rank;
    for (int i = 0; i < cnt; i++)
    {
        string name1, reposted, name2;
        cin >> name1 >> reposted >> name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
        if (get_rank[name1] == 0)
            get_rank[name1] = rank++;
        if (get_rank[name2] == 0)
            get_rank[name2] = rank++;
        graph[get_rank[name1]].push_back(get_rank[name2]);
    }
    int max_len = 0;
    for (int i = 1; i < rank; i++)
    {
        int len = dfs(graph, i, 0);
        if (len > max_len)
            max_len = len;
    }
    cout << max_len + 1;
    system("pause");
    return 0;
}
