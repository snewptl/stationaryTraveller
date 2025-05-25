#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxN = 2e5 + 5;
struct TreeNode {
    std::array<int, 4> basicVec;
    std::array<int, 4> sumVec;
};
class Tree {
   public:
    int N;
    TreeNode t[maxN << 2];
    void build(int rt, int l, int r) {}
    void updateSelf(int rt, int l, int r, int queryL, int queryR, int x) {}
    void updateSelf(int rt, int l, int r, int queryL, int queryR, int x) {}
    void query(int rt, int l, int r, int queryL, int queryR) {}
} trees[2];
int n, m, q;
ll a[maxN], b[maxN];
void update(int opt, int l, int r, int x) {
    // trees[opt].updateSelf(1, 1, trees[opt].N, l, r, x);
    // trees[opt^1].reCalculate(1, 1, trees[opt].N);
}
ll getAns() {
    return trees[0].t[1].sum[]
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= m; ++i)
            std::cin >> b[i];
        trees[0].N = n, trees[1].N = m;
        for (int i = 0; i < 2; ++i)
            trees[0].build(1, 1, trees[i].N);
        while (q--) {
            int t, l, r;
            ll x;
            std::cin >> t >> l >> r >> x;
            --t;
            update(t, l, r, x);
            std::cout << getAns() << '\n';
        }
    }

    return 0;
}
