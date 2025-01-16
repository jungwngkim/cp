#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    if(r > 8) r = 15 - r + 1;
    if(c > 8) c = 15 - c + 1;
    if(r > c) swap(r, c);

    cout << (r & 1 ? "black" : "white");

    // for(int i = 1; i <= 15; i++) {
    //     for(int j = 1; j <= 15; j++) {
    //         int ii = i, jj = j;
    //         if(ii > 8) ii = 15 - ii + 1;
    //         if(jj > 8) jj = 15 - jj + 1;
    //         if(ii > jj) swap(ii, jj);
    //         cout << (ii & 1 ? "*" : " ");
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}