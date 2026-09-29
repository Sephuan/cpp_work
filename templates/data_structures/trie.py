class Trie:
    """
    1D 连续扁平数组 Trie (适配 PyPy / 兼顾多测安全)

    【复杂度】
    - 时间复杂度:
      * __init__: O(1)
      * insert / delete / countWord / countPrefix / findLongestPrefixTag: O(|S|)
        其中 |S| 为当前操作的字符串长度，字符集大小固定为 26。
    - 空间复杂度:
      * O(V * 26)，其中 V 为插入的所有前缀形成的唯一节点总数，动态按需扩容。

    【用法规范】
    - t = Trie()
        初始化空字典树。多测题目在每组数据内独立新建即可，无内存泄漏与额外开销。
    - t.insert(s, val=1, tag=0) -> int:
        插入字符串 s。val 为权值/频次增量，tag 为附加数据（如原输入下标、时间戳）。返回终止节点编号。
    - t.delete(s, val=1) -> bool:
        逻辑删除 s，扣减 val 频次。若树中数量不足返回 False，删除成功返回 True。
    - t.countWord(s) -> int:
        精准查询完全匹配 s 的有效单词数量。
    - t.countPrefix(s) -> int:
        查询以 s 为前缀的有效单词总数。
    - t.findLongestPrefixTag(s) -> int:
        查找 s 的最长有效前缀单词，并返回其 tag。若无匹配前缀则返回 0。
    """
    __slots__ = ('ch', 'passCnt', 'endCnt', 'tag')

    def __init__(self):
        self.ch = [0] * 26
        self.passCnt = [0]
        self.endCnt = [0]
        self.tag = [0]

    def insert(self, s: str, val: int = 1, tag: int = 0) -> int:
        u = 0
        self.passCnt[0] += val
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            idx = u * 26 + (ord(c) - 97)
            nxt = ch[idx]
            if not nxt:
                nxt = len(passCnt)
                ch[idx] = nxt
                ch.extend([0] * 26)
                passCnt.append(0)
                self.endCnt.append(0)
                self.tag.append(0)
            u = nxt
            passCnt[u] += val
        self.endCnt[u] += val
        if tag:
            self.tag[u] = tag
        return u

    def delete(self, s: str, val: int = 1) -> bool:
        if self.countWord(s) < val:
            return False
        u = 0
        self.passCnt[0] -= val
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            passCnt[u] -= val
        self.endCnt[u] -= val
        if self.endCnt[u] == 0:
            self.tag[u] = 0
        return True

    def countWord(self, s: str) -> int:
        u = 0
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return 0
        return self.endCnt[u]

    def countPrefix(self, s: str) -> int:
        u = 0
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return 0
        return passCnt[u]

    def findLongestPrefixTag(self, s: str) -> int:
        u = 0
        bestTag = 0
        ch, passCnt, endCnt, tag = self.ch, self.passCnt, self.endCnt, self.tag
        for c in s:
            if endCnt[u]:
                bestTag = tag[u]
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return bestTag
        if endCnt[u]:
            bestTag = tag[u]
        return bestTag

"""

class Trie:
    __slots__ = ('ch', 'passCnt', 'endCnt', 'tag')
    def __init__(self):
        self.ch = [0] * 26
        self.passCnt = [0]
        self.endCnt = [0]
        self.tag = [0]
    def insert(self, s: str, val: int = 1, tag: int = 0) -> int:
        u = 0
        self.passCnt[0] += val
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            idx = u * 26 + (ord(c) - 97)
            nxt = ch[idx]
            if not nxt:
                nxt = len(passCnt)
                ch[idx] = nxt
                ch.extend([0] * 26)
                passCnt.append(0)
                self.endCnt.append(0)
                self.tag.append(0)
            u = nxt
            passCnt[u] += val
        self.endCnt[u] += val
        if tag:
            self.tag[u] = tag
        return u
    def delete(self, s: str, val: int = 1) -> bool:
        if self.countWord(s) < val:
            return False
        u = 0
        self.passCnt[0] -= val
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            passCnt[u] -= val
        self.endCnt[u] -= val
        if self.endCnt[u] == 0:
            self.tag[u] = 0
        return True
    def countWord(self, s: str) -> int:
        u = 0
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return 0
        return self.endCnt[u]
    def countPrefix(self, s: str) -> int:
        u = 0
        ch, passCnt = self.ch, self.passCnt
        for c in s:
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return 0
        return passCnt[u]
    def findLongestPrefixTag(self, s: str) -> int:
        u = 0
        bestTag = 0
        ch, passCnt, endCnt, tag = self.ch, self.passCnt, self.endCnt, self.tag
        for c in s:
            if endCnt[u]:
                bestTag = tag[u]
            u = ch[u * 26 + (ord(c) - 97)]
            if not u or not passCnt[u]:
                return bestTag
        if endCnt[u]:
            bestTag = tag[u]
        return bestTag

"""