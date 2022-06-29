#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n;
    while(cin >> n) {
        int m = 0;
        for(int i = 1; ; i++) {
            m = (10 * m + 1) % n;
            if(!m) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}