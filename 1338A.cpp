#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int size       = 0;
        int difference = 0;
        cin >> size;
        vector<int> vc(size);
        int         max_num = 0x80000000;
        for (int j = 0; j < size; j++) {
            cin >> vc[j];
            if (vc[j] > max_num) { max_num = vc[j]; }
            else {
                difference = max(difference, max_num - vc[j]);
            }}
        for (int j = 0;; j++) {
            if (pow(2, j) - 1 >= difference) {
                cout << j << endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}
