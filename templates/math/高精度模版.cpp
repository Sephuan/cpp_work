#include <bits/stdc++.h>
using namespace std;

// ======================================================================================
//                                   C++ 高精度运算通用模板
// ======================================================================================
// 说明：
// 1. 本模板基于 string 和 vector<int> 实现，适用于常规算法竞赛。
// 2. 输入输出均为 string 类型，方便处理超长整数。
// 3. 基础运算复杂度多为 O(N) 或 O(N*M)，N, M 为数字长度。
// 4. 除非特别说明，函数参数默认 a, b 为非负整数且无前导零（"0"除外）。
// ======================================================================================

// ========================== 高精度加法 (High Precision Addition) ==========================
// 功能：返回 string a + string b
// 范围：a, b 长度通常 <= 10^4 (取决于内存和时间限制)
// 变量解释：
//   a, b: 加数 (addends)
//   res: 结果字符串 (result)，构建时是逆序的
//   carry: 进位 (carry)
//   i, j: 遍历索引 (indices)，从低位（字符串末尾）开始
string add(string a, string b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    
    // 只要还有位数未处理或有进位，就继续循环
    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0'; // 加上 a 的当前位
        if (j >= 0) carry += b[j--] - '0'; // 加上 b 的当前位
        res += (carry % 10) + '0';         // 取个位作为当前位结果
        carry /= 10;                       // 计算新的进位
    }
    
    reverse(res.begin(), res.end());       // 翻转得到正确顺序
    return res;
}

// ========================== 高精度减法 (High Precision Subtraction) ==========================
// 功能：返回 string a - string b
// 限制：必须保证 a >= b
// 变量解释：
//   a: 被减数 (minuend)
//   b: 减数 (subtrahend)
//   res: 结果字符串 (result)
//   borrow: 借位 (borrow)，0 表示无借位，-1 表示有借位
//   t: 当前位的临时计算值 (temp)
string sub(string a, string b) {
    string res;
    int borrow = 0;
    int i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || borrow) {
        int t = borrow;
        if (i >= 0) t += a[i--] - '0'; // 加上被减数当前位
        if (j >= 0) t -= b[j--] - '0'; // 减去减数当前位
        
        if (t < 0) { 
            t += 10;    // 向高位借位
            borrow = -1; 
        } else {
            borrow = 0;
        }
        res += t + '0';
    }
    
    // 去除前导零 (例如 100 - 99 = 001 -> 1)，保留结果为 "0" 的情况
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    
    reverse(res.begin(), res.end());
    return res;
}

// ========================== 高精度乘法 (High Precision Multiplication) ==========================
// 功能：返回 string a * string b
// 范围：a, b 长度 <= 5000 (复杂度 O(N*M))
// 变量解释：
//   n, m: 两个数的长度
//   res: 结果数组 (vector)，res[i] 存储第 i 位的数值（未处理进位前可能大于10）
//   s: 最终转换的字符串
string mul(string a, string b) {
    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0); // 结果最长为 n+m 位
    
    // 逐位相乘 (模拟竖式乘法)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            // res[i + j + 1] 对应结果的低位
            res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    
    // 处理进位
    for (int i = n + m - 1; i > 0; i--) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
    
    // 转为字符串并去前导零
    string s;
    for (int i = 0; i < n + m; i++) {
        if (s.empty() && res[i] == 0) continue; // 跳过前导零
        s += res[i] + '0';
    }
    return s.empty() ? "0" : s;
}

// ========================== 高精度阶乘 (High Precision Factorial) ==========================
// 功能：返回 string n!
// 范围：n <= 5000 (结果位数约 1.6e4 位)
// 变量解释：
//   res: 存储结果的动态数组，res[0] 为最低位
//   carry: 进位值
//   t: 临时乘积 (long long 防止溢出)
string fac(int n) {
    if (n < 2) return "1";
    vector<int> res = {1}; 
    
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        // 高精度 * 单精度
        for (size_t j = 0; j < res.size(); ++j) {
            long long t = (long long)res[j] * i + carry;
            res[j] = t % 10;
            carry = t / 10;
        }
        // 处理剩余进位
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    // 逆序输出转字符串
    string s;
    for (int i = res.size() - 1; i >= 0; i--)
        s += '0' + res[i];
    return s;
}

// ========================== 高精度除法 (High Precision Division) ==========================
// 功能：返回 string a / string b (整除)
// 原理：模拟竖式除法，通过减法确定商的每一位
// 依赖：sub 函数
// 变量解释：
//   rem: 当前余数 (remainder)
//   res: 商 (quotient)
//   blen: 除数长度
//   x: 当前位的商
string div(string a, string b) {
    // 特判：被除数小于除数
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) return "0";
    
    string res, rem = "";
    int blen = b.size();
    
    for (int i = 0; i < a.size(); i++) {
        rem += a[i]; // 将被除数下一位移入余数
        
        // 去除 rem 的前导零 (例如 "03" -> "3")
        while (rem.size() > 1 && rem[0] == '0') rem.erase(0, 1);
        
        int x = 0;
        // 只要余数 >= 除数，就一直减，统计减的次数作为商
        while (rem.size() >= blen && (rem.size() > blen || rem >= b)) {
            rem = sub(rem, b);
            x++;
        }
        res += '0' + x;
    }
    
    // 去除商的前导零
    while (res.size() > 1 && res[0] == '0') res.erase(0, 1);
    return res.empty() ? "0" : res;
}

// ========================== 高精度求余 (High Precision Modulo) ==========================
// 功能：返回 string a % string b
// 原理：同除法，只是最后返回的是余数 rem
// 依赖：sub 函数
string mod(string a, string b) {
    string rem = "";
    int blen = b.size();
    
    for (int i = 0; i < a.size(); i++) {
        rem += a[i];
        while (rem.size() > 1 && rem[0] == '0') rem.erase(0, 1);
        
        while (rem.size() >= blen && (rem.size() > blen || rem >= b)) {
            rem = sub(rem, b);
        }
    }
    return rem.empty() ? "0" : rem;
}

// ========================== 高精度幂 (High Precision Power) ==========================
// 功能：返回 string a ^ b
// 范围：b <= 1e9 (使用二进制快速幂)
// 依赖：mul 函数
// 变量解释：
//   res: 结果，初始化为 "1"
//   base: 底数
//   exponent: 指数
string pow(string a, int b) {
    string res = "1";
    while (b > 0) {
        if (b % 2 == 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

// ========================== 测试主函数 ==========================
signed main() {
    // 加法测试
    cout << "Add: " << add("123456789", "987654321") << endl;  // 1111111110
    
    // 减法测试 (需保证 a >= b)
    cout << "Sub: " << sub("1000000", "999") << endl;          // 999001
    
    // 乘法测试
    cout << "Mul: " << mul("123", "456") << endl;              // 56088
    
    // 阶乘测试
    cout << "Fac: " << fac(5) << endl;                         // 120
    cout << "Fac: " << fac(50) << endl;                        // 304140...000
    
    // 除法测试
    cout << "Div: " << div("100", "3") << endl;                // 33
    cout << "Div: " << div("123456", "123") << endl;           // 1003
    
    // 取模测试
    cout << "Mod: " << mod("100", "3") << endl;                // 1
    
    // 幂运算测试
    cout << "Pow: " << pow("2", 10) << endl;                   // 1024
    
    return 0;
}
