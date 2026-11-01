/**
 * @file fenwick.hpp
 * @brief 树状数组（Fenwick Tree）模板
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_DS_FENWICK_HPP
#define ACM_DS_FENWICK_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 树状数组（单点修改、区间查询）
 * @tparam T 元素类型
 *
 * 功能：
 *   - 单点加：add(pos, val)
 *   - 前缀和查询：sum(pos)        // [1, pos]
 *   - 区间和查询：range_sum(l, r)  // [l, r]
 *
 * @note 时间复杂度：O(log n) 每次操作
 * @note 空间复杂度 O(n)
 *
 * 用法：
 *   Fenwick<long long> ft(n);
 *   ft.add(1, 5);
 *   cout << ft.range_sum(1, 3);
 */
template <typename T>
class Fenwick {
private:
    int n;
    vector<T> tree;

public:
    explicit Fenwick(int size) : n(size), tree(size + 1, 0) {}

    /**
     * @brief 单点加：第 pos 个元素加上 val
     * @param pos 位置（1-based）
     * @param val 增量
     */
    void add(int pos, T val) {
        for (; pos <= n; pos += pos & -pos)
            tree[pos] += val;
    }

    /**
     * @brief 前缀和查询：sum(1..pos)
     * @param pos 右端点
     * @return 前缀和
     */
    T sum(int pos) const {
        T res = 0;
        for (; pos > 0; pos -= pos & -pos)
            res += tree[pos];
        return res;
    }

    /**
     * @brief 区间和查询：sum(l..r)
     */
    T range_sum(int l, int r) const { return sum(r) - sum(l - 1); }

    /**
     * @brief 从数组初始化
     * @param a 1-based 数组
     */
    void build(const vector<T> &a) {
        for (int i = 1; i <= n; ++i)
            add(i, a[i]);
    }
};

#endif // ACM_DS_FENWICK_HPP
