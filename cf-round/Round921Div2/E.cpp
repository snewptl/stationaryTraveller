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
const int maxn = 3e5 + 5;
int n, m, q;
struct Harbour {
    int position, value;
    Harbour() {
        position = 0;
        value = 0;
    }
    Harbour(int position, int value) {
        this->position = position;
        this->value = value;
    }
    bool isEmpty() { return this->position == 0; }
    void destroy() { position = value = 0; }
} harbours[maxn];
bool operator<(const Harbour& lhs, const Harbour& rhs) {
    return lhs.position < rhs.position;
}
std::set<Harbour> harbourSet;
struct Tree {
    int left, right;
    ll sum, coast;
    ll lazyDelta, lazyValue;
    int middle() { return (left + right) / 2; }
    // 只有子树内所有节点的右侧harbour相同才可以调该方法
    void updateCoast() { coast = sum * lazyValue; }
    void replaceValue(int newValue) {
        lazyValue = newValue;
        updateCoast();
    }
    void subtractSum(int dec) {
        // warning：wa2 爆int
        sum -= 1ll * (right - left + 1) * dec;
        lazyDelta += dec;
        updateCoast();
    }
} tree[maxn << 2];

void pushUp(int root) {
    tree[root].coast = tree[root << 1].coast + tree[root << 1 | 1].coast;
    tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
    // 只有两个子节点的lazyValue相同时，root的lazyValue才有意义
    tree[root].lazyValue =
        tree[root << 1].lazyValue == tree[root << 1 | 1].lazyValue
            ? tree[root << 1].lazyValue
            : 0;
}
void pushDown(int root) {
    if (tree[root].lazyDelta) {
        tree[root << 1].subtractSum(tree[root].lazyDelta);
        tree[root << 1 | 1].subtractSum(tree[root].lazyDelta);
        tree[root].lazyDelta = 0;
    }
    if (tree[root].lazyValue) {
        tree[root << 1].replaceValue(tree[root].lazyValue);
        tree[root << 1 | 1].replaceValue(tree[root].lazyValue);
    }
}
int getLeftValue(int position) {
    if (position == 1)
        return 0;
    auto it = harbourSet.lower_bound(Harbour(position, 0));
    --it;
    return it->value;
}
int getRightDistance(int position) {
    auto it = harbourSet.lower_bound(Harbour(position, 0));
    return it->position - position;
}
void build(int root, int left, int right) {
    tree[root].left = left;
    tree[root].right = right;
    if (left == right) {
        tree[root].lazyValue = getLeftValue(left);
        tree[root].sum = getRightDistance(left);
        tree[root].updateCoast();
        return;
    }
    int middle = (left + right) / 2;
    build(root << 1, left, middle);
    build(root << 1 | 1, middle + 1, right);
    pushUp(root);
}
void updateSum(int root,
               int left,
               int right,
               int queryLeft,
               int queryRight,
               int delta) {
    int middle = (left + right) / 2;
    if (left == queryLeft && right == queryRight) {
        tree[root].subtractSum(delta);
        tree[root].updateCoast();
        return;
    }
    pushDown(root);
    if (queryLeft <= middle)
        updateSum(root << 1, left, middle, queryLeft,
                  std::min(middle, queryRight), delta);
    if (queryRight > middle)
        updateSum(root << 1 | 1, middle + 1, right,
                  std::max(middle + 1, queryLeft), queryRight, delta);
    pushUp(root);
}
void updateValue(int root,
                 int left,
                 int right,
                 int queryLeft,
                 int queryRight,
                 int newValue) {
    int middle = (left + right) / 2;
    if (left == queryLeft && right == queryRight) {
        tree[root].replaceValue(newValue);
        tree[root].updateCoast();
        return;
    }
    pushDown(root);
    if (queryLeft <= middle)
        updateValue(root << 1, left, middle, queryLeft,
                    std::min(middle, queryRight), newValue);
    if (queryRight > middle)
        updateValue(root << 1 | 1, middle + 1, right,
                    std::max(middle + 1, queryLeft), queryRight, newValue);
    pushUp(root);
}

// warning: int -> ll
ll query(int root, int left, int right, int queryLeft, int queryRight) {
    int middle = (left + right) / 2;
    if (left == queryLeft && right == queryRight)
        return tree[root].coast;
    pushDown(root);
    ll result = 0;
    if (queryLeft <= middle)
        result += query(root << 1, left, middle, queryLeft,
                        std::min(middle, queryRight));
    if (queryRight > middle)
        result += query(root << 1 | 1, middle + 1, right,
                        std::max(middle + 1, queryLeft), queryRight);
    return result;
}
void addHarbour(Harbour newHarbour) {
    auto frontHarbour = harbourSet.lower_bound(newHarbour);
    auto nextHarbour = frontHarbour;
    --frontHarbour;
    int left = frontHarbour->position + 1, right = newHarbour.position;
    if (left <= right)
        updateSum(1, 1, n, left, right, nextHarbour->position - right);
    left = newHarbour.position + 1, right = nextHarbour->position;
    if (left <= right)
        updateValue(1, 1, n, left, right, newHarbour.value);
    harbourSet.insert(newHarbour);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n >> m >> q;
        for (int i = 1; i <= m; ++i) {
            std::cin >> harbours[i].position;
        }
        for (int i = 1; i <= m; ++i) {
            std::cin >> harbours[i].value;
        }
        for (int i = 1; i <= m; ++i) {
            harbourSet.insert(harbours[i]);
        }
        build(1, 1, n);
        while (q--) {
            int t, x, v;
            std::cin >> t >> x >> v;
            if (t == 1) {
                addHarbour(Harbour(x, v));
            } else {
                std::cout << query(1, 1, n, x, v) << '\n';
            }
        }
    }

    return 0;
}
/*
8 3 4
1 3 8
3 24 10
2 2 5
1 5 15
2 5 5
2 7 8
*/
