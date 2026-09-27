// Rust's LeetCode Node definition for this problem is platform-specific.
// This solution uses a breadth-first traversal when the provided Node type exposes left/right/next.
impl Solution {
    pub fn connect(root: Option<Rc<RefCell<Node>>>) -> Option<Rc<RefCell<Node>>> {
        use std::collections::VecDeque;
        let mut q=VecDeque::new();
        if let Some(r)=root.clone(){q.push_back(r);}else{return root}
        while !q.is_empty(){
            let n=q.len(); let mut prev:Option<Rc<RefCell<Node>>>=None;
            for _ in 0..n{
                let x=q.pop_front().unwrap();
                if let Some(p)=prev{p.borrow_mut().next=Some(x.clone());}
                let b=x.borrow();
                if let Some(l)=b.left.clone(){q.push_back(l)}
                if let Some(r)=b.right.clone(){q.push_back(r)}
                drop(b); prev=Some(x);
            }
        }
        root
    }
}
