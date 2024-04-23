#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


/*
    name: Kashyap Bathina
    date: 3/8/24
    program: inventory
*/


#define MAXLEN 19
#define TABLESIZE 300007

// struct item
typedef struct item {
    char name[MAXLEN+1];
    int quantity;
    int saleprice;
} item;

// struct node
typedef struct node {
    item* iPtr;
    struct node* next;
} node;

// struct hashtable
typedef struct hashtable {
    node** lists;
    int size;
} hashtable;

// hashfunction
int hashfunc(char* word, int size) {
    // takes in word and returns hash index
    int len = strlen(word);
    int res = 0;
    for (int i=0; i<len; i++)
        res = (1151*res + (word[i]-'a'))%size;

    return res;
}

// creates item using name, quantity, and price given in
item* create_item(char* item_name, int quant, int price) {
    item* new_item = (item*) malloc(sizeof(item));

    strcpy(new_item->name, item_name);
    new_item->quantity = quant;
    new_item->saleprice = price;

    return new_item; // Return a pointer to the created item.
}

// creates node and initialzes the iPtr to the item given
node* create_node(item* new_item) {
    node* new_node = (node*) malloc(sizeof(node));

    new_node->iPtr = new_item;
    new_node->next = NULL;
    return new_node; // Return a pointer to the created node.
}

// buy function using hashtable, item name, quantity, price, and pointers to complexity, cash, and output file
void buy(hashtable* my_hashtable, char* item_name, int quantity, int price, int* total_complexity, int* total_cash, FILE* out) {
    // getting hash index
    int hash = hashfunc(item_name, (*my_hashtable).size);
        
    // case list empty in that hash index, add to list
    if (my_hashtable->lists[hash] == NULL) {
        // create item struct and allocate space for new node struct
        item* new_item = create_item(item_name, quantity, 0);
        node* new_node = create_node(new_item);

        // adding node to list at index, updating complexity and cash
        my_hashtable->lists[hash] = new_node;
        (*total_complexity)++;
        (*total_cash) -= price;

        // printing buy output
        fprintf(out, "%s %d %d\n", my_hashtable->lists[hash]->iPtr->name, my_hashtable->lists[hash]->iPtr->quantity, *total_cash);
        return;
    }
    // looking through list until find item
    node* temp = my_hashtable->lists[hash];
    int k = 1;
    while (temp != NULL) {
        // if find item, buy items, update complexity and cash
        if (strcmp(temp->iPtr->name, item_name)==0) {
            temp->iPtr->quantity += quantity;
            (*total_complexity) += k;
            (*total_cash) -= price;
            fprintf(out, "%s %d %d\n", temp->iPtr->name, temp->iPtr->quantity, *total_cash);
            return;
        }
        // if not found add to complexity and go to next node
        k++;
        temp = temp->next;
    }

    // case not find item in list, add to front of list
    item* new_item = create_item(item_name, quantity, 0);
    node* new_node = create_node(new_item);
    new_node->next = my_hashtable->lists[hash];
    my_hashtable->lists[hash] = new_node;
    (*total_complexity) += k;
    (*total_cash) -= price;
    
    // printing buy output
    fprintf(out, "%s %d %d\n", my_hashtable->lists[hash]->iPtr->name, my_hashtable->lists[hash]->iPtr->quantity, *total_cash);
    return;
}
 
// sell function using hashtable, item name, quantity, and pointers to complexity, cash, and output file
void sell(hashtable* my_hashtable, char* item_name, int quantity, int* total_complexity, int* total_cash, FILE* out) {
    // getting hash index
    int hash = hashfunc(item_name, (*my_hashtable).size);
    node* temp = my_hashtable->lists[hash];

    int k = 1;
    // looping thru list at hash index 
    while (temp != NULL) {
        // if find item
        if (strcmp(temp->iPtr->name, item_name)==0){
            // if stock of item less than demand
            if (temp->iPtr->quantity < quantity) {
                // then give all stock quantity in item
                (*total_cash) += temp->iPtr->saleprice * temp->iPtr->quantity;
                temp->iPtr->quantity = 0;
            }
            // if enough stock
            else {
                // then give stock as requested
                (*total_cash) += temp->iPtr->saleprice * quantity;
                temp->iPtr->quantity -= quantity;
            }
            // printiing out sell output
            (*total_complexity) += k;
            fprintf(out, "%s %d %d\n", temp->iPtr->name, temp->iPtr->quantity, *total_cash);
            return;
        }
        // if current node not item, increment complexity and go to next pointer
        k++;
        temp = temp->next;
    }
}

// change price function that takes in hashtable, item name, new price, and pointers to current complexity and current cash
void change_price(hashtable* my_hashtable, char* item_name, int new_price, int* total_complexity, int* total_cash) {
    // getting hash index
    int hash = hashfunc(item_name, (*my_hashtable).size);
    node* temp = my_hashtable->lists[hash];

    int k = 0;
    // looping thru list at hash index 
    while (temp != NULL) {
        k++;
        // if find item, change price and update complexity
        if (strcmp(temp->iPtr->name, item_name)==0){
            temp->iPtr->saleprice = new_price;
            (*total_complexity) += k;
            return;
        }
        temp = temp->next;
    }
}

// dealloc list given pointer to linked list head
void deallocateList(node** head) {
    // go through list with temp and head, updating head and free previous node
    node* tmp = *head;
    while (tmp != NULL) {
        *head = tmp->next;
        free(tmp->iPtr);
        free(tmp);
        tmp = *head;
    }
    *head = NULL;
}

// main function
int main(int argc, char *argv[]) {
    // usage error
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // opening file from command line input
    /* the first command-line parameter is in argv[1]; (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
    FILE *out = fopen(argv[2], "w"); 

    // checking if file given is existent
    if (fp == NULL || out == NULL) {
        printf("The file you gave either does not exist, or is spelled incorrectly\n");
        return 1;
    }
    // if file given
    else {
        // scanning in n
        int n, total_complexity = 0, total_cash = 100000;       
        fscanf(fp, "%d", &n);

        // making hashtable
        hashtable my_hashtable; 
        my_hashtable.lists = (node**) malloc(TABLESIZE * sizeof(node*));
        my_hashtable.size = TABLESIZE;

        // setting each index in hashtable to NULL
        for (int i = 0; i < TABLESIZE; i++) {
            my_hashtable.lists[i] = NULL;
        }

        // going through n commands 
        for (int i=0;i<n;i++) {
            char command[15];
            fscanf(fp, "%s", command);

            // if add item, take in input and do buy function
            if (strcmp(command, "buy")==0) {
                char item_name[MAXLEN+1];
                int quantity, price;

                fscanf(fp, "%s", item_name);
                fscanf(fp, "%d", &quantity);
                fscanf(fp, "%d", &price);
                
                buy(&my_hashtable, item_name, quantity, price, &total_complexity, &total_cash, out);
            }
            // if sell item, take in input and do sell function
            else if (strcmp(command, "sell")==0) {
                char item_name[MAXLEN+1];
                int quantity;
                
                fscanf(fp, "%s", item_name);
                fscanf(fp, "%d", &quantity);
                
                sell(&my_hashtable, item_name, quantity, &total_complexity, &total_cash, out);
            }
            // if change price function, take in input and do sell function
            else {
                char item_name[MAXLEN+1];
                int new_price;

                fscanf(fp, "%s", item_name);
                fscanf(fp, "%d", &new_price);
                    
                change_price(&my_hashtable, item_name, new_price, &total_complexity, &total_cash);
            }            
        }
        
        // freeing memory, for each hash index, free that list
        for (int i=0;i<TABLESIZE;i++) {
            deallocateList(my_hashtable.lists);
        }

        // printing complexity and cash
        fprintf(out, "%d\n", total_cash);
        fprintf(out, "%d\n", total_complexity);
    }
    // closing files
    fclose(fp);
    fclose(out);
    return 0;
}