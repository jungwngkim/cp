#include <iostream>
#define N 2097152

using namespace std;

int tree[2 * N];

void add(int k)
{
    k += N;
    for(; k >= 1; k /= 2) tree[k] += 1;
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

    int n; cin >> n;
    while(n--)
    {
        int q, x; cin >> q >> x;
        if(q == 1) add(x);
        else cout << remove(x) << '\n';
    }
    
    return 0;
}