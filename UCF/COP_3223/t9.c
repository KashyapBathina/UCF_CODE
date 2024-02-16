#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*------------module 8------------------------------------------------------------------------------------------------------------*/

/*
    Important: p--, where p is a pointer, decreases the pointers adress by the size of type it points too, so when p=a[1], then p=[0] b/c decreasing adress exactly to past index
    Struct: array that allows you to store related variables of the same type in same struct, usually put a declaration after #defines
        Gen struct: struct name {
                dataType var1;
                dataType var2;
            };
    Typedef: keyword that is used to provide existing data types with a new named
        Gen struct: typedef long long ll;
                    int main() {
                        ll var = 20;
                    }
        Can combine with struct to where a new data type can be created and used to define the structure variable
            Gen struct: typedef struct {
                            char name[50];
                        } student;
                        int main () { student s1; . . .s1.name="..."}


    Dynamic Memory Allocation: more productive and efficient and has many advantages:
        Many Advantages:
            1. For when we do not know how much memory we need beforehard
            2. When we want data structs w/o any limits on upper memory
            3. When you want to use memorry space more efficently
            4. Dynamic allocation creates list of insertions and deletions by manipulatinng adresses: linked lists
            5. Important to concepts of structs and linked lists
        Malloc: used to dynamically assign a single block of memory with a certain size
            Gen Struct: ptr = (cast-type*) malloc(size of bytes);
        Calloc: when we need continuous allocatin for a specified # of blocks memory for spec type
            Gen Struct: prt = (cast-type*) calloc(n, element size); where n is element size and ES is size of each.
        Free: used to dynamically deallocate memory, or give back borrowed.
            Gen Struct: free(ptr);
        Realloc: used to add or append more memory to whhat is already set aside;
            Gen Struct: ptr = realloc(ptr, newSize); where ptr is reallocated with new size 'newSize'
        Linked List: linear data struct in which elements are not stored in a contiguous location, rather they are linkked using pointers
        and forms a series where each nodes stores the data and address of next node.
            Visualization:
                Single ll: head -> data/next (node) -> data/next (node) -> NULL
                Double ll: head -> prev/data/next (node) -> prev/data/next (node) -> NULL
            Benefits:
                1. dynamic data struct-with size that can be allocated/deallocated in run time for insertion/deletion
                2. ease of insertion/deletion-elements are simpler than arrays since no elements need to be shifted or deleted, just update adress
                3. efficient memory utilization-no wasting memory
                4. implementation-various datat structs can be implemented: stack or que
                5. uses-good for searching for certain data points
            Disadvantages:
                1. random acess-do not allow direct acess to a stored data value, must go through entire list until find
                2. require more memory to store pointers than array
*/

/*
struct block {
    int num;
    char letter;
    char color[15];
};

// where a & b are instances of the block type
#define SIZE 3
void setUp(struct block *b);
void printBlock(struct block b);
int equal(struct block a, struct block b);


int main() {
    int i, j;
    struct block mySet[SIZE];

    for (i=0;i<SIZE;i++) {
        setUp(&mySet[i]);
        printBlock(mySet[i]);
    }

    for (i=0;i<SIZE;i++) {
        for (j=i+1;j<SIZE;j++) {
            if (equal(mySet[i], mySet[j])) {
                printf("Blocks %d and %d are identical\n", i, j);
            }
        }
    }

    for (i=0;i<SIZE;i++) {
        printBlock(mySet[i]);
    }

    return 0;
}

void setUp(struct block *b) {
    printf("Enter number, letter, and color\n");
    scanf("%d %c %s", &(b->num), &(b->letter), &(b->color));
}

void printBlock(struct block b) {
    printf("%d %c %s", b.num, b.letter, b.color);
}

int equal(struct block a, struct block b) {
    if (a.number == b.number && a.letter == b.letter && !strcmp(a.color, b.color)) return 1;
    else return 0;
}
*/

/*
void fun() {
    int a;
}

int main() {
    int b;
    int c[10];
}
*/

/*
int main()
{
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;
    // Get the number of elements for the array
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Entered number of elements: %d\n", n);
    // Dynamically allocate memory using malloc()
    ptr = (int*)malloc(n * sizeof(int));
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");
        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
    return 0;
}
*/

/*
For Memory Allocation, Malloc, Calloc, and Free Code/Explanation, use:
https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/#
*/

struct node {
    int value;
    struct node *next;
};

void printLinkedList(struct node *p) {
    while (p!=NULL) {
        // -> used to access struct using pointers, . used to access regularly
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;

    head = one;
    printLinkedList(head);
}
