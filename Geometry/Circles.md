**const double PI = 3.14159265358979323846;**
### 1. **Distance Between Two Points (Centers of Circles)**:
   The distance $d$ between two points $(x1, y1)$  and  $(x2, y2)$  is calculated using the **Euclidean distance formula**:
   $d = \sqrt{(x2 - x1)^2 + (y2 - y1)^2}$
   This is used to determine the relative positions of the two circles.

---
### 2. **Area of a Circle**:
   The area \( A \) of a circle with radius $r$ is given by:
   $A = \pi r^2$
   This is used to calculate the area of each circle.

---
### 3. **Conditions for Circle Intersection**:
   - **No Intersection**:
     If the distance $d$ between the centers is greater than or equal to the sum of the radii $( d \geq r1 + r2 )$, the circles **do not intersect.**
   - **One Circle Inside the Other**:
     If the distance $d$ is less than the absolute difference of the radii $( d < |r1 - r2| )$, one circle is completely inside the other without intersecting.
   - **Tangent Circles**:
     If the distance $d$ equals the sum or difference of the radii $( d = r1 + r2 )$ or $( d = |r1 - r2| )$, the circles touch at exactly one point (tangent).
   - **Partial Intersection**:
     If the distance $d$ is between the sum and difference of the radii $( |r1 - r2| < d < r1 + r2 )$, the circles intersect at two points.

---

### 4. **Area of Intersection of Two Circles**:
   When two circles intersect partially, the area of intersection can be calculated using the following steps:
   - **Step 1**: Calculate the distance $d$ between the centers.
   - **Step 2**: Use the **Law of Cosines** to find the angles subtended by the chord at the centers of the circles:
     $\text{angle1} = \cos^{-1}\left(\frac{r1^2 + d^2 - r2^2}{2 \cdot r1 \cdot d}\right)$ 
     $\text{angle2} = \cos^{-1}\left(\frac{r2^2 + d^2 - r1^2}{2 \cdot r2 \cdot d}\right)$
   - **Step 3**: Calculate the area of the sectors of the circles:
     $\text{sectorArea1} = r1^2 \cdot \text{angle1}$
     $\text{sectorArea2} = r2^2 \cdot \text{angle2}$
   - **Step 4**: Calculate the area of the triangles formed by the radii and the chord
	   $\text{triangleArea1} = \frac{1}{2} \cdot r1^2 \cdot \sin(2 \cdot \text{angle1})$
	   $\text{triangleArea2} = \frac{1}{2} \cdot r2^2 \cdot \sin(2 \cdot \text{angle2})$
   - **Step 5**: The area of intersection is the sum of the sector areas minus the triangle areas:
     $\text{intersectionArea} = (\text{sectorArea1} - \text{triangleArea1}) + (\text{sectorArea2} - \text{triangleArea2})$

---

### 5. **Area of the Crescent (Helal)**:
   The area of the largest crescent $(Helal)$ is the area of the larger circle minus the area of intersection:
   $\text{HelalArea} = \max(\text{area1}, \text{area2}) - \text{intersectionArea}$
   If the circles do not intersect or one is completely inside the other without touching, the $Helal$ area is **undefined** (output `-1`).

---

### 6. **Concentric Circles**:
   If the circles are concentric (same center) and have the same radius, they do not form a Helal. The output should be `-1`.

---

`double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));`  // distance
`if(d >= r1 + r2){`  **No Intersection or Externally Tangent Circles** 
    `return -1;`  
`}`  
`else if(d < abs(r1 - r2)){`  **One Circle Completely Inside the Other Without Intersection**
    `return -1;`  
`}`  
`else if (d == 0 and r1 == r2) {`  **Concentric Circles with Same Radius**
    `return -1;`  
`}`  
`else{`   **Internally Tangent Circles or Partial Intersection** $->$ **Calculate the intersection area**
    `double angle1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));`  
    `double angle2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));`  
    `double area1 = r1 * r1 * angle1 - 0.5 * r1 * r1 * sin(2 * angle1);`  
    `double area2 = r2 * r2 * angle2 - 0.5 * r2 * r2 * sin(2 * angle2);`  
    `return area1 + area2;`  
`}`