#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    pair<int, int> arr[100];
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    sort(arr + 1, arr + 1 + N);

    int max_inc_num = 0, inc_num[100] = {0,};
    for (int i = 1; i <= N; i++)
    {
        int curr_inc_num = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            if(arr[j].second < arr[i].second && curr_inc_num < inc_num[j])
            {
                curr_inc_num = inc_num[j];
            }
        }
        inc_num[i] = curr_inc_num + 1;
        max_inc_num = max(max_inc_num, inc_num[i]);
    }

    cout << N - max_inc_num;
    
    return 0;
}