#include <stdio.h>
#include <stdlib.h>

static int countsAllocated = 0;

struct Node
{
	int value;
	struct Node* next;
};

void printList(struct Node* head)
{
	struct Node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

struct Node* allocateNode(int value)
{
	struct Node* node = (struct Node *) malloc(sizeof(struct Node));
	node->value = value;
	node->next = NULL;
	countsAllocated++;
	return node;
}

struct Node* mergeLists(struct Node* pNumbers1, struct Node* pNumbers2) {
    if (pNumbers1 == NULL)
        return pNumbers2;
    if (pNumbers2 == NULL)
        return pNumbers1;

    struct Node* mergedList = NULL; // Initialize the merged list head
    struct Node* tail = NULL; // Initialize the tail pointer for efficient insertion

    while (pNumbers1 != NULL || pNumbers2 != NULL)
    {
        // Compare the values of the current nodes of both lists
        if (pNumbers1 != NULL && pNumbers1->value <= pNumbers2->value) {
            // If value from list 1 is smaller or equal, append it to merged list
            if (mergedList == NULL)
                mergedList = tail = pNumbers1;
            else
            {
                tail->next = pNumbers1;
                tail = pNumbers1;
            }
            pNumbers1 = pNumbers1->next; // Move to the next node in list 1
        }
        if (pNumbers1 != NULL && pNumbers2->value <= pNumbers1->value) {
            // If value from list 2 is smaller, append it to merged list
            if (mergedList == NULL)
                mergedList = tail = pNumbers2;
            else
            {
                tail->next = pNumbers2;
                tail = pNumbers2;
            }
            pNumbers2 = pNumbers2->next; // Move to the next node in list 2
        }
    }

    return mergedList; // Return the head of the merged list
}

void insert(struct Node** pHead, int value)
{
	struct Node* newNode = allocateNode(value);
	newNode->next = *pHead;
	*pHead = newNode;
}

void* freeList(struct Node** pHead)
{
	struct Node* tmp = *pHead;
	while (tmp != NULL)
	{	
		*pHead = tmp->next;
		free (tmp);
		tmp = *pHead;
		countsAllocated--;
	}

	return *pHead;
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums1;
	int countOfNums2;
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;

	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		head1 = NULL;
		head2 = NULL;
		head3 = NULL;
		fscanf(inFile, " %d %d\n", &countOfNums1, &countOfNums2);
		for (i = 0; i < countOfNums1; i++)
		{
			fscanf(inFile," %d", &value);
			insert(&head1, value);
		}
		for (i = 0; i < countOfNums2; i++)
		{
			fscanf(inFile, " %d", &value);
			insert(&head2, value);
		}

		printf("List 1:\n");
		printList(head1);
		printf("List 2:\n");
		printList(head2);

		printf("Memory Allocated before merge : %d\n", countsAllocated);
		head3 = mergeLists(head1, head2);
		printf("List 3:\n");
		printList(head3);

		freeList(&head3);
		printf("Memory Allocated after free : %d\n", countsAllocated);

	}

	fclose(inFile);
}