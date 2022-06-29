#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int abs(int a)
{ 
    return a > 0 ? a : -a;
}

int main()
{
    auto cmp = [](int left, int right) {
        if(abs(left) == abs(right))
        {
            return left > right;
        }
        return abs(left) > abs(right);
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int op;
        scanf("%d", &op);
        if(op == 0)
        {
            if(pq.empty())
            {
                printf("0\n");
            }
            else 
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else 
        {
            pq.push(op);
        }
    }
    return 0;
}