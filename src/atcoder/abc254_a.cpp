#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n, ans;
    cin >> n;

    ans = n % 100;
    if(ans == 0) {
        cout << "00";
    }
    else if(ans < 10) {
        cout << '0' << ans;
    }
    else {
        cout << ans;
    }
    
    return 0;
}