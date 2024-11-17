// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *delete(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = delete(root->left, key);
  else if (key > root->key)
    root->right = delete(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = delete(root->right, temp->key);
  }
  return root;
}

// Driver code
int main(){
int choice,i,b;
struct node *root = NULL;
while(1){
printf("Enter Choice \n 1 Insert \n 2 Delete \n 3 InOrder\n");
printf("Enter the choice:\t");
scanf("%d", &choice);
switch(choice){
case 1:{
    printf("element to insert :\t");
    scanf("%d",&i);
    root=insert(root,i);
break;
}
case 2:
printf("Enter the element to be deleted");
scanf("%d",&b);
root = delete(root,b);

break;
case 3:
	printf("showing the element in inorder: \n");
inorder(root);
break;
/*case 4:
preorder(root);
break;
case 5:
postorder(root);
break;*/
case 4: exit(0);
default: printf("Wrong option");
}
}
return 0;
}