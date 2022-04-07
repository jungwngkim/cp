#include <iostream>
#include <map>

using namespace std;

map<string, int> table = {
    { "black", 0 },
    { "brown", 1 },
    { "red", 2 },
    { "orange", 3 },
    { "yellow", 4 },
    { "green", 5 },
    { "blue", 6 },
    { "violet", 7 },
    { "grey", 8 },
    { "white", 9 }
};

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    int n1, n2, n3;
    string s;
    
    cin >> s;
    n1 = table[s];

    cin >> s;
    n2 = table[s];

    cin >> s;
    n3 = table[s];

    if(n1)
    {
        cout << n1 << n2;
        for(int i = 0; i < n3; i++) cout << 0;
    }
    else
    {
        if(n2)
        {
            cout << n2;
            for(int i = 0; i < n3; i++) cout << 0;
        }
        else
        {
            cout << 0;
        }
    }

    return 0;
}