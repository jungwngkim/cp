#include <iostream>
#include <vector>

using namespace std;

class Fenwick {
    private:
        int s;
        vector<int> arr;
        vector<int> fw;
    public:
        Fenwick(int _s) : s(_s), arr(_s), fw(_s + 1) {}

        void update(int pos, int inc) {
            arr[pos] += inc;
            pos++;
            for (; pos <= s; pos += pos & -pos) {
                fw[pos] += inc;
            }
        }

        int query(int pos) {
            pos++;
            int res = 0;
            for (; pos > 0; pos -= pos & -pos) {
                res += fw[pos];
            }
            return res;
        }

        void set(int pos, int val) {
            update(pos, val - arr[pos]);
        }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    Fenwick fw(n);

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        fw.set(i, x);    
    }

    int m;
    cin >> m;

    int q, v, i, j, k = 0;
    while (m--) {
        cin >> q;
        if (q == 1) {
            cin >> i >> v;
            fw.set()
        }
    }

    return 0;
}
