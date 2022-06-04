#include <iostream>

using namespace std;

int n, ans;
char b[10][3];

int h_count;
bool h_valid[10][10][10], g_used;

bool check_1(int i, int x1, int x2, int x3) {
	return (b[x1][i] == b[x2][i] && b[x2][i] == b[x3][i] && b[x3][i] == b[x1][i]) ||
		(b[x1][i] != b[x2][i] && b[x2][i] != b[x3][i] && b[x3][i] != b[x1][i]);
}

bool check_3(int x1, int x2, int x3) {
	return check_1(0, x1, x2, x3) && check_1(1, x1, x2, x3) && check_1(2, x1, x2, x3);
}

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);

	for(int i = 1; i <= 9; i++) {
		string s;
		cin >> s;
		b[i][0] = s[0];
		cin >> s;
		b[i][1] = s[0];
		cin >> s;
		b[i][2] = s[0];
	}

	for(int x1 = 1; x1 <= 9; x1++) {
		for(int x2 = x1 + 1; x2 <= 9; x2++) {
			for(int x3 = x2 + 1; x3 <= 9; x3++) {
				if(check_3(x1, x2, x3)) {
					h_valid[x1][x2][x3] = true;
					h_count++;
					// cout << x1 << ' ' << x2 << ' ' << x3 << '\n';
				}
			}
		}
	}

	cin >> n;
	while(n--) {
		char q;
		int x1, x2, x3;
		cin >> q;

		if(q == 'H') {
			cin >> x1 >> x2 >> x3;
			if(x3 < x2) swap(x2, x3);
			if(x2 < x1) swap(x1, x2);
			if(x3 < x2) swap(x2, x3);

			if(h_valid[x1][x2][x3]) {
				h_valid[x1][x2][x3] = false;
				h_count--;
				ans++;
			}
			else {
				ans--;
			}
		}
		else {
			if(!g_used && h_count == 0) {
				g_used = true;
				ans += 3;
			}
			else {
				ans--;
			}
		}
	}

	cout << ans;
    
    return 0;
}