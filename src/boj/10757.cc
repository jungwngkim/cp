#include <iostream>

using namespace std;

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

void string_sum(string s1, string s2)
{
    reverseStr(s1);
    reverseStr(s2);

    int length = s1.length() > s2.length() ? s1.length() : s2.length();

    // array 1, array 2, array sum
    int a1[length + 1], a2[length + 1], as[length + 1];

    for (int i = 0; i <= length; i++)
    {
        a1[i] = i < s1.length() ? s1[i] - '0' : 0;
        a2[i] = i < s2.length() ? s2[i] - '0' : 0;
    }

    int carry = 0;
    for (int i = 0; i <= length; i++)
    {
        as[i] = a1[i] + a2[i] + carry;
        carry = as[i] / 10;
        as[i] = as[i] % 10;
    }

    if (as[length] != 0)
    {
        cout << as[length];
    }
    for (int i = length - 1; i >= 0; i--)
    {
        cout << as[i];
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string_sum(s1, s2);

    return 0;
}