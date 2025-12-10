= Optimization Tricks

== Bit Hacks
- `n & -n` gives the least significant set bit of `$n$`.
- `n | (1 << x)` sets the $x$-th bit in `n`.
- `n ^ (1 << x)` flips the $x$-th bit in `n`.
- `n & ~(1 << x)` clears the $x$-th bit in `n`.
- `n & (n + 1)` clears all trailing ones in `n`.
- `n | (n + 1)` sets the last cleared bit in `n`.
- To loop over all subset masks of $m$ (excluding $m$ itself): \
  ```cpp for (int x = m; x;){ --x &= m; }```
- To find the next number after $x$ with the same number of bits set, use:
  ```cpp c = x &-x, r = x + c; (((r^x) >> 2) / c) | r```
- For cumulative sums of subsets, use: \
  #block[
    ```cpp
    for (int b = 0; b < k; b++)
      for (int i = 0; i < (1 << k); i++)
        if (i & 1 << b) D[i] += D[i ^ (1 << b)];
    ```
  ]

== Language & Compiler Support

C++ supports some of the bit hacks since C++20 via the bit standard library:

+ `has_single_bit`: checks if the number is a power of two
+ `bit_ceil` / `bit_floor`: round up/down to the next power of two
+ `rotl` / `rotr`: rotate the bits in the number
+ `countl_zero` / `countr_zero` / `countl_one` / `countr_one`: count the leading/trailing zeros/ones
+ `popcount`: count the number of set bits

GCC defines a list at Built-in Functions Provided by GCC that also work in
older versions of C++:

+ ```cpp __builtin_popcount(unsigned int)``` returns the number of set bits (```cpp __builtin_popcount(0b0001'0010'1100) == 4```)
+ ```cpp __builtin_ffs(int)``` finds the index of the first (most right) set bit (```cpp __builtin_ffs(0b0001'0010'1100) == 3```)
+ ```cpp __builtin_clz(unsigned int)``` the count of leading zeros (```cpp __builtin_clz(0b0001'0010'1100) == 23```)
+ ```cpp __builtin_ctz(unsigned int)``` the count of trailing zeros (```cpp __builtin_ctz(0b0001'0010'1100) == 2```)
+ ```cpp __builtin_parity(x)``` the parity (even or odd) of the number of ones in the bit representation

Note that some of the operations (both the C++20 functions and the Compiler
Built-in ones) might be quite slow in GCC if you don't enable a specific
compiler target with ```cpp #pragma GCC target("popcnt")```.

== Pragmas

+ Use ```cpp #pragma GCC optimize ("Ofast")``` to enable GCC's
  auto-vectorization and better optimization for floating points (assumes
  associativity and turns off denormals).
+ Use ```cpp #pragma GCC target ("avx,avx2")``` to potentially double
  performance of vectorized code, though it may cause crashes on older machines.
  Consider using ```cpp #pragma GCC target ("sse4")``` for older
  architectures.
+ Use ```cpp #pragma GCC optimize ("trapv")``` to kill the program on integer
  overflows (but it may slow down execution).
