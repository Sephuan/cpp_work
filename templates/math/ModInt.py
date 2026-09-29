class MI:
    MOD = 998_244_353
    __slots__ = ('x',)
    def __init__(self, x=0):
        self.x = x % self.MOD
    def __add__(self, o):
        return MI(self.x + (o.x if isinstance(o, MI) else o))
    def __radd__(self, o):
        return MI(o + self.x)
    def __sub__(self, o):
        return MI(self.x - (o.x if isinstance(o, MI) else o))
    def __rsub__(self, o):
        return MI(o - self.x)
    def __mul__(self, o):
        return MI(self.x * (o.x if isinstance(o, MI) else o))
    def __rmul__(self, o):
        return MI(o * self.x)
    def __truediv__(self, o):
        if isinstance(o, MI):
            return MI(self.x * o.inv().x)
        return MI(self.x * pow(o % self.MOD, self.MOD - 2, self.MOD))
    def __pow__(self, e):
        return MI(pow(self.x, e, self.MOD))
    def inv(self):
        return MI(pow(self.x, self.MOD - 2, self.MOD))
    def __int__(self):
        return self.x
    def __eq__(self, o):
        return self.x == (o.x if isinstance(o, MI) else o % self.MOD)
    def __repr__(self):
        return str(self.x)