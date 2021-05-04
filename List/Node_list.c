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

Nodelist* reverse(Nodelist *head){
    Nodelist *p, *q, *r;

    p=head;
    q=NULL;
    while(p!=NULL){
        //link를 따라 1칸씩 움직임
        r=q;
        q=p;
        p=p->link;
        //q가 가르키는 노트의 link를 이전의 노드(q)를 가르키게 바꿈, 마지막엔 q는 기본리스트의 마지막 노드를 가르킴
        q->link = r;
    }

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