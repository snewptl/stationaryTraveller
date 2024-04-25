#include <bits/stdc++.h>
#define all(x) x.begin(), (x).end()

using namespace std;

const int M = 1000000007;
long long ans = 0;
int real_len = 0;


long long binpow(long long a, int x) {
    long long ans0 = 1;
    while (x) {
        if (x % 2) {
            ans0 *= a;
            ans0 %= M;
        }
        a *= a;
        a %= M;
        x /= 2;
    }
    return ans0;
}


void chill(vector<int> &b) {
    int mn = b[0];
    ans += (int) ((long long) mn * binpow(2, real_len - 1) % M);
    if (ans >= M) {
        ans -= M;
    }
    for (auto &x : b) {
        x -= mn;
    }
}


void F(vector<int> &b, int sub = 0) {
    --real_len;
    vector<int> cnd;
    for (int i = 0; i < b.size(); i++) {
        for (int j = i + 1; j < b.size(); j++) {
            if (i * j >= b.size()) break;
            cnd.push_back(b[i] + b[j]);
        }
    }
    sort(all(cnd));
    vector<int> b2((int) b.size() - sub);
    for (int i = 0; i < (int) b.size() - sub; i++) {
        b2[i] = cnd[i];
    }
    chill(b2);
    b = b2;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int L = 64;
    vector<int> b(min(n, L));
    for (int i = 0; i < min(n, L); i++) {
        b[i] = a[i];
    }
    real_len = n;
    chill(b);
    while (b.size() < real_len) {
        if (b[1] + b[2] > b.back()) {
            F(b, 1);
            F(b, 1);
        } else {
            F(b);
        }
    }
    while (real_len > 1) {
        F(b, 1);
    }
    ans += b[0];
    ans %= M;
    cout << ans << '\n';
}