#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
map<string, int> name_idx;
string name[500];

int p[500];

int find(int x)
{
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    if(find(a) != find(b))
    {
        a = find(a);
        b = find(b);

        p[a] = a;
        p[b] = a;
    }
    else 
    {
        p[a] = a;
        p[b] = a;
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    string s;
    getline(cin, s);
    for(int i = 0; i < n; i++) 
    {
        getline(cin, s);
        name[i] = s;
        name_idx[s] = i;
        p[i] = i;
    }

    string s1, s2;
    for(int w; m--;)
    {
        getline(cin, s1, ',');
        getline(cin, s2, ',');
        cin >> w;
        getline(cin, s);

        if(w == 1) merge(name_idx[s1], name_idx[s2]);
        else merge(name_idx[s2], name_idx[s1]);
    }

    vector<string> ans;
    for(int i = 0; i < n; i++) 
        if(p[i] == i)
            ans.push_back(name[i]);
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(string i : ans) 
        cout << i << '\n';
    
    return 0;
}