#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    double d, h, w;
    cin >> d >> h >> w;

    double t = atan(h / w);
    cout << floor(d * sin(t)) << ' ' << floor(d * cos(t));
    
    return 0;
}