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
int n, a[maxn];
std::vector<pii> operations;
void update(int l, int r) {
    std::vector<int> vec;
    for (int i = l; i <= r; ++i) {
        vec.push_back(a[i]);
    }
    std::sort(all(vec));
    int mex = 0;
    for (int i = 0; i < r - l + 1; ++i) {
        if (mex == vec[i]) ++mex;
        else break;
    }
    for (int i = l; i <= r; ++i) {
        a[i] = mex;
    }
}
void pushOperation(int l, int r) {
    operations.push_back({l, r});
    update(l, r);
}
void clear(int l, int r) {
    pushOperation(l, r);
    if (a[l]) pushOperation(l, r);
}
void fromZero2Sequence(int l, int r){
    if (l == r) {
        return;
    }
    fromZero2Sequence(l, r - 1);
    pushOperation(l, r);
    clear(l, r - 1);
    fromZero2Sequence(l, r - 1);
}
void addOperations(int l, int r, int isFirstDivIn) {
    if (l == r && isFirstDivIn) {
        if (!a[l]) pushOperation(l, l);
        else return;
    } else {
        clear(l, r);
        fromZero2Sequence(l, r);
        pushOperation(l, r);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        operations.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        pii dp[20][20];
        dp[0][0] = {0, 0};
        for (int i = 1; i <= n; ++i) {
            int val = 0;
            int pos = 0;
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j - 1];
                int newVal = 0;
                if (j > 1) {
                    newVal = dp[i - 1][j - 1].first + j * j;
                } else {
                    newVal = dp[i - 1][0].first + std::max(1, a[i]);
                }
                if (val < newVal) {
                    val = newVal;
                    pos = i - 1 - (j - 1);
                }
            }
            dp[i][0] = {val, pos};
        }
        int pos = n;
        while(pos) {
            int next = dp[pos][0].second;
            addOperations(next + 1, pos, 1);
            pos = next;
        }
        std::cout << dp[n][0].first << ' ' << operations.size() << '\n';
        for (auto it : operations) {
            std::cout << it.first << ' ' << it.second << '\n';
        }
        // std::cout << "=======\n"; 
        // for (int i = 1; i <= n; ++i) {
        //     std::cout << a[i] << ' ';
        // }
        // std::cout << '\n';
    }

    return 0;
}
