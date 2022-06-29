#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, a[200001], t[400001], p[200001], pi[200001];

int main()
{
    cin.tie(0);   
    ios_base::sync_with_stdio(0);

    cin >> n;

    // input t
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    a[n] = a[0] + 360000;
    for(int i = 0; i < n; i++) t[i] = a[i + 1] - a[i];
    for(int i = 0; i < n; i++) t[i + n] = t[i];

    // input p
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    a[n] = a[0] + 360000;
    for(int i = 0; i < n; i++) p[i] = a[i + 1] - a[i];

    // calculate pi
    memset(pi, 0, sizeof(pi));
    for(int i = 1, j = 0; i < n; i++)
    {
        while(j && p[i] != p[j]) j = pi[j - 1];
        if(p[i] == p[j]) pi[i] = ++j;
    }

    // search
    bool possible = false;
    int i = 0, j = 0;
    while(i < 2 * n)
    {
        while(j < n && t[i] == p[j]) i++, j++;
        if(j == n) 
        {
            possible = true;
            break;
        }
        if(j) j = pi[j - 1];
        else i++;
    }

    // output answer
    cout << (possible ? "possible" : "impossible");
    
    return 0;
}