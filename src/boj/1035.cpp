#include <iostream>
#include <vector>

using namespace std;

bool check[25];
vector<int> adj[25];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            int idx = i * 5 + j;
            check[idx] = s[j] == '*';
        }
    }

    return 0;
}
