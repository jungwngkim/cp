#include <vector>

typedef long long ll;

// 1..n (1 indexed fenwick tree - only update)
class Fenwick {
    private:
        int s;
        vector<ll> fw;
    public:
        Fenwick(int _s) : s(_s), fw(_s + 1) {}

        void update(int pos, ll inc) {
            for (; pos <= s; pos += pos & -pos) {
                fw[pos] += inc;
            }
        }

        ll query(int pos) {
            ll res = 0;
            for (; pos > 0; pos -= pos & -pos) {
                res += fw[pos];
            }
            return res;
        }
};

// 0 indexed fenwick tree, support of set
class Fenwick {
    private:
        int s;
        vector<ll> arr;
        vector<ll> fw;
    public:
        Fenwick(int _s) : s(_s), arr(_s), fw(_s + 1) {}

        void update(int pos, ll inc) {
            arr[pos] += inc;
            pos++;
            for (; pos <= s; pos += pos & -pos) {
                fw[pos] += inc;
            }
        }

        ll query(int pos) {
            pos++;
            ll res = 0;
            for (; pos > 0; pos -= pos & -pos) {
                res += fw[pos];
            }
            return res;
        }

        void set(int pos, int val) {
            update(pos, val - arr[pos]);
        }
};