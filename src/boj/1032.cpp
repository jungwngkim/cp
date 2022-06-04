#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n, m;
    string s1, s2;
    
    cin >> n >> s1;
    m = s1.length();

    for(int i = 1; i < n; i++)
    {
        cin >> s2;
        for(int j = 0; j < m; j++)
        {
            if(s1[j] != s2[j]) s1[j] = '?';
        }
    }

    cout << s1;
    
    return 0;
}