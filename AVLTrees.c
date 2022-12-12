// Citation: https://www.programiz.com/dsa/avl-tree

#include <stdio.h>
#include <stdlib.h>


struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

int max(int a, int b);
int height(struct node *n) {
  if (n == NULL)
  {
    return 0;
  }
  return n->height;
}

int max(int a, int b) {return (a > b) ? a : b;}


struct node *newnode(int key) {
  struct node *no = (struct node *)
    malloc(sizeof(struct node));
  no->key = key;
  no->left = NULL;
  no->right = NULL;
  no->height = 1;
  return (no);
}


struct node *rightRot(struct node *y) {
  struct node *x = y->left;
  struct node *B2 = x->right;

  x->right = y;
  y->left = B2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

struct Node *leftRot(struct node *x) {
  struct node *y = x->right;
  struct node *B2 = y->left;

  y->left = x;
  x->right = B2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int checkBalance(struct node *n) {
  if (n == NULL)
    return 0;
  return height(n->left) - height(n->right);
}


struct node *insert(struct node *no, int key) {
  if (no == NULL)
    return (newnode(key));

  if (key < no->key)
    no->left = insert(no->left, key);
  else if (key > no->key)
    no->right = insert(no->right, key);
  else
    return no;


  no->height = 1 + max(height(no->left),
               height(no->right));

  int balance = checkBalance(no);
  if (balance > 1 && key < no->left->key)
    return rightRot(no);

  if (balance < -1 && key > no->right->key)
    return leftRot(no);

  if (balance > 1 && key > no->left->key) {
    no->left = leftRot(no->left);
    return rightRot(no);
  }

  if (balance < -1 && key < no->right->key) {
    no->right = rightRot(no->right);
    return leftRot(no);
  }

  return no;
}

struct node *minVal(struct node *no) {
  struct node *current = no;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct node *delete(struct node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = delete(root->left, key);

  else if (key > root->key)
    root->right = delete(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct node *tmp = root->left ? root->left : root->right;

      if (tmp == NULL) {
        tmp = root;
        root = NULL;
      } else
        *root = *tmp;
      free(tmp);
    } else {
      struct Node *tmp = minVal(root->right);

      root->key = tmp->key;

      root->right = delete(root->right, tmp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = checkBalance(root);
  if (balance > 1 && checkBalance(root->left) >= 0)
    return rightRot(root);

  if (balance > 1 && checkBalance(root->left) < 0) {
    root->left = leftRot(root->left);
    return rightRot(root);
  }

  if (balance < -1 && checkBalance(root->right) <= 0)
    return leftRot(root);

  if (balance < -1 && checkBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRot(root);
  }

  return root;
}

void printOrder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

//Some random driver code//
int main() {
  struct node *root = NULL;

  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 7);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 8);

  printOrder(root);

  root = delete(root, 3);

  printOrder(root);

  return 0;
}
