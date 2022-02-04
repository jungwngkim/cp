#include <iostream>
#include <deque>

#define N 5000000

using namespace std;

int a[N], n, l;
deque<int> q;

int query()
{
    return q.front();
}

void push(int x)
{
    while(!q.empty() && q.back() > x)
    {
        q.pop_back();
    }
    q.push_back(x);
}

void pop(int x)
{
    if(!q.empty() && q.front() == x)
    {
        q.pop_front();
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < l; i++)
    {
        push(a[i]);
        cout << query() << ' ';
    }

    for(int i = l; i < n; i++)
    {
        pop(a[i - l]);
        push(a[i]);
        cout << query() << ' ';
    }
    
    return 0;
}