# LeetCode 2911 — Minimum Changes to Make K Semi-palindromes

[View problem on LeetCode](https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/) · **Hard** · Dynamic Programming, String

Independent **C, C++, Java, and Rust** solutions, with a shared algorithm and language-specific test harnesses. Each `solution` file is ready to submit directly to LeetCode (no `main` function needed).

## Problem summary

Given a lowercase string `s` and integer `k`, divide `s` into exactly `k` contiguous, nonempty substrings. Every substring must be a **semi-palindrome**, and we want to minimize the total number of character replacements needed.

For a substring of length `L`, choose a **proper positive divisor** `d` of `L`: `1 <= d < L` and `L % d == 0`. Split the substring into `d` interleaved groups, one for each offset `r` in `0..d-1`:

```text
r, r + d, r + 2d, ...
```

Each group must read the same forwards and backwards. We may choose a different `d` for each substring. A substring of length 1 cannot qualify, so **each part has length at least 2**.

**Example:** `abcabc` is already a semi-palindrome, using `d = 3`:

```text
positions (0-based):    0 1 2 3 4 5
letters:                a b c a b c

d = 3:
  group 0: positions 0, 3 -> aa (palindrome)
  group 1: positions 1, 4 -> bb (palindrome)
  group 2: positions 2, 5 -> cc (palindrome)
```

### Examples

| Input | Output | Explanation |
| --- | ---: | --- |
| `s = "abcac", k = 2` | `1` | Partition `"ab" + "cac"`; change one letter in `"ab"` |
| `s = "abcdef", k = 2` | `2` | Partition `"abc" + "def"`, one replacement each |
| `s = "aabbaa", k = 3` | `0` | `"aa" + "bb" + "aa"` already satisfies the condition |

Constraints: `2 <= s.length <= 200`; `1 <= k <= s.length / 2`; lowercase English letters only.

## Approach: precomputed costs + partition DP

### 1. Precompute the cost of every valid substring

Define `cost[start][end]` as the minimum number of replacements needed to make `s[start:end]` semi-palindromic, where `end` is exclusive.

For every substring of length `L >= 2`, try each proper divisor `d` of `L`. Each of the `d` groups contains `L / d` characters. Compare mirrored characters inside each group; each mismatched pair requires **exactly one** replacement. The sum of mismatches is the optimal cost for that `d` because the compared pairs are independent.

For each offset `r` and pair index `t`, compare:

```text
left  = start + r + t * d
right = start + r + (L / d - 1 - t) * d
```

Then set:

```text
cost[start][end] = min(mismatches for all proper divisors d)
```

### 2. Dynamic programming over partitions

Let `dp[p][i]` be the minimum replacements to partition the first `i` characters into exactly `p` valid substrings.

Base case: `dp[0][0] = 0`, all other states start at infinity.

For the last part, choose its starting index `j`:

```text
dp[p][i] = min(dp[p-1][j] + cost[j][i])
```

We need `2 * (p-1) <= j <= i - 2` because every part must have at least two characters, and `i >= 2*p`.

Answer: **`dp[k][n]`**. The implementations use two DP rows (`prev` and `curr`) rather than storing the entire table.

### Why this works

1. For a fixed `d`, every letter is in exactly one interleaved group. Each group must be a palindrome, so matching each mirrored pair is both necessary and sufficient; one substitution fixes any mismatched pair.
2. Trying every valid `d` gives the exact minimum semi-palindrome conversion cost of each substring.
3. Every valid `p`-part partition of a prefix has a unique final substring `s[j:i]`. The recurrence considers every feasible `j` and combines the optimal solution to the preceding prefix with the independently optimal cost of the final substring. Thus, by induction on `p`, it yields the globally minimal total cost.

## Complexity

Let `n = s.length` and `D` be the maximum number of proper positive divisors among lengths `2..n`.

- **Precomputing costs:** `O(n³ · D)` time as a safe upper bound. Each of `O(n²)` substrings tries at most `D` divisors, with `O(n)` comparisons per divisor.
- **Partition DP:** `O(k · n²)` time.
- **Total time:** `O(n³ · D + k · n²)`.
- **Auxiliary space:** `O(n²)` for the cost table, plus `O(n)` for two DP arrays.

With `n <= 200`, this direct divisor enumeration is fast enough; no heuristic approximations are used.

## Files

```text
2911-minimum-changes-to-make-k-semi-palindromes/
├── README.md
├── .gitignore
├── c/solution.c             # LeetCode: minimumChanges(char* s, int k)
├── cpp/solution.cpp         # LeetCode: Solution::minimumChanges(string s, int k)
├── java/Solution.java       # LeetCode: Solution.minimumChanges(String s, int k)
├── rust/solution.rs         # LeetCode: Solution::minimum_changes(String, i32)
└── tests/
    ├── run_tests.sh         # Runs available language test suites
    ├── c_test.c
    ├── cpp_test.cpp
    ├── TestSolution.java
    └── rust_tests.rs
```

## Run tests locally

On Linux, macOS, or WSL:

```bash
bash tests/run_tests.sh
```

The script uses `gcc`, `g++`, `javac`/`java`, and `rustc` where installed, and reports any missing compilers as skipped. Each language has 15 checks: the three provided examples, edge cases, interleaved palindrome examples, and an `n=200, k=100` boundary case.

For Windows PowerShell, run each language's `tests/` harness in its respective compiler environment, or invoke the above script from WSL / Git Bash with the compilers installed.

**Submitting on LeetCode:** select the desired language and paste only that language's solution file. For the Rust submission, LeetCode supplies the `Solution` type; the local Rust test harness defines it explicitly.
