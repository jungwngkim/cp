#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define N 100001

using namespace std;

int n;
int order_idx, scc_root_idx, scc_parent_num;
int order[N], scc_root[N], scc_parent_cnt[N], scc_indegree[N];
bool visited[N];
vector<int> adj[N], rev_adj[N], scc[N], scc_adj[N], ans, comp;

void dfs1(int u) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs1(v);
        }
    }

    order[order_idx++] = u;
}

void dfs2(int u) {
    scc_root[u] = scc_root_idx;
    comp.push_back(u);

    for(int v : rev_adj[u]) {
        if(!scc_root[v]) {
            dfs2(v);
        }
    }
}

void dfs3(int scc_u) {
    visited[scc_u] = true;
    scc_parent_cnt[scc_u]++;

    for(int scc_v : scc_adj[scc_u]) {
        if(!visited[scc_v]) {
            dfs3(scc_v);
        }
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int u = 1, m; u <= n; u++) {
        cin >> m;
        adj[u].resize(m);
        for(int &x : adj[u]) {
            cin >> x;
            rev_adj[x].push_back(u);
        }
    }

    for(int u = 1; u <= n; u++) {
        if(!visited[u]) {
            dfs1(u);
        }
    }

    for(int i = n - 1, u; i >= 0; i--) {
        u = order[i];
        if(!scc_root[u]) {
            comp.clear();
            scc_root_idx++;
            dfs2(u);
            scc[scc_root_idx] = comp;
        }
    }

    // for(int scc_u = 1; scc_u <= scc_root_idx; scc_u++) {
    //     cout << scc_u << " : ";
    //     for(int x : scc[scc_u]) cout << x << ' ';
    //     cout << '\n';
    // }
    // return 0;

    for(int u = 1; u <= n; u++) {
        for(int v : adj[u]) {
            if(scc_root[u] != scc_root[v]) {
                scc_adj[scc_root[u]].push_back(scc_root[v]);
                scc_indegree[scc_root[v]]++;
            }
        }
    }

    // for(int scc_u = 1; scc_u <= scc_root_idx; scc_u++) {
    //     cout << scc_u << " : " << scc_indegree[scc_u] << '\n';
    // }
    // return 0;

    for(int scc_u = 1; scc_u <= scc_root_idx; scc_u++) {
        if(!scc_indegree[scc_u]) {
            scc_parent_num++;
            memset(visited, false, sizeof(visited));
            visited[scc_u] = true;
            for(int scc_v : scc_adj[scc_u]) {
                dfs3(scc_v);
            }
        }
    }
    
    for(int scc_u = 1; scc_u <= scc_root_idx; scc_u++) {
        if(scc_parent_cnt[scc_u] < scc_parent_num) {
            ans.insert(ans.end(), scc[scc_u].begin(), scc[scc_u].end());
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << ' ';
    for(int x : ans) {
        cout << x << ' ';
    }

    return 0;
}