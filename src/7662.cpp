#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k, n;
        char c;
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        map<int, int> maxcnt, mincnt;

        cin >> k;
        while(k--)
        {
            cin >> c >> n;
            if(!mincnt.count(n)) mincnt.insert({ n, 0 });
            if(!maxcnt.count(n)) maxcnt.insert({ n, 0 });

            if(c == 'I')
            {
                minq.push(n);
                maxq.push(n);
            }
            else
            {
                if(n == 1 && !maxq.empty())
                {
                    mincnt[maxq.top()]++;
                    maxq.pop();
                }
                
                if(n == -1 && !minq.empty())
                {
                    maxcnt[minq.top()]++;
                    minq.pop();
                }

                while(!minq.empty() && mincnt[minq.top()]) 
                {
                    mincnt[minq.top()]--;
                    minq.pop();
                }

                while(!maxq.empty() && maxcnt[maxq.top()]) 
                {
                    maxcnt[maxq.top()]--;
                    maxq.pop();
                }
            }
        }

        while(!minq.empty() && mincnt[minq.top()]) 
        {
            mincnt[minq.top()]--;
            minq.pop();
        }

        while(!maxq.empty() && maxcnt[maxq.top()]) 
        {
            maxcnt[maxq.top()]--;
            maxq.pop();
        }

        if(minq.empty() || maxq.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << maxq.top() << ' ' << minq.top() << '\n';
        }
    }
    
    return 0;
}