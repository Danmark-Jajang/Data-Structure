#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Nodelist{
    element data;
    struct Nodelist *link;
}Nodelist;

Nodelist* insert_first(Nodelist *head, element item){
    Nodelist *p = (Nodelist *)malloc(sizeof(Nodelist));
    p->data = item;
    p->link = head;
    head = p;
    return head;
}

Nodelist* insert(Nodelist *head, Nodelist *pre, element item){
    Nodelist *p = (Nodelist *)malloc(sizeof(Nodelist));
    p->data = item;
    p->link = pre->link;
    pre->link = p;
    return head;
}

Nodelist* delete_first(Nodelist *head){
    Nodelist *deleted;
    if(head==NULL) return NULL;
    deleted = head;
    head = deleted->link;
    free(deleted);
    return head;
}

Nodelist* delete(Nodelist *head, Nodelist *pre){
    Nodelist *deleted;
    if(head==NULL) return NULL;
    deleted = pre->link;
    pre->link = deleted->link;
    free(deleted);
    return head;
}

void print_list(Nodelist *head){
    Nodelist *p;
    for(p=head;p!=NULL;p = p->link){
        printf("%d -> ",p->data);
    }
    printf("NULL\n");
}

void main(){
    int i;
    Nodelist *head = NULL;
    
    for(i=0;i<5;i++){
        head = insert_first(head, i*10);
        print_list(head);
    }

    for(i=0;i<5;i++){
        head = delete_first(head);
        print_list(head);
    }
}