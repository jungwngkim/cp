#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for(char c : s) {
        if(c <= 'Z') cout << (char) (c - 'A' + 'a');
        else cout << (char) (c - 'a' + 'A');
    }
    return 0;
}