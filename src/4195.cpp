#include <iostream>
#include <map>

using namespace std;

int p[100000], size[100000];

void create(int x) 
{
    p[x] = x;
    size[x] = 1;
}

int find(int x)
{
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a != b) 
    {
        if(size[a] < size[b]) swap(a, b);
        p[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
    {
        map<string, int> m;
        int n; cin >> n;
        while(n--)
        {
            string s1, s2; cin >> s1 >> s2;

            if(!m.count(s1)) 
            {
                m[s1] = m.size();
                create(m[s1]);
            }
            if(!m.count(s2)) 
            {
                m[s2] = m.size();            
                create(m[s2]);
            }

            merge(m[s1], m[s2]);
            cout << size[find(m[s1])] << '\n';
        }
    }

    return 0;
}