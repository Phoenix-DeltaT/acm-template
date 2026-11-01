/**
 * @file fast_io.hpp
 * @brief 快速输入输出模板
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_UTILS_FAST_IO_HPP
#define ACM_UTILS_FAST_IO_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 快速输入输出优化
 * @note 在 main 函数开头调用即可加速 IO
 *
 * 用法：
 *   int main() {
 *       fast_io();
 *       // ...
 *   }
 */
inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/**
 * @brief 更快的整数输入（手动读入）
 * @tparam T 整数类型
 * @return 读入的整数
 * @note 比 cin 快 5~10 倍，适用于大量数据
 */
template <typename T>
inline T read_int() {
    T x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

/**
 * @brief 快速输出整数
 * @tparam T 整数类型
 * @param x 待输出的整数
 */
template <typename T>
inline void write_int(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write_int(x / 10);
    putchar(x % 10 + '0');
}

#endif // ACM_UTILS_FAST_IO_HPP
