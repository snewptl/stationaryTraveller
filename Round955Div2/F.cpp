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
const int maxn = 5e5 + 5;
int n, a[maxn], q, pos[maxn], val[maxn];
std::map<int, int> rank, used;
std::vector<int> vec;
namespace T {
    int N;
    struct node {
        int pre, nxt;
        int realSize;
    };
    node t[maxn << 2];
    void build(int rt, int l, int r) {
        if (l == r) {
            t[rt].realSize = used[l];
            t[rt]. 
            return;
        }
        int mid = l + r >> 1;
    }
    void del(int rt, int l, int r, int xp) {

    }
    void add(int rt, int l, int r, int xp) {

    }
    void update(int xp, int xval) {
        
    }
    void print() {
        if (t[1].realSize == N) std::cout << "-1 -1\n";
        else std::cout << t[1].pre + 1 << " " << n - t[1].nxt << '\n';
    }
};
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            vec.push_back(a[i]);
            used[a[i]] = 1;
        }
        std::cin >> q;
        for (int i = 1; i <= q; ++i) {
            std::cin >> pos[i] >> val[i];
            vec.push_back(pos[i]);
        }
        sort(all(vec));
        T::N = n + q;
        for (int i = 1; i <= T::N; ++i) {
            rank[vec[i - 1]] = i;
        }
        
        T::build(1, 1, T::N);
        T::print();
        for (int i = 1; i <= q; ++i) {
            T::update(pos[i], val[i]);
            T::print();
        }
    }

    return 0;
}
