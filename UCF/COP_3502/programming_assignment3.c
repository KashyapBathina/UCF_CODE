#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

// constants and global vars
#define name_size 50
int n, b;

/*
    name: Kashyap Bathina
    date: 3/7/24
    program: movieline
*/




// struct for name, nt, ln, and at
typedef struct customer {
    char name[name_size];
    int number_of_tickets;
    int line_number;
    int arrival_time;
} customer;

// struct for customer type and next node
typedef struct node {
    customer* node_customer;
    struct node* next;
} node;

// queue made of node structs front and back and size
typedef struct queue {
    node* front;
    node* back;
    int size;
} queue;






// enqueue given customer into given queue
void enqueue(queue *queue, customer *customer) {
    // creating new node for queue and fill it in with customer
    node* new_node = (node*) malloc(sizeof(node));
    new_node->node_customer = customer;
    new_node->next = NULL;

    // depending on whether que empty or not
    if (queue->size==0) {
        // if empty, make front and back thew new_node
        queue->front = new_node;
        queue->back = new_node;
    } 
    // if queue not empty
    else {
        // add queue and update back
        queue->back->next = new_node;
        queue->back = new_node;
    }
    // increse que size
    queue->size++;
}

// deque first element of queue
customer* dequeue(queue *queue) {
    // if queue empty
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }

    // creating temp node
    node *temp = queue->front;
    customer *node_customer = temp->node_customer;
    
    // dequeuing and settling case queue now empty
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->back = NULL;
    }

    // freeing node, decreasing size, and returning customer
    free(temp);
    queue->size--;
    return node_customer;
}

// gets front element of queue
customer* peek(queue *queue) {
    // if queue empty
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->front->node_customer;
}

// Function to check if a queue is empty
int is_empty(queue *queue) {
    return queue->front == NULL;
}

// Function to get the size of a queue
int get_size(queue *queue) {
    return queue->size;
}









// initializes queue and returns pointer to the queue
queue* initialize_queue() {
    // allocates memory and initializes values of queue
    queue* my_queue = (queue*) malloc(sizeof(queue));

    my_queue->front = NULL;
    my_queue->back = NULL;
    my_queue->size = 0;

    return my_queue;
}

// makes customer given values and returns pointer to the customer object
customer* make_customer(char cname[], int cnumber_of_tickets, int cline_number, int carrival_time){
    // allocates memory and initializes values of customer given the paramaters 
    customer* newCustomer = malloc(sizeof(customer));

    strcpy(newCustomer->name, cname);
    newCustomer->number_of_tickets = cnumber_of_tickets;
    newCustomer->line_number = cline_number;
    newCustomer->arrival_time = carrival_time;

    return newCustomer;
} 

// distributing queues into booths and caluclating checkout time
void distribute_into_booths(queue** my_queues, int b){
    // creating arr to keep track of non-zero queues
    int k=0, non_empty_queues[12];


    // calculate k, put these line numbers in int array
    for (int i=0;i<12;i++) {
        if (!(is_empty(my_queues[i]))) {
            non_empty_queues[k] = i;
            k++;
        }
    }



    int index = 0;
    // for each booth, add corresponding queues and merge accordingly
    for (int i=0;i<b;i++) {
        int num_queues = 0;

        printf("Booth %d\n", i+1);

        // calculate how many queues in each booth
        if (i < (k%b))
            num_queues = k / b + 1;
        else 
            num_queues = k/b;
        
        int time = 0;
        int queues_still_not_emptied = num_queues;
        while (queues_still_not_emptied != 0) {
            int min = 1000000001;
            // iterate through front of each queue find if <min
            
            int index_for_min = -1;
            for (int j=0;j<num_queues;j++) {
                if (!(is_empty(my_queues[non_empty_queues[index + j]]))) {
                    // the arrival time of the customer at the front of that queue
                    int at = my_queues[non_empty_queues[index + j]]->front->node_customer->arrival_time;

                    // find min arrival time among fronts of queues
                    if (at < min) {
                        min = at;
                        index_for_min = index + j;
                    }
                }
            }


            // dequeue the node where queue front is min and find what the line num is
            customer* dq = dequeue(my_queues[non_empty_queues[index_for_min]]);
            char name[50];
            strcpy(name, dq->name);
            int nt = dq->number_of_tickets;
            int ln = dq->line_number;
            int at = dq->arrival_time;

            // do calculations for checkout time
            if (time < at) {
                time = at + (30 + (nt*5));
            }
            else {
                time += (30 + (nt*5));
            }

            // printing customer and checkout time
            printf("%s from line %d checks out at time %d.\n", name, ln, time);

            // if the line num at the queue you dequeues == 0, num_queues--; 
            if (my_queues[dq->line_number-1]->size==0) {
                queues_still_not_emptied--;
            }

            // freeing customer
            free(dq);

        }
        
        index += num_queues;
        printf("\n");
    }
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
        fscanf(fp, "%d", &b);
        
        // creating 12 queues and initializing each
        queue* my_queues[12];
        for (int i=0;i<12;i++) {
            my_queues[i] = initialize_queue();
        }

        // for each n
        for (int i=0;i<n;i++) {
            char name[50];
            int nt;
            int line_num;
            int t;

            // scanning in name, num of tickets, and arrival time
            fscanf(fp, "%s ", name);
            fscanf(fp, "%d ", &nt);
            fscanf(fp, "%d ", &t);


            // choosing which queue using formula
            line_num = (name[0]-'A') % 13;
            
            // case p%13 is 0
            if (line_num==0) {
                int min = 500001;
                int min_index = -1;

                // iterating over all queues and finding queue with smallest size
                for (int j=0;j<12;j++) {
                    if ((my_queues[j]->size != 0) && (my_queues[j]->size < min)) {
                        min = my_queues[j]->size;
                        min_index = j;
                    }
                }

                // case all queues empty
                if (min_index==-1)
                    line_num=1;
                // determining line number
                else 
                    line_num = min_index+1;
            }

            // creating a customer with name, nt, ln just calculated, and t
            customer* new_customer = make_customer(name, nt, line_num, t);

            // adding this customer to appropriate queue num just calculated
            enqueue(my_queues[line_num-1], new_customer);
        }

        // divide queues into appropriate booths and print out the result for each booth
        distribute_into_booths(my_queues, b);
    }
    
    // closing file pointer
    fclose(fp);
}