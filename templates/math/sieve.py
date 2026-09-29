def eulerSieve(n) -> tuple[list[int], list[int]]:
    """
    预处理 1 ~ n 的质数和最小质因数
    min_prime[x]: x 的最小质因数 (x 为质数时 min_prime[x] == x)
    """
    min_prime = [0] * (n + 1)
    primes = []
    for i in range(2, n + 1):
        if min_prime[i] == 0:
            min_prime[i] = i
            primes.append(i)
        for p in primes:
            if p * i > n:
                break
            min_prime[p * i] = p
            if i % p == 0:
                break         
    return primes, min_prime

# 利用 min_prime 快速分解质因数 (单次查询 O(log x))
def getFactors(x, min_prime):
    factors = []
    while x > 1:
        p = min_prime[x]
        cnt = 0
        while x % p == 0:
            x //= p
            cnt += 1
        factors.append((p, cnt))
    return factors

def sieveMultiplicative(n):
    """
    线性筛预处理:
    - primes: 质数列表
    - phi: 欧拉函数值列表
    - mu: 莫比乌斯函数值列表
    """
    is_prime = [True] * (n + 1)
    primes = []
    phi = [0] * (n + 1)
    mu = [0] * (n + 1)
    phi[1] = 1
    mu[1] = 1
    is_prime[0] = is_prime[1] = False
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            phi[i] = i - 1
            mu[i] = -1
        for p in primes:
            if p * i > n:
                break
            is_prime[p * i] = False
            if i % p == 0:
                phi[p * i] = phi[i] * p
                mu[p * i] = 0
                break
            else:
                phi[p * i] = phi[i] * (p - 1)
                mu[p * i] = -mu[i]        
    return primes, phi, mu

class EulerSieve:
    """
    线性筛（欧拉筛）全能模板类

    【功能特性】
    1. O(N) 严格线性时间预处理 1 ~ n 的质数和最小质因数 (min_prime / SPF)。
    2. O(1) 单次质数判断。
    3. O(log x) 单次高频质因数分解。
    4. 快速枚举 x 的所有正约数（因子）。
    5. 可选预处理积性函数：欧拉函数 φ 与 莫比乌斯函数 μ。

    【复杂度】
    - 预处理时间复杂度: O(N)
    - 空间复杂度: O(N)
    - is_prime(x) 查询: O(1)
    - factorize(x) 分解: O(log x)
    - phi / mu 查询: O(1)

    【初始化参数】
    - n (int): 预处理的最大值上限（闭区间 [1, n]）
    - with_phi (bool): 是否同时线性筛欧拉函数 φ，默认 False
    - with_mu (bool): 是否同时线性筛莫比乌斯函数 μ，默认 False

    【常用成员属性】
    - primes (list[int]): 1 ~ n 的所有质数升序列表
    - min_prime (list[int]): 下标 x 的最小质因数；若 x 为质数，则 min_prime[x] == x
    - phi (list[int]): 下标 x 的欧拉函数值（需开启 with_phi）
    - mu (list[int]): 下标 x 的莫比乌斯函数值（需开启 with_mu）
    """
    def __init__(self, n: int, with_phi: bool = False, with_mu: bool = False) -> None:
        self.n: int = n
        self.primes: list[int] = []
        self.min_prime: list[int] = [0] * (n + 1)
        self.with_phi: bool = with_phi
        self.with_mu: bool = with_mu
        self.phi: list[int] = [0] * (n + 1) if with_phi else []
        self.mu: list[int] = [0] * (n + 1) if with_mu else []
        self._sieve()
    def _sieve(self) -> None:
        if self.with_phi:
            self.phi[1] = 1
        if self.with_mu:
            self.mu[1] = 1
        for i in range(2, self.n + 1):
            if self.min_prime[i] == 0:
                self.min_prime[i] = i
                self.primes.append(i)
                if self.with_phi:
                    self.phi[i] = i - 1
                if self.with_mu:
                    self.mu[i] = -1
            for p in self.primes:
                if p * i > self.n:
                    break
                self.min_prime[p * i] = p
                if i % p == 0:
                    if self.with_phi:
                        self.phi[p * i] = self.phi[i] * p
                    if self.with_mu:
                        self.mu[p * i] = 0
                    break
                else:
                    if self.with_phi:
                        self.phi[p * i] = self.phi[i] * (p - 1)
                    if self.with_mu:
                        self.mu[p * i] = -self.mu[i]
    def is_prime(self, x: int) -> bool:
        """O(1) 判断质数"""
        return x >= 2 and self.min_prime[x] == x
    def factorize(self, x: int) -> list[tuple[int, int]]:
        """O(log x) 分解质因数: [(p1, c1), (p2, c2), ...]"""
        factors: list[tuple[int, int]] = []
        while x > 1:
            p = self.min_prime[x]
            cnt = 0
            while x % p == 0:
                x //= p
                cnt += 1
            factors.append((p, cnt))
        return factors
    def get_divisors(self, x: int, sort: bool = False) -> list[int]:
        """获取 x 的所有正因数"""
        if x == 1:
            return [1]
        divs: list[int] = [1]
        for p, count in self.factorize(x):
            temp: list[int] = []
            cur = 1
            for _ in range(count):
                cur *= p
                for d in divs:
                    temp.append(d * cur)
            divs.extend(temp)
        if sort:
            divs.sort()
        return divs