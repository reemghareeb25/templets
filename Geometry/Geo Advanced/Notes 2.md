### Transformations 
1) Translation 
2) Scaling
3) Rotating 

`pt translate(pt p, pt v){ // translate point p with vector v`  
    `return p+v;`  
`}`  

`pt scale(pt c, ld factor, pt p){ // scale point p with specific factor around point c`  
    `return c + (p-c) * factor;`  
`}`  

`pt rotate(pt p, pt c, ld a){ // To rotate point p around point c with a specific angle with radian`  
    `pt v = p - c; // vector between two points`  
    `pt rotate = {cos(a), sin(a)};`  
    `return c + rotate * v;`  
`}`

`pt linearTransformation(pt p, pt q, pt r, pt fp, pt fq){`  
    `return fp + (r-p) * (fq-fp) / (q-p);`  
`}`

----
### Dot product and cross product + angles

##### Dot Product
`T dot(pt v, pt w){`  
    `return v.x * w.x + v.y * w.y;`  
`}`

##### Cross product 
`T cross(pt v, pt w){`  
    `return v.x * w.y - v.y * w.x;`  
`}`
##### to get angle between two vectors out from the origin point (0, 0)
`T angle(pt v, pt w){` 
    `return acos(clamp(dot(v, w) / abs(v) / abs(w), (T)-1.0, (T)1.0));`  
`}`
##### to get an angle between a vector and x-axis  (Polar angle)
`const ld EPS = 1e-9;`  
`const ld PI = 3.141592653589793238L;`

`int sgn(T val){`  
    `if(val > EPS) return 1;`  
    `if(val < -EPS) return -1;`  
    `else return 0;`  
`}`  
  
`void RIM() {`  
    `ld x, y;`  
    `cin >> x >> y;`  
    `ld c = atan2(y, x);`  
    `if(sgn(c) == -1)`  
        `c += 2 * PI;`  
    `cout << fixed << setprecision(10) << c;`  
`}`
##### To check if an angle between two vectors is perpendicular
`bool isPerp(pt v, pt w){  
    `return fabs(dot(v, w)) < EPS;`  
`}`
##### if we have a vector (a, b), vector(-b, a) will be perpendicular on it on it's left side.
`pt perp(pt v){`  
    `return (-v.y, v.x);`  
`}`

