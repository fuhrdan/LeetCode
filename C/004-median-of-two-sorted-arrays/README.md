# 4. Median of Two Sorted Arrays

**Difficulty:** Hard  
**LeetCode:** [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

## Problem

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n`, return the median of the two sorted arrays.

The overall runtime complexity should be:

```text
O(log(m + n))
```

## Examples

### Example 1

```text
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
```

Explanation:

```text
Merged array = [1,2,3]

Median = 2
```

### Example 2

```text
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
```

Explanation:

```text
Merged array = [1,2,3,4]

Median = (2 + 3) / 2
       = 2.5
```

## Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-1000000 <= nums1[i], nums2[i] <= 1000000`

## Approach

Use binary search on the smaller of the two arrays.

Instead of actually merging the arrays, find a partition that divides both arrays into a left half and a right half such that:

- Every value on the left is less than or equal to every value on the right.
- The left side contains half of the total elements.

For partitions `i` and `j`:

```text
i + j = (m + n + 1) / 2
```

The correct partition satisfies:

```text
nums1[i - 1] <= nums2[j]
nums2[j - 1] <= nums1[i]
```

Once the correct partition is found:

- If the total number of elements is odd, the median is the largest value on the left.
- If the total number of elements is even, the median is the average of the largest value on the left and the smallest value on