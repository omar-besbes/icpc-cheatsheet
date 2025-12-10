= Geometry

== Point
#raw(read("/code/geometry/Point.h"), lang: "cpp")

== Line
Line $a · x + b · y + c = 0$:

- $bold(n) = (a, b)$ is a normal vector, $bold(d) = (-b, a)$ is a direction vector.
- Parallel lines at distance $r$ have equations:
  $a · x + b · y + c ± r · sqrt(a^2 + b^2) = 0$.
- Distance of a point $(x, y)$ to the line:
  $frac(a · x + b · y + c, sqrt(a^2 + b^2))$.
- The sign of $a · x + b · y + c$ determines the point’s side relative to the line
  (0 means the point lies on the line).
#raw(read("/code/geometry/Line.h"), lang: "cpp")

== Segment
#raw(read("/code/geometry/Segment.h"), lang: "cpp")

== Ray
#raw(read("/code/geometry/Ray.h"), lang: "cpp")

== Bisector
#raw(read("/code/geometry/Bisector.h"), lang: "cpp")

== Circle
#raw(read("/code/geometry/Circle.h"), lang: "cpp")

== Closest Pair
#raw(read("/code/geometry/ClosestPair.h"), lang: "cpp")

== Rotating Callipers
#raw(read("/code/geometry/RotatingCallipers.h"), lang: "cpp")

== Polygon Area
#raw(read("/code/geometry/PolygonArea.h"), lang: "cpp")

== In Polygon
#raw(read("/code/geometry/InPolygon.h"), lang: "cpp")

== Circle Tangents
#raw(read("/code/geometry/CircleTangents.h"), lang: "cpp")

== Convex Hull
#raw(read("/code/geometry/ConvexHull.h"), lang: "cpp")

== Point 3D
#raw(read("/code/geometry/Point3D.h"), lang: "cpp")

== Point
#raw(read("/code/geometry/Point.h"), lang: "cpp")
