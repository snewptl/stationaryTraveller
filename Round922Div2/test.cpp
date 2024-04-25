#include <vector>
#include <iostream>
#include <queue>
 
using ll = long long;
 
const int N = 3e5;
 
int g_n;
ll g_a[N];
ll g_v[N];
int g_b[N];
 
class DAG {
public:
    DAG() :
        m_tr{}, m_d{} {}
 
    void addEdge(int u, int v) {
        m_tr[u].push_back(v);
    }
 
    std::vector<int> getOrder() {
        for (int u = 1; u <= g_n; u++) {
            for (auto v: m_tr[u]) {
                m_d[v]++;
            }
        }
 
        std::vector<int> res;
        std::queue<int> q;
        for (int u = 1; u <= g_n; u++) {
            if (m_d[u] == 0) {
                q.push(u);
            }
        }
 
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
 
            for (int to: m_tr[x]) {
                if (--m_d[to] == 0) {
                    q.push(to);
                }
            }
        }
 
        return res;
    }
 
private:
    std::vector<int> m_tr[N];
    int m_d[N];
};
 
DAG g_tree;
DAG g_dag;
 
int main() {
    std::ios::sync_with_stdio(false);
 
    std::cin >> g_n;
    for (int i = 1; i <= g_n; i++) { std::cin >> g_a[i]; }
    for (int i = 1; i <= g_n; i++) {
        std::cin >> g_b[i];
        if (g_b[i] != -1) {
            g_tree.addEdge(i, g_b[i]);
        }
    }
 
    for (int x: g_tree.getOrder()) {
        g_v[x] += g_a[x];
        if (g_b[x] == -1) { continue; }
        if (g_v[x] < 0) {
            g_dag.addEdge(g_b[x], x);
        } else {
            g_v[g_b[x]] += g_v[x];
            g_dag.addEdge(x, g_b[x]);
        }
    }
 
    ll ans = 0;
    auto ansV = g_dag.getOrder();
    for (int x: ansV) {
        ans += g_a[x];
        if (g_b[x] != -1) {
            g_a[g_b[x]] += g_a[x];
        }
    }
    std::cout << ans << "\n";
    for (int x: ansV) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
