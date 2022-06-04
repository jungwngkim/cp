#include <iostream>

using namespace std;

long long area(long long *h, int start, int end)
{
    if (start == end)
        return h[start];

    int mid = (start + end) / 2;
    long long left_area = area(h, start, mid), right_area = area(h, mid + 1, end);

    long long mid_area = h[mid], min_height = h[mid];
    int lo = mid - 1, hi = mid + 1;
    while (start <= lo && hi <= end)
    {
        if (h[lo] <= h[hi])
        {
            min_height = min(min_height, h[hi]);
            mid_area = max(mid_area, (hi - lo) * min_height);
            hi++;
        }
        else
        {
            min_height = min(min_height, h[lo]);
            mid_area = max(mid_area, (hi - lo) * min_height);
            lo--;
        }
    }

    while (hi <= end)
    {
        min_height = min(min_height, h[hi]);
        mid_area = max(mid_area, (hi - lo) * min_height);
        hi++;
    }

    while (start <= lo)
    {
        min_height = min(min_height, h[lo]);
        mid_area = max(mid_area, (hi - lo) * min_height);
        lo--;
    }

    return max(mid_area, max(left_area, right_area));
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        long long *h;
        h = (long long *)malloc(sizeof(long long) * n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        cout << area(h, 0, n - 1) << '\n';
    }

    return 0;
}