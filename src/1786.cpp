#include <iostream>
#include <vector>

using namespace std;

void prefix_function(string &s, vector<int> &pi)
{
    int len = s.length();
    pi.assign(len, 0);
    for(int i = 1; i < len; i++)
    {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}

void search(string &t, string &p, vector<int> &res)
{
    vector<int> pi;
    prefix_function(p, pi);

    int i = 0, j = 0, n = t.length(), m = p.length();
    while(i < n)
    {
        while(j < m && t[i] == p[j]) i++, j++;
        if(j == m) res.push_back(i - m + 1);
        if(j) j = pi[j - 1];
        else i++;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string t, p;
    getline(cin, t);
    getline(cin, p);
    
    vector<int> res;
    search(t, p, res);

    cout << res.size() << '\n';
    for(int i : res) cout << i << ' ';

    return 0;
}