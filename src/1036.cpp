#include <iostream>

using namespace std;

string num[50];
int weight[36];
int n, k, ans;

int idx(char c)
{
    if(c >= '0' && c <= '9') return c - '0'
    else return c - 'A' + 10;
}

int main()
{
    cin.tie(0);  
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> num[i];
    }

    while(k--)
    {
        change();
    }

    return 0;
}