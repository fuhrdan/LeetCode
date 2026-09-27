# 2. Add Two Numbers

**Difficulty:** Medium  
**LeetCode:** [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Problem

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

You may assume the numbers do not contain leading zeros, except for the number `0`.

## Examples

### Example 1

```text
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
```

Explanation:

```text
342 + 465 = 807
```

Because the digits are stored in reverse order:

```text
342 -> [2,4,3]
465 -> [5,6,4]
807 -> [7,0,8]
```

### Example 2

```text
Input: l1 = [0], l2 = [0]
Output: [0]
```

### Example 3

```text
Input: l1 = [9,9,9,9,9,9,9]
Input: l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- The linked lists represent numbers without leading zeros, except for the number `0`.

## Approach

Traverse both linked lists at the same time and add the corresponding digits.

For each position:

1. Add the current values from `l1` and `l2`.
2. Add any carry from the previous position.
3. Store `sum % 10` in a new result node.
4. Set the new carry to `sum / 10`.
5. Continue until both lists are exhausted and no carry remains.

A dummy head node is used to simplify building the result linked list.