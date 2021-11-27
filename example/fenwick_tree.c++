int sum(int k) {
    int s = 0;
    while(k >= 1) {
        s += t[k];
        k -= k & -k;
    }
    return s;
}

int sum(int a, int b) {
    return sum(b) - sum(a - 1);
}

void add(int k, int x) {
    while(k <= n) {
        t[k] += x;
        k += k & -k;
    }
}