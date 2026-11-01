/**
 * @file mst.hpp
 * @brief 最小生成树模板：Kruskal、Prim
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_GRAPH_MST_HPP
#define ACM_GRAPH_MST_HPP

#include <bits/stdc++.h>
#include "ds/dsu.hpp"
using namespace std;

/**
 * @struct Edge
 * @brief 边结构体
 */
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

/**
 * @brief Kruskal 最小生成树（并查集 + 贪心）
 * @param n 节点数
 * @param edges 边列表
 * @param total_weight 输出：MST 总权值
 * @return 生成树的边列表
 * @note 时间复杂度 O(m log m)
 * @note 适用于稀疏图
 */
inline vector<Edge> kruskal(int n, vector<Edge> &edges, long long &total_weight) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    vector<Edge> mst;
    total_weight = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.w;
        }
    }
    return mst;
}

/**
 * @brief Prim 最小生成树（堆优化）
 * @param n 节点数
 * @param adj 邻接表
 * @param total_weight 输出：MST 总权值
 * @note 时间复杂度 O((n + m) log n)
 * @note 适用于稠密图
 */
inline void prim(int n, const vector<vector<pair<int, long long>>> &adj,
                 long long &total_weight) {
    vector<long long> min_dist(n + 1, 1e18);
    vector<bool> visited(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    min_dist[1] = 0;
    pq.push({0, 1});
    total_weight = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total_weight += d;
        if (++cnt == n) break;
        for (auto [v, w] : adj[u]) {
            if (!visited[v] && w < min_dist[v]) {
                min_dist[v] = w;
                pq.push({w, v});
            }
        }
    }
}

#endif // ACM_GRAPH_MST_HPP
