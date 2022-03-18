#include <iostream>

using namespace std;

int a[8];

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i = 0; i < 8; i++) cin >> a[i];

    bool asc = true, des = true;
    for(int i = 1; i < 8; i++)
    {
        if(asc && a[i - 1] > a[i]) asc = false;
        if(des && a[i - 1] < a[i]) des = false;
    }

    if(asc) cout << "ascending";
    else if(des) cout << "descending";
    else cout << "mixed";
    
    return 0;
}