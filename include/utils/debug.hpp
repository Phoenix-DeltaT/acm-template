/**
 * @file debug.hpp
 * @brief 调试工具模板（竞赛本地调试用，提交时删除）
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_UTILS_DEBUG_HPP
#define ACM_UTILS_DEBUG_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 调试打印单个值
 * @param name 变量名
 * @param val 变量值
 */
template <typename T>
void debug(const string &name, const T &val) {
    cerr << "[DEBUG] " << name << " = " << val << endl;
}

/**
 * @brief 调试打印容器（vector、set、map 等）
 */
template <typename T>
void debug_container(const string &name, const T &container) {
    cerr << "[DEBUG] " << name << " = [";
    bool first = true;
    for (const auto &x : container) {
        if (!first) cerr << ", ";
        cerr << x;
        first = false;
    }
    cerr << "]" << endl;
}

/**
 * @brief 调试打印二维数组/矩阵
 */
template <typename T>
void debug_matrix(const string &name, const vector<vector<T>> &mat) {
    cerr << "[DEBUG] " << name << ":" << endl;
    for (size_t i = 0; i < mat.size(); ++i) {
        cerr << "  row " << i << ": ";
        for (size_t j = 0; j < mat[i].size(); ++j) {
            if (j) cerr << " ";
            cerr << mat[i][j];
        }
        cerr << endl;
    }
}

#endif // ACM_UTILS_DEBUG_HPP
