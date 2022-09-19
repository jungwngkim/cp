#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;
    if(b > c) swap(b, c);
    if(a > b) swap(a, b);
    cout << b + c;
    
    return 0;
}