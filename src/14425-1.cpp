#include <iostream>
#include <cstring>

using namespace std;

int trie[5010000][26], node_cnt;
bool finish[5010000][26];

void insert(string s)
{
    int node = 0;
    for(int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        if(trie[node][c] == -1) trie[node][c] = ++node_cnt;
        if(i == s.length() - 1) finish[node][c] = true;
        node = trie[node][c];
    }
}

bool search(string s)
{
    int node = 0;
    for(int i = 0; i < s.length(); i++)
    {
        int c = s[i] - 'a';
        if(trie[node][c] == -1) return false;
        if(i == s.length() - 1) return finish[node][c];
        node = trie[node][c];
    }

}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    memset(trie, -1, sizeof(trie));
    memset(finish, false, sizeof(finish));

    int n, m;
    cin >> n >> m;

    while(n--)
    {
        string s;
        cin >> s;
        insert(s);
    }

    int cnt = 0;
    while(m--)
    {
        string s;
        cin >> s;
        cnt += search(s);
    }
    cout << cnt;

    return 0;
}