#include <iostream>
#define N 131072

using namespace std;

int tree[2 * N];

void add(int k)
{
    k += N;
    for(; k >= 1; k /= 2) tree[k]++;
}

int remove(int x)
{
    int k = 1;
    while(k < N)
    {
        tree[k]--;
        k *= 2;
        if(tree[k] < x)
        {
            x -= tree[k];
            k++;
        }
    }
    tree[k]--;
    return k - N;
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n, k; cin >> n >> k;

    for(int i = 1; i <= n; i++) add(i);
    
    cout << '<';
    int idx = k;
    for(int i = n - 1; i >= 1; i--)
    {
        cout << remove(idx) << ", ";
        idx = (idx + k - 1) % i;
        if(!idx) idx += i;
    }
    cout << remove(idx) << '>';

    return 0;
}