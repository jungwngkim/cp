#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int a, b;
    while(true) {
        cin >> a >> b;
        if(!a && !b) break;
        cout << (a > b ? "Yes\n" : "No\n");
    }
    
    return 0;
}