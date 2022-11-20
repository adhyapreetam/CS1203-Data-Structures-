// Citation: https://www.sanfoundry.com/c-program-construct-balanced-binary-tree/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}
no;

no* newnode(int value){
    no* node = (no*)malloc(sizeof(no));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

no* bist(int array[], int firstpos, int lastpos)
{
    int middlepos;
    no* tmp = (no*)malloc(sizeof(no));
    if(firstpos<lastpos){
        return NULL;
    }
    middlepos = (firstpos + lastpos)/2;
    tmp = newnode(array[middlepos]);
    tmp->left = bist(array, firstpos, middlepos - 1);
    tmp->right = bist(array, middlepos + 1, lastpos);
    return tmp;
}

void show(no *tmp){
    printf("%d \t", tmp->val);
    if (tmp->left != NULL){
        show(tmp->left);
    }
    if (tmp->right != NULL){
        show(tmp->right);
    }

}

no* bitsearch(no* root, int f)
{
    if(root == NULL){
        return NULL;
    } 
    if(f < root->val) 
    {
        return bitsearch(root->val , f);
        
    }
    else if(f > root->val) 
    {
        return bitsearch(root->right, f);
        
    }
    else {
        return root;
        
    }
}

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void sort(int array[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (array[j] > array[max])
        max = j;
    }
    swap(&array[max], &array[i]);
  }
}

void printarr(int array[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d \t", array[i]);
  }
  printf("\n");
}

int main() {
    int m;
    printf("Enter the size of your array: \n");
    scanf("%d", &m);
    int array[m], i;
    int *a = array;
    printf("Enter your array: \n");
    for (i = 0; i < m; i++){
        scanf("%d", &array[i]);}
    no *root = (no*)malloc(sizeof(no));
    printf("Sorted array:\n");
    sort(array, m);
    printarr(array, m);
    root = bist(array, 0, m-1);
    
    printf("The binary search tree can be traversed in the following (prefix) order: \n");
    show(root);
    printf("\n");
    return 0;
    
            
}
