# LeetCode 2567 — Minimum Score by Changing Two Elements

**Difficulty:** Medium  
**Languages:** C, C++, Java, Rust  
**Technique:** Sorting + three candidate ranges (greedy observation)  
**Problem link:** https://leetcode.com/problems/minimum-score-by-changing-two-elements/

## Problem

Given an integer array `nums`, change the values of **exactly two elements** (changing an element may also leave its value unchanged). Minimize:

- **Low score:** The minimum absolute difference between any two elements.
- **High score:** The maximum absolute difference between any two elements.
- **Total score:** `low score + high score`.

Return the minimum achievable total score.

**Constraints:** `3 <= nums.length <= 100000` and `1 <= nums[i] <= 10^9`.

### Examples

| Input | Output | Explanation |
|---|---:|---|
| `nums = [1,4,7,8,5]` | `3` | Change `1` and `4` to `6`: `[6,6,7,8,5]`. Low = 0, high = 3. |
| `nums = [1,4,3]` | `0` | Change two elements to `1` to make `[1,1,1]`. |

## Key insight

The **low score can always be zero**: since `n >= 3`, at least one element remains unchanged. Change at least one of the two chosen elements to match a remaining element, creating an equal pair (difference `0`). Set the other changed element to a value inside the interval of the remaining elements, so the high score does not increase.

Thus the only quantity to minimize is the **high score**, which is

`max(nums) - min(nums)`.

After changing two values, the remaining `n - 2` original values cannot be altered. We should therefore keep an `n - 2`-element subset with the smallest possible range. After sorting, a minimum-range subset of this size can always be chosen as `n - 2` **consecutive sorted elements**. There are exactly three such windows.

With `a = sorted(nums)` and `n = len(a)`, the answer is:

```text
min(
    a[n - 3] - a[0],   # change two largest
    a[n - 2] - a[1],   # change smallest and largest
    a[n - 1] - a[2]    # change two smallest
)
```

**Why only three?** After sorting, keeping `n - 2` adjacent elements removes two positions from the ends. Those two removals can be distributed as `(0, 2)`, `(1, 1)`, or `(2, 0)`.

For `n = 3`, each expression is `a[i] - a[i] = 0`; this is correct because two changes can make all three equal.

## Example walkthrough

`nums = [1,4,7,8,5]` → sorted `[1,4,5,7,8]`.

| Changed positions in sorted array | Kept elements | Range |
|---|---|---:|
| Two largest | `[1,4,5]` | `5 - 1 = 4` |
| One smallest, one largest | `[4,5,7]` | `7 - 4 = 3` |
| Two smallest | `[5,7,8]` | `8 - 5 = 3` |

Answer: **`min(4, 3, 3) = 3`**.

## Correctness proof

1. **Lower bound.** Any choice of two changed positions leaves `n - 2` original entries. Regardless of what replaces the two changed values, the final maximum-minus-minimum is at least the range of these unchanged entries, and the low score is nonnegative. Therefore the final score is at least the range of those `n - 2` entries.
2. **Consecutive-window lemma.** For any selection of `n - 2` sorted entries, let its first and last sorted indices be `i` and `j`. It spans at least `n - 2` positions, so a consecutive window of `n - 2` entries can be chosen entirely between `i` and `j`. That window's range is no larger than the selected entries' range. Hence some optimal choice keeps a consecutive window.
3. **Upper bound and attainability.** Take any of the three consecutive windows. Change both excluded elements to equal any one of the kept elements. Both changes lie inside the kept range, so the high score equals the window's range; at least two values are equal, so the low score is `0`. Thus its total score equals exactly that range.
4. **Conclusion.** The algorithm evaluates all three possible windows, finds the smallest range, and both lower and upper bounds match. The result is optimal.

## Complexity

| Resource | Complexity | Reason |
|---|---|---|
| Time | **O(n log n)** | Sorting dominates; comparing the three ranges is O(1). |
| Additional space | **Sorting-dependent** | No extra arrays are allocated by the solution; library sorting implementations may use stack/scratch space. |

All implementations sort the supplied array/vector **in place** (the Rust function consumes its vector by value). All differences fit in a 32-bit signed integer because the input values lie between `1` and `10^9`.

## Files

```text
leetcode-2567-minimum-score/
├── README.md
├── C/
│   └── solution.c          # int minimizeSum(int* nums, int numsSize)
├── CPP/
│   └── Solution.cpp        # class Solution::minimizeSum
├── Java/
│   └── Solution.java       # class Solution::minimizeSum
├── Rust/
│   └── solution.rs         # impl Solution::minimize_sum
└── tests/
    ├── test_c.c
    ├── test_cpp.cpp
    ├── TestSolution.java
    ├── test_rust.rs
    └── run_tests.sh
```

## Submission to LeetCode

Open the solution file for your language, copy its entire contents into the LeetCode editor for problem 2567, and submit it. The Rust file follows LeetCode's `impl Solution` convention: LeetCode provides the `Solution` type, so the file does not declare it itself.

| Language | Required LeetCode entry point |
|---|---|
| C | `int minimizeSum(int* nums, int numsSize)` |
| C++ | `int Solution::minimizeSum(vector<int>& nums)` |
| Java | `int Solution.minimizeSum(int[] nums)` |
| Rust | `pub fn Solution::minimize_sum(nums: Vec<i32>) -> i32` |

## Running the tests

Run from the project directory on Linux, macOS, or WSL:

```bash
bash tests/run_tests.sh
```

The script detects installed compilers and runs available languages; it skips a language when its compiler is missing. Each of the C, C++, and Java harnesses covers 23 fixed tests plus one 100,000-element stress test. The Rust harness covers the same 24 scenarios via two Rust unit tests.

To run Rust tests manually:

```bash
rustc --edition=2021 --test -O tests/test_rust.rs -o test_rust
./test_rust
```

## Suggested GitHub commit

```bash
git add leetcode-2567-minimum-score
git commit -m "Add LeetCode 2567 solutions in C, C++, Java, and Rust"
git push
```

**Note:** These are standalone source files for LeetCode's submission format; the test harnesses provide `main` / the Rust `Solution` type outside the submissions.
