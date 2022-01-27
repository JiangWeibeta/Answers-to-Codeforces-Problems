#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> mark(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 2; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (arr[i][j] >= arr[i - 1][j])
                mark[i][j] = mark[i - 1][j] + 1;
            else
                mark[i][j] = 0;
        }
    }
    vector<int> ans(n + 1, 0);
    for (int i = 2; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++)
            ans[i] = max(ans[i], mark[i][j]);
    }
    int k = 0;
    cin >> k;
    while (k--) {
        int l = 0, r = 0;
        cin >> l >> r;
        if (ans[r] >= r - l)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
