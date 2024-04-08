#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


/*
    name: Kashyap Bathina
    date: 3/30/24
    program: loyalty
*/

int n, total_customers;
#define MAXLEN 19

typedef struct customer {
    char name[MAXLEN+1];
    int points;
} customer;

typedef struct treenode {
    customer* cPtr;
    int size;
    struct treenode* left;
    struct treenode* right;
} treenode;













customer* create_customer(char* name, int points) {
  // Allocate space for the node, set the fields.
    customer* temp = (customer*) malloc(sizeof(customer));

    strcpy(temp->name, name);
    temp->points = points;

    return temp; // Return a pointer to the created node.
}


treenode* create_node(treenode *root, char *name, int points) {

  // Allocate space for the node, set the fields.
    treenode *temp = (treenode*) malloc(sizeof(treenode));

    temp->cPtr = create_customer(name, points);
    temp->size = 1;
    temp->left = NULL;
    temp->right = NULL;

    total_customers++;
    return temp; // Return a pointer to the created node.
}

treenode* insert(treenode *root, treenode *element) {
    if (root==NULL) 
        return element;
    else {
        // if element less than node
        if (strcmp(element->cPtr->name, root->cPtr->name) < 0) {
            if (root->left != NULL) 
                root->left = insert(root->left, element);
            else  
                root->left = element;
        }
        else {
            if (root->right != NULL) 
                root->right = insert(root->right, element);
            else  
                root->right = element;
        }
        root->size++;
        return root;
    }
}

treenode* find(treenode *root, char* name){
    if (root != NULL) {
        if (strcmp(name, root->cPtr->name)==0)
            return root;
        if (strcmp(name, root->cPtr->name)<0)
            return find(root->left, name);
        else 
            return find(root->right, name);
    }
    else
        return NULL;
}

treenode* max_val(struct treenode *root) {

  // Root stores the maximal value.
  if (root->right == NULL)
    return root;

  // The right subtree of the root stores the maximal value.
  else
    return max_val(root->right);
}












treenode* add(treenode *root, char *name, int points){
    // see if customer already in tree
    treenode *customer_node = find(root, name);
    
    // if new customer
    if (customer_node==NULL) {
        // create node and insert into tree
        treenode* node = create_node(root, name, points); 
        root = insert(root, node);
    }
    // if customer exists
    else {
        // add points
        customer_node->cPtr->points += points;
        points = customer_node->cPtr->points;
    }
    
    printf("%s %d\n", name, points);
    return root;
}

void sub(treenode *root, char *name, int points){
    treenode *customer_node = find(root, name);
    
    if (customer_node==NULL) 
        printf("%s not found\n", name);
    else {
        if(customer_node->cPtr->points <= points) {
            customer_node->cPtr->points=0;
            printf("%s 0\n", name);
        }
        else {
            customer_node->cPtr->points -= points;
            printf("%s %d\n", name, customer_node->cPtr->points);
        }
    }
}

treenode* del(treenode *root, char* name, int deleted){
    treenode *delnode = find(root, name);

    if (delnode==NULL) 
        printf("%s not found\n", name);
    else {
        // go through tree (left or right) until find the node wanna delete, decrement size while doing so
        // if target on left 
        if (strcmp(name, root->cPtr->name)<0) {
            root->left = del(root->left, name, deleted);
            root->size--;
        }
        //if on right
        else if (strcmp(name, root->cPtr->name)>0) {
            root->right = del(root->right, name, deleted);
            root->size--;
        }
        // case find target
        else {
            // now for that node (target), create a temp that stores the deleted, sets the current node to the approprite children, then free temp
            // case 0 children--leaf
            if (root->left==NULL && root->right==NULL) {
                if (deleted==1)
                    printf("%s deleted\n", root->cPtr->name);
                free(root->cPtr);
                free(root);
                total_customers--;
                return NULL;
            }
            
            // case 1 children--left
            else if (root->left!=NULL && root->right==NULL) {
                if (deleted==1)
                    printf("%s deleted\n", root->cPtr->name);
                treenode *temp = root->left;
                free(root->cPtr);
                free(root);
                total_customers--;
                return temp;
            }

            // case 1 children--right
            else if (root->left==NULL && root->right!=NULL) {
                if (deleted==1)
                    printf("%s deleted\n", root->cPtr->name);
                treenode *temp = root->right;
                free(root->cPtr);
                free(root);
                total_customers--;
                return temp;
            }
            
            // case 2 children
            else {
                printf("%s deleted\n", root->cPtr->name);
                treenode *temp = max_val(delnode->left);
                root->cPtr = temp->cPtr;
                root->left = del(root->left, temp->cPtr->name, 0);
                root->size--;
                return root;
            }
        }
    }
}

void search(treenode *root, char* name, int depth){
    if (root == NULL) {
        printf("%s not found\n", name);
        return;
    }

    int cmp = strcmp(name, root->cPtr->name);
    if (cmp == 0) {
        printf("%s %d %d\n", root->cPtr->name, root->cPtr->points, depth);
    }
    else if (cmp < 0) {
        search(root->left, name, depth + 1);
    }
    else {
        search(root->right, name, depth + 1);
    }
}

void count_smaller(treenode *root, char* name, int smaller) {
    if (root==NULL) {
        printf("%d\n", smaller);
        return;
    }
    // if node left
    if (strcmp(name, root->cPtr->name)<0)
        count_smaller(root->left, name, smaller); 
    // if node right  
    else if (strcmp(name, root->cPtr->name)>0){
        if (root->left != NULL)
            count_smaller(root->right, name, (smaller+root->left->size+1));
        else 
            count_smaller(root->right, name, (smaller+1));
    }
    // if node reached
    else { 
        if (root->left != NULL)
            printf("%d\n", smaller+root->left->size);
        else 
            printf("%d\n", smaller);
        return;
    }
}

void fill_customer_array(treenode* root, customer** customer_arr, int *index) {
    if (root==NULL) 
        return;
    
    fill_customer_array(root->left, customer_arr, index);
    customer_arr[(*index)++] = root->cPtr;
    fill_customer_array(root->right, customer_arr, index);
}

void free_tree(treenode* node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node->cPtr);
    free(node);
}

int compare_customers(customer* c1, customer* c2) {
    // Compare points
    if (c1->points != c2->points) {
        return c1->points - c2->points; // Sort by points
    } else {
        // If points are equal, compare names alphabetically
        return strcmp(c2->name, c1->name);
    }
}

// Partition function for Quick Sort
int partition(customer* arr[], int low, int high) {
    customer* pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j]->points > pivot->points || (arr[j]->points == pivot->points && strcmp(arr[j]->name, pivot->name) < 0)) {
            i++;
            customer* temp = NULL;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    customer* temp = NULL;
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i + 1;
}


// Implement Quick Sort for sorting customers
void quick_sort(customer* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}


void print_customer_array(customer** customer_arr) {
    for (int i=0;i<total_customers;i++) 
        printf("%s %d\n", customer_arr[i]->name, customer_arr[i]->points);
}






int main(int argc, char *argv[]) {
    // opening file from command line input
    /* the first command-line parameter is in argv[1]; (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    // checking if file given is existent
    if (fp == NULL) 
        printf("The file you gave either does not exist, or is spelled incorrectly\n");
    
    else {       
        // scanning in n and b
        fscanf(fp, "%d", &n);
        treenode *root = NULL;

        for (int i=0;i<n;i++) {
            char command[15];

            fscanf(fp, "%s", command);

            // if add customer
            if (strcmp(command, "add")==0) {
                char name[MAXLEN+1];
                int points;
                fscanf(fp, "%s", name);
                fscanf(fp, "%d", &points);

                root = add(root, name, points);
            }

            else if (strcmp(command, "sub")==0) {
                char name[MAXLEN+1];
                int points;
                fscanf(fp, "%s", name);
                fscanf(fp, "%d", &points);

                sub(root, name, points);
            }

            else if (strcmp(command, "del")==0) {
                char name[MAXLEN+1];
                fscanf(fp, "%s", name);

                root = del(root, name, 1);
            }

            else if (strcmp(command, "search")==0) {
                char name[MAXLEN+1];
                fscanf(fp, "%s", name);
                //printf("hello world"); 
                //printf("++%d", (find(root, name)->cPtr->points));

                search(root, name, 0);
            }
            

            else {
                char name[MAXLEN+1];
                fscanf(fp, "%s", name);

                count_smaller(root, name, 0);
            }
        }

        // creating customer array
        customer** customers = (customer**) malloc(total_customers * sizeof(customer*));
        // filling customer array
        int index = 0;
        fill_customer_array(root, customers, &index);
        // sorting customer array by value and breaking tie by alphabet
        quick_sort(customers, 0, total_customers-1);
        // printing in descending order
        print_customer_array(customers);

        //free_tree(root);
    }

    fclose(fp);
}