#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int t = 0;
    while(true) 
    {    
        t++;
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        vector<int> p(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < m; i++)
        {
            int v, w;
            cin >> v >> w;
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        int tree_count = 0;
        for(int i = 1; i <= n; i++)
        {
            int is_tree = 1;
            if(p[i] == 0)
            {
                queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int v = q.front();
                    q.pop();

                    for(int w : adj[v])
                    {
                        if(p[v] == w) continue;
                        else if(p[w] == 0)
                        {
                            p[w] = v;
                            q.push(w);
                        }
                        else is_tree = 0;
                    }
                }
            }
            else
            {
                is_tree = 0;
            }
            tree_count += is_tree;
        }

        cout << "Case " << t << ": ";
        if(tree_count == 0) cout << "No trees.";
        else if (tree_count == 1) cout << "There is one tree.";
        else cout << "A forest of " << tree_count << " trees.";
        cout << '\n';
    }
    return 0;
}