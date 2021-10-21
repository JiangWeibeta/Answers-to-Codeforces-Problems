#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int size = 0;
        cin >> size;
        vector<int> vc(size);
        for (int j = 0; j < size; j++)
            cin >> vc[j];
        bool first = true;
        bool win   = false;
        for (int j = 0; j < size; j++)
        {
            if (vc[j] != 1 || j == size - 1)
            {
                if (first)
                {
                    win = true;
                }
                break;
            }
            else
            {
                first = !first;
            }
        }
        cout << (win ? "First" : "Second") << endl;
    }
    system("pause");
    return 0;
}
