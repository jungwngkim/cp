#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000], N;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int lo = 0, hi = N - 1, ans_lo = 0, ans_hi = N - 1;
    while(lo < hi)
    {
        if(abs(arr[lo] + arr[hi]) < abs(arr[ans_lo] + arr[ans_hi]))
        {
            ans_lo = lo;
            ans_hi = hi;
        }

        if(arr[lo] + arr[hi] > 0) {
            hi--;
        }
        else if(arr[lo] + arr[hi] < 0)
        {
            lo++;
        }
        else
        {
            ans_lo = lo;
            ans_hi = hi;
            break;
        }
    }
    
    cout << arr[ans_lo] << ' ' << arr[ans_hi];
    
    return 0;
}