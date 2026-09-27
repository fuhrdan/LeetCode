class Solution{public:Node* connect(Node*r){for(Node*l=r;l&&l->left;l=l->left)for(Node*p=l;p;p=p->next){p->left->next=p->right;if(p->next)p->right->next=p->next->left;}return r;}};
