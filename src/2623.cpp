#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> topology;
int state[1001];

bool dfs(int u) {
	if(state[u] == 1) return false;
	else if(state[u] == 2) return true;

	bool res = true;
	state[u] = 1;
	for(int v : adj[u]) {
		res = res && dfs(v);
	}
	state[u] = 2;
	topology.push_back(u);

	return res;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	while(m--) {
		int tn;
		vector<int> t;
		cin >> tn;
		t.resize(tn);
		for(int &tel : t) {
			cin >> tel;
		}

		for(int i = 0; i < tn; i++) {
			for(int j = i + 1; j < tn; j++) {
				adj[t[i]].push_back(t[j]);
			}
		}
	}

	bool res = true;
	for(int i = 1; i <= n; i++) {
		res = res && dfs(i);
	}

	if(res) {
		for(auto it = topology.rbegin(); it != topology.rend(); it++) {
			cout << *it << '\n';
		}
	}
    else {
		cout << 0;
	}

    return 0;
}