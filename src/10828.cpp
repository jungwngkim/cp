#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    stack<int> st;
    string op;

    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == "push") 
        {
            cin >> x;
            st.push(x);
        }
        else if(op == "pop")
        {
            if(st.empty()) cout << "-1\n";
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(op == "size") cout << st.size() << '\n';
        else if(op == "empty") cout << st.empty() << '\n';
        else
        {
            if(st.empty()) cout << "-1\n";
            else cout << st.top() << '\n';
        }
    }
    
    return 0;
}