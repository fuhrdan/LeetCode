# LeetCode 3331 — Find Subtree Sizes After Changes

**Difficulty:** Medium  
**Problem:** https://leetcode.com/problems/find-subtree-sizes-after-changes/

## Problem

Given a tree rooted at node `0`, represented by `parent`, and a lowercase-letter string `s` assigning a character to each node:

For **every non-root node simultaneously**, find its **closest ancestor in the original tree** with the same character. If one exists, reattach the node directly to that ancestor. Otherwise, leave its parent unchanged.

Return an integer array `answer`, where `answer[i]` is the size of the subtree rooted at node `i` **after all changes**.

**Constraints:**

- `n == parent.length == s.length`
- `1 <= n <= 100000`
- `parent[0] == -1`
- `parent` represents a valid rooted tree
- `s` contains only lowercase English letters

### Example 1

```text
Input:  parent = [-1,0,0,1,1,1], s = "abaabc"
Output: [6,3,1,1,1,1]
```

Node `3`, whose character is `a`, changes its parent from node `1` to node `0` (its closest ancestor with character `a`). All other nodes retain their original parents.

### Example 2

```text
Input:  parent = [-1,0,4,0,1], s = "abbba"
Output: [5,2,1,1,1]
```

Both reattachments happen **simultaneously** based on the original tree: node `4` moves under node `0`, while node `2` moves under node `1`.

## Approach — Iterative DFS + Reverse Preorder

We can solve the problem in **O(n)** time, without recursion or explicitly constructing the modified tree.

### 1. Build the original tree

The `parent` array specifies parent pointers. Build an adjacency list of children using compact arrays `head` and `next`. This takes O(n) time and space.

### 2. Compute every node's new parent, using the original tree

Traverse the **original** tree in depth-first order. Maintain `nearest[26]`, where `nearest[c]` is the nearest currently active ancestor whose character is `c`.

When entering node `u`:

1. Read `nearest[s[u]]` *before* registering `u` itself.
2. Set `newParent[u]` to that matching ancestor if present; otherwise retain `parent[u]` (`-1` for the root).
3. Save the previous `nearest[s[u]]`, then update it to `u`.
4. Record `u` in DFS preorder.

When leaving `u`, **restore** the saved nearest ancestor for `s[u]`. This prevents matches from leaking between different branches of the tree.

The implementations use a stack of **enter and exit events** instead of recursion, so a chain of 100,000 nodes is safe. In the C, C++, and Java implementations, the exit event for node `u` is encoded as `~u` (a negative integer). Rust uses the same convention.

### 3. Aggregate subtree sizes in reverse original preorder

Start with:

```text
answer[u] = 1 for all u
```

Then visit all nodes except the root **in reverse original preorder**:

```text
for u in reverse(original_preorder excluding root):
    answer[newParent[u]] += answer[u]
```

Why is reverse preorder enough? Each new parent is **always an ancestor in the original tree**. As a result, the new parent is guaranteed to precede its child in the original DFS preorder. Traversing that order backward processes children before their new parents, even when an edge skips multiple levels.

This step takes O(n) time and does not require allocating a second adjacency list for the modified tree.

## Correctness explanation

**Lemma 1.** At each DFS entry of node `u`, `nearest[c]` identifies the closest *proper ancestor* of `u` with character `c`, if one exists.

**Reason:** DFS enters nodes along a single root-to-node path. Registering a node's character replaces the previous ancestor of that character, and restoring on exit removes the node from the active path. Before registering `u`, the active values describe exactly its proper ancestors.

**Lemma 2.** `newParent[u]` is the parent required by the simultaneous update rule.

**Reason:** By Lemma 1, the closest original matching ancestor is found without changing the original tree. If none exists, the original parent is preserved. Every node's decision is therefore made against the same original tree.

**Lemma 3.** For every non-root node `u`, its final parent appears earlier than `u` in the original preorder.

**Reason:** `newParent[u]` is either the original parent or another original ancestor. Every ancestor appears before its descendants in preorder.

**Theorem.** The returned array contains the subtree sizes in the final tree.

**Reason:** Initialize every subtree to contain its own node. By Lemma 3, processing original preorder in reverse visits each node after all of its descendants in the modified tree. When processing `u`, its accumulated size can therefore be added to `newParent[u]` exactly once. This yields the correct subtree size for every node.

## Complexity

Let `n` be the number of nodes:

| Operation | Time | Auxiliary space |
| --- | --- | --- |
| Build original adjacency lists | O(n) | O(n) |
| Iterative DFS / determine new parents | O(n) | O(n) |
| Reverse-order subtree aggregation | O(n) | O(n) |
| **Total** | **O(n)** | **O(n)** |

The 26-entry nearest-ancestor table uses O(1) space because the alphabet is fixed.

## Files — Flat folder layout

All the files are in **one directory**, with no separate language subdirectories:

```text
README.md
solution.c
solution.cpp
Solution.java
solution.rs
test_cases.md
verify.py
```

| Language | File | LeetCode signature |
| --- | --- | --- |
| C | `solution.c` | `int* findSubtreeSizes(int* parent, int parentSize, char* s, int* returnSize)` |
| C++ | `solution.cpp` | `vector<int> Solution::findSubtreeSizes(vector<int>& parent, string s)` |
| Java | `Solution.java` | `int[] Solution.findSubtreeSizes(int[] parent, String s)` |
| Rust | `solution.rs` | `Vec<i32> Solution::find_subtree_sizes(Vec<i32>, String)` |

Each solution is intended to be pasted directly into the corresponding LeetCode editor. LeetCode supplies the method-calling harness; the source files do not need a `main` method. The C return value is heap-allocated for the online judge to free.

## Run the tests locally

From this directory:

```bash
python verify.py
```

The test script creates temporary runner programs, compiles the solutions using installed toolchains (`gcc`, `g++`, `javac`/`java`, `rustc`), and compares the results against an independent reference implementation. It includes the supplied examples, edge cases, 650 fixed-seed randomized trees (including shuffled node indices), and 100,000-node chain/star stress tests.

The verifier will **skip** languages whose compiler is unavailable. It does not modify the solution files or require third-party Python packages. See [`test_cases.md`](test_cases.md) for the test plan.

**Validation in the build environment:** C, C++, and Java each passed all **663 cases**. Rust was not compiled there because `rustc` was not installed; the Rust implementation is included for submission and can be tested wherever Rust is available.

## Publish to GitHub

Extract the ZIP into a folder of your LeetCode repository, then commit and push it as usual. You can also keep all seven files at your repository root if that is your preferred layout.

```bash
git add .
git commit -m "Add LeetCode 3331 solutions in C, C++, Java, and Rust"
git push
```

Do not use the intermediate test harnesses as LeetCode submissions—submit the appropriate `solution.*` / `Solution.java` file instead.
