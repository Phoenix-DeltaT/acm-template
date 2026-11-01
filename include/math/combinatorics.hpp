/**
 * @file combinatorics.hpp
 * @brief 组合数学模板：逆元、组合数、阶乘预处理
 * @author Phoenix-DeltaT
 * @date 2026
 */
#ifndef ACM_MATH_COMBINATORICS_HPP
#define ACM_MATH_COMBINATORICS_HPP

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 组合数工具类（预处理阶乘与逆元）
 * @tparam MAXN 最大预处理范围
 * @tparam MOD 模数
 * @note 时间复杂度：预处理 O(n)，查询 O(1)
 * @note 空间复杂度 O(n)
 *
 * 用法：
 *   Comb<100000, 998244353> C;
 *   C.init();
 *   long long c = C.C(n, k);
 */
template <int MAXN, long long MOD>
class Comb {
public:
    vector<long long> fact;   // fact[i] = i!
    vector<long long> inv_fact; // inv_fact[i] = (i!)^{-1}

    Comb() : fact(MAXN + 1), inv_fact(MAXN + 1) {}

    /**
     * @brief 预处理阶乘与逆元阶乘
     * @note 必须在使用 C() 之前调用
     */
    void init() {
        fact[0] = 1;
        for (int i = 1; i <= MAXN; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        inv_fact[MAXN] = qpow_mod(fact[MAXN], MOD - 2);
        for (int i = MAXN - 1; i >= 0; --i)
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    /**
     * @brief 计算组合数 C(n, k)
     * @param n 总数
     * @param k 选取数
     * @return C(n, k) mod MOD
     * @note 时间复杂度 O(1)
     */
    long long C(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    }

    /**
     * @brief 计算排列数 A(n, k)
     * @param n 总数
     * @param k 选取数
     * @return A(n, k) mod MOD
     */
    long long A(int n, int k) const {
        if (k < 0 || k > n) return 0;
        return fact[n] * inv_fact[n - k] % MOD;
    }

    /**
     * @brief 快速幂（模 MOD）
     * @param base 底数
     * @param exp 指数
     * @return base^exp % MOD
     */
    static long long qpow_mod(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
};

/**
 * @brief 线性求逆元（1~n 在模 p 下的逆元）
 * @param n 范围
 * @param p 模数（必须为素数）
 * @param inv 输出：inv[i] = i^{-1} mod p
 * @note 时间复杂度 O(n)
 * @note 公式：inv[i] = (p - p/i) * inv[p%i] % p
 */
inline void linear_inverse(int n, long long p, vector<long long> &inv) {
    inv.resize(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (p - p / i) * inv[p % i] % p;
}

#endif // ACM_MATH_COMBINATORICS_HPP
