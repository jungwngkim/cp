#include <iostream>

using namespace std;

int h, m, c;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> h >> m >> c;
    m += c;
    h += m / 60;
    
    m %= 60;
    h %= 24;

    cout << h << ' ' << m << '\n';
    
    return 0;
}