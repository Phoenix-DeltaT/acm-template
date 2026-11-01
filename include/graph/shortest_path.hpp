/**
 * @file shortest_path.hpp
 * @brief 最短路算法模板：Dijkstra、SPFA、Floyd
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_GRAPH_SHORTEST_PATH_HPP
#define ACM_GRAPH_SHORTEST_PATH_HPP

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

/**
 * @brief Dijkstra 最短路（堆优化，适用于非负权图）
 * @param n 节点数
 * @param adj 邻接表，adj[u] = {{v, w}, ...}
 * @param s 源点
 * @param dist 输出：dist[v] = s 到 v 的最短距离
 * @note 时间复杂度 O((n + m) log n)
 * @note 不适用于负权边
 */
inline void dijkstra(int n, const vector<vector<pair<int, long long>>> &adj,
                     int s, vector<long long> &dist) {
    dist.assign(n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

/**
 * @brief SPFA 最短路（队列优化，适用于含负权图）
 * @param n 节点数
 * @param adj 邻接表
 * @param s 源点
 * @param dist 输出：最短距离
 * @return true 表示无负环，false 表示存在负环
 * @note 时间复杂度：平均 O(m)，最坏 O(nm)
 * @note 可检测负权环
 */
inline bool spfa(int n, const vector<vector<pair<int, long long>>> &adj,
                 int s, vector<long long> &dist) {
    dist.assign(n + 1, INF);
    vector<int> cnt(n + 1, 0);
    vector<bool> in_queue(n + 1, false);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        in_queue[u] = false;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    if (++cnt[v] > n) return false; // 负环
                }
            }
        }
    }
    return true;
}

/**
 * @brief Floyd 多源最短路（DP）
 * @param n 节点数
 * @param dist 邻接矩阵，dist[i][j] 为 i 到 j 的距离（对角线为 0）
 * @note 时间复杂度 O(n^3)
 * @note 空间复杂度 O(n^2)
 * @note 适用于 n <= 500 的小图
 */
inline void floyd(int n, vector<vector<long long>> &dist) {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

#endif // ACM_GRAPH_SHORTEST_PATH_HPP
