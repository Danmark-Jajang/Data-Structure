#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct _QueueType{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q){
    if(q->front==q->rear) return 1;
    else return 0;
}

int is_full(QueueType *q){
    if((q->rear+1)%MAX_QUEUE_SIZE==q->front) return 1;
    else return 0;
}

void print_queue(QueueType *q){
    printf("Queue(F=%d, R=%d)",q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1)%MAX_QUEUE_SIZE;
            printf("%d | ",q->data[i]);
            if(i==q->rear) break;
        }while(i!=q->front);
        printf("\n");
    }
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
         printf("Queue Full Error Occur\n");
         return;
    }
    else{
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        printf("Queue Empty Error Occur\n");
    }
    else{
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

void main(){
    QueueType q;
    element item;

    init_queue(&q);

    enqueue(&q,10);
    print_queue(&q);
    enqueue(&q,20);
    print_queue(&q);
    enqueue(&q,30);
    print_queue(&q);
    enqueue(&q,40);
    print_queue(&q);
    enqueue(&q,50);

    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
    dequeue(&q);
}