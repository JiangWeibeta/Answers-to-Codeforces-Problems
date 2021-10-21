#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int n = 0;
        cin >> n;
        bool can_divide = true;
        int num_1 = 0, num_2 = 0, sum = 0;
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            cin >> tmp;
            sum += tmp;
            if (tmp == 1) { num_1++; }
            else {
                num_2++;
            }
        }
        if (sum % 2) { can_divide = false; }
        else {
            if (num_1 == 0 && num_2 % 2 == 1) {
                can_divide = false;
            }
        }
        if (can_divide) { cout << "YES" << endl; }
        else {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}
