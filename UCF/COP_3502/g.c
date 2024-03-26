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
    binary search tree: not just random alphabets, instead for ordering numbers; for each node n, vals in left are all < n and all vals in right are > n; so insted of O(n) for serch
        -ing, halfing search time is O(logn) so binary search tree essentially imbeds binary search for each node, hence the name
    insertion: must first allocate new node--create_node(int val) {1. deaclaring pointer node tree_node* temp; 2. allocating space temp=malloc(...) 3. initializing fields temp->data
        =val; temp->left=null; right... 4. returning pointer to new node return temp}; then can insert--must maintain ordering smaller in left and larger right by starting @ root, go
        right if > root, left if < root, and keep going til empty position; 
        code: create new node, find parent, attach new node as leaf, find position using recursion or loop, param-insert(my_root,temp_node) if my_root null, tree empty & just return
            temp_node as it will be assigned to root and already defined it to be leaf (no children when initializing), else see wich tree to insrt by cmparin temp_node to root data
            and based on comparison, recurs insert left or right: for example if > root, the insert right code: if(element->data > root->data) {if (root->data != NULL) root-right =
            insert(root->right, element)      else root->right=element;} do similar if < root->data then return root; here there are two cases 1) there is a subtree already on right
            or 2) nothing on the right and so place directly, what 1) does is alter the right or left subtree recursively then set the root-right (where root changing b/c of recurs)
            to the altered subtree and when it does come upon a place where it can insert it does 2)
        when testing to see if tree correct, print tree in in-order traversal search to see if produce data in sorted order
    sum of nodes: one way is to traverse and sum, but easier way by adding root vals and recurs adding left and right, code: int add(node *cur_ptr) {if (cur_ptr != NULL) return cur_
        ptr->data + add(cur_ptr->left) + add(cur_ptr->right)}
    search: to see if val in tree, if(root null) return 0, else check root, if val in root (root here changes to each node b/c recursv) return 1, else if val < than root, search in
        left else search right; returns 1 if found else 0; 
        code: int find(node *cur_ptr, int val) {if(cur_ptr=null) {if(cur_ptr->data=val) return 1; if(val<cur_ptr->data) return find(cur_ptr->left, val); else (right)} else return 0}
    deletions: not simple, three cases: deleting leaf node, node w 1 child, node w 2 child; difficult b/c must change entire subtrees if children b/c need to link children again
        leaf deletion: easy, start by identifying parent of node we want to delete, then eiether free(parent->left) or free(parent->right) then update the p->left || p->right = null
        one child deletion: also easy, deletion just lifts by on level, find parent of deletion, the one way is parent->right = parent->right->right and etc for left/right
        two child deletion: not easy, imagine node a with left child b, where b children c and d, cannot just delete b and raise both its children as only a left only 1 pointer, so
            insted you need to replace deleted with val that still maintains binary tree property, should replace the deleted node with either max of left subtree of deleted or min
            of right subtree of deleted; thus copy one of these to the position of deleted and free the place where that max or min was previously; the reason behind this is b/c we 
            are guaranteed this node has at most 1 child (which is easier to delete as shown above), the reason at most 1 is given, ie for the max left, there canot be a node right
            to that max left node, this is b/c already the max so cannot be max if child is greater; similar for min right, cannot be min right and also have left children which is
            smaller; in the case that there is 1 child for that max left or min right, easy, just elevate/raise up position like for one child above b/c subtree alwys either > or <
        auxiliary functions: many functs req for deletion:
            findnode: returns pointer to node in tree that stores particular val, same as search func from before but insted if found, returns pointer to node insted of 1 else null
            parent: finds parent of given node in binary tree, since need to know parent of deletion so we can modify left and right child takes in root and pointer to node want to
            delete: parent(root, node){if(root null or is the node we want to delete) return null; if(root left || right is node) return root; if (node < root) return parent(root->
            left, node); else if(node > root) return parent(root->right, node); return null (\\extraneous cases)}
            minval: finds min val in given tree, in case 2 children deletion like above, takes in root and retrns pointer to min val, minval(root){if(root->left==null) return root;
            else return minval(root->left);
            maxval: finds max val in given tree, like above maxval(root){if(root->right==null) return root; else return maxval(root->right);
            isleaf: determines if node leaf or !, to dtermine how many children when deleting, isleaf(node) {return (node->left==null && node->right==null)};
            hasonlyleftchild: name exaplains, for determning how many children (also usful to find which side child): isleaf(node) {return (node->left!=null && node->right==null)};
            hasonlyrightchild: name exaplains, for above deletion and same as above: isleaf(node) {return (node->left==null && node->right!=null)};

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