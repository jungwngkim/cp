#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define node(y, x) (200 * ((y) - 1) + 2 * ((x) - 1))

using namespace std;

struct Edge { int to, cap; };

int src, snk;
vector<int> adj[20000];
vector<Edge> edges;
int en = 0;

int dy[2] = { 0, 1 }, dx[2] = { 1, 0 };

void add_edge(int from, int to, int cap) {
	edges.push_back({ to, cap });
	edges.push_back({ from, 0 });
	adj[from].push_back(en);
	adj[to].push_back(en + 1);
	en += 2;
}

void add_seperation_edge(int u) {
	add_edge(u, u + 1, 1);
}

void add_bridge_edge(int u, int v) {
	add_edge(u + 1, v, 0x3f3f3f);
	add_edge(v + 1, u, 0x3f3f3f);
}

void get_input() {
	bool b[102][102];
	int n, m;

	memset(b, false, sizeof(b));

	cin >> n >> m;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			char c;
			cin >> c;
			b[y][x] = c != '#';
			if (c == 'K') src = node(y, x) + 1;
			if (c == 'H') snk = node(y, x);
		}
	}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (!b[y][x]) continue;

			add_seperation_edge(node(y, x));

			for (int i = 0; i < 2; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (!b[ny][nx]) continue;

				add_bridge_edge(node(y, x), node(ny, nx));
			}
		}
	}

	// for (int y = 1; y <= n; y++) {
	// 	for (int x = 1; x <= m; x++) {
	// 		cout << "Node: " << node(y, x) << '\n';
	// 		for (int idx : adj[node(y, x)]) {
	// 			Edge e = edges[idx];
	// 			cout << idx << ' ' << e.to << ' ' << e.cap << '\n';
	// 		}
	// 		cout << '\n';

	// 		cout << "Node: " << (node(y, x) ^ 1) << '\n';
	// 		for (int idx : adj[node(y, x) ^ 1]) {
	// 			Edge e = edges[idx];
	// 			cout << idx << ' ' << e.to << ' ' << e.cap << '\n';
	// 		}
	// 		cout << '\n';

	// 	}
	// }
}


int max_flow() {
	int flow = 0;
    int history[20000];

    while (true) {
		memset(history, -1, sizeof(history));
		history[src] = -2;

		queue<int> q;
		q.push(src);

		while (!q.empty() && history[snk] == -1) {
			int from = q.front();
			q.pop();

			for (int idx : adj[from]) {
				Edge e = edges[idx];
				if (history[e.to] == -1 && e.cap > 0) {
					history[e.to] = idx;
					q.push(e.to);
				}
			}
		}

		if (history[snk] == -1) break;

        flow++;
        for (int cur = snk, idx; cur != src; cur = edges[idx ^ 1].to) {
			idx = history[cur];
			edges[idx].cap--;
			edges[idx ^ 1].cap++;
        }

		if (flow > 4) break;
    }

    return flow;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	get_input();
	int f = max_flow();
	cout << (f > 4 ? -1 : f) << '\n';

	return 0;
}
