class Combination:
    """
    基于快速幂、线性逆元与卢卡斯定理的组合数学工具类

    【功能特性】
    1. O(N) 线性预处理阶乘 (fact) 与阶乘逆元 (inv_fact)。
    2. O(1) 单次查询常规组合数 C(n, k) 与排列数 P(n, k)。
    3. O(log_p n) 卢卡斯定理查询超大组合数 lucas(n, k)（支持 n, k 达 10^18）。
    4. O(1) 卡特兰数 catalan(n)。
    5. O(1) 查询任意单数的模逆元 mod_inv(x)。

    【参数设置技巧】
    - 常规场景 (n <= 10^6): n 传入题目的最大值即可。
    - 卢卡斯场景 (n <= 10^18, mod <= 10^6 为质数): 初始化时传入 n = mod - 1 即可。
    """
    def __init__(self, n: int, mod: int = 998244353) -> None:
        self.n: int = n
        self.mod: int = mod
        self.fact: list[int] = [1] * (n + 1)
        self.inv_fact: list[int] = [1] * (n + 1)
        self.inv_table: list[int] = [1] * (n + 1)
        self._build()
    def _build(self) -> None:
        mod = self.mod
        for i in range(1, self.n + 1):
            self.fact[i] = self.fact[i - 1] * i % mod
        self.inv_fact[self.n] = pow(self.fact[self.n], mod - 2, mod)
        for i in range(self.n - 1, -1, -1):
            self.inv_fact[i] = self.inv_fact[i + 1] * (i + 1) % mod
        for i in range(1, self.n + 1):
            self.inv_table[i] = self.fact[i - 1] * self.inv_fact[i] % mod
    def C(self, n: int, k: int) -> int:
        if k < 0 or k > n or n > self.n:
            return 0
        return self.fact[n] * self.inv_fact[k] % self.mod * self.inv_fact[n - k] % self.mod
    def P(self, n: int, k: int) -> int:
        if k < 0 or k > n or n > self.n:
            return 0
        return self.fact[n] * self.inv_fact[n - k] % self.mod
    def catalan(self, n: int) -> int:
        if 2 * n > self.n:
            raise ValueError()
        return self.C(2 * n, n) * self.mod_inv(n + 1) % self.mod
    def mod_inv(self, x: int) -> int:
        if 1 <= x <= self.n:
            return self.inv_table[x]
        return pow(x, self.mod - 2, self.mod)
    def lucas(self, n: int, k: int) -> int:
        if k < 0 or k > n:
            return 0
        if k == 0:
            return 1
        res = 1
        mod = self.mod
        while n > 0 or k > 0:
            ni, ki = n % mod, k % mod
            if ni < ki:
                return 0
            res = res * self.C(ni, ki) % mod
            n //= mod
            k //= mod
        return res