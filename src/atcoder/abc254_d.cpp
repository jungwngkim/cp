#include <iostream>
#include <vector>

using namespace std;

int n, ans;
int cnt[200000];
vector<int> factorize[200000];

vector<int> primes;
bool is_prime[200000];

void get_primes(){
    for(int i = 2; i < 200000; i++){
        if(is_prime[i]) continue;
        primes.push_back(i);
        for(int j = i; j < 200000; j += i) {
            is_prime[j] = true;
            factorize[j].push_back(i);
        }
    }
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    get_primes();

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int mul = 1;
        for(int x : factorize[i]) {
            int cnt = 0, t = i;
            while(t > 1 && t % x == 0) {
                t /= x;
                cnt++;
            }
            if(cnt & 1) mul *= x;
        }

        ans += 2 * cnt[mul];
        cnt[mul]++;
    }

    cout << ans + n;

    return 0;
}