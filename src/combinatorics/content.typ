= Combinatorics

== Permutations

=== Factorial
#include "/src/combinatorics/factorial.typ"

=== Cycles
Let $g_S (n)$ be the number of $n$-permutations whose cycle lengths all belong to the set $S$.
Then
$ sum_(n=0)^infinity g_S(n) (x^n)/(n!) = exp(sum_(n in S) (x^n)/n ) $.

=== Derangements
Permutations of a set such that none of the elements appear in their original position.
$
  D(n) &= (n-1)(D(n-1) + D(n-2)) \
       &= n D(n-1) + (-1)^n \
       &= ⌊ n!/e ⌉
$

=== Burnside's lemma
Given a group $G$ of symmetries and a set $X$, the number of elements of $X$ _up to symmetry_ equals
$ (1/(|G|)) sum_(g in G) |X^g| $
where $X^g$ are the elements fixed by $g$ $(g dot x = x)$.

If $f(n)$ counts “configurations” of length $n$, we can ignore rotational symmetry using $G = bb(Z)_n$ to get
$ g(n) = (1/n) sum_(k=0)^(n-1) f(gcd(n, k)) = (1/n) sum_(k | n) f(k) phi(n/k).$

== Partitions and subsets

=== Partition function
Number of ways of writing $n$ as a sum of positive integers, disregarding the order of the summands.
$
  p(0) = 1, quad
  p(n) = sum_(k in ZZ; k != 0) (-1)^(k+1) p(n - k(3k-1)/2)
$
$
  p(n) ~ 0.145 / n dot exp(2.56 sqrt(n))
$

#show table.cell.where(y: 0): strong
#set table(align: center)
#table(
  columns: 14,
  table.header(
    [n], [0], [1], [2], [3], [4], [5], [6], [7], [8], [9], [20], [50], [100],
  ),
  [p(n)], [1], [1], [2], [3], [5], [7], [11], [15], [22], [30], [627], [\~2e5], [\~2e8],
)

=== Lucas' Theorem
Let $n,m$ be non-negative integers and $p$ a prime. Write
$n = n_k p^k + dots + n_1 p + n_0$ and $m = m_k p^k + dots + m_1 p + m_0$.
Then
$ binom(n, m) equiv product_(i=0)^k binom(n_i, m_i) (mod p) $.

#raw(read("/code/combinatorics/BinomialCoefficient.h"), lang: "cpp")

== General purpose numbers

=== Bernoulli numbers
EGF of Bernoulli numbers is $B(t) = t/(e^t - 1)$ (FFT-able).
$B[0, dots] = [1, -1/2, 1/6, 0, -1/30, 0, 1/42, dots]$.

Sums of powers:
$ sum_(i=1)^n n^m = (1/(m+1)) sum_(k=0)^m binom(m+1, k) B_k dot (n+1)^(m+1-k) $

Euler-Maclaurin formula for infinite sums:
$ sum_(i=m)^infinity f(i) = integral_m^infinity f(x) "dx" - sum_(k=1)^infinity (B_k)/(k!) f^"(k-1)"(m) $
$ approx integral_m^infinity f(x) "dx" + f(m)/2 - f'(m)/12 + f'''(m)/720 + O(f^"(5)"(m)). $

=== Stirling numbers of the first kind
Number of permutations on $n$ items with $k$ cycles.
$
  c(n,k) = c(n-1,k-1) + (n-1) c(n-1,k), c(0,0) = 1 \
  sum_(k=0)^n c(n,k) x^k = x(x+1) dots (x+n-1)
$
$c(8,k) = 8, 0, 5040, 13068, 13132, 6769, 1960, 322, 28, 1$  
$c(n,2) = 0, 0, 1, 3, 11, 50, 274, 1764, 13068, 109584, dots$

=== Eulerian numbers
Number of permutations $pi in S_n$ with exactly $k$ descents ($j$ such that $pi(j) > pi(j+1)$).
$
  E(n,k) = (n-k)E(n-1,k-1) + (k+1)E(n-1,k), \
  E(n,0) = E(n,n-1) = 1 \
  E(n,k) = sum_(j=0)^k (-1)^j binom(n+1, j) (k+1-j)^n
$

=== Stirling numbers of the second kind
Partitions of $n$ distinct elements into exactly $k$ groups.
$
  S(n,k) = S(n-1,k-1) + k S(n-1,k), \
  S(n,1) = S(n,n) = 1 \
  S(n,k) = (1/k!) sum_(j=0)^k (-1)^(k-j) binom(k, j) j^n
$

=== Bell numbers
Total number of partitions of $n$ distinct elements.
$ B(n) = 1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, dots $
For prime $p$, $B(p^m + n) equiv m B(n) + B(n+1) (mod p)$.

=== Labeled unrooted trees
Number on $n$ vertices: $n^(n-2)$  

Number formed from $k$ existing trees of sizes $n_i$: $n_1 n_2 dots n_k ; n^(k-2)$  

Number with degrees $d_i$: $(n-2)! / ((d_1-1)! dots (d_n-1)!)$

=== Catalan numbers
$
  C_n = (1/(n+1)) binom(2n, n) = binom(2n, n) - binom(2n, n+1) = (2n)!/((n+1)!n!) \
  C_0 = 1, quad C_(n+1) = (2(2n+1))/(n+2) C_n, quad C_(n+1) = sum_ i C_i C_(n-i)
$
$ C_n = 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, dots $

- sub-diagonal monotone paths in an $n times n$ grid.
- strings with $n$ pairs of parentheses, correctly nested.
- binary trees with $n+1$ leaves (0 or 2 children).
- ordered trees with $n+1$ vertices.
- ways a convex polygon with $n+2$ sides can be cut into triangles by connecting vertices with straight lines.
- permutations of $[n]$ with no 3-term increasing subsequence.

#raw(read("/code/combinatorics/Catalan.h"), lang: "cpp")
