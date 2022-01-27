//
// Created by 姜伟 on 2022/1/27.
//
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    int ans = 0;
    if (k == 2) {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < str.size(); i++) {
            if (i % 2) {
                if (str[i] != 'A') {
                    ans1++;
                } else {
                    ans2++;
                }
            } else {
                if (str[i] != 'B') {
                    ans1++;
                } else {
                    ans2++;
                }
            }
        }
        cout << min(ans1, ans2) << endl;
        if (ans1 < ans2) {
            for (int i = 0; i < str.size(); i++) {
                if (i % 2)
                    cout << 'A';
                else
                    cout << 'B';
            }
        } else {
            for (int i = 0; i < str.size(); i++) {
                if (i % 2)
                    cout << 'B';
                else
                    cout << 'A';
            }
        }
        return 0;
    }
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) {
            for (char ch = 'A'; ch <= 'A' + k - 1; ch++) {
                if (i + 1 < str.size()) {
                    if (ch != str[i - 1] && ch != str[i + 1]) {
                        ans++;
                        str[i] = ch;
                        break;
                    }
                } else {
                    if (ch != str[i]) {
                        ans++;
                        str[i] = ch;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    cout << str << endl;
    return 0;
}
