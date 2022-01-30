//
// Created by 姜伟 on 2022/1/30.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll sum_of_digits(ll num) {
    ll sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    ll n = 0, s = 0;
    cin >> n >> s;
    ll l = s, r = n;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll diff = mid - sum_of_digits(mid);
        if (diff < s) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ans = n - r;
    cout << ans;
    return 0;
}
