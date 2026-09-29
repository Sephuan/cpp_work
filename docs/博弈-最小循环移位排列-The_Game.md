# Problem D. The Game —— 最小循环移位 + 博弈

> 关键词：<span style="color:#FF6347">最小循环移位</span>、<span style="color:#4169E1">字典序博弈</span>、<span style="color:#00FF7F">状态化简</span>、<span style="color:#FFD700">构造 O(n)</span>

---

## 一、题意

Alice 和 Bob 轮流往一个空序列末尾追加数字，一共 $n$ 步，Alice 先手：

- 每步从 $1\sim n$ 中选一个<span style="color:#FF7F50">尚未用过</span>的数，追加到序列末尾；
- $n$ 步后序列恰好是 $1\sim n$ 的一个排列 $p$。

对排列 $p$，定义 $f(p)$ 为 $p$ 的<span style="color:#FF6347">所有循环移位中字典序最小</span>的那一个。

- <span style="color:#00BFFF">Alice</span> 想让 $f(p)$ 字典序<span style="color:#00FF7F">尽可能小</span>；
- <span style="color:#FF69B4">Bob</span> 想让 $f(p)$ 字典序<span style="color:#FF6347">尽可能大</span>。

双方都最优，求最终的 $f(p)$。

数据范围：$T\le 10^5$，$1\le n\le 5\cdot 10^5$，$\sum n\le 5\cdot 10^5$。

样例：

| n | 答案 |
|---|---|
| 1 | 1 |
| 2 | 1 2 |
| 3 | 1 3 2 |
| 4 | 1 3 2 4 |

---

## 二、化简第一步：$f(p)$ 到底长什么样

<span style="color:#FFD700">引理 1</span>：$f(p)$ 就是<span style="color:#FF6347">把 $p$ 旋转到数字 1 打头</span>的那个序列。

证明很直白：$p$ 是 $1\sim n$ 的排列，所以数字 $1$ <span style="color:#00FF7F">恰好出现一次</span>，而且它是全局最小值。比较两个循环移位时先看第一位，凡是首位不是 $1$ 的移位，首位 $\ge 2$，一定大于那个首位是 $1$ 的移位。而首位是 $1$ 的移位<span style="color:#DA70D6">只有一个</span>（因为 1 只出现一次），所以最小移位唯一确定。

例：$p=(3,2,4,1)$，四个移位是 $(3,2,4,1),(2,4,1,3),(4,1,3,2),(1,3,2,4)$，最小的就是 $1$ 打头的 $(1,3,2,4)$。

<span style="color:#FF6B81">推论</span>：答案第一位<span style="color:#FF6B81">永远是 1</span>。真正要博弈的是「1 后面跟着谁」。

---

## 三、化简第二步：把「追加」翻译成「环」

追加只在末尾发生，而 $f$ 是循环读的，所以可以把序列想成一个<span style="color:#4169E1">环</span>：末尾元素的下一个就是首元素。

以 $n=4$、实际落子顺序 $3,2,4,1$ 为例：

```mermaid
graph LR
  A["第1步 3"] --> B["第2步 2"]
  B --> C["第3步 4"]
  C --> D["第4步 1"]
  D -->|"环回"| A
```

从 $1$ 出发绕一圈读出来：$1\to 3\to 2\to 4$，即答案 `1 3 2 4`。

把这个观察写成通用形式。设数字 $1$ 是在<span style="color:#FFD700">第 $t$ 步</span>被落下的，落子序列为 $p_1,p_2,\dots,p_n$（$p_t=1$），那么

$$f(p)=\underbrace{1}_{\text{锚点}},\;\underbrace{p_{t+1},p_{t+2},\dots,p_n}_{\text{在 1 之后落的}},\;\underbrace{p_1,p_2,\dots,p_{t-1}}_{\text{在 1 之前落的}}$$

<span style="color:#FFD700">引理 2</span>（三段式）：

答案 = <span style="color:#FF6B81">1</span> + <span style="color:#00FF7F">「1 之后落的，按落子顺序」</span> + <span style="color:#DA70D6">「1 之前落的，按落子顺序」</span>。

这条是<span style="color:#FF6347">全题的核心</span>，它说明：

- 在 $1$ <span style="color:#00BFFF">之后</span>落的子，占据答案<span style="color:#00FF7F">最靠前、最要命</span>的位置；
- 在 $1$ <span style="color:#00BFFF">之前</span>落的子，被<span style="color:#DA70D6">挤到答案尾巴</span>上，几乎不影响字典序。

所以「落 1」这一步就像一个<span style="color:#FF6347">开关</span>：谁按下它，谁就把答案最值钱的第 2 位<span style="color:#FF6B81">拱手让给对手</span>（因为下一步是对手走）。

---

## 四、化简第三步：1 一落地，后面全是无脑贪心

<span style="color:#FFD700">引理 3</span>：一旦 $1$ 被落下，剩下的过程<span style="color:#FF6347">完全确定</span>，没有任何博弈成分。

设 $1$ 在第 $t$ 步落下，剩余可用集合为 $R$（$|R|=n-t$）。由引理 2，第 $t+1,t+2,\dots,n$ 步依次填答案的 $a_2,a_3,\dots,a_{n-t+1}$，而尾巴部分早已<span style="color:#DA70D6">冻结</span>。

字典序的性质是：$a_2$ 的大小<span style="color:#FF6347">压倒</span>后面所有位的一切组合。也就是说轮到填 $a_2$ 的人，不管后面怎么演化，只要把 $a_2$ 弄到自己想要的极值就一定不亏。而剩余集合里<span style="color:#00FF7F">任何数都能放</span>，所以：

- 轮到 <span style="color:#00BFFF">Alice</span> 填 → 取 $\min R$；
- 轮到 <span style="color:#FF69B4">Bob</span> 填 → 取 $\max R$。

然后对 $a_3$ 归纳同理。于是后半段是一个<span style="color:#FFD700">最小-最大交替取端点</span>的过程。

举例：$1$ 在第 8 步落下，$n=10$，$R=\{2,3,4,7,8,9,10\}$，第 9 步是 Alice（奇数步）：

| 步 | 走子方 | 取法 | 值 | 填入 |
|---|---|---|---|---|
| 9 | Alice | min | 2 | $a_2$ |
| 10 | Bob | max | 10 | $a_3$ |

<span style="color:#FF6B81">这条引理把整个游戏压缩成了一个问题</span>：

> 双方在「不落 1」时随便烧掉别的数（烧掉的进答案尾巴），核心只有一件事——<span style="color:#FF6347">谁在什么时候按下「落 1」这个开关</span>。

---

## 五、双方的动机：一场「烧数字」的对攻

由引理 3，若<span style="color:#FFD700">我方</span>落 1，则 $a_2$ 由<span style="color:#FF6B81">对手</span>取端点：

| 落 1 的人 | $a_2$ 变成 | 对落 1 者 |
|---|---|---|
| Alice（奇数步） | $\max R$ | <span style="color:#FF6347">极亏</span>（把最大数塞到第 2 位） |
| Bob（偶数步） | $\min R$ | <span style="color:#FF6347">极亏</span>（把最小数塞到第 2 位） |

所以<span style="color:#FF6B81">谁都不想主动落 1</span>——除非剩余集合 $R$ 已经被自己「调教」成对自己有利的样子：

- <span style="color:#FF69B4">Bob</span> 想落 1 前，先<span style="color:#FF6347">把小数字烧光</span>，让 $\min R$ 尽量大；
- <span style="color:#00BFFF">Alice</span> 想落 1 前，先<span style="color:#00FF7F">把大数字烧光</span>，让 $\max R$ 尽量小。

于是形成一场<span style="color:#DA70D6">对撞</span>：Bob 从 $2$ 往上烧，Alice 从 $n$ 往下烧，一人一步，<span style="color:#FFD700">在正中间会师</span>。会师时活下来的最小数大约就是 $n/2+1$——这正是答案第 2 位的来源。

### 打表验证这个直觉

$n=10$，枚举 Alice 第一步走什么，后面双方最优（暴力搜索得到的博弈值）：

| Alice 首步 | 博弈值 |
|---|---|
| 1 | 1 <span style="color:#FF6347">10</span> 2 9 3 8 4 7 5 6 |
| 2 | 1 <span style="color:#FFD700">6</span> 7 2 5 8 4 9 3 10 |
| 3 | 1 <span style="color:#FFD700">6</span> 7 3 5 8 4 9 2 10 |
| 4 | 1 <span style="color:#FFD700">6</span> 7 4 5 8 3 9 2 10 |
| 5 | 1 <span style="color:#FFD700">6</span> 7 5 4 8 3 9 2 10 |
| <span style="color:#00FF7F">6</span> | 1 <span style="color:#FFD700">6</span> <span style="color:#00FF7F">5</span> 7 4 8 3 9 2 10 ← <span style="color:#00FF7F">最优</span> |
| 7 | 1 <span style="color:#FFD700">6</span> 7 5 8 4 9 3 10 2 |
| 8 | 1 <span style="color:#FFD700">6</span> 8 5 7 4 9 3 10 2 |
| 9 | 1 <span style="color:#FFD700">6</span> 9 5 7 4 8 3 10 2 |
| 10 | 1 <span style="color:#FFD700">6</span> 10 5 7 4 8 3 9 2 |

读出两条信息：

1. 除了自杀式的「首步落 1」，$a_2$ <span style="color:#FF6B81">恒等于 6</span>。也就是 $a_2=\lceil n/2\rceil+1$ 是<span style="color:#FFD700">双方都无法撬动</span>的均衡值：Bob 保证 $a_2\ge 6$，Alice 保证 $a_2\le 6$。
2. Alice 在 $a_2$ 已定的前提下继续<span style="color:#00FF7F">优化第 3 位</span>，首步走 6 得到 $a_3=5$，是所有选择里最小的。

### 均衡对局长什么样（$n=10$，$k=5$）

落子：`A6 B5 A7 B4 A8 B3 A9 B2 A10 B1`

- <span style="color:#00BFFF">Alice 的地盘</span>是<span style="color:#00FF7F">上半段</span> $\{6,7,8,9,10\}$，按<span style="color:#00FF7F">升序</span>烧（她绝不去烧小数，那等于帮 Bob 抬高 $\min R$）；
- <span style="color:#FF69B4">Bob 的地盘</span>是<span style="color:#FF6347">下半段</span> $\{5,4,3,2\}$，按<span style="color:#FF6347">降序</span>烧（他必须烧小数，否则 Alice 一按开关就拿到 $a_2=2$）；
- 到最后一步只剩 $1$，<span style="color:#FF6B81">Bob 被迫落 1</span>（$n$ 是偶数，末步归 Bob），此时 $R=\varnothing$；
- 由引理 2，答案 = $1$ + 全部落子序列 = `1 6 5 7 4 8 3 9 2 10`。

为什么<span style="color:#FF69B4">Bob</span> 明明想让尾巴大、却去走小数 5,4,3,2？因为尾巴是<span style="color:#DA70D6">次要目标</span>，保住「按开关的威胁」才是主要目标。反例验证（$n=10$，前缀 `A6`）：

| Bob 第二步 | 博弈值 |
|---|---|
| 1 | 1 <span style="color:#00FF7F">2</span> 10 3 9 4 8 5 7 6 |
| <span style="color:#FF6347">5</span> | 1 6 <span style="color:#FF6347">5</span> 7 4 8 3 9 2 10 ← <span style="color:#FF6347">最优</span> |
| 7 | 1 <span style="color:#00FF7F">5</span> 6 7 8 4 9 3 10 2 |
| 10 | 1 <span style="color:#00FF7F">5</span> 6 10 7 4 8 3 9 2 |

Bob 若走大数 7 或 10，$a_2$ 立刻从 6 掉到 <span style="color:#00FF7F">5</span>——因为 5 被留在了 $R$ 里，Alice 到残局时（只剩 $\{1,5\}$）自己按下开关，Bob 被迫补上 5。Bob 若立刻落 1，$a_2$ 直接掉到 <span style="color:#00FF7F">2</span>，更惨。

### 奇偶为什么不一样

关键在<span style="color:#FFD700">末步归谁</span>：

| $n$ | 末步 | 若谁都不按开关 | 后果 |
|---|---|---|---|
| 偶数 | <span style="color:#FF69B4">Bob</span> | Bob 被迫落 1，$R=\varnothing$ | 答案 = 1 + 落子序列，$a_2$ = <span style="color:#00BFFF">Alice 首步</span> |
| 奇数 | <span style="color:#00BFFF">Alice</span> | Alice 落 1 反而<span style="color:#00FF7F">很舒服</span>（$a_2$ = 她自己首步，可设为 2） | Bob 不能容忍，必须<span style="color:#FF6347">提前一步</span>（第 $n-1$ 步）按开关 |

所以：

- <span style="color:#4169E1">偶数 $n=2k$</span>：$1$ 在<span style="color:#FFD700">第 $n$ 步</span>落下，$a_2$ 就是 Alice 首步，她只能<span style="color:#FF6B81">把首步花在 $k+1$ 上</span>（走更小的会被 Bob 用「烧小数 + 提前按开关」的方案打回 $k+1$，还白丢一个好位置）。
- <span style="color:#4169E1">奇数 $n=2k+1$</span>：$1$ 在<span style="color:#FFD700">第 $n-1$ 步</span>由 Bob 落下，只剩一个数留给 Alice 填 $a_2$，对撞的结果是 $a_2=k+2$。既然 $a_2$ 撬不动，Alice 就把首步<span style="color:#00FF7F">白送成 2</span>，去抢 $a_3$（此时 $a_3$ 恰好等于她的首步）。

$n=9$ 的均衡对局：`A2 B5 A7 B4 A8 B3 A9 B1 A6`

- Alice 首步 2（廉价占坑），随后烧大数 7,8,9；
- Bob 烧 5,4,3 抬高 $\min R$，第 8 步按开关落 1，$R=\{6\}$；
- Alice 第 9 步补 6，得 $a_2=6=k+2$；
- 答案 = $1$ + $[6]$ + $[2,5,7,4,8,3,9]$ = `1 6 2 5 7 4 8 3 9`。

---

## 六、结论：$O(n)$ 构造公式

统一记 $a_2=\lceil n/2\rceil+1$，分奇偶给出完整序列。

### 偶数 $n=2k$

$$1,\;\underbrace{k+1,\;k}_{},\;\underbrace{k+2,\;k-1}_{},\;\underbrace{k+3,\;k-2}_{},\;\dots,\;2,\;2k$$

即：先输出 1，然后 <span style="color:#00BFFF">hi 从 $k+1$ 递增</span>、<span style="color:#FF69B4">lo 从 $k$ 递减</span>，交替输出（hi 先走）。

### 奇数 $n=2k+1$（$n\ge 3$）

$$1,\;k+2,\;2,\;\underbrace{k+1,\;k+3}_{},\;\underbrace{k,\;k+4}_{},\;\dots$$

即：先输出 `1, k+2, 2`，然后 <span style="color:#FF69B4">lo 从 $k+1$ 递减</span>、<span style="color:#00BFFF">hi 从 $k+3$ 递增</span>，交替输出（lo 先走）。

$n=1$ 特判输出 `1`。

### 打表核对（已与暴力搜索逐位比对，$n\le 12$ 全部一致）

| $n$ | 答案 |
|---|---|
| 1 | 1 |
| 2 | 1 2 |
| 3 | 1 3 2 |
| 4 | 1 3 2 4 |
| 5 | 1 4 2 3 5 |
| 6 | 1 4 3 5 2 6 |
| 7 | 1 5 2 4 6 3 7 |
| 8 | 1 5 4 6 3 7 2 8 |
| 9 | 1 6 2 5 7 4 8 3 9 |
| 10 | 1 6 5 7 4 8 3 9 2 10 |
| 11 | 1 7 2 6 8 5 9 4 10 3 11 |
| 12 | 1 7 6 8 5 9 4 10 3 11 2 12 |

<span style="color:#FFD700">口诀</span>：<span style="color:#FF6B81">1 打头，中点起跳，一上一下交替铺满</span>；<span style="color:#00BFFF">偶数直接跳</span>，<span style="color:#FF69B4">奇数先塞个 2</span>。

---

## 七、代码（C++，$O(\sum n)$）

```cpp
#include <bits/stdc++.h>
using namespace std;

static char ibuf[1 << 22]; int ipos, ilen;
inline int gc(){
    if(ipos == ilen){
        ilen = (int)fread(ibuf, 1, sizeof(ibuf), stdin);
        ipos = 0;
        if(ilen <= 0) return -1;
    }
    return ibuf[ipos++];
}
inline int readInt(){
    int c = gc();
    while(c < '0' || c > '9') c = gc();
    int x = 0;
    while(c >= '0' && c <= '9'){ x = x * 10 + (c - '0'); c = gc(); }
    return x;
}

static char obuf[1 << 23]; int opos;
inline void writeInt(int x, char sep){
    char t[12]; int m = 0;
    if(!x) t[m++] = '0';
    while(x){ t[m++] = char('0' + x % 10); x /= 10; }
    while(m) obuf[opos++] = t[--m];
    obuf[opos++] = sep;
}

int a[500005];

int main(){
    int T = readInt();
    while(T--){
        int n = readInt();
        a[0] = 1;                      // 引理1：答案必以 1 打头
        if(n % 2 == 0){                // n = 2k：hi 升 / lo 降，hi 先
            int hi = n / 2 + 1, lo = n / 2, i = 1;
            while(i < n){
                a[i++] = hi++;
                if(i < n) a[i++] = lo--;
            }
        } else if(n > 1){              // n = 2k+1：开头 1, k+2, 2；之后 lo 降 / hi 升，lo 先
            int k = (n - 1) / 2;
            a[1] = k + 2;
            a[2] = 2;
            int lo = k + 1, hi = k + 3, i = 3;
            while(i < n){
                a[i++] = lo--;
                if(i < n) a[i++] = hi++;
            }
        }
        for(int i = 0; i < n; i++) writeInt(a[i], i + 1 == n ? '\n' : ' ');
    }
    fwrite(obuf, 1, opos, stdout);
    return 0;
}
```

复杂度：时间 $O(\sum n)$，额外空间 $O(\max n)$。

---

## 八、坑点清单

1. <span style="color:#FF6347">$n=1$ 必须特判</span>：奇数分支要访问 `a[1]`、`a[2]`，$n=1$ 时会越界写脏数据。
2. <span style="color:#FF6347">$n=2,3$ 的边界</span>：$n=2$ 时 lo 一次都不输出；$n=3$ 时开头三个数就填满了，交替循环一次都不进。写成 `while(i < n)` + 内层再判 `if(i < n)` 就自动兼容。
3. <span style="color:#FF6347">IO 是真瓶颈</span>：$T$ 最大 $10^5$，输出总量约 $5\cdot 10^5$ 个数。别用 `endl`，最好上手写快读快写或至少 `sync_with_stdio(false)`。
4. <span style="color:#FF6B81">不要试图模拟博弈</span>：暴力搜索是 $O(n!)$ 级别，本题只能靠上面的结论直接构造。
5. <span style="color:#DA70D6">别忘了 $f$ 不是 $p$</span>：题目要输出的是<span style="color:#FF6347">最小循环移位</span>，不是落子序列本身，所以答案首位一定是 1。

---

## 九、方法论小结

这题的价值不在结论，而在<span style="color:#FFD700">化简链条</span>：

```
原问题：n! 状态的字典序博弈
  ↓ 引理1（1 是唯一最小值）
f(p) = 旋转到 1 打头
  ↓ 引理2（追加 = 环）
答案 = 1 + (1 之后落的) + (1 之前落的)
  ↓ 引理3（字典序高位压倒低位）
落 1 之后全是 min/max 交替贪心，零博弈
  ↓ 只剩一个决策
"谁在第几步按下落 1 这个开关"
  ↓ 烧数字对撞，中点会师
a₂ = ⌈n/2⌉+1，整个序列被确定
```

可复用的三条经验：

- <span style="color:#00BFFF">循环移位类问题</span>：先找<span style="color:#FF6B81">唯一锚点</span>（这里是最小值 1），把「循环」拍平成「线性」。
- <span style="color:#00FF7F">字典序博弈</span>：高位<span style="color:#FF6347">绝对压倒</span>低位，所以只要某一位「谁都能随便填」，那一位就是<span style="color:#FFD700">纯贪心</span>，博弈只发生在「决定谁来填这一位」的地方。
- <span style="color:#DA70D6">找不到证明就打表</span>：先写 $O(n!)$ 记忆化 minimax 跑 $n\le 12$，看出规律再回头补直觉，比硬推快得多。
