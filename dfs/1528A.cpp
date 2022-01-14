#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
struct node
{
    int         lo = 0;
    int         hi = 0;
    vector<int> child;
};
 
void dfs(vector<node>& tree, vector<vector<ll>>& dp, int root, int parent)
{
    for (int i = 0; i < tree[root].child.size(); i++)
    {
        if (tree[root].child[i] != parent)
        {
            dfs(tree, dp, tree[root].child[i], root);
            dp[0][root] +=
                max(abs(tree[root].lo - tree[tree[root].child[i]].lo) + dp[0][tree[root].child[i]],
                    abs(tree[root].lo - tree[tree[root].child[i]].hi) + dp[1][tree[root].child[i]]);
            dp[1][root] +=
                max(abs(tree[root].hi - tree[tree[root].child[i]].lo) + dp[0][tree[root].child[i]],
                    abs(tree[root].hi - tree[tree[root].child[i]].hi) + dp[1][tree[root].child[i]]);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        vector<node> tree(n + 1);
        for (int i = 1; i < n + 1; i++)
            cin >> tree[i].lo >> tree[i].hi;
        for (int i = 1; i < n; i++)
        {
            int u = 0, v = 0;
            cin >> u >> v;
            tree[u].child.push_back(v);
            tree[v].child.push_back(u);
        }
        vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
        dfs(tree, dp, 1, -1);
        cout << max(dp[1][1], dp[0][1]) << endl;
    }
    return 0;
}
