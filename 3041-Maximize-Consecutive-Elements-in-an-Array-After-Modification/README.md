# LeetCode 3041 — Maximize Consecutive Elements in an Array After Modification

**Difficulty:** Hard  
**Problem:** https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/

## Problem

Given an array `nums` of positive integers, each element can be increased by **at most 1** (or left unchanged). Choose the largest possible subset whose values, after modification and sorting, form a sequence of **distinct consecutive integers**. Return the number of selected elements.

### Examples

| Input | Output | Explanation |
| --- | ---: | --- |
| `nums = [2,1,5,1,1]` | `3` | Choose values that become `1,2,3`. |
| `nums = [1,4,7,10]` | `1` | No two values can become consecutive. |
| `nums = [1,1]` | `2` | Keep one `1` and raise the other to `2`. |
| `nums = [1,1,1]` | `2` | Only `1` and `2` are possible. |

**Constraints:** `1 <= nums.length <= 100000`; `1 <= nums[i] <= 1000000`.

## Algorithm: sorting + dynamic programming

Sort `nums` in ascending order. Define `dp[v]` as the maximum length of a consecutive sequence **ending at value `v`** using elements processed so far.

For each sorted element `x`, there are two choices:

1. **Increase it to `x+1`:** `dp[x+1] = max(dp[x+1], dp[x] + 1)`
2. **Keep it as `x`:** `dp[x] = max(dp[x], dp[x-1] + 1)`

**The update order is essential:** update `dp[x+1]` **before** `dp[x]`. Otherwise the same element could first extend a sequence ending at `x-1` to `x` and then extend that new sequence to `x+1`, incorrectly counting the element twice.

The result is the maximum `dp` value encountered.

### Why sorting works

Every selected element can only become `x` or `x+1`. Processing values in ascending order means any earlier element that can precede the current final value has already been considered. An optimal consecutive chain can therefore be built by extending a chain ending exactly one smaller than the chosen final value.

### Correctness sketch

Induct over the sorted elements. Before processing `x`, `dp[v]` records the best consecutive chain ending at `v` from previously processed elements. Any chain newly ending at `x+1` must use the current element raised by one and extend a previous chain ending at `x`; any chain newly ending at `x` must use the element unchanged and extend a previous chain ending at `x-1`. The transitions consider both choices, and updating `x+1` first prevents reuse of the current element. Chains not using the element remain available through the `max` operations. Thus the invariant holds after each step, and the maximum state is optimal.

## Complexity

Let `n = nums.length` and `M = max(nums)`.

- **Time:** `O(n log n + M)` (sorting plus zero-initializing the DP array and processing all elements).
- **Auxiliary space:** `O(M)` for the DP array, plus sorting overhead depending on language.
- With `M <= 1,000,000`, this fits the constraints.

## Files (all in this folder)

| File | Language | LeetCode entry point |
| --- | --- | --- |
| `solution.c` | C | `int maxSelectedElements(int* nums, int numsSize)` |
| `solution.cpp` | C++ | `Solution::maxSelectedElements(vector<int>& nums)` |
| `Solution.java` | Java | `Solution.maxSelectedElements(int[] nums)` |
| `solution.rs` | Rust | `Solution::max_selected_elements(Vec<i32>)` |
| `test_cases.md` | All | Expected results and test instructions |

Copy the contents of the relevant file into the corresponding LeetCode language editor. The C, C++, and Java solutions sort the supplied array in place; Rust owns and sorts its input vector.

## GitHub

These files are deliberately kept together in the **root of the ZIP**, without language-specific subfolders. Add this folder to your LeetCode repository or copy its files to your preferred location.
