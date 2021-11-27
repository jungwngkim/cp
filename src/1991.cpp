#include <iostream>
#include <cstring>

using namespace std;

int n, l[26], r[26];

void pre(int x)
{
    if(x == -1) return;

    cout << (char) (x + 'A');
    pre(l[x]); 
    pre(r[x]);
}

void mid(int x)
{
    if(x == -1) return;

    mid(l[x]); 
    cout << (char) (x + 'A');
    mid(r[x]);
}

void post(int x)
{
    if(x == -1) return;
    
    post(l[x]); 
    post(r[x]);
    cout << (char) (x + 'A');
}

int main()
{
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0);

    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));

    cin >> n;
    for(int i=0; i<n; i++) 
    {
        char p, cl, cr;
        cin >> p >> cl >> cr;
        if(cl != '.') l[p - 'A'] = cl - 'A';
        if(cr != '.') r[p - 'A'] = cr - 'A';
    }

    pre(0); 
    cout << '\n';
    mid(0);
    cout << '\n';
    post(0);

    return 0;
}