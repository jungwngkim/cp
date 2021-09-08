#include <iostream>

using namespace std;

bool parse_able(int code)
{
    if (code % 10 == 0)
    {
        if (code == 10 || code == 20)
            return true;
        else
            return false;
    }

    return true;
}

int code_num(int code)
{
    if (!parse_able(code))
        return 0;

    if (code / 10 == 0 || code > 26) // 1 digit or over 26
        return 1;
    else // 2 digit under 26
        return 2;
}

int main()
{
    int ans = 0, dp[5000];
    string s;
    cin >> s;

    if (s[0] == '0')
    {
        cout << 0;
        return 0;
    }

    if (s.length() <= 2)
    {
        cout << code_num(stoi(s));
        return 0;
    }

    dp[0] = 1;
    dp[1] = code_num(stoi(s.substr(0, 2)));

    if (dp[1] == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i < s.length(); i++)
    {
        int ten = s[i - 1] - '0', one = s[i] - '0';
        int num = ten * 10 + one;

        if (!parse_able(num))
        {
            ans = 0;
            break;
        }

        if (num % 10 == 0)
            dp[i] = dp[i - 2];
        else if (num <= 26)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1];

        ans = dp[i] %= 1000000;
    }

    cout << ans;

    return 0;
}