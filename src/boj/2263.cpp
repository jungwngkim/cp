#include <iostream>

using namespace std;

int in_idx[100001], post[100001], n;

void pre(int in_left, int in_right, int post_left, int post_right)
{
    if(in_left > in_right) return;

    cout << post[post_right] << ' ';
    int in_parent = in_idx[post[post_right]];
    int left_size = in_parent - in_left;
    int right_size = in_right - in_parent;

    pre(in_left, in_parent - 1, post_left, post_left + left_size - 1);
    pre(in_parent + 1, in_right, post_right - right_size, post_right - 1);
} 

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        int t;
        cin >> t;
        in_idx[t] = i;
    }
    for(int i = 1; i <= n; i++) cin >> post[i];
    pre(1, n, 1, n);
    return 0;
}