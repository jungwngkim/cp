#include <iostream>

using namespace std;

char star(int y, int x, int n)
{
    if((y / n) % 3 == 1 && (x / n) % 3 == 1) return ' ';
    else 
    {
        if(n == 1) return '*';
        else return star(y, x, n / 3);
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for(int y = 0; y < n; y++) 
    {
        for(int x = 0; x < n; x++) cout << star(y, x, n);
        cout << '\n';
    }
    
    return 0;
}