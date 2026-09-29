# 算法模板索引 (Algorithm Templates Index)

本目录按算法竞赛各大核心板块组织了 C++ 与 Python 高质量可复用模板代码。

> 完整算法手册、数学推导与全真代码块请参见项目根目录的 [`算法模板.md`](../算法模板.md)。

---

## 板块目录结构

```text
templates/
├── basic/            # 基础工程与缺省源 (缺省源、快速IO、离散化、二维前缀和)
├── data_structures/  # 经典与高级数据结构 (并查集、树状数组、线段树、字典树、01-Trie、线性基)
├── math/             # 数论与代数 (自动取模类、组合数学、扩展欧几里得、素数筛、高精度、卢卡斯定理)
├── graph/            # 图论与树论 (最短路 Dijkstra、动态树直径)
└── strings/          # 字符串算法 (KMP 匹配、回文串生成与处理)
```

---

## 1. 基础工程与工具 (`templates/basic/`)

| 文件名 | 语言 | 功能说明 | 核心特性 / 复杂度 |
| :--- | :---: | :--- | :--- |
| [`template.cpp`](basic/template.cpp) | C++ | C++ 标准竞赛工程缺省源 | 快读解绑、多测框架、八方向位移向量、`__int128` |
| [`template.py`](basic/template.py) | Python | Python 竞赛缺省源骨架 | `sys.stdin.readline`、快速输入包装、常用容器 |
| [`py_1.py`](basic/py_1.py) | Python | Python 多测解题骨架 | 轻量单测/多测快速切换 |
| [`FastIO.cpp`](basic/FastIO.cpp) | C++ | 极速输入输出流 | `getchar_unlocked` / 负数友好快读，大数据量必备 |
| [`离散化.cpp`](basic/离散化.cpp) | C++ | 坐标/值域离散化 | `sort` + `unique` + `lower_bound`，$O(N \log N)$ |
| [`二维前缀和.cpp`](basic/二维前缀和.cpp) | C++ | 二维前缀和与区间和查询 | 容斥递推预处理，$O(1)$ 矩形区域和查询 |

---

## 2. 数据结构 (`templates/data_structures/`)

| 文件名 | 语言 | 功能说明 | 核心特性 / 复杂度 |
| :--- | :---: | :--- | :--- |
| [`01-Trie.cpp`](data_structures/01-Trie.cpp) | C++ | 01 字典树 (异或字典树) | 异或最大/最小值、异或第 $k$ 小、阈值计数 |
| [`trie.cpp`](data_structures/trie.cpp) | C++ | 字符串字典树 (Trie) | 静态多叉树、字符串频次与前缀匹配统计 |
| [`trie.py`](data_structures/trie.py) | Python | 一维扁平字典树 (Trie) | 针对 PyPy 深度优化，支持插入、删除、前缀计数 |
| [`DSU.cpp`](data_structures/DSU.cpp) | C++ | 并查集 (Disjoint Set Union) | 路径压缩、按秩/大小合并、连通分量计数 |
| [`DSU.py`](data_structures/DSU.py) | Python | 并查集 (Python 版) | 减半路径压缩、循环防递归爆栈 |
| [`Fenwick.cpp`](data_structures/Fenwick.cpp) | C++ | 树状数组 (Binary Indexed Tree) | 单点增减、前缀和、区间和、倍增 $O(\log N)$ 查第 $k$ 小 |
| [`Fenwick.py`](data_structures/Fenwick.py) | Python | 树状数组 (Python 版) | 1-based 线性建树、倍增 $O(\log N)$ `kth` 阈值查找 |
| [`LazySegmentTree.cpp`](data_structures/LazySegmentTree.cpp) | C++ | 通用 Lazy 标记线段树 | 现代化 Tag/Info 解耦设计，支持区间加、区间最值、区间求和 |
| [`SegmentTree.py`](data_structures/SegmentTree.py) | Python | 线段树 (Python 版) | 完整 Lazy 标记区间修改与区间和/最值查询 |
| [`线性基.cpp`](data_structures/线性基.cpp) | C++ | 线性基 (Linear Basis) | 子集异或最大/最小、存在性判定、第 $k$ 小异或和、基底合并 |
| [`LinearBasis.cpp`](data_structures/LinearBasis.cpp) | C++ | 线性基 (英文命名版) | 同上，便于不同环境与编辑器命名习惯 |

---

## 3. 数论与代数 (`templates/math/`)

| 文件名 | 语言 | 功能说明 | 核心特性 / 复杂度 |
| :--- | :---: | :--- | :--- |
| [`ModInt.cpp`](math/ModInt.cpp) | C++ | 自动取模类 | 运算符重载、快速幂、费马小定理逆元、防溢出 |
| [`ModInt.py`](math/ModInt.py) | Python | 自动取模类 (Python 版) | 魔术方法重载、自动负数转正模 |
| [`BigInt.cpp`](math/BigInt.cpp) | C++ | 结构体大整数类 | 支持高精度加、减、乘、除、模及运算符重载 |
| [`高精度模版.cpp`](math/高精度模版.cpp) | C++ | 过程式大数字符串计算 | 轻量免结构体实现大数加减乘除 |
| [`标准卢卡斯定理.cpp`](math/标准卢卡斯定理.cpp) | C++ | 卢卡斯定理 (Lucas) | 求解大组合数对质数取模 $C(n, m) \pmod p$ |
| [`Combination.py`](math/Combination.py) | Python | 组合数学工具类 | 线性预处理阶乘逆元、$O(1)$ 组合数、卢卡斯定理、卡特兰数 |
| [`cross.py`](math/cross.py) | Python | 二维向量叉积 | 二维点向量几何基础，计算 $AB \times AC$ 旋向与面积 |
| [`exgcd.py`](math/exgcd.py) | Python | 扩展欧几里得算法 | 求解贝祖等式、求任意模数逆元、线性递推逆元 |
| [`sieve.py`](math/sieve.py) | Python | 线性筛与积性函数 | 欧拉筛、最小质因数快速分解、欧拉函数 $\phi$、莫比乌斯函数 $\mu$ |
| [`E_sieve.cpp`](math/E_sieve.cpp) | C++ | 埃氏筛法 | $O(N \log \log N)$ 基础质数筛法 |
| [`ola.cpp`](math/ola.cpp) | C++ | 欧拉线性筛法 | 严格 $O(N)$ 线性质数筛与合数标记 |
| [`mr_test.cpp`](math/mr_test.cpp) | C++ | Miller-Rabin 大素数测试 | 确定性底数集，单次 $O(k \log^3 N)$ 判定 $2^{64}$ 内大数素性 |

---

## 4. 图论与树论 (`templates/graph/`)

| 文件名 | 语言 | 功能说明 | 核心特性 / 复杂度 |
| :--- | :---: | :--- | :--- |
| [`dijkstra.py`](graph/dijkstra.py) | Python | 堆优化 Dijkstra 最短路 | 小根堆优先队列，支持非负权图单源最短路与快速 IO |
| [`DynamicTreeDiameter.cpp`](graph/DynamicTreeDiameter.cpp) | C++ | 动态树直径维护 | 树上倍增 LCA、动态加点维护树的最远点对 (直径) |

---

## 5. 字符串算法 (`templates/strings/`)

| 文件名 | 语言 | 功能说明 | 核心特性 / 复杂度 |
| :--- | :---: | :--- | :--- |
| [`KMP.cpp`](strings/KMP.cpp) | C++ | KMP 字符串模式匹配 | $\pi$ 前缀函数计算，严格 $O(|S| + |T|)$ 匹配所有出现位置 |
| [`gen_palindrome.py`](strings/gen_palindrome.py) | Python | 回文数/回文串生成器 | 生成器模式高效产出指定范围内的对称回文结构 |
