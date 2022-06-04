#include <iostream>
#include <set>

using namespace std;

int n1, n2;
set<int> s;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n1 >> n2;

    int t;
    while(n1--) {
        cin >> t;
        s.insert(t);
    }

    while(n2--) {
        cin >> t;
        if(s.count(t)) {
            s.erase(t);
        }
        else {
            s.insert(t);
        }
    }

    cout << s.size();
    
    return 0;
}