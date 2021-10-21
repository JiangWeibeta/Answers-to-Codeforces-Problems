#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int size = 0;
        cin >> size;
        vector<char> vc(size + 1);
        for (int j = 0; j < size; j++) { cin >> vc[j]; }
        vc[size] = 'B';
        for (int j = 0; j < size + 1; j++) {
            if (vc[j] != '?') {
                for (int k = j - 1; k >= 0 && vc[k] == '?'; k--) {
                    if (vc[k + 1] == 'R') { vc[k] = 'B'; }
                    else {
                        vc[k] = 'R';
                    }
                }
                for (int k = j + 1; k <= size && vc[k] == '?'; k++) {
                    if (vc[k - 1] == 'R') { vc[k] = 'B'; }
                    else {
                        vc[k] = 'R';
                    }
                }
            }
        }
        vc.pop_back();
        for (char c : vc) cout << c;
        cout << endl;
    }
    system("pause");
    return 0;
}

