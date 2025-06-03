#include <bits/stdc++.h>

using namespace std;

vector<set<int>> graph;
vector<int> ans;

void dfs(int v) {
    while (!graph[v].empty()) {
        int u = *graph[v].begin();
        graph[u].erase(v);
        graph[v].erase(u);
        dfs(u);
    }
    ans.push_back(v);
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        graph.clear();
        ans.clear();
        int n;
        cin >> n;
        map<int, int> p, v;
        map<pair<int, int>, int> toIndex;
        vector<pair<int, int>> part;
        for (int i = 1; i <= n; ++i) {
            int volume, pitch;
            cin >> volume >> pitch;
            toIndex[make_pair(volume, pitch)] = i;
            if (p.count(pitch) == 0) {
                p[pitch] = graph.size();
                graph.push_back(set<int>());
                part.push_back(make_pair(0, pitch));
            }
            if (v.count(volume) == 0) {
                v[volume] = graph.size();
                graph.push_back(set<int>());
                part.push_back(make_pair(volume, 0));
            }
            graph[v[volume]].insert(p[pitch]);
            graph[p[pitch]].insert(v[volume]);
        }
        int root = 0;
        int cnt = 0;
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i].size() % 2 == 1) {
                ++cnt;
                root = i;
            }
        }
        dfs(root);
        if (ans.size() != n + 1 || cnt > 2) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> out;
        for (int i = 0; i < n; ++i) {
            auto p1 = part[ans[i]];
            auto p2 = part[ans[i + 1]];
            out.push_back(toIndex[make_pair(p1.first + p2.first, p1.second + p2.second)]);
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << out[i] << " ";
        }
        cout << endl;
    }
    return 0;
}