#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int a = 0, b, cnt = 1;
    bool inc = true;
    while(n--)
    {
        cin >> b;

        if(inc && a > b) 
        {
            inc = false;
            cnt++;
        }
        if(!inc && a < b)
        {
            inc = true;
            cnt++;
        }

        a = b;
    }
    
    cout << ceil(log2(cnt));
    return 0;
}