#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int sum;
    cin >> sum;

    bool is_negative = false;

    char op;
    int num;
    while(cin >> op >> num)
    {
        if(op == '-') is_negative = true;
        if(is_negative) sum -= num;
        else sum += num;
    }
    cout << sum;
    
    return 0;
}