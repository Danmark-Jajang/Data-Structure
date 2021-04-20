#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct _ArrayListType{
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;

void init(ArrayListType *l){
    l->size = 0;
}

int is_empty(ArrayListType *l){
    return l->size==0;
}

int is_full(ArrayListType *l){
    return l->size==MAX_LIST_SIZE;
}

element get_entry(ArrayListType *l, int pos){
    if(pos<0||pos>MAX_LIST_SIZE){
        printf("Position Error\n");
        return -1;
    }
    return l->array[pos];
}

void print_list(ArrayListType *l){
    int i;
    for(i=0;i<l->size;i++){
        printf("%d -> ",l->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType *l, element item){
    if(l->size>=MAX_LIST_SIZE){
        printf("Overflow Error\n");
        return;
    }
    l->array[l->size++]=item;
}

void insert(ArrayListType *l, int pos, element item){
    int i;
    if(!is_full(l)&&(pos>=0)&&(pos<=l->size)){ //가득차지 않았고 pos가 가르키고 있는 위치가 빈공간이 아닐때
        for(i=l->size-1;i>=pos;i--){
            l->array[i+1] = l->array[i]; //pos부터 끝까지 한칸씩 뒤로 밀기
        }
        l->array[pos] = item;
        l->size++;
    }
}

element delete(ArrayListType *l, int pos){
    element item;
    int i;
    if(pos<0||pos>=l->size){
        printf("Position Error\n");
        return -1;
    }
    item = l->array[pos];
    for(i=pos;i<l->size-1;i++){
        l->array[i] = l->array[i+1];
    }
    l->size--;
    return item;
}

void main(){
    ArrayListType list;
    init(&list);

    insert(&list, 0, 10); print_list(&list);
    insert(&list, 0, 20); print_list(&list);
    insert(&list, 0, 30); print_list(&list);
    insert(&list, 0, 40); print_list(&list);
    insert(&list, 0, 50); print_list(&list);
    insert_last(&list, 60); print_list(&list);
    delete(&list, 0); print_list(&list);
}