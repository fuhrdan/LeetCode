# 2333. Minimum Sum of Squared Difference

**Difficulty:** Medium

Given two equal-length arrays `nums1` and `nums2`, plus operation budgets `k1` and `k2`, minimize:

```text
sum((nums1[i] - nums2[i])^2)
```

Each operation changes one array element by `+1` or `-1`.

## Approach

Work only with absolute differences:

```text
diff[i] = abs(nums1[i] - nums2[i])
```

Each useful operation reduces one positive difference by exactly `1`. Because squaring is convex, reducing the largest differences first is optimal.

Since every difference is at most `100000`, use a frequency table:

```text
count[d] = number of differences equal to d
```

Process `d` from largest to smallest, moving as many values as possible from `d` to `d - 1`.

The two budgets can be combined:

```text
operations = k1 + k2
```

If `operations` is at least the sum of all differences, the answer is `0`.

## Complexity

- **Time:** `O(n + D)`, where `D <= 100000`
- **Space:** `O(D)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)
