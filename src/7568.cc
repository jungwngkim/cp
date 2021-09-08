#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N, arr[50][2], ans[50];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i][0] >> arr[i][1];

    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1])
                ans[i]++;

    for (int i = 0; i < N; i++)
        cout << ans[i] + 1 << '\n';

    return 0;
}