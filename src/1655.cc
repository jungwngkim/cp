#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    int n;
    scanf("%d", &n);
    while (n--)
    {
        int num;
        scanf("%d", &num);

        if (max_heap.empty())
        {
            max_heap.push(num);
        }
        else
        {
            if (max_heap.size() == min_heap.size())
            {
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
            }

            if (max_heap.top() > min_heap.top())
            {
                int max_top = max_heap.top();
                int min_top = min_heap.top();

                max_heap.pop();
                min_heap.pop();

                max_heap.push(min_top);
                min_heap.push(max_top);
            }
        }

        printf("%d\n", max_heap.top());
    }

    return 0;
}