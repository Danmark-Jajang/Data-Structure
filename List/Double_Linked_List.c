#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DLList{
    element data;
    struct DLList* llink;
    struct DLList* rlink;
}DLList;

void init(DLList* head){
    head->llink = head;
    head->rlink = head;
}

void insert(DLList* before, element data){
    DLList *node = (DLList*)malloc(sizeof(DLList));

    node->data = data;
    node->llink = before;
    node->rlink = before->rlink;

    before->rlink->llink = node;
    before->rlink = node;
}

void delete(DLList* head, DLList* removed){
    if(head==NULL) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void print_list(DLList* head){
    DLList* p;
    for(p=head->llink;p!=head;p=p->llink){
        printf("<-|%d|->",p->data);
    }
    printf("\n");
}

void print_list_reverse(DLList* head){
    DLList* p=head;
    printf("print data in reverse: ");
    for(p=p->rlink;p!=head;p=p->rlink){
        printf("%d ",(int)p->data);
    }
    printf("\n");
}

DLList* search(DLList* head, element data){
    DLList* p=head->rlink;
    if(head==NULL) return NULL;
    while(p!=head){
        if(p->data==data) return p;
        p=p->rlink;
    }
    return NULL;

}

void main(){
    int i;
    DLList* head = (DLList*)malloc(sizeof(DLList));
    DLList* find = NULL;
    init(head);
    
    for(i=0;i<5;i++){
        insert(head, i);
    }
    find = search(head, 3);
    printf("search result: %d", find->data);
}