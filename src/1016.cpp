#include <iostream>
#include <cstring>
#include <vector>

#define N 1000000

using namespace std;

typedef long long ll;

vector<ll> square;
bool is_prime[N + 1], ans[N + 1];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    ll l, r, intv;
    cin >> l >> r;
    intv = r - l;

    memset(is_prime, true, sizeof(is_prime));
    memset(ans, true, sizeof(ans));
                                            
    for(ll i = 2; i * i <= r; i++)
    {
        if(is_prime[i])
        {
            square.push_back(i * i);
            for(ll j = 2 * i; j * j <= r; j += i)
            {
                is_prime[j] = false;
            }
        }
    }   

    for(ll i = 0; i <= intv; i++)
    {
        if(ans[i])
        {
            for(ll s : square)
            {
                if((i + l) % s == 0)
                {
                    for(ll j = i; j <= intv; j += s)
                    {
                        ans[j] = false;
                    }
                }
            }
        }
    }

    int cnt = 0;
    for(ll i = 0; i <= intv; i++)
    {
        if(ans[i]) cnt++;
    }
    cout << cnt;
    
    return 0;
}