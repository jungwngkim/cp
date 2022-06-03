#include <iostream>
#include <map>

using namespace std;

int n, m;
string str;
map<string, int> str_to_int;
string int_to_str[100001];

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> str;
        str_to_int[str] = i;
        int_to_str[i] = str;
    }

    while(m--) {
        cin >> str;
        if(str[0] >= '0' && str[0] <= '9') {
            cout << int_to_str[stoi(str)] << '\n';
        }
        else {
            cout << str_to_int[str] << '\n';
        }
    }
    
    return 0;
}