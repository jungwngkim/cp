#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long h1, a1, h2, a2, p, s, t1, t2, tmp;
    cin >> h1 >> a1 >> h2 >> a2 >> p >> s;

    t1 = (h1 + a2 - 1) / a2;   // t1 만큼 맞으면 용사 사망
    t2 = (h2 + a1 - 1) / a1;   // t2 만큼 맞으면 마왕 사망
    tmp = h2 - (t2 - 1) * a1;  // 죽기 전 1 turn에서 마왕이 남은 체력
    // 만약 남은 체력이 1이상 p이하라면 t2갱신
    if (tmp >= 1 && tmp <= p) t2 = (h2 + s + a1 - 1) / a1;

    // 용사가 마왕보다 적은 turn에서 죽으면 gg
    cout << (t2 <= t1 ? "Victory!" : "gg");

    return 0;
}
