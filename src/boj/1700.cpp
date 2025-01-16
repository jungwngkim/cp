#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n, k, a[101];
set<int> s;
deque<int> nxt[101];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;

        a[i] = x;
        nxt[x].push_back(i);
    }

    for (int i = 1; i <= k; i++) {
        nxt[i].push_back(10000);
    }

    int m = 0, ans = 0;
    for (int i = 0; i < k; i++) {
        int x = a[i];
        nxt[x].pop_front();
        
        // 이미 사용중
        if (s.count(x)) {
            continue;
        }

        // 빈칸 있음
        if (m < n) {
            m++;
            s.insert(x);
            continue;
        }

        // 빈칸 없음.
        // 현재 사용중인 원소들 중 제일
        // 나중에 등장하는 원소를 제거
        int el = *s.begin();
        for (auto it = s.begin(); it != s.end(); it++) {
            int nx = *it;
            if (nxt[el].front() < nxt[nx].front()) {
                el = nx;
            }
        }

        //cout << el << '\n';

        s.erase(el);
        s.insert(x);
        ans++;
    }

    cout << ans;

    return 0;
}
