#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 100;
vector <pair <int, int>> g[N];
int val[N];

vector <int> ans;
map <int, int> cnt1, cnt2;
set <int> mad1, mad2;

vector <int> path, path_ind;
bool used[N];


bool dfs(int v, int tar) {
    used[v] = true;
    path.push_back(v);
    if (v == tar) {
        return true;
    }
    for (auto [i, ind] : g[v]) {
        if (!used[i]) {
            path_ind.push_back(ind);
            if (dfs(i, tar)) {
                return true;
            }
            path_ind.pop_back();
        }
    }
    path.pop_back();
    return false;
}


int mad() {
    int mx = 0;
    if (!mad1.empty()) {
        mx = max(mx, *mad1.rbegin());
    }
    if (!mad2.empty()) {
        mx = max(mx, *mad2.rbegin());
    }
    return mx;
}


void recalc(int v, int ban1, int ban2) {
    cnt1[val[v]]++;
    if (cnt1[val[v]] == 2) {
        mad1.insert(val[v]);
    }
    cnt2[val[v]]--;
    if (cnt2[val[v]] == 1) {
        mad2.erase(val[v]);
    }
    for (auto [i, _] : g[v]) {
        if (i != ban1 && i != ban2) {
            recalc(i, v, -1);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }

    map <int, vector <int>> ind;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        ind[val[i]].push_back(i);
        cnt2[val[i]]++;
        if (cnt2[val[i]] == 2) {
            mad2.insert(val[i]);
        }
    }

    while (!ind.empty() && ind.rbegin() -> second.size() == 1) {
        ind.erase(prev(ind.end()));
    }
    if (ind.empty()) {
        for (int i = 0; i < n - 1; i++) {
            cout << "0\n";
        }
        return 0;
    } else if (ind.rbegin()->second.size() > 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << ind.rbegin() -> first << "\n";
        }
        return 0;
    }

    int a = ind.rbegin()->second[0], b = ind.rbegin()->second[1];
    dfs(a, b);

    ans.assign(n - 1, ind.rbegin() -> first);
    recalc(path[0], path[1], -1);
    ans[path_ind[0]] = mad();

    for (int i = 1; i + 1 < path.size(); i++) {
        recalc(path[i], path[i - 1], path[i + 1]);
        ans[path_ind[i]] = mad();
    }

    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}