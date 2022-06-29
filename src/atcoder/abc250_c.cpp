#include <iostream>

using namespace std;

int n, q, x;
int num[200001], idx[200001];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        num[i] = idx[i] = i;  
    }

    while(q--) {
        cin >> x;
        if(idx[x] == n) {
            swap(num[n], num[n - 1]);
            swap(idx[num[n]], idx[num[n - 1]]);
        }
        else {
            swap(num[idx[x]], num[idx[x] + 1]);
            swap(idx[num[idx[x]]], idx[num[idx[x] + 1]]);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << num[i] << ' ';
    }
    
    return 0;
}