#include <iostream>

using namespace std;

int get_unique(int a, int b, int c)
{
    if(a == b) 
        return c;
    else 
        if(a == c)
            return b;
        else    
            return a;
}

int main()
{
    int x[3], y[3];
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];

    cout 
        << get_unique(x[0], x[1], x[2]) 
        << ' ' 
        << get_unique(y[0], y[1], y[2]);
    
    return 0;
}