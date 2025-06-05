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