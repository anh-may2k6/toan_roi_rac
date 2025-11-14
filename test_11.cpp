#include <bits/stdc++.h>
using namespace std;

int x[100], k;  // x[] là phân tích, k là số phần tử

bool sinh() {
    int i = k;
    // Tìm phần tử bên phải cùng > 1 để giảm nó đi
    while (i > 0 && x[i] == 1) i--;
    if (i == 0) return false;  // đã là phân tích cuối cùng (toàn 1)

    x[i]--;           // giảm phần tử đó
    int d = k - i + 1;  // tổng phần bị giảm ra (số lượng phần tử 1 bị bỏ)
    int sum = d;        // tổng số 1 trước kia

    // Chia lại sum cho x[i]
    int q = sum / x[i];
    int r = sum % x[i];

    k = i;  // reset độ dài

    // Gán q lần x[i]
    for (int j = 1; j <= q; j++) x[++k] = x[i];

    // Nếu còn dư, thêm 1 phần tử bằng r
    if (r > 0) x[++k] = r;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    k = 1;
    x[1] = n;

    do {
        for (int i = 1; i <= k; i++) cout << x[i] << " ";
        cout << "\n";
    } while (sinh());
}
