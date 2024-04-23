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
    data struct similar to binary trees, however difference is all values in subtree of given node must be < or == to value stored in that node, called heap property and is why max
    val on top in root, property called max-heap; however can also be reverse, where miniheap has min at root and all children greater, those were basic heaps, 
    binary heaps: to be this type of heap, must adhere to shape property--where heap must be complete binary tree and all levels except last filled or if last not filled, then node
        filled from left to right,to ensure this property, all new values must be added to bottom and insrted left to right; no relationships among node in each level, meaning left
        and right child dont necesarily need to be left is smaller and right is larger like in BST, only criteria is either larger or smaler than parent; hence b/c of this, heap is
        always balanced and partially ordered, though not sorted; b/c of this, a heap can have many different shapes depending on the order the data is inputed, even tho data might
        be the same
    priority-queues: to reason binary heaps are important is b/c it used to create this abstract data type--which is a queue based not on 1stin-1stout, but on priority; 1 method is
        with linked lists, but its easier to do with binary heaps so make an abstract type (prio queues) with another abstract (heaps); run time is O(logn) for both insertion & del
        -etion into a Heap; to find max in maxheap or min in minheap, just O(1) since looking at top
        addition: to add, assume that you are + to a proper binary heap balanced & has shape property, then 1) add to next available spot on the last levl, however, not usually bal
            -anced when you do this so this is usually just temp place, so to enusre heap property and fix order, must 2) perlocate up--for max heap, if parent not > than current
            , then swap; this is 1 perlocate up and then continue perlocating until in correct order where parent of new is > than current and if reach  to top, then new root; the 
            insertion is O(1) since just insert at bottom, but to ensure order, might have to go all the way to top level which is O(logn), hence insertion O(logn)
        deletion: in priority queues, alway 1) deleting top root which (either max for maxheap or converse) has highest priority, however, since now no root, must reorder, 2) copy
            last node in last level and put in position of root temporily, since likely not ordered still 3) perlocate down--like perl up, we swap new root with the greater of its
            children nodes and do until last node ends where children have values smaller (again maxheap) and not greater; run time for actual deletion and  replacement are each 
            O(1) as delting root and moving last to root, but to reorder, worst case is perlocating down until full length of tree O(logn), so overall O(logn)
        building heap from scratch: when given list of nums, just a series of insertions and ordering with perlocating up, so run time is insertion*num elements, logn*n = O(nlogn)
            however, better method than O(nlogn) called heapify: 1) arbritarily place elements into complete binary tree that is shaped (not necessarily binary ordering ie left <)
            2) starting on lowest lvl, perlocate down if necessary (note perlocating at lowest ! necessarily doing anything since no children, but start at lowest anyway for cons-
            istency for the algorithm) and work from bottom to top/root and doing perlocate down from right to left, other way to interpret is just divide into subtrees and doing 
            heapify from bottom subtree right to left; run time: in each tree, lowest has 1/2 total nodes, so in complete 31 nodes, lowest 16 and these 16 don't need to be perloc
            ated since no children, the level above has rest 8 out of 16, but these 8 at most only perlocate 1 level since only 1 lvl below, above is 4 and perlocated 2 etc.., so
            can say worst runtime (when complete tree since most nodes) is proportioal to height of node, n/2 0 level perlocated (h=0), n/4 is 1, n/8 is 2, so general: (0*n/2) + 
            (1*n/4) ... = sum from k=1 to h, k * (n/2^(k+1)) which is rougly O(n) with calculus
        binary heaps in an array: do it the same way we implement binary tree as array, if tree is complete: root index 1(skip index 0 for counting measures), two children indx 2
            and 3, next 4 nodes 4-7, next 8 nodes 8-15 etc, to make actual heap (insted of making entire new heap), use array which in turn implements priority queue and the way 
            we derefrence and manipulate data makes the array a tree (ie the way we jump indexes simulates tree); hence, easier to do all (heap/priority queue) in an array insted
            of regular struct, each with left and right children and nodes and values ect; array is just top to bottom, left to right, but the way we access dictates the binary
            heap: root is a[1] (again skip 0), left child of a at i a[i]=a[2i], right child a[i]=a[2i+1], note empty positions iin array where empty child; 

avl trees: remeber goal of BST is to provide O(logn) lookup for insrtion/deletion, however this only works if complete tree and all lvls filled with excpt last lvl which is filled
    left to right where in this case, since 2 children each, logn; however in case BST not complete, not necessarily logn as height depends on order, ie 1 2 3 4 5, which is just a
    skewed slanted line and unbalanced, essentially a linked list with heigh n instead of logn; hence motivation for AVL is to mainatin balance to maintain O(logn)--AVL is BST in
    which heights of subtrees of given node differ by no more than 1; for every node in BST must check height of left and right subtree; AVL essentially height balanced BST; def: T
    BST, is an AVL if Tl and Tr also AVL and |hl-hr| <= 1, in other words between -1,0,1, called balance factor (ie the hl-hr); note height of subtree does not count current node
    implementation in code is just additional int, Bf in node struct; now search is O(logn), but now also have to re-balance tree for every insert and del
    insertion: same typical BST insertion, but now need to worry about balance; 4 ways AVL gets unbalanced due to insertion: 1) ins new node to right subtree or right child 2) ins-
        erting new node to left subtree of left child 3) inserting new node to left subtree of right child 4) inserting new node right subtree of left child; algoritm inserton then 
        is: 1) insert in typucal BST rule 2) from ins point, update BF's of all nodes along path to the path of the root; 3) if node as you go up has bf 2 or -2, in other words 1st 
        node out of balance, mark that node as one of 3 restructuring nodes, take 2 steps back down towards the insertion and mark those 2 nodes as well, label those as A,B,C nodes, 
        4) restructr those three nodes so middle value is parent; to restructure children of the 3 nodes, name t0, t1, t2, t3, where in inorder listing, once nodes labeled, all diff 
        cases fixed same way, where b middle parent, a left child with children t0,t1 and C right child with children t2,t3, noting smallest A, mid B, largest C; remember the child
        are in inorder (meaning read left child, then current, then right child); another way to mark children t0, t1.. is smallest to largest subtrees
        rotations: in the case 1 and 2 above for unbalanced (either cba slanted left or abc slanted right), we only do 1 rotation as we just rotate the top node (c if cba) and move
            it from parent to child of b, only 1 rotation since a already child of b and b just stays as is; howevr, when insertun right subtree of left child or convrse, the shape
            of the three nodes is triangle shaped, so in case of cab, which is triangel pointed left, we need to move b from child of a to parent of a, which gets cba, then we need
            to make c child of b (it is current parent of b), which gets b (left:c right:a), hence 2 rotations if triangle
    deletion: 1) start with normal BST deletion 2) update balance factors of nodes along path from del to root 3) when find first node out of balance, mark as 1 of 3 restruc nodes, 
        but now instead of going back down path towards del point, go step down towards taller subtree and mark 2 nodes (b/c restruct makes subtree smaller, but we don't want to go 
        back path of deleted since dont want alrdy deleted subtree to get even shorter, instead go path longer opposite side side to make that side shorter to balance out deletion 
        in deleted side) 4) restruct the three nodes 5) recursively checking again bf up to root (reason we check bf again is b/c, unlike insertion where only at most 1 node re-bal
        anced, deletion has multiple nodes being reblanced and when fixed b/c we are 1) deleting node 2) then restructring and shortening oppossite longer end, so 2 heighst changed
        which might mean 1 less level, so error might propogate to ancestor); note when going down longer side, if two sides = go to the same side as parent is to grandparent, ie if 
        curr node is right child of parent, do the right child of current if same heights left and right
*/






#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}