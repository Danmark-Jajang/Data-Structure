#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct _DequeType{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}DequeType;

void init_queue(DequeType *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(DequeType *q){
    if(q->front==q->rear) return 1;
    else return 0;
}

int is_full(DequeType *q){
    if((q->rear+1)%MAX_QUEUE_SIZE==q->front) return 1;
    else return 0;
}

void add_rear(DequeType *q, element item){
    if(is_full(q)){
        printf("Queue Full Error Occur\n");
        exit(1);
    }
    else{
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

void add_front(DequeType *q, element item){
    if(is_full(q)){
         printf("Queue Full Error Occur\n");
        exit(1);
    }
    else{
        q->data[q->front] = item;
        q->front = (q->front-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
    }
}

element pop_rear(DequeType *q){
    if(is_empty(q)){
        printf("Queue Empty Error Occur\n");
        return -1;
    }
    else{
        q->rear = (q->rear-1+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
        return q->data[q->rear];
    }
}

element pop_front(DequeType *q){
    if(is_empty(q)){
        printf("Queue Empty Error Occur\n");
        return -1;
    }
    else{
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

void print_queue(DequeType *q){
    printf("Deque(F=%d, R=%d)",q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1)%MAX_QUEUE_SIZE;
            printf("%d | ",q->data[i]);
            if(i==q->rear) break;
        }while(i!=q->front);
    }
    printf("\n");
}

void main(){
    DequeType q;

    init_queue(&q);
    
    add_front(&q,10);
    print_queue(&q);
    add_front(&q,20);
    print_queue(&q);
    add_rear(&q,30);
    print_queue(&q);

    pop_front(&q);
    print_queue(&q);
    pop_rear(&q);
    print_queue(&q);
    pop_rear(&q);
    print_queue(&q);
    
}