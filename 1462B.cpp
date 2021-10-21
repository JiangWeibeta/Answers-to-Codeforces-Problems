#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int size = 0;
        cin >> size;
        string str;
        cin >> str;
        if (str.substr(0, 4) == "2020" || str.substr(size - 4, size) == "2020") {
            cout << "YES" << endl;
        }
        else {
            if (str[0] == '2' && str.substr(size - 3, size) == "020") { cout << "YES" << endl; }
            else if (str.substr(0, 2) == "20" && str.substr(size - 2, size) == "20") {
                cout << "YES" << endl;
            }
            else if (str[size - 1] == '0' && str.substr(0, 3) == "202") {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    system("pause");
    return 0;
}
