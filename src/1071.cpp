#include <iostream>
#include <vector>

#define N 1001

using namespace std;

typedef pair<int, int> pi;

int n, a[N];
vector<pi> v;
vector<int> ans;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a[t]++;
    }

    for(int i = 0; i < N; i++)
    {
        if(a[i]) 
        {
            
        }
    }
    
    return 0;
}