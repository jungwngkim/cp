#include <iostream>
#include <algorithm>

using namespace std;

struct Country 
{ 
    int g, s, b, idx; 

    bool operator<(const Country &c) const 
    {
        if(g == c.g) {
            if(s == c.s) {
                return b > c.b;
            }
            else {
                return s > c.s;
            }
        }
        else {
            return g > c.g;
        }
    }

    bool operator==(const Country &c) const 
    {
        return g == c.g && s == c.s && b == c.b;
    }
};

int n, k;
int r[1001];
Country c[1001];

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> c[i].idx >> c[i].g >> c[i].s >> c[i].b;
    }

    sort(c, c + n);

    // for(int i = 0; i < n; i++)
    // {
    //     cout << c[i].g << c[i].s << c[i].b << '\n';
    // }
    
    r[c[0].idx] = 1;
    for(int i = 1; i < n; i++)
    {
        if(c[i - 1] == c[i])
        {
            r[c[i].idx] = r[c[i - 1].idx];
        }
        else
        {
            r[c[i].idx] = i + 1;
        }
    }

    cout << r[k];

    return 0;
}