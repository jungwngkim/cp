#include <iostream>

using namespace std;

inline int calc(int a, char op, int b)
{
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else return a / b;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; 
    cin >> n;

    int a[2][2] = { {1, 1}, {1, 1} };

    int i;
    for(i = 0; i < n; i++)
    {
        char op1, op2;
        int x1, x2;

        cin >> op1 >> x1 >> op2 >> x2;

        if(a[0][0] > 0)
        {
            a[1][0] = max(calc(a[0][0], op1, x1), calc(a[0][0], op2, x2));
            a[1][1] = max(max(calc(a[0][1], op1, x1), calc(a[0][1], op2, x2)), a[0][0]);

            a[0][0] = a[1][0];
            a[0][1] = a[1][1];
        }
        else
        {
            a[1][1] = max(calc(a[0][1], op1, x1), calc(a[0][1], op2, x2));
            
            a[0][1] = a[1][1];
        }

        if(a[0][0] <= 0 && a[0][1] <= 0) break;
    }

    if(i < n) cout << "ddong game";
    else cout << max(a[0][0], a[0][1]);

    return 0;
}