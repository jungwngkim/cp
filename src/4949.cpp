#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    string s;

    while(getline(cin, s))
    {
        if(s == ".") break;

        stack<char> st;
        bool balanced = true;
        for(char &c : s)
        {
            if(c == ')')
            {
                if(st.empty() || st.top() == '[')
                {
                    balanced = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }

            if(c == ']')
            {
                if(st.empty() || st.top() == '(')
                {
                    balanced = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }

            if(c == '(' || c == '[')
            {
                st.push(c);
            }
        }

        cout << (balanced && st.empty() ? "yes\n" : "no\n");
    }
    
    return 0;
}