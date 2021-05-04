//Warning!! LAST NODE IS FIRST NODE
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode* insert_fisrt(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    
    node->data = data;
    if(head==NULL){ //add new node to head point
        head = node;
        node->link = head;
    }
    else{ //attech new node to head point and change head->link
        node->link = head->link;
        head->link = node;
    }

    return head;
}

ListNode* insert_last(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    node->data = data;
    if(head==NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }

    return head;
}

void print_list(ListNode* head){
    ListNode *p;
    if(head==NULL) return;
    p=head->link; //head 다음 노드부터 출력, 원형이기 때문에 시작 순서는 무의미
    do{
        printf("%d->",p->data);
        p=p->link;
    }while(p!=head); //순환하는 리스트이므로 순환의 끝을 찾을 필요가 있음
    printf("%d",p->data); //마지막 head노드 data출력
}


ListNode* search(ListNode* head, element data){
    ListNode* p = head;
    while(p->data!=data){
        p = p->link;
    }
    return p;
}

int getSize(ListNode* head){
    ListNode* p = head->link;
    int size=1;
    if(head==NULL) return 0;
    while(p!=head){
        size++;
        p=p->link;
    }
    return size;
}

void main(){
    ListNode* head = NULL;
    //ListNode* goal;
    int size = 0;

    head = insert_fisrt(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_fisrt(head, 50);
    head = insert_last(head, 60);

    // goal = search(head, 20);
    // printf("goal: %d\n",goal->data);
    size = getSize(head);
    printf("Size: %d\n",size);

    print_list(head);
}

