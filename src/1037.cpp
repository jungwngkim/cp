#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, factor, min_factor = 1000001, max_factor = 0;
    cin >> n;
    while(n--)
    {
        cin >> factor;
        min_factor = min(min_factor, factor);
        max_factor = max(max_factor, factor);
    }
    cout << min_factor * max_factor;
    
    return 0;
}