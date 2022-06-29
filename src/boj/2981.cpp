#include <iostream>

using namespace std;

int n, max_val;
int a[100];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    for(int MOD = 2; MOD <= max_val; MOD++) {
        bool ok = true;
        int z = a[0] % MOD;
        for(int i = 1; i < n; i++) {
            if(z != a[i] % MOD) {
                ok = false;
                break;
            }
        }
        if(ok) cout << MOD << ' ';
    }
    
    return 0;
}