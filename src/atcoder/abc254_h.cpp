#include <iostream>

using namespace std;

struct edge {
    int there, cap, cost;
};

int a[100000], b[100000];
vector<edge> edges;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        for(int j = 0; j < n; j++) {
            if(a[i] == b[i]) {
                
            }
        }
    }

    return 0;
}