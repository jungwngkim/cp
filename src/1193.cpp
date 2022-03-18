#include <iostream>

using namespace std;

int n;

int bin_search()
{
    int lo = 1, hi = 10000;
    while(lo < hi)
    {
        int mid = (lo + hi) / 2;
        if(mid * (mid + 1) / 2 == n) return 0;
        
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    
    
    return 0;
}