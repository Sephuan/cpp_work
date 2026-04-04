#include <iostream>
using namespace std;

// 自动取模整型模板 (Modular Integer)
template <int MOD>
struct ModInt {
    int v;

    // 构造时自动处理负数和超大数取模
    ModInt() : v(0) {}
    ModInt(long long _v) { 
        v = _v % MOD; 
        if (v < 0) v += MOD; 
    }

    // 快速幂 (计算 base^power % MOD)
    ModInt power(long long p) const {
        ModInt res = 1, base = *this;
        while (p > 0) {
            if (p & 1) res *= base;
            base *= base;
            p >>= 1;
        }
        return res;
    }

    // 乘法逆元 (基于费马小定理，要求 MOD 是质数)
    ModInt inv() const { return power(MOD - 2); }

    // 核心复合赋值运算
    ModInt& operator+=(const ModInt& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
    ModInt& operator-=(const ModInt& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
    ModInt& operator*=(const ModInt& o) { v = 1LL * v * o.v % MOD; return *this; }
    ModInt& operator/=(const ModInt& o) { return *this *= o.inv(); } // 除法转为乘逆元

    // 四则运算
    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

    // 比较运算
    bool operator==(const ModInt& o) const { return v == o.v; }
    bool operator!=(const ModInt& o) const { return v != o.v; }

    // 输入输出流
    friend istream& operator>>(istream& is, ModInt& x) {
        long long val; is >> val; x = ModInt(val); return is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.v;
    }
};

// ================== 常用的模数定义 ==================
using MI_1e9 = ModInt<1000000007>;   // 最常见的 1e9+7
using MI_998 = ModInt<998244353>;    // NTT 常用的 998244353
using MI = MI_1e9;                   // 默认的 MI 设置为 1e9+7，可根据题目随时改

// ================== MI 测试代码 ==================

int main() {
    MI a = 1000000006;
    MI b = 5;
    
    // a + b 自动变为 (1000000006 + 5) % 1000000007 = 4
    cout << "a + b = " << a + b << endl; 
    
    // 支持直接除法取模！内部自动计算乘法逆元
    MI c = a / b;
    cout << "a / b = " << c << endl;
    
    return 0;
}
