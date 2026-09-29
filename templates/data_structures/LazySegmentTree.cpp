#include <bits/stdc++.h>
using namespace std;

// ======================== 业务逻辑区域（只需按题目修改这部分） ========================

// 1. 懒标记结构体
struct Tag {
    long long add = 0; // 默认空标记为 0

    // 是否存在有效标记（如果只是加法，用 add != 0 即可；若是区间赋值，通常需要 bool has）
    bool has() const { return add != 0; }

    // 父标记应用到子标记（标记下传时的合并）
    void apply(const Tag& t) {
        add += t.add;
    }
};

// 2. 节点维护的信息结构体
struct Info {
    long long sum = 0;
    long long mx = -1e18;
    long long mn = 1e18;
    int len = 1;

    // 单点初始化的构造函数
    Info() = default;
    Info(long long val) : sum(val), mx(val), mn(val), len(1) {}

    // 将懒标记应用到当前节点
    void apply(const Tag& t) {
        sum += t.add * len;
        mx += t.add;
        mn += t.add;
    }
};

// 3. 两个子节点信息合并（pushup 逻辑）
Info operator+(const Info& a, const Info& b) {
    Info res;
    res.sum = a.sum + b.sum;
    res.mx = max(a.mx, b.mx);
    res.mn = min(a.mn, b.mn);
    res.len = a.len + b.len;
    return res;
}

// ======================== 线段树核心（永远无需改动） ========================

template <class Info, class Tag>
struct LazySegmentTree {
    int n;
    vector<Info> tree;
    vector<Tag> tag;

    LazySegmentTree(int n = 0) { init(n); }
    template <class T>
    LazySegmentTree(const vector<T>& a) { init(a); }

    void init(int n_) {
        n = n_;
        tree.assign(4 * n + 5, Info());
        tag.assign(4 * n + 5, Tag());
    }

    template <class T>
    void init(const vector<T>& a) {
        n = (int)a.size() - 1; // 假定 a 是 1-indexed
        tree.assign(4 * n + 5, Info());
        tag.assign(4 * n + 5, Tag());
        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) {
                tree[p] = Info(a[l]);
                return;
            }
            int mid = (l + r) >> 1;
            self(self, p << 1, l, mid);
            self(self, p << 1 | 1, mid + 1, r);
            pushup(p);
        };
        build(build, 1, 1, n);
    }

    void apply_tag(int p, const Tag& t) {
        tree[p].apply(t);
        tag[p].apply(t);
    }

    void pushup(int p) {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    void pushdown(int p) {
        if (tag[p].has()) {
            apply_tag(p << 1, tag[p]);
            apply_tag(p << 1 | 1, tag[p]);
            tag[p] = Tag(); // 清空当前标记
        }
    }

    // 区间修改
    void modify(int p, int l, int r, int ql, int qr, const Tag& t) {
        if (ql <= l && r <= qr) {
            apply_tag(p, t);
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) modify(p << 1, l, mid, ql, qr, t);
        if (qr > mid) modify(p << 1 | 1, mid + 1, r, ql, qr, t);
        pushup(p);
    }

    // 单点直接赋值/修改
    void set(int p, int l, int r, int pos, const Info& v) {
        if (l == r) {
            tree[p] = v;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (pos <= mid) set(p << 1, l, mid, pos, v);
        else set(p << 1 | 1, mid + 1, r, pos, v);
        pushup(p);
    }

    // 区间查询
    Info query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[p];
        pushdown(p);
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(p << 1, l, mid, ql, qr);
        if (ql > mid) return query(p << 1 | 1, mid + 1, r, ql, qr);
        return query(p << 1, l, mid, ql, qr) + query(p << 1 | 1, mid + 1, r, ql, qr);
    }

    // 辅助对外接口
    void modify(int l, int r, const Tag& t) { if (l <= r) modify(1, 1, n, l, r, t); }
    void set(int pos, const Info& v) { set(1, 1, n, pos, v); }
    Info query(int l, int r) { return query(1, 1, n, l, r); }

    // 线段树二分：找到 [ql, qr] 内第一个满足谓词 pred 的下标，不存在返回 -1
    template <class F>
    int find_first(int p, int l, int r, int ql, int qr, F pred) {
        if (l > qr || r < ql || !pred(tree[p])) return -1;
        if (l == r) return l;
        pushdown(p);
        int mid = (l + r) >> 1;
        int res = find_first(p << 1, l, mid, ql, qr, pred);
        if (res == -1) res = find_first(p << 1 | 1, mid + 1, r, ql, qr, pred);
        return res;
    }
    template <class F>
    int find_first(int l, int r, F pred) { return find_first(1, 1, n, l, r, pred); }
};



/*

---

### 填这个板子的“四步公式”

只要题目在适用范围内，你**永远不需要去碰** `LazySegmentTree` 主体。遇到新题时，只回答以下 4 个问题：

1. **`Info` 存什么？** 询问区间时需要返回什么答案，就存什么。
2. **`Info + Info` 怎么写？** 左右儿子合并时，父亲的各个字段怎么由两个儿子算出来。
3. **`Tag` 存什么？** 修改操作有什么参数（加法、乘法、覆盖）。两个连续操作复合时（`Tag::apply`），后来的操作怎么叠加到旧操作上。
4. **`Info::apply(Tag)` 怎么写？** 当一个区间被整体打上标记时，区间的各项信息怎么迅速更新。

---

### 常见场景实战配置

#### 案例 1：区间推平（覆盖赋值）+ 区间求和

区间赋值会直接覆盖原有的加法或未结算标记，因此需要一个布尔值记录“是否有覆盖”。

```cpp
struct Tag {
    long long cov = 0;
    bool has_cov = false;

    bool has() const { return has_cov; }

    // 新的标记 t 覆盖旧标记
    void apply(const Tag& t) {
        if (t.has_cov) {
            cov = t.cov;
            has_cov = true;
        }
    }
};

struct Info {
    long long sum = 0;
    int len = 1;

    Info() = default;
    Info(long long val, int l = 1) : sum(val), len(l) {}

    void apply(const Tag& t) {
        if (t.has_cov) {
            sum = t.cov * len; // 整个区间被推平成 cov
        }
    }
};

Info operator+(const Info& a, const Info& b) {
    return {a.sum + b.sum, a.len + b.len};
}

// 业务调用：把 [l, r] 区间所有数修改为 v
// seg.modify(l, r, Tag{v, true});

```

---

#### 案例 2：区间乘法 + 区间加法 + 区间和（洛谷 P3373 模板）

同时存在两种复合操作时，规定标记形式为 $x \leftarrow x \cdot mul + add$。
当新来一个操作 $(mul', add')$ 作用在原操作 $(mul, add)$ 上时：


$$x \cdot (mul \cdot mul') + (add \cdot mul' + add')$$

```cpp
constexpr int MOD = 571373; // 依题目给定的模数

struct Tag {
    long long mul = 1;
    long long add = 0;

    bool has() const { return mul != 1 || add != 0; }

    // 复合新操作 t
    void apply(const Tag& t) {
        mul = (mul * t.mul) % MOD;
        add = (add * t.mul + t.add) % MOD;
    }
};

struct Info {
    long long sum = 0;
    int len = 1;

    Info() = default;
    Info(long long val, int l = 1) : sum(val % MOD), len(l) {}

    void apply(const Tag& t) {
        sum = (sum * t.mul + t.add * len) % MOD;
    }
};

Info operator+(const Info& a, const Info& b) {
    return {(a.sum + b.sum) % MOD, a.len + b.len};
}

// 业务调用：
// 1. 区间 [l, r] 乘 k:  seg.modify(l, r, Tag{k, 0});
// 2. 区间 [l, r] 加 k:  seg.modify(l, r, Tag{1, k});

```

---

#### 案例 3：区间最大子段和（GSS1 / 洛谷 P4513）

单点修改，查询任意区间 $[L, R]$ 内连续子数组的最大和。这类题**不需要懒标记**，核心全在信息合并。

```cpp
struct Tag {
    bool has() const { return false; }
    void apply(const Tag& t) {}
};

struct Info {
    long long sum = 0;   // 区间总和
    long long lmax = 0;  // 紧靠左端点的最大前缀和
    long long rmax = 0;  // 紧靠右端点的最大后缀和
    long long ans = 0;   // 区间内最大连续子段和

    Info() = default;
    Info(long long val) {
        sum = lmax = rmax = ans = val;
    }
    void apply(const Tag& t) {}
};

Info operator+(const Info& a, const Info& b) {
    Info res;
    res.sum = a.sum + b.sum;
    res.lmax = max(a.lmax, a.sum + b.lmax);
    res.rmax = max(b.rmax, b.sum + a.rmax);
    res.ans = max({a.ans, b.ans, a.rmax + b.lmax});
    return res;
}

// 业务调用：
// 单点修改位置 pos 为 val:  seg.set(pos, Info(val));
// 查询区间 [l, r] 的最大子段和:  long long ans = seg.query(l, r).ans;

```

---

#### 案例 4：线段树二分（查找区间内第一个 $\ge V$ 的位置）

找在 $[L, R]$ 范围内第一个不小于 $V$ 的元素下标（常用于跳跃游戏、贪心排队等场景）。直接利用模板内写好的 `find_first`，传入 lambda 谓词即可：

```cpp
// 维护单点修改 + 区间最大值
struct Tag {
    bool has() const { return false; }
    void apply(const Tag& t) {}
};

struct Info {
    long long mx = -1e18;
    Info() = default;
    Info(long long val) : mx(val) {}
    void apply(const Tag& t) {}
};

Info operator+(const Info& a, const Info& b) {
    return {max(a.mx, b.mx)};
}

// 业务调用：
// 在 [L, R] 中找第一个 >= V 的下标：
int pos = seg.find_first(L, R, [&](const Info& info) {
    return info.mx >= V;
});

if (pos != -1) {
    // 找到了对应位置 pos
} else {
    // [L, R] 内所有元素都严格小于 V
}

```

*/