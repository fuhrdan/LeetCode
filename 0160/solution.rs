// Standard ownership-based Rust ListNode cannot represent shared tails.
// The pointer-switching algorithm requires reference-sharing semantics not exposed by LeetCode's usual Rust ListNode.
