#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    Node *child[26];
    int word_cnt, child_cnt;
    bool finish;

    Node()
    {
        for(int c = 0; c < 26; c++) child[c] = nullptr;
        word_cnt = child_cnt = 0;
        finish = false;
    }

    ~Node()
    {
        for(int c = 0; c < 26; c++) if(child[c]) delete child[c];
    }
};

Node * root;

void insert(string s)
{
    Node * node = root;
    for(int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';

        if(!node->child[c])
        {
            node->child[c] = new Node();
            node->child_cnt++;
        }
        node->child[c]->word_cnt++;

        node = node->child[c];
    }
    node->finish = true;
}

int calc_cnt()
{
    int cnt = 0;

    queue<Node *> q;
    q.push(root);

    while(!q.empty())
    {
        Node * node = q.front();
        q.pop();

        if(node->finish || !cnt || node->child_cnt > 1)
        {
            for(int c = 0; c < 26; c++)
            {
                if(node->child[c])
                {
                    cnt += node->child[c]->word_cnt;
                }
            }
        }

        for(int c = 0; c < 26; c++)
        {
            if(node->child[c] && node->child[c]->word_cnt > 1)
            {
                q.push(node->child[c]);
            }
        }
    }

    return cnt;
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);
    cout.precision(2);
    cout << fixed;

    int n;
    while(cin >> n)
    {
        root = new Node();

        for(int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            insert(s);
        }

        cout << calc_cnt() / (double) n << '\n';

        delete root;
    }

    return 0;
}