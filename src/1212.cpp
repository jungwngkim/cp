#include <iostream>

using namespace std;

string bin[8] = {
    "000",
    "001",
    "010",
    "011",
    "100",
    "101",
    "110",
    "111"
};

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s, ans = "";
    cin >> s;

    if(s == "0") cout << 0;
    else
    {
        for(char c : s)
        {
            ans += bin[c - '0'];
        }

        while(ans[0] == '0')
        {
            ans = ans.substr(1);
        }
        
        cout << ans;
    }
   
    return 0;
}