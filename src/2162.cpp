#include <iostream>
#include <cmath>

#define EPS (double) 1E-9

using namespace std;

// Segment-segment intersection

struct pt {
    double x, y;
};

struct line {
    double a, b, c;

    line(pt p1, pt p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p1.y * p2.x;
        
        double z = sqrt(a * a + b * b);
        if(z > EPS) a /= z, b /= z, c /= z;
    }

    double dist(pt p) {
        return a * p.x + b * p.y + c;
    }
};

inline bool intersect_1d(double a, double b, double c, double d) {
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

inline double det(double a, double b, double c, double d) {
    return a * d - b * c;
}

inline bool btwn(double l, double r, double x) {
    if(l > r) swap(l, r);
    return l <= x + EPS && x <= r + EPS;
}

bool intersect(pt p1, pt p2, pt p3, pt p4) {
    if(!intersect_1d(p1.x, p2.x, p3.x, p4.x) || !intersect_1d(p1.y, p2.y, p3.y, p4.y)) return false;

    line l1(p1, p2), l2(p3, p4);
    double z = det(l1.a, l1.b, l2.a, l2.b);
    
    if(abs(z) < EPS) {
        return abs(l1.dist(p3)) < EPS && abs(l2.dist(p1)) < EPS;
    }
    else {
        double ix = -det(l1.c, l1.b, l2.c, l2.b) / z, iy = -det(l1.a, l1.c, l2.a, l2.c) / z;
        return btwn(p1.x, p2.x, ix) && btwn(p3.x, p4.x, ix) &&
               btwn(p1.y, p2.y, iy) && btwn(p3.y, p4.y, iy);
    }
}

// Disjoint set 
int p[3000], size[3000];
int max_set_size = 1, cnt_set = 0;

void create(int x) {
    p[x] = x;
    size[x] = 1;
    cnt_set++;
}

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);

    if(a == b) return;

    if(size[a] < size[b]) swap(a, b);
    p[b] = a;
    size[a] += size[b];

    max_set_size = max(max_set_size, size[a]);
    cnt_set--;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    pair<pt, pt> pts[3000]; 
    for(int i = 0; i < n; i++) cin >> pts[i].first.x >> pts[i].first.y >> pts[i].second.x >> pts[i].second.y;

    for(int i = 0; i < n; i++) create(i);

    for(int i = 0; i < n - 1; i++) for(int j = i + 1; j < n; j++) {
        if(intersect(pts[i].first, pts[i].second, pts[j].first, pts[j].second)) {
            merge(i, j);
        }
    }

    cout << cnt_set << '\n' << max_set_size;

    return 0;
}