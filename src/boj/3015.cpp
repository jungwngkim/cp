#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    queue<int> q;
    int n, x, ans = 0;

    cin >> n;

    while (n--) {
        cin >> x;
        if (!q.size()) {
            q.push(x);
            continue;
        }

        // 중복 고려하기
        // 자신이 제일 작은 원소가 될 때까지 q.pop()
    }

    cout << ans;

    return 0;
}