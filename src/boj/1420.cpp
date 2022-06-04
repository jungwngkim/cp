#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define u(y, x) (2 * ((y) * 100 + (x)))

using namespace std;

struct Edge { int u, v, c, f; };

int n, m;
int s, t;
char b[100][100];
vector<int> adj[20000];
vector<Edge> edge;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
		cin >> b[y][x];
	}

	for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
		if(b[y][x] == '#') continue;

		
	}
	return 0;
}