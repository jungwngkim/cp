#include <iostream>

using namespace std;

int n, a, b;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> a >> b;

    for(int i = 0; i < n; i++) for(int ii = 0; ii < a; ii++) {
        for(int j = 0; j < n; j++) for(int jj = 0; jj < b; jj++)
            printf("%c", ((i + j) % 2 == 0) ? '.' : '#');
        printf("\n");
    }

    return 0;
}