#include <iostream>
#include <cstring>

using namespace std;

int n, pi[1000000];
string s;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);
    while(true)
    {
        cin >> s;
        if(s == ".") break;

        n = s.length();
        memset(pi, 0, sizeof(pi));
        for(int i = 1, j = 0; i < n; i++)
        {
            while(j && s[i] != s[j]) j = pi[j - 1];
            if(s[i] == s[j]) pi[i] = ++j;
        }

        int l = n - pi[n - 1];
        if(n % l == 0 && l != n) cout << n / l << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}