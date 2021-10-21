#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    long long  ans      = 0;
    int  multi    = 1;
    bool has_zero = false;
    for (int i = 0; i < size; i++) {
        int tmp = 0;
        cin >> tmp;
        if (tmp == 0) { has_zero = true; }
        if (abs(tmp + 1) < abs(tmp - 1)) {
            multi *= -1;
            ans += abs(tmp + 1);
        }
        else {
            ans += abs(tmp - 1);
        }
    }
    if (multi == -1 && !has_zero) { ans += 2; }
    cout << ans << endl;
    system("pause");
    return 0;
}
