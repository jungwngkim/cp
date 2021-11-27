#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    string a[20000];
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a + N, cmp);
    for (int i = 0; i < N; i++)
        if (i == 0 || a[i] != a[i - 1])
            cout << a[i] << '\n';

    return 0;
}