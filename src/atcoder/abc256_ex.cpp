#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
vector<long long> t, lz, a;

void create(int v, int tl, int tr) {
    if(tl == tr) t[v] = a[tl];
    else {
        create(v * 2, tl, (tl + tr) >> 1);
        create(v * 2 + 1, (tl + tr) >> 1 + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void update_lazy(int v, int tl, int tr, int l, int r, long long val) {
    
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    

    return 0;
}