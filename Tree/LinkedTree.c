//이진 트리(Binary Tree), 가장 많이 쓰이는 트리이며 모든 노드가 2개의 서브트리를 가지고 있는 트리이다. 
//이진트리의 조건
//1. 공집합이거나
//2. 루트(root)의 왼쪽 서브트리, 오른쪽 서브트리로 구성된 노드들의 유한 집합으로 정의된다. 이진트리의 서브트리들은 모두 이진트리여야 한다.
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

//traversal, 순회 방법, V: 이번에 방문하는 노드, L: 방문한 노드의 왼쪽 노드, R: 방문한 노드의 오른쪽 노드, rn: root node
//가장 기본적인 순회 방법이며 모두 순환(recursive)을 이용했다. 순환 함수가 아니라면 구현이 어렵다.
void preorder(TreeNode *rn); //전위순회, VLR
void inorder(TreeNode *rn); //중위순회, LVR
void postorder(TreeNode *rn); //후위순회, LRV

void preorder(TreeNode *rn){
    if(rn!=NULL){
        printf("[%d] ", rn->data);
        preorder(rn->left);
        preorder(rn->right);
    }
}

void inorder(TreeNode *rn){
    if(rn!=NULL){
        inorder(rn->left);
        printf("[%d] ", rn->data);
        inorder(rn->right);
    }
}

void postorder(TreeNode *rn){
    if(rn!=NULL){
        postorder(rn->left);
        postorder(rn->right);
        printf("[%d] ", rn->data);
    }
}

void main(){
    TreeNode *n1, *n2, *n3;
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));

    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    n2->data = 20;
    n2->left = NULL;
    n2->right = NULL;

    n3->data = 30;
    n3->left = NULL;
    n3->right = NULL;

    printf("\npreOrder: ");
    preorder(n1);

    printf("\ninOrder: ");
    inorder(n1);

    printf("\npostOrder: ");
    postorder(n1);

    free(n1);
    free(n2);
    free(n3);
}