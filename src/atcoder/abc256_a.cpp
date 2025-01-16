#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n;
    long long ans = 1;
    cin >> n;

    for(int i = 0; i < n; i++) ans *= 2;

    cout << ans;
    
    return 0;
}