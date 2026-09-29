def cross(a, b, c):
    """
    计算向量 AB 与 AC 的二维叉积 (AB × AC)
    参数形式均为坐标元组/列表 (x, y)
    """
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])