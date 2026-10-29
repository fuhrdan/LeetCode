# 3841. Palindromic Path Queries in a Tree

**Difficulty:** Hard

Use 26-bit parity masks. Let `rootXor[u]` be the XOR of node-character masks on the root-to-`u` path. Then for `w = LCA(u,v)`:

```text
pathMask = rootXor[u] ^ rootXor[v] ^ charMask[w]
```

A path can be rearranged into a palindrome iff `pathMask` has at most one set bit.

For an update at node `u`, changing `old` to `new`, every descendant root-prefix XOR changes by `mask(old) ^ mask(new)`. Euler-tour numbering makes the subtree of `u` one interval, so updates become range-XOR updates on a lazy segment tree. Point queries recover current `rootXor` values. Binary lifting answers LCA queries.

## Complexity
- Preprocessing: `O(n log n)`
- Update: `O(log n)`
- Query: `O(log n)`
- Space: `O(n log n)`

## Files
- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode
[3841. Palindromic Path Queries in a Tree](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)
