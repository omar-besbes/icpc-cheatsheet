= Mathematics

== Equations
$
  a x^2 + b x + c = 0 => x = (-b ± sqrt(b^2-4a c)) / (2a)
$

The extremum is given by $x = -b/(2a)$.

$
  cases(
    a x + b y = e,
    c x + d y = f
  )
  =>
  cases(
    x = (e d - b f) / (a d - b c),
    y = (a f - e c) / (a d - b c)
  )
$

In general, given an equation $A x = b$, the solution to a variable $x_i$ is given by,
$ x_i = det(A'_i) / det(A) $
where $A'_i$ is $A$ with the $i$'th column replaced by $b$.

== Recurrences
If $a_n = c_1 a_(n-1) + … + c_k a_(n-k)$
and $r_1, …, r_k$ are distinct roots of
$ x^k - c_1 x^(k-1) - … - c_k $
there are $d_1, …, d_k$ such that
$ a_n = d_1 r_1^n + … + d_k r_k^n $

Non-distinct roots $r$ become polynomial factors, e.g. $a_n = (d_1 n + d_2) r^n$.

== Trigonometry
$
  sin(v+w) = sin(v)cos(w) + cos(v)sin(w)
  \
  cos(v+w) = cos(v)cos(w) - sin(v)sin(w)
  \
  tan(v+w) = (tan v + tan w)/(1 - tan v tan w)
  \
  sin v + sin w = 2 sin((v+w)/2) cos((v-w)/2)
  \
  cos v + cos w = 2 cos((v+w)/2) cos((v-w)/2)
  \
  (V+W) tan(v-w)/2 = (V-W) tan(v+w)/2
$
where $V, W$ are lengths of sides opposite angles $v, w$.

$
  a cos x + b sin x = r cos(x - φ)
  \
  a sin x + b cos x = r sin(x + φ)
$
where $r = sqrt(a^2+b^2), φ = "atan2"(b,a)$.

== Geometry

=== Triangles
#grid(
  columns: (11fr, 13fr),
  row-gutter: 1.2em,
  align: horizon,
  [Side lengths: $a,b,c$],
  [Area: $A = sqrt(p(p-a)(p-b)(p-c))$],
  [Circumradius: $R = a b c/(4A)$],
  [Semiperimeter: $p = (a+b+c)/2$],
  [Inradius: $r = A/p$],
  [Length of median: $m_a = 1/2 sqrt(2b^2+2c^2-a^2)$],
  grid.cell(
    colspan: 2,
    [Angle bisector: $s_a = sqrt(b c(1 - (a/(b+c))^2))$],
  ),
  grid.cell(
    colspan: 2,
    [Law of sines: $sin α / a = sin β / b = sin γ / c = 1/(2R)$],
  ),
  grid.cell(
    colspan: 2,
    [Law of cosines: $a^2 = b^2 + c^2 - 2b c cos α$],
  ),
  grid.cell(
    colspan: 2,
    [Law of tangents: $(a+b)/(a-b) = tan((α+β)/2) / tan((α-β)/2)$],
  ),
)

=== Quadrilaterals
With side lengths $a,b,c,d$, diagonals $e, f$, diagonals angle $θ$, area $A$, and flux $F = b^2 + d^2 - a^2 - c^2$:
$
  4A = 2e f sin θ = F tan θ = sqrt(4e^2 f^2 - F^2)
$
For cyclic quadrilaterals: opposite angles sum to $180°$,

$e f = a c + b d$ and $A = sqrt((p-a)(p-b)(p-c)(p-d))$.

=== Spherical coordinates
#align(center)[
  #image("/src/mathematics/spherical-coordinates.jpg", width: 25mm)

  #grid(
    columns: 2,
    align: center,
    gutter: 1.2em,
    $x = r sin(θ) cos(φ)$, $r = sqrt(x^2+y^2+z^2)$,
    $y = r sin(θ) sin(φ)$, $θ = "acos"(z/sqrt(x^2+y^2+z^2))$,
    $z = r cos(θ)$, $φ = "atan2"(y,x)$,
  )
]

== Derivatives/Integrals
#block[
  #show math.equation.where(block: true): set align(left)
  #grid(
    columns: (3fr, 2fr),
    gutter: 1.2em,
    $ d/"dx" arcsin x = 1/sqrt(1-x^2) $, $ d/"dx" arccos x = -1/sqrt(1-x^2) $,
    $ d/"dx" tan x = 1+tan^2 x $, $ d/"dx" arctan x = 1/(1+x^2) $,
    $ ∫ tan(a x) = -(ln|cos(a x)|)/a $, $ ∫ e^(-x^2) = sqrt(π)/2 "erf"(x) $,
    $ ∫ x sin(a x) = (sin(a x) - a x cos(a x))/a^2 $, $ ∫ x e^(a x) = e^(a x)/a^2 (a x-1) $,
  )
]


Integration by parts:
$ ∫_a^b f(x)g(x)"dx" = [F(x)g(x)]_a^b - ∫_a^b F(x)g'(x) "dx" $

== Sums
#block[
  #show math.equation.where(block: true): set align(left)
  #grid(
    columns: 2,
    gutter: 1.2em,
    $ sum_(i=m)^n c^i = (c^(n+1) - c^m)/(c-1), c ≠ 1 $,
    $ sum_(i=0)^n binom(n, i) a^(n-i) b^i = (a+b)^n $,
    $ sum_(i=0)^n binom(n, i) = 2^n $,
    $ sum_(i=0)^n binom(i, k) = binom(n+1, k+1) $,
    $ sum_(i=0)^n i binom(n, i) = n 2^(n-1) $,
    $ sum_(i=0)^n binom(n, i)/(i+1) = (2^(n+1)-1)/(n+1) $,
    $ sum_(i=0)^n i! binom(n, i) = ⌊n! e⌋ $,
    $ sum_(i=0)^n i P_k binom(n, i) = P_k (2^(n-k)) $,
    $ sum_(i=0)^n i ⋅ i! = (n+1)! - 1 $,
    $ sum_(k=0)^m binom(n+k, n) = binom(n+m+1, n+1) $,
    $ sum_(i=0)^n binom(n, i)^2 = binom(2n, n) $,
    $ sum_(i=0)^n 1/i! = ⌊n! e⌋/n! $,
    grid.cell(
      colspan: 2,
      $ sum_(i=1)^n i + k P_(k+1) = sum_(i=1)^n product_(j=0)^k (i+j) = ((n+k+1)!)/((n-1)!(k+2)) $,
    ),
    $ sum_(i=0)^n i! binom(n, i) = sum_(i=0)^n P_n i = floor(n! e) $,
  )
]

== Series
$ e^x = 1+x+x^2/2!+x^3/3!+…, (-infinity<x≤+infinity) $
$ ln(1+x) = x - x^2/2 + x^3/3 - …, (-1<x≤1) $
$ sqrt(1+x) = 1+x/2 - x^2/8 + 2x^3/32 - 5x^4/128 + …, (-1<x≤1) $
$ sin x = x - x^3/3! + x^5/5! - …, (-infinity<x≤+infinity) $
$ cos x = 1 - x^2/2! + x^4/4! - …, (-infinity<x≤+infinity) $

== Probability theory
Let $X$ be a discrete random variable with distribution $p_X (x)$. Then:

Expected value (mean): $μ = EE[X] = sum_x x p_X(x)$

Variance: $sigma^2 = V(X) = EE(X^2) - EE(X)^2 = sum_x (x-E[X])^2 p_X(x)$

For continuous $X$, replace sums with integrals.

Linearity: $EE(a X+b Y) = a EE(X) + b EE(Y)$

For independent $X,Y$: $V(a X+b Y) = a^2 V(X) + b^2 V(Y)$

=== Discrete distributions

==== Binomial distribution
The number of successes in $n$ independent yes/no experiments, each of which
yields success with probability $p$ is $"Bin"(n, p), n = 1, 2, …, 0 ≤ p ≤ 1$.
$ p(k) = binom(n, k) p^k (1 - p)^(n - k) $
$ μ = n p, sigma^2 = n p (1 - p) $
$"Bin"(n, p)$ is approximately $"Po"(n p)$ for small $p$.

==== First success distribution
The number of trials needed to get the first success in independent yes/no
experiments, each of which yields success with probability $p$, is
$"Fs"(p), 0 ≤ p ≤ 1$.
$ p(k) = p (1 - p)^(k - 1), k = 1, 2, … $
$ μ = 1/p, sigma^2 = (1 - p)/p^2 $

==== Poisson distribution
The number of events occurring in a fixed period of time $t$ if these events
occur with a known average rate $κ$ and independently of the time since
the last event is $"Po"(λ), λ = t κ$.
$ p(k) = e^(-λ) λ^k / k!, k = 0, 1, 2, … $
$ μ = λ, sigma^2 = λ $

=== Continuous distributions

==== Uniform distribution
If the probability density function is constant between $a$ and $b$ and $0$
elsewhere it is $U(a, b), a < b$.
$ f(x) = cases(
  1/(b - a) & a < x < b,
  0         & "otherwise",
) $
$ μ = (a + b)/2, sigma^2 = (b - a)^2 / 12 $

==== Exponential distribution
The time between events in a Poisson process is $"Exp"(λ),\ λ > 0$.
$ f(x) = cases(
  λ e^(-λ x) & x ≥ 0,
  0 & x < 0,
) $
$ μ = 1/λ, sigma^2 = 1/λ^2 $

==== Normal distribution
Most real random values with mean $μ$ and variance $sigma^2$ are well described by $N(μ, sigma^2), sigma > 0$.
$ f(x) = 1 / sqrt(2 π sigma^2) · e^(-(x - μ)^2 / (2 sigma^2)) $
If $X_1 ~ N(μ_1, sigma_1^2)$ and $X_2 ~ N(μ_2, sigma_2^2)$ then
$ a X_1 + b X_2 + c ~ N(μ_1 + μ_2 + c, a^2 sigma_1^2 + b^2 sigma_2^2) $

== Markov chains
A _Markov chain_ is a discrete random process with the property that the
next state depends only on the current state. Let $X_1, X_2, …$ be a
sequence of random variables generated by the Markov process. Then there is a
transition matrix $bold(P) = (p_"ij")$, with $p_"ij" = "Pr"(X_n = i | X_(n-1) = j)$, and $bold(p)^"(n)" = bold(P)^n bold(p)^"(0)"$ is the probability distribution for $X_n$ (i.e., $p_i^"(n)" = "Pr"(X_n = i)$), where $bold(p)^"(0)"$ is the initial distribution.

=== Stationary distribution
$π$ is a stationary distribution if $π = π bold(P)$.
If the Markov chain is _irreducible_ (it is possible to get to any state from any state), then $π_i = 1 / EE(T_i)$ where $EE(T_i)$ is the expected time between two visits in state $i$.
$π_j / π_i$ is the expected number of visits in state $j$ between two visits in state $i$.

For a connected, undirected, and non-bipartite graph where the transition
probability is uniform among all neighbors, $π_i$ is proportional to node
$i$'s degree.

=== Ergodicity
A Markov chain is _ergodic_ if the asymptotic distribution is independent
of the initial distribution. A finite Markov chain is ergodic iff it is
irreducible and _aperiodic_ (i.e., the $"gcd"$ of cycle lengths is $1$).
$lim_(k → ∞) bold(P)^k = bold(1) π$.

=== Absorption
A Markov chain is an A-chain if the states can be partitioned into two sets
$bold(A)$ and $bold(G)$, such that all states in $bold(A)$ are
absorbing ($p_"ii" = 1$), and all states in $bold(G)$ lead to an absorbing
state in $bold(A)$. The probability for absorption in state
$i ∈ bold(A)$, when the initial state is $j$, is
$ a_"ij" = p_"ij" + sum_(k ∈ bold(G)) a_"ik" p_"kj" $.
The expected time until absorption, when the initial state is $i$, is
$ t_i = 1 + sum_(k ∈ bold(G)) p_(k i) t_k $.
