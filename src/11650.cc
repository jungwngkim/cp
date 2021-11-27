#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < N; i++)
        printf("%d %d\n", v[i].first, v[i].second);

    return 0;
}