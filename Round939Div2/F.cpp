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
const int maxn = 4e6 + 5;
int n;
pii seg[maxn];
int leftHand[maxn], rightHand[maxn], disabled[maxn], link[maxn];
int nextAble[maxn];
int ans, vis[maxn];
std::vector<int> e[maxn];
pii intersection(pii x) {
    return {std::max(n + 1, x.first), std::min(n * 2, x.second)};
}
void clear() {
    for (int i = 0; i <= 2 * n + 1; ++i) {
        disabled[i] = 0;
        leftHand[i] = rightHand[i] = 0;
        link[i] = 0;
        e[i].clear();
        vis[i] = 0;
        nextAble[i] = 0;
    }
    ans = 0;
}
void addEdge(int u, int v) {
    e[u].push_back(v);
    e[v].push_back(u);
}
void bfs(int u) {
    std::queue<int> q;
    vis[u] = 1;
    q.push(u);
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        for (auto v : e[it]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = 1;
        }
    }
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        ans++;
        bfs(i);    
    }
    std::cout << ans << '\n';
}
void getDisabledList() {
    for (int i = 1; i <= n; ++i) {
        pii leftSeg = {i - seg[i].second + n, i - seg[i].first + n};
        pii rightSeg = {i + seg[i].first + n, i + seg[i].second + n};
        if (leftSeg.first <= leftSeg.second) {
            leftHand[leftSeg.first]++;
            leftHand[leftSeg.second + 1]--;
        }
        if (rightSeg.first <= rightSeg.second) {
            rightHand[rightSeg.first]++;
            rightHand[rightSeg.second + 1]--;
        }
    }
    int leftHandStatus = 0, rightHandStatus = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
        leftHandStatus += leftHand[i];
        rightHandStatus += rightHand[i];
        if (!leftHandStatus || !rightHandStatus) disabled[i] = 1;
    }
    for (int i = 2 * n; i >= n + 1; --i) {
        if (disabled[i]) {
            if (i == n * 2) {
                nextAble[i] = 0;
            } else {
                nextAble[i] = nextAble[i + 1];
            }
        } else {
            nextAble[i] = i;
        }
    }
}
void linkEdges() {
    for (int i = 1; i <= n; ++i) {
        pii leftSeg = {i - seg[i].second + n, i - seg[i].first + n};
        pii rightSeg = {i + seg[i].first + n, i + seg[i].second + n};
        if (nextAble[leftSeg.first] && nextAble[leftSeg.first] <= leftSeg.second) {
            addEdge(i, nextAble[leftSeg.first]);
                    if (leftSeg.first < leftSeg.second) {
            link[leftSeg.first]++;
            link[leftSeg.second]--;
        }
        }
        if (nextAble[rightSeg.first] && nextAble[rightSeg.first] <= rightSeg.second) {
            addEdge(i, nextAble[rightSeg.first]);
            if (rightSeg.first < rightSeg.second) {
                link[rightSeg.first]++;
                link[rightSeg.second]--;
            }
        }
    }
    for (int i = n + 2; i <= n * 2; ++i) {
        link[i] += link[i - 1];
    }
    for (int i = n + 1; i < n * 2; ++i) {
        if (link[i]) addEdge(i, i + 1);
    }
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
        std::cin >> n;
        getDisabledList();
        linkEdges();
        solve();
        clear();
    }

    return 0;
}
