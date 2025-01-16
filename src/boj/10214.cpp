#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int k = 0, y = 0;
        for(int i = 0, ki, yi; i < 9; i++) {
            cin >> yi >> ki;
            k += ki, y += yi;
        }

        if(k > y) cout << "Korea\n";
        else if(y > k) cout << "Yonsei\n";
        else cout << "Draw\n";
    }
    
    return 0;
}