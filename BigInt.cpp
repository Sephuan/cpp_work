#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct BI {
    vector<int> d;

    // ================= 构造函数 =================
    BI() {}
    
    // 拦截普通 int (包括 0)，彻底消除与 const char* 的歧义
    BI(int v) : BI((long long)v) {}
    
    BI(long long v) {
        if (v == 0) d.push_back(0);
        while (v > 0) { d.push_back(v % 10); v /= 10; }
    }
    
    BI(string s) {
        if (s.empty()) { d.push_back(0); return; }
        for (int i = (int)s.size() - 1; i >= 0; i--) d.push_back(s[i] - '0');
        clean();
    }
    
    // 拦截双引号字符串字面量
    BI(const char* s) : BI(string(s)) {}

    // 去除前导零
    void clean() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }

    // ================= 输入输出流重载 =================
    friend istream& operator>>(istream& is, BI& x) {
        string s; if (is >> s) x = BI(s); return is;
    }
    friend ostream& operator<<(ostream& os, const BI& x) {
        if (x.d.empty()) { os << 0; return os; }
        for (int i = (int)x.d.size() - 1; i >= 0; i--) os << x.d[i];
        return os;
    }

    // ================= 比较运算符 =================
    bool operator<(const BI& b) const {
        if (d.size() != b.d.size()) return d.size() < b.d.size();
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        }
        return false;
    }
    bool operator>(const BI& b) const { return b < *this; }
    bool operator<=(const BI& b) const { return !(b < *this); }
    bool operator>=(const BI& b) const { return !(*this < b); }
    bool operator==(const BI& b) const { return !(*this < b) && !(b < *this); }
    bool operator!=(const BI& b) const { return (*this < b) || (b < *this); }

    // ================= 基础复合赋值 (+, -, *) =================
    BI& operator+=(const BI& b) {
        int carry = 0;
        for (int i = 0; i < max(d.size(), b.d.size()) || carry; i++) {
            if (i == d.size()) d.push_back(0);
            carry += d[i] + (i < b.d.size() ? b.d[i] : 0);
            d[i] = carry % 10;
            carry /= 10;
        }
        return *this;
    }

    BI& operator-=(const BI& b) {
        int borrow = 0;
        for (int i = 0; i < d.size(); i++) {
            d[i] = d[i] - borrow - (i < b.d.size() ? b.d[i] : 0);
            if (d[i] < 0) { d[i] += 10; borrow = 1; } 
            else borrow = 0;
        }
        clean();
        return *this;
    }

    BI& operator*=(const BI& b) {
        if (d.empty() || b.d.empty()) return *this = BI(0);
        vector<int> res(d.size() + b.d.size(), 0);
        for (int i = 0; i < d.size(); i++) {
            for (int j = 0; j < b.d.size(); j++) {
                res[i + j] += d[i] * b.d[j];
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
        d = move(res);
        clean();
        return *this;
    }

    // ================= 高精 与 低精 的除法和求余 =================
    BI operator/(long long b) const {
        BI res;
        res.d.assign(d.size(), 0);
        long long rem = 0;
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            rem = rem * 10 + d[i];
            res.d[i] = rem / b;
            rem %= b;
        }
        res.clean();
        return res;
    }

    long long operator%(long long b) const {
        long long rem = 0;
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            rem = (rem * 10 + d[i]) % b;
        }
        return rem;
    }

    // ================= 高精 与 高精 的除法和求余 =================
    BI operator/(const BI& b) const {
        if (*this < b) return BI(0);
        BI res, rem;
        res.d.assign(d.size(), 0);
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            if (!(rem.d.size() == 1 && rem.d[0] == 0)) rem.d.insert(rem.d.begin(), d[i]);
            else rem.d[0] = d[i];
            
            int quotient = 0;
            while (rem >= b) {
                rem -= b;
                quotient++;
            }
            res.d[i] = quotient;
        }
        res.clean();
        return res;
    }

    BI operator%(const BI& b) const {
        if (*this < b) return *this;
        BI rem;
        for (int i = (int)d.size() - 1; i >= 0; i--) {
            if (!(rem.d.size() == 1 && rem.d[0] == 0)) rem.d.insert(rem.d.begin(), d[i]);
            else rem.d[0] = d[i];
            
            while (rem >= b) {
                rem -= b;
            }
        }
        rem.clean();
        return rem;
    }

    // ================= 四则运算和高精复合赋值的收尾 =================
    BI operator+(const BI& b) const { BI res = *this; res += b; return res; }
    BI operator-(const BI& b) const { BI res = *this; res -= b; return res; }
    BI operator*(const BI& b) const { BI res = *this; res *= b; return res; }
    
    BI& operator/=(const BI& b) { return *this = *this / b; }
    BI& operator%=(const BI& b) { return *this = *this % b; }
};

// ----------------- 测试代码 (使用例) -----------------

int main() {
    // 现在双引号字符串直接赋值完全没问题了
    BI a = "1000000000000000000000";
    BI b = "3";
    long long c = 7;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    cout << "高精 + 高精: " << a + b << endl;
    cout << "高精 - 高精: " << a - b << endl;
    cout << "高精 * 高精: " << a * b << endl;
    
    cout << "高精 / 高精: " << a / b << endl;
    cout << "高精 % 高精: " << a % b << endl;
    
    cout << "高精 / 低精: " << a / c << endl;
    cout << "高精 % 低精: " << a % c << endl;

    return 0;
}