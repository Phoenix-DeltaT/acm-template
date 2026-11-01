/**
 * @file kmp.hpp
 * @brief KMP 字符串匹配模板
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_STRING_KMP_HPP
#define ACM_STRING_KMP_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 计算 KMP 的 next 数组（前缀函数）
 * @param pattern 模式串
 * @return next 数组，next[i] 表示 pattern[0..i] 的最长相等前后缀长度
 * @note 时间复杂度 O(m)
 */
inline vector<int> compute_next(const string &pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = next[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];
        if (pattern[i] == pattern[j])
            ++j;
        next[i] = j;
    }
    return next;
}

/**
 * @brief KMP 字符串匹配
 * @param text 文本串
 * @param pattern 模式串
 * @return 所有匹配位置的起始下标（0-based）
 * @note 时间复杂度 O(n + m)
 */
inline vector<int> kmp_search(const string &text, const string &pattern) {
    vector<int> next = compute_next(pattern);
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = next[j - 1];
        if (text[i] == pattern[j])
            ++j;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = next[j - 1];
        }
    }
    return positions;
}

#endif // ACM_STRING_KMP_HPP
