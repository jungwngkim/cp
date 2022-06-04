/*
boolean 배열로 
avaliable[31][40001]
avaliable[0][0] = true
이렇게 시작

모든 추를 입력받아서 크기 역순으로 정렬
모든 추에 대해서 avaliable[i-1][j]에 true가 있으면 j + - weight[i] index에다가 true로 표시
나중에 입력받는 구슬에 대해서 avaliable[marble][1-n]에 query해서 하나라도 true면 true
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool cmp(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int n, m, w[30];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    sort(w, w + n, cmp);

    set<int> s = {0};
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int el : s)
        {
            v.push_back(el + w[i]);
            v.push_back(el - w[i]);
        }
        s.insert(v.begin(), v.end());
    }

    scanf("%d", &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        printf("%c ", *s.lower_bound(x) == x ? 'Y' : 'N');
    }

    return 0;
}