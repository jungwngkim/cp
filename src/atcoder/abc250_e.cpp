#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Query {
    int x, y, idx;
    bool ans;
};

int n, m;
Query q[200000];
int a[200000], b[200000];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> q[i].x >> q[i].y;
        q[i].idx = i;
    }

    sort(q, q + m, [](auto &a, auto &b) { 
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    for(int i = 0; i < m; i++) {
        cout << q[i].x << q[i].y << '\n';
        
    }
    
    return 0;
}