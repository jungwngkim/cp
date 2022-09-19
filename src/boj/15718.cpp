#include <iostream>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    return 0;
}

// m = 4, n = 3
// 1 1 1 0
// -> m개 날짜에 n을 분배하는 방법의 개수
// if m == 0 -> 0
// if m == 1 -> 1
// if m == n -> 1

m n
1 1 -> 0
1 0 -> 1
2 2 -> 