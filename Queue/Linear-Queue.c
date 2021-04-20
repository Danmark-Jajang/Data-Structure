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
    q->front = -1;
    q->rear = -1;
}

void print_queue(QueueType *q){
    int i;
    for(i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=q->front || i>q->rear){
            printf("   | ");
        }
        else{
            printf("%d | ",q->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){
    if(q->rear==MAX_QUEUE_SIZE-1) return 1;
    else return 0;
}

int is_empty(QueueType *q){
    if(q->front==q->rear) return 1;
    else return 0;
}

void enqueue(QueueType *q, element item){
    if(is_full(q)){
        printf("Queue Full Error Occur");
        exit(1);
    }
    else{
        q->data[++(q->rear)] = item;
    }
}

element dequeue(QueueType *q){
    if(is_empty(q)){
        printf("Queue Empty Error Occur");
        exit(1);
    }
    else{
        return q->data[++(q->front)];
    }
}

void main(){
    element item;
    QueueType q;
    init_queue(&q);

    enqueue(&q, 10);
    print_queue(&q);
    enqueue(&q, 20);
    print_queue(&q);
    enqueue(&q, 30);
    print_queue(&q);

    item = dequeue(&q);
    print_queue(&q);
    item = dequeue(&q);
    print_queue(&q);
    item = dequeue(&q);
    print_queue(&q);
}
