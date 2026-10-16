            for (auto v : e[it]) {
                deg[v] -= 1;
                max_node[v] = std::max(max_node[it], it);
                if (deg[v] == 0) s.insert(v);
            }