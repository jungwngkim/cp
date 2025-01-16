#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct intv { 
    int l, r;

    bool operator<(const intv &o) {
        if(l == o.l) return r > o.r;
        else return l < o.l;
    }
};

int n;
vector<intv> v;
vector<int> ans;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    v.resize(n);
    for(intv &i : v) cin >> i.l >> i.r;

    sort(v.begin(), v.end());

    for(int i = 0; i < n;) {
        int j;
        for(j = i + 1; j < n; j++) {
            if(v[j].l <= v[i].r) v[i].r = max(v[j].r, v[i].r);
            else break;
        }
        ans.push_back(i);
        i = j;
    }

    for(int i : ans) {
        cout << v[i].l << ' ' << v[i].r << '\n';
    }
    
    return 0;
}