#include <iostream>
#include <map>

using namespace std;

struct Node 
{
    map<string, Node> children;
};

void print_trie(Node & node, int depth)
{
    for(pair<string, Node> child : node.children)
    {
        for(int i = 0; i < depth; i++) cout << "--";
        cout << child.first << '\n';
        print_trie(child.second, depth + 1);
    }
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    Node root = Node();

    int n; cin >> n;
    while(n--)
    {
        int k; cin >> k;
        Node * node = &root;
        while(k--)
        {
            string s; cin >> s;
            if(!node->children.count(s)) node->children[s] = Node();
            node = &node->children[s];
        }
    }

    print_trie(root, 0);

    return 0;
}