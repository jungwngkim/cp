#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < 5; i++)
    {
        int t;
        cin >> t;
        cout << t - n * m << ' ';
    }
    
    return 0;
}