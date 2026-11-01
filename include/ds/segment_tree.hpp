/**
 * @file segment_tree.hpp
 * @brief 线段树模板：区间修改 + 区间查询（懒标记）
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_DS_SEGMENT_TREE_HPP
#define ACM_DS_SEGMENT_TREE_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 线段树（支持区间加法、区间求和）
 * @tparam T 元素类型（建议 long long）
 *
 * 功能：
 *   - 单点更新：update(pos, val)
 *   - 区间更新：update(l, r, val)  // 区间加 val
 *   - 区间查询：query(l, r)       // 区间求和
 *
 * @note 时间复杂度：建树 O(n)，单次操作 O(log n)
 * @note 空间复杂度 O(4n)
 *
 * 用法：
 *   SegmentTree<long long> st(n);
 *   st.build(a);  // a 为 1-based 数组
 *   st.update(1, 3, 5);
 *   cout << st.query(1, 3);
 */
template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> sum;   // 区间和
    vector<T> lazy;  // 懒标记

    /**
     * @brief 下传懒标记
     * @param node 当前节点
     * @param l 左端点
     * @param r 右端点
     */
    void push_down(int node, int l, int r) {
        if (lazy[node] == 0) return;
        int mid = (l + r) >> 1;
        sum[node << 1]     += lazy[node] * (mid - l + 1);
        sum[node << 1 | 1] += lazy[node] * (r - mid);
        lazy[node << 1]     += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        lazy[node] = 0;
    }

    void build(int node, int l, int r, const vector<T> &a) {
        lazy[node] = 0;
        if (l == r) { sum[node] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
    }

    void update(int node, int l, int r, int ql, int qr, T val) {
        if (ql <= l && r <= qr) {
            sum[node] += val * (r - l + 1);
            lazy[node] += val;
            return;
        }
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(node << 1, l, mid, ql, qr, val);
        if (qr > mid)  update(node << 1 | 1, mid + 1, r, ql, qr, val);
        sum[node] = sum[node << 1] + sum[node << 1 | 1];
    }

    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[node];
        push_down(node, l, r);
        int mid = (l + r) >> 1;
        T res = 0;
        if (ql <= mid) res += query(node << 1, l, mid, ql, qr);
        if (qr > mid)  res += query(node << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }

public:
    /**
     * @brief 构造函数
     * @param size 数组大小（下标 1~size）
     */
    explicit SegmentTree(int size) : n(size) {
        sum.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
    }

    /**
     * @brief 建树（从数组初始化）
     * @param a 1-based 数组，a[1..n]
     */
    void build(const vector<T> &a) { build(1, 1, n, a); }

    /**
     * @brief 区间更新：[l, r] 每个元素加 val
     */
    void update(int l, int r, T val) { update(1, 1, n, l, r, val); }

    /**
     * @brief 单点更新：第 pos 个元素加 val
     */
    void update(int pos, T val) { update(1, 1, n, pos, pos, val); }

    /**
     * @brief 区间查询：[l, r] 求和
     */
    T query(int l, int r) { return query(1, 1, n, l, r); }
};

#endif // ACM_DS_SEGMENT_TREE_HPP
