#include <iostream>

using namespace std;

int f(int n, int k)
{
    if(n < k) return n;
    else return n - n % k + f(n % k + n / k, k);
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n, k;
    while(cin >> n >> k) cout << f(n, k) << '\n';

    return 0;
}