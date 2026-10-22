# 3942. Minimum Operations to Sort a Permutation

**Difficulty:** Medium

Allowed operations are full-array reverse and left-rotate-by-one. Reachable states are rotations of the original permutation or rotations of its reverse.

Find the index of `0`, then check whether values increase cyclically when traversing right or left from `0`.

If increasing to the right, candidates are `zero` and `n - zero + 2` operations. If increasing to the left, candidates are `zero + 2` and `n - zero`. Return the minimum valid cost, or `-1` if neither direction works.

## Complexity
- Time: `O(n)`
- Space: `O(1)`

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`
