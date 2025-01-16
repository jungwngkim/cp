#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Event {
    int x1, x2, y1, y2;
};

int n;
string a[2000];
vector<Event> ev;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == '1') {
                Event e = {x, 0, y, y};
                while (x + 1 < n && a[y][x + 1] == '1') x++;
                if (e.x1 == x) continue;
                e.x2 = x;
                ev.push_back(e);
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (a[y][x] == '1') {
                Event e = {x, x, y, 0};
                while (y + 1 < n && a[y + 1][x] == '1') y++;
                if (e.y1 == y) continue;
                e.y2 = y;
                ev.push_back(e);
            }
        }
    }

    sort(ev.begin(), ev.end(), [](const Event &a, const Event &b) {
        return a.x1 < b.x1;
    });

    vector<int> idx;
    for(int i = 0; i < ev.size(); i++) {
        Event e = ev[i];
        if(e.x1 == e.x2) {
            for(int j : idx) {
                
            }
        }
    }

    return 0;
}