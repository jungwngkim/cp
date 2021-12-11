#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    int n; cin >> n;
    pair<double, double> pts[10000];

    for(int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
    
    double area = 0.0;
    for(int i = 0; i < n; i++)
    {
        pair<double, double> p = i ? pts[i - 1] : pts[n - 1];
        pair<double, double> q = pts[i];
        area += (q.first - p.first) * (q.second + p.second) / 2.0;
    }

    cout.precision(1);
    cout << fixed << (area > 0 ? area : -area);

    return 0;
}