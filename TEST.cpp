#include <iostream>

using namespace std;

int main()
{
    int num = -1;
    cin >> num;
    while (num != 42)
    {
        cout << num << endl;
        cin >> num;
    }
}
