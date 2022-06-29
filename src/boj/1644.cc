#include <iostream>
#include <vector>

using namespace std;

int N;
bool isPrime[4000001];
vector<int> primes;
int main()
{
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i + i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.push_back(0);
    int lo = 0, hi = 0, sum = 0, cnt = 0;
    while (hi <= primes.size())
    {
        if (sum >= N)
            sum -= primes[lo++];
        else
            sum += primes[hi++];

        if (sum == N)
            cnt++;
    }
    cout << cnt;

    return 0;
}