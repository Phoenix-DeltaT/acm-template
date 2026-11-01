/**
 * @file number_theory.hpp
 * @brief 数论常用模板：gcd、扩展欧几里得、快速幂、素数筛
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_MATH_NUMBER_THEORY_HPP
#define ACM_MATH_NUMBER_THEORY_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 最大公约数（欧几里得算法）
 * @tparam T 整数类型
 * @param a 第一个数
 * @param b 第二个数
 * @return gcd(a, b)
 * @note 时间复杂度 O(log(min(a, b)))
 */
template <typename T>
T gcd(T a, T b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

/**
 * @brief 最小公倍数
 * @tparam T 整数类型
 * @param a 第一个数
 * @param b 第二个数
 * @return lcm(a, b)
 */
template <typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

/**
 * @brief 扩展欧几里得算法
 * @tparam T 整数类型
 * @param a 第一个数
 * @param b 第二个数
 * @param x 输出：满足 ax + by = gcd(a,b) 的 x
 * @param y 输出：满足 ax + by = gcd(a,b) 的 y
 * @return gcd(a, b)
 * @note 时间复杂度 O(log(min(a, b)))
 * @note 用于求模逆元、解线性同余方程
 */
template <typename T>
T exgcd(T a, T b, T &x, T &y) {
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

/**
 * @brief 快速幂（二进制快速幂）
 * @tparam T 整数类型
 * @param base 底数
 * @param exp 指数
 * @param mod 模数（默认 0 表示不取模）
 * @return base^exp % mod
 * @note 时间复杂度 O(log exp)
 */
template <typename T>
T qpow(T base, T exp, T mod = 0) {
    T res = 1;
    if (mod) base %= mod;
    while (exp > 0) {
        if (exp & 1) res = mod ? res * base % mod : res * base;
        base = mod ? base * base % mod : base * base;
        exp >>= 1;
    }
    return res;
}

/**
 * @brief 埃拉托斯特尼筛法（素数筛）
 * @param n 筛取范围 [2, n]
 * @param primes 输出：存储素数的 vector
 * @note 时间复杂度 O(n log log n)
 * @note 空间复杂度 O(n)
 */
inline void sieve(int n, vector<int> &primes) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((long long)i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
        }
    }
}

/**
 * @brief 线性筛（欧拉筛）
 * @param n 筛取范围 [2, n]
 * @param primes 输出：存储素数的 vector
 * @note 时间复杂度 O(n)
 * @note 可同时求欧拉函数等积性函数
 */
inline void linear_sieve(int n, vector<int> &primes) {
    vector<bool> is_comp(n + 1, false);
    primes.clear();
    for (int i = 2; i <= n; ++i) {
        if (!is_comp[i]) primes.push_back(i);
        for (int p : primes) {
            if (i * p > n) break;
            is_comp[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

#endif // ACM_MATH_NUMBER_THEORY_HPP
