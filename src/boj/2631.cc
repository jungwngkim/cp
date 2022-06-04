#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; cin >> N;
    int arr[100000], len[100000];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int max_len = 1;
    for (int i = 0; i < N; i++)
    {
        len[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                len[i] = max(len[i], len[j] + 1);
            }
        }
        if(max_len < len[i])
        {
            max_len = len[i];
        }
    }

    cout << N - max_len << endl;

    return 0;
}