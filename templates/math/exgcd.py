
def exgcd(a: int, b: int) -> tuple[int, int, int]:
    """
    扩展欧几里得算法
    返回: (g, x, y)，满足 a*x + b*y = g = gcd(a, b)
    """
    if b == 0:
        return a, 1, 0
    g, x1, y1 = exgcd(b, a % b)
    return g, y1, x1 - (a // b) * y1


def mod_inverse_exgcd(a: int, m: int) -> int:
    """
    扩展欧几里得求逆元（模数 m 不需要是质数，只需 gcd(a, m) == 1）
    若不存在逆元，抛出 ValueError
    """
    g, x, _ = exgcd(a, m)
    if g != 1:
        raise ValueError(f"Inverse does not exist: gcd({a}, {m}) = {g} != 1")
    return (x % m + m) % m


def linear_inv(n: int, p: int) -> list[int]:
    """
    O(N) 递推预处理 1 ~ n 在模 p (质数) 意义下的所有逆元
    递推式: inv[i] = (p - p // i) * inv[p % i] % p
    """
    inv = [0] * (n + 1)
    inv[1] = 1
    for i in range(2, n + 1):
        inv[i] = (p - p // i) * inv[p % i] % p
    return inv