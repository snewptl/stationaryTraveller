#include<cstdio>
#include<algorithm>
#include<iostream>
#include<set>
typedef long long ll;
typedef std::pair<int, int> pii;
const int maxn = 1e3 + 5;
int n;
ll A[maxn][maxn];
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> A[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ll min = 1e18;
        for (int j = i; j <= n; ++j) {
            min = std::min(A[i][j], A[j][i]);
        }
        ans += min;
    }
    std::cout << ans << '\n';

}