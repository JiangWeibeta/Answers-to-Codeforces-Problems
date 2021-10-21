#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int size = 0;
        cin >> size;
        int         max_num   = 0;
        int         max_index = 0;
        int         min_num   = 0x3FFFFFFF;
        int         min_index = 0;
        vector<int> arr(size);
        for (int j = 0; j < size; j++) {
            cin >> arr[j];
            if (arr[j] > max_num) {
                max_num   = arr[j];
                max_index = j;
            }
            if (arr[j] < min_num) {
                min_num   = arr[j];
                min_index = j;
            }
        }
        if (min_index > max_index) { swap(min_index, max_index); }
        int x1 = min_index;
        int x2 = max_index - min_index - 1;
        int x3 = size - max_index - 1;
        cout << min(x1 + x2, min(x1 + x3, x2 + x3)) + 2 << endl;
    }
    system("pause");
    return 0;
}
