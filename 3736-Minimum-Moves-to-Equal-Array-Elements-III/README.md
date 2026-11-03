# 3736. Minimum Moves to Equal Array Elements III

**Difficulty:** Easy

In one move, you may increment any single element by `1`.

Because values can only increase, the smallest possible final common value is the current maximum element.

Let:

```text
maxValue = max(nums)
```

Then each element `nums[i]` needs:

```text
maxValue - nums[i]
```

moves.

So:

```text
answer = sum(maxValue - nums[i])
```

or equivalently:

```text
answer = maxValue * nums.length - sum(nums)
```

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3736. Minimum Moves to Equal Array Elements III](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/)
