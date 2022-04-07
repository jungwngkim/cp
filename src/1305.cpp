#include <iostream>

using namespace std;

int pi[1000000];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int l;
    string s;
    cin >> l >> s;

    for(int i = 1, j = 0; i < l; i++)
    {
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) pi[i] = ++j;
    }

    cout << l - pi[l - 1];

    return 0;
}