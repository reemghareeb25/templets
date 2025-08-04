 **Cross Product (Collinearity Check)**
To check if **3 points** lie on the same straight line (**collinear**):
**Given points:**
- **P1(x1, y1)**
- **P2(x2, y2)**
- **P3(x3, y3)**
**Steps:**

1. Calculate differences:
```
dx1 = x2 - x1  
dy1 = y2 - y1  
dx2 = x3 - x1  
dy2 = y3 - y1
```
2. Compute cross product:
```
cross_product = dx1 * dy2 - dy1 * dx2
```
3. Decision:
- If **Cross product == 0** → Points are **collinear**.
- Otherwise → Not collinear.
----
**📝 Quick C++ Function:**
```cpp
bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1);
}
```
