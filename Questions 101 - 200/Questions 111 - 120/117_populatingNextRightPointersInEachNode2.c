#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
} Node;

int height(struct Node *root){
    if(root==NULL) return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if(left>right)
        return left+1;
    else
        return right+1;
}

int maxNodesPerLevel(int level){
    return pow(2,level);
}

void getNodes(struct Node *root, int currentLevel, int targetLevel, struct Node **arr, int *arrIndex){

    if(root==NULL) return;

    if(currentLevel==targetLevel){
        arr[(*arrIndex)++] = root;
        return;
    }
    else{
        getNodes(root->left, currentLevel+1, targetLevel, arr, arrIndex);
        getNodes(root->right, currentLevel+1, targetLevel, arr, arrIndex);
        return;
    }    
}

void setNextPointers(struct Node **arr, int n){
    for(int i=0; i<n-1;i++){
        arr[i]->next = arr[i+1];
    }
    arr[n-1]->next = NULL;
}

struct Node* connect(struct Node* root) {
    
    if(!root) return root;
    
    int h = height(root);
    root->next = NULL;    
    
    for(int i=1;i<h;i++){
        int arrIndex = 0;
        struct Node **arr = (struct Node**)malloc(sizeof(struct Node*)*maxNodesPerLevel(i));
        getNodes(root,0,i,arr,&arrIndex);
        setNextPointers(arr, arrIndex);
    }
    
    return root;
}

Node* initTree(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->val = 5;

    head->left = (Node*)malloc(sizeof(Node));
    head->left->val = 3;

    head->right = (Node*)malloc(sizeof(Node));
    head->right->val = 7;

    head->left->left = (Node*)malloc(sizeof(Node));
    head->left->left->val = 1;
    head->left->left->left = NULL;
    head->left->left->right = NULL;

    head->left->right = (Node*)malloc(sizeof(Node));
    head->left->right->val = 4;
    head->left->right->left = NULL;
    head->left->right->right = NULL;

    head->right->left = NULL;

    head->right->right = (Node*)malloc(sizeof(Node));
    head->right->right->val = 10;
    head->right->right->left = NULL;
    head->right->right->right = NULL;

    /*
            5
           / \
          3    7
         / \  / \
        1  4 N   10
    */
   return head;
}

void main(){
    Node *root = initTree();

    connect(root);

    printf("Success");
}