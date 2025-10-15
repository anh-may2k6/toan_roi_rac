// Liệt kê các tập con k phần tử của {1, 2, ..., n}
// Quay lui (Backtracking)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("input.in");
ofstream out("output.in");

int n, k;
vector<int> a;

void back_track(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            for (int q = 1; q <= k; q++) out << a[q];
            out << "\n";
        } else {
            back_track(i + 1);
        }
    }
}

void test_case() {
    in >> n >> k;
    a.assign(k + 1, 0); // khởi tạo mảng a
    back_track(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    in >> t;
    while (t--) {
        test_case();
        out << '\n'; // cách dòng giữa các test
    }
    return 0;
}
