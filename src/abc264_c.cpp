#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

map<int, vector<pi>> pos;
int h1, w1, h2, w2, a[10][10], b[10][10];
pi diag[10];

bool calc(int i) {
    if(i == w2)
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> h1 >> w1;
    for (int y = 0; y < h1; y++) {
        for (int x = 0; x < w1; x++) {
            cin >> a[y][x];
            if (pos.find(a[y][x]) == pos.end()) {
                pos[a[y][x]] = vector<pi>();
                pos[a[y][x]].push_back({y, x});
            }
        }
    }

    cin >> h2 >> w2;
    for (int y = 0; y < h2; y++) {
        for (int x = 0; x < w2; x++) {
            cin >> b[y][x];
        }
    }

    return 0;
}