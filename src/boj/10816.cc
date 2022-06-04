#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    cin >> M;
    while (M--)
    {
        int num;
        cin >> num;
        cout << upper_bound(arr, arr + N, num) - lower_bound(arr, arr + N, num) << ' ';
    }

    return 0;
}