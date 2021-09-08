#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    int count = 1;
    int prev = 1;
    bool isUp = true;
    for (int i = 0; i < N; i++)
    {
        int next;
        cin >> next;
        if (isUp && (prev > next))
        {
            count++;
            isUp = false;
        }
        if (!isUp && (prev < next))
        {
            count++;
            isUp = true;
        }
        prev = next;
    }

    cout << ceil(log2(count));
    return 0;
}
