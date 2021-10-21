#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

bool mark[1001];

int main()
{
    int n = 0;
    cin >> n;
    int max_num = 0;
    int num = 0;
    for (int i = 1;; i++) {
        if (n - i >= 0) {
            mark[i] = true;
            num++;
            max_num = i;
            n -= i;
        }
        else {
            mark[max_num] = false;
            mark[max_num + n] = true;
            break;
        }
    }
    cout << num << endl;
    for (int i = 1; i < 1001; i++) {
        if (mark[i]) {
            cout << i << " ";
        }
    }
    system("pause");
    return 0;
}
