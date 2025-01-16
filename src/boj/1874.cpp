#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<bool> v;

bool solve(int n) {
    stack<int> s;

    for (int i = 0, x, y = 1; i < n; i++) {
        cin >> x;
        if (s.empty()) {
            s.push(y++);
            v.push_back(true);
        }
        while (s.top() < x) {
            s.push(y++);
            v.push_back(true);
        }
        if (s.top() != x) return false;
        s.pop();
        v.push_back(false);
    }

    return true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if(solve(n)) {
        for(bool x : v) {
            cout << (x ? "+\n" : "-\n");
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
