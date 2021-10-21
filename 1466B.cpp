#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int size = 0;
        cin >> size;
        vector<int> vc(size);
        int         ans = 0;
        map<int, int> mm;
        for (int j = 0; j < size; j++) {
            cin >> vc[j];
            if (!mm[vc[j]]) {
                mm[vc[j]]++;
                ans++;
            }
            else {
                if (!mm[vc[j] + 1]) {
                    mm[vc[j] + 1]++;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}
