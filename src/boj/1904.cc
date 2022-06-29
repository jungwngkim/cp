#include <iostream>

using namespace std;

int num(int N)
{
    int arr[1000001];
    arr[0] = 0; arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= N; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
    return arr[N];
}

int main()
{
    int N; cin >> N; cout << num(N);
    return 0;
}