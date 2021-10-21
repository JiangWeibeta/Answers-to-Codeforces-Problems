#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int test_cases = 0;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        int size    = 0;
        int queries = 0;
        cin >> size >> queries;
        vector<char> vc(size);
        for (int j = 0; j < size; j++) { cin >> vc[j]; }
        for (int j = 0; j < queries; j++) {
            int l = 0, r = 0;
            cin >> l >> r;
            vector<int> tmp;
            int         rank  = l - 1;
            int         count = 0;
            for (int k = 0; k < size && rank < r; k++) {
                if (vc[k] == vc[rank]) { count++; }
                else {
                    if (count) tmp.push_back(count);
                    count = 0;
                    k--;
                    rank++;
                }
            }
            if (count) { tmp.push_back(count); }
            bool mark = false;
            if (tmp.size() == r - l + 1)
                for (int n : tmp) {
                    if (n != 1) {
                        mark = true;
                        break;
                    }
                }
            cout << (mark ? "YES" : "NO") << endl;
        }
    }
    system("pause");
    return 0;
}
