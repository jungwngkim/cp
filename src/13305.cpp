#include <iostream>

#define N 100000
#define INF 1000000001

using namespace std;

int n, dist[N];
long long sum, min_price = INF;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n - 1; i++) cin >> dist[i];

    for(int i = 0; i < n - 1; i++) 
    {
        long long price;
        cin >> price;
        min_price = min(price, min_price);
        sum += min_price * dist[i];
    }
    cout << sum;
    
    return 0;
}