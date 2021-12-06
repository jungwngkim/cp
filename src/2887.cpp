#include <iostream>

using namespace std;

int main()
{
    int n = 100000;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            n = 100000;
        }
    }
    cout << "Done\n";
    return 0;
}