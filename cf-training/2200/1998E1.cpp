#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, x;
int a[maxn];
std::pair<ll, pii> seq[maxn];
pli go_right[maxn];
ll sum[maxn];
void solve() {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = n; i >= 1; --i) {
        go_right[i] = {a[i], i};
        while (go_right[i].second < n && go_right[i].first >= a[go_right[i].second + 1]) {
            go_right[i].first += go_right[go_right[i].second + 1].first;
            go_right[i].second = go_right[go_right[i].second + 1].second;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        seq[i] = {go_right[i].first, {i, go_right[i].second}};
        int flag = 1;
        while (flag) {
            flag = 0;
            int left_wall = seq[i].second.first - 1;
            int right_wall = seq[i].second.second + 1;
            if (right_wall <= n && seq[i].first >= a[right_wall]) {
                flag = 1;
                seq[i].first += go_right[right_wall].first;
                seq[i].second.second = go_right[right_wall].second;
            }
            if (left_wall > 0 && seq[i].first >= a[left_wall]) {
                flag = 1;
                if (seq[left_wall].second.second >= i) {
                    seq[i] = seq[left_wall];
                    break;
                } else {
                    seq[i].first += seq[left_wall].first;
                    seq[i].first -= sum[seq[left_wall].second.second] - sum[left_wall];
                    seq[i].second.first = seq[left_wall].second.first;
                    seq[i].second.second = std::max(seq[i].second.second, seq[left_wall].second.second);
                }
            }
        }
        if (seq[i].second.first == 1 && seq[i].second.second == n) ++ans;
    }
    std::cout << ans << '\n';
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        solve();
    }

    return 0;
}