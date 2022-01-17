#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int sum = 0, num;
    for(int i = 0; i < 5; i++)
    {
        cin >> num;
        sum += num * num % 10;
    }
    cout << sum % 10;
    
    return 0;
}