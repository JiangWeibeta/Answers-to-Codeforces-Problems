#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
void level_order(vector<vector<ll>>& graph, vector<ll>& distance)
{
    queue<ll> qq;
    distance[1] = 0;
    qq.push(1);
    vector<bool> visited(distance.size(), false);
    visited[1] = true;
    while (!qq.empty())
    {
        ll tmp = qq.front();
        qq.pop();
        for (ll i = 0; i < graph[tmp].size(); i++)
        {
            if (!visited[graph[tmp][i]])
            {
                distance[graph[tmp][i]] = distance[tmp] + 1;
                qq.push(graph[tmp][i]);
                visited[graph[tmp][i]] = true;
            }
        }
    }
}
 
int tree_size(vector<vector<ll>>& graph, vector<int>& child, vector<bool>& visited, int root)
{
    visited[root] = true;
    for (int i = 0; i < graph[root].size(); i++)
    {
        if (!visited[graph[root][i]])
            child[root] += tree_size(graph, child, visited, graph[root][i]);
    }
    return child[root];
}
 
int main()
{
    ll n = 0, k = 0;
    cin >> n >> k;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vector<ll> distance(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int>  child(n + 1, 1);
    tree_size(graph, child, visited, 1);
    level_order(graph, distance);
    for (ll i = 1; i < n + 1; i++)
    {
        distance[i] -= (child[i] - 1);
    }
    // sort(distance.begin(), distance.end(), [&g = graph](ll& a, ll& b) {
    //     if (a != b)
    //     {
    //         return a < b;
    //     }
    //     else
    //     {
    //         return g[a].size() < g[b].size();
    //     }
    // });
    sort(distance.begin(), distance.end(), [](ll& a, ll& b){return a > b;});
    ll ans = 0;
    for (ll i = 1; i <= k; i++)
    {
        ans += distance[i];
    }
    cout << ans << endl;
    return 0;
}
