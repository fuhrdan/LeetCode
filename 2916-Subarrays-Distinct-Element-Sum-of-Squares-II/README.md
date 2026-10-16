# 2916. Subarrays Distinct Element Sum of Squares II

**Difficulty:** Hard

For every non-empty subarray, square its number of distinct values and return the total modulo `1_000_000_007`.

## Approach

Process right endpoints from left to right. Let `f[l]` be the distinct count of `nums[l..r]` for the current `r`.

If `nums[r] = x` last appeared at `last[x]`, then only starts in:

```text
last[x] + 1 .. r
```

gain a new distinct value. So we perform a range increment by `1` on those `f[l]` values.

A lazy segment tree stores both:

- `sum = Σ f[l]`
- `squareSum = Σ f[l]^2`

For a range add of `d` over `len` values:

```text
newSquareSum = oldSquareSum + 2*d*oldSum + d*d*len
newSum       = oldSum + d*len
```

After each update, the root's `squareSum` is the contribution of all subarrays ending at the current right endpoint.

## Complexity

- **Time:** `O(n log n)`
- **Space:** `O(n + V)`, with `V <= 100000`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

### Java signature

```java
public int sumCounts(java.util.List<Integer> nums)
```

## LeetCode

[2916. Subarrays Distinct Element Sum of Squares II](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)
