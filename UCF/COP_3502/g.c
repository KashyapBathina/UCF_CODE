/*
binary trees:
    data struct with pointers and notes like linked list, but while linked list linear with 1 predeceessor and 1 successor, tree is hierarchical relationship with several successors 
    called children and predecesoor as parent; top node is root with no parents above it, every node can have children & each child be parent to own children; leaves=nodes with no
    children; leaf=node that is not root or leaf; each node max 2 children, else called n-ary tree with max n children; binary tree only 2 children and full binary tree if every node 
    other than leaves have exactly 2 children; complete binary tree if evry level exept last is filled completely and all nodes far left as possible; height is lrgest num of edges in
    path from root node to leaf node or just the height of the root node (if 1 node, then just root node so height 0), total max number of nodes = 2^(height + 1) - 1, h= log((n+1)/2)
    binary tree uses linked storage with each node having left and right subtrees reached with pointers, ie struct tree_node {int data, struct tree_node* left_child, ... right_child}
    traversal: cannot just walk thru like linked lists from head to last, no linear ordering, so multiple ways to traverse, note depth-first search explores path all  way to a leaf 
    before backtracking & exploring nother path (look up for visualization) hence left nodes found before right side, all three traverse methods use DFS & names chosen based on which
    step the root node is visited:
        preorder: root visited bfore left and right subtrees; code--preorder(treenode *p){ printf(data); preorder(p->left); preorder(p->right); }; ie a b(left) c(right) -> abc, becus
            recursive, acts just like depth-first prints each leaf and goes leftmots then rightmost and then goes back accordingly by backtracking 
        inorder: root visisted between subtree; code--preorder(treenode *p){ preorder(p->left); printf(data); preorder(p->right) }; ie a b(left) c(right) -> bac, however, this also 
            means that the node is considered as a root each time, meaning that it also won't print it until all children printed, meaning if b has children, goes through the childrn
            on left until null (meaning leaf), then prints the left -> parent -> right so if a b(left) -> (d(left) e(right)) c(right) -> (f(left)), meaning that b has children d & e,
            then it goes and visits left-bottom-node bfore printing to get dbeacf
        postorder: root visited after left and right subtrees; code--preorder(treenode *p){ preorder(p->left); preorder(p->right); printf(data);}; ie a b(left) c(right) -> bca, like
            for inorder, means that each node considered as root, meaning that it recurses such that it goes far most left first b/c it repetedly goes p->left until leaf then prints
            left then right then parent; 
    purpose: not just random alphabets, instead for ordering numbers; for each node n, vals in left are all < n and all vals in right are > n; so insted of O(n) for serching, halfing 
        search time is O(logn) so binary search tree essentially imbeds binary search for each node, hence the name
    insertion: must first allocate new node--create_node(int val) {1. deaclaring pointer node tree_node* temp; 2. allocating space temp=malloc(...) 3. initializing fields temp->data
        =val; temp->left=null; right... 4. returning pointer to new node return temp}; then can insert--must maintain ordering smaller in left and larger right by starting @ root, go
        right if > root, left if < root, and keep going til empty position; 

heaps:
    lorem ipsum
*/






#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}