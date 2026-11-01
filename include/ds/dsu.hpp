/**
 * @file dsu.hpp
 * @brief 并查集（Disjoint Set Union）模板
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_DS_DSU_HPP
#define ACM_DS_DSU_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 并查集（路径压缩 + 按秩合并）
 *
 * 功能：
 *   - 合并两个集合：unite(a, b)
 *   - 查询根节点：find(x)
 *   - 判断是否同集合：same(a, b)
 *   - 查询集合大小：size(x)
 *
 * @note 时间复杂度：均摊 O(α(n))，近似常数
 * @note 空间复杂度 O(n)
 *
 * 用法：
 *   DSU dsu(n);
 *   dsu.unite(1, 2);
 *   if (dsu.same(1, 2)) cout << "same";
 */
class DSU {
public:
    vector<int> parent; // 父节点
    vector<int> sz;     // 集合大小（仅根节点有效）

    /**
     * @brief 构造函数
     * @param n 元素个数（编号 1~n）
     */
    explicit DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    /**
     * @brief 查找根节点（路径压缩）
     * @param x 元素
     * @return 根节点编号
     */
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // 路径压缩（隔代压缩）
            x = parent[x];
        }
        return x;
    }

    /**
     * @brief 合并两个集合（按大小合并）
     * @param a 元素 a
     * @param b 元素 b
     * @return true 表示合并成功，false 表示已在同一集合
     */
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    /**
     * @brief 判断两个元素是否在同一集合
     */
    bool same(int a, int b) { return find(a) == find(b); }

    /**
     * @brief 查询元素所在集合的大小
     */
    int size(int x) { return sz[find(x)]; }
};

#endif // ACM_DS_DSU_HPP
