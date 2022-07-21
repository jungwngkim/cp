#include <iostream>

using namespace std;

int T, N, a[2001];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0, x; i < N; i++) {
            cin >> x;
            a[x] = i;
        }

        bool ok = true, even = true;
        for(int x = 2; ok && x <= N; x++) {
            if(even && abs(a[x] - a[1]) % 2 == 0) ok = false;
            if(!even && abs(a[x] - a[1]) % 2 == 1) ok = false;
            even = !even;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    
    return 0;
}