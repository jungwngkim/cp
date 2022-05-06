#include <iostream>
#include <cmath>

using namespace std;

const double halfpi = acos(0.0);

int t;
int a, b, d;
double x, y, z;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    // r unknown
    // calculate r - r cos theta
    // r sin theta and r theta known

    // solving method
    // we know sin theta / theta = a
    // a theta = sin theta
    // find theta. 

    cin >> t;
    while(t--) 
    {
        cin >> b >> d;
        a = b + d;
        
        x = (double) a / 2;
        y = (double) b / 2;
        z = y / x;

        double lo = 0.0, hi = halfpi, theta;

        for(int i = 0; i < 200; i++)
        {
            theta = (lo + hi) / 2;
            if(z * theta < sin(theta))
                lo = theta;
            else
                hi = theta;
        }

        cout << round(x / theta * (1.0 - cos(theta))) << '\n';
    }

    return 0;
}