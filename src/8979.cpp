#include <iostream>
#include <algorithm>

using namespace std;

struct Country { int g, s, b, idx; };

int n, k;
int rank[1001];
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
    
    rank[c[0].idx] = 1;
    for(int i = 1; i < n; i++)
    {
        if(c[i - 1].g == c[i].g && c[i - 1].s == c[i].s && c[i - 1].b == c[i].b)
        {
            rank[c[i].idx] = rank[c[i - 1].idx];
        }
        else
        {
            rank[c[i].idx] = i + 1;
        }
    }

    cout << rank[k];

    return 0;
}