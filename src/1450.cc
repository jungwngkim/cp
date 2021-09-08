#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;

void sum_all(vector<long long> num, vector<long long> *sum, long long curr_sum, int curr_idx, int max_idx)
{
    if (curr_idx == max_idx)
    {
        (*sum).push_back(curr_sum);
        return;
    }

    sum_all(num, sum, curr_sum, curr_idx + 1, max_idx);
    sum_all(num, sum, curr_sum + num[curr_idx], curr_idx + 1, max_idx);
}

int main()
{
    cin >> N >> C;
    int l_cnt = N / 2;
    int r_cnt = N - l_cnt;

    vector<long long> l_num, r_num;
    for (int i = 0; i < l_cnt; i++)
    {
        long long t;
        cin >> t;
        l_num.push_back(t);
    }
    for (int i = 0; i < r_cnt; i++)
    {
        long long t;
        cin >> t;
        r_num.push_back(t);
    }
    
    vector<long long> l_sum, r_sum;
    sum_all(l_num, &l_sum, 0, 0, l_cnt);
    sum_all(r_num, &r_sum, 0, 0, r_cnt);

    sort(r_sum.begin(), r_sum.end());

    int cnt = 0;
    for(long long l_el : l_sum)
    {
        cnt += upper_bound(r_sum.begin(), r_sum.end(), C - l_el) - r_sum.begin();
    }
    cout << cnt;
    return 0;
}