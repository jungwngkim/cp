#include <iostream>

using namespace std;

long long a0[3], a1[3], a2[3], b[3], A, A0, A1, A2;
double x0, x1, x2;

long long det(long long c0[], long long c1[], long long c2[]) {
    return c0[0] * (c1[1] * c2[2] - c2[1] * c1[2]) - c1[0] * (c0[1] * c2[2] - c2[1] * c0[2]) + c2[0] * (c0[1] * c1[2] - c1[1] * c0[2]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> a0[i] >> a1[i] >> a2[i] >> b[i];
        }

        A0 = det(b, a1, a2);
        A1 = det(a0, b, a2);
        A2 = det(a0, a1, b);
        A = det(a0, a1, a2);

        cout << A0 << ' ' << A1 << ' ' << A2 << ' ' << A << ' ' << '\n';
        if (A) {
            x0 = A0 / (double)A;
            x1 = A1 / (double)A;
            x2 = A2 / (double)A;

            if (x0 > -0.0005 && x0 < 0.0005) x0 = 0;
            if (x1 > -0.0005 && x1 < 0.0005) x1 = 0;
            if (x2 > -0.0005 && x2 < 0.0005) x2 = 0;

            printf("Unique solution: %.3f %.3f %.3f\n\n", x0, x1, x2);
        } else {
            printf("No unique solution\n\n");
        }
    }

    return 0;
}