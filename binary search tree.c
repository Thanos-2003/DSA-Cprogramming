
#include <stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};


struct node *new(){
struct node *new;
printf("Emter element to insert");
new = (struct node *)malloc(sizeof(struct node ));
scanf("%d", &new->data);
new -> left = NULL;
new -> right = NULL;
return new;
}

struct node *insert(struct node *root, struct node *key){
if(key -> data< root -> data){     //if the input is leser than the value in the root 
if (root->left !=NULL){           //some element is already there in the left part of the tree
insert(root->left,key);           //root->left will become the new root and 'insert' gets called again
}
else{                      //no element is there in the left part of the tree so we directly assign the input to the left part 
root->left = key;
}
}
else{
if (root->right !=NULL){       //same as above
insert(root->right,key);       //same as above
}
else
root->right = key;

}
return root;          //returning the same value we're getting because a structure function HAS to return some value
}
struct node *ipre(struct node *root){
root = root -> left;
while(root -> right != NULL){
root = root -> right;
}
return root;
}
struct node *delete(struct node *root, int key){
struct node *temp;

if (root == NULL){
return NULL;                  // after deleting a value that place becomes empty, so we assign NULL to it  
}

if(root -> right == NULL && root -> left == NULL){   //if the node is a leaf node
free(root);                     
return NULL;
}

if(key < root->data){
root -> left = delete(root->left, key);
}

else if(key > root -> data){
root -> right = delete(root -> right, key);
}

else{
temp = ipre(root);
root -> data = temp -> data;
root -> left =delete(root->left, temp -> data);
}
}

void inorder(struct node *t) {
if(t != NULL) {

inorder(t -> left);
printf("\n%d\n", t -> data);
inorder(t->right);
}

}
void preorder(struct node *t) {
if(t != NULL) {
printf("\n%d\n", t -> data);
preorder(t -> left);

preorder(t->right);
}

}

void postorder(struct node *t) {
if(t != NULL) {

postorder(t -> left);

postorder(t->right);
printf("\n%d\n", t -> data);
}

}

int main(){
int choice,a;
struct node *root = NULL, *temp;
while(1){
printf("Enter Choice /n 1 Insert /n 2 Delete /3 InOrder /4 PreOrder /n 5 PostOrder");
scanf("%d", &choice);
switch(choice){
case 1:
temp = new();         //*temp cos we need to take in a whole node rather than just an int value
if(root== NULL){     //if the tree is empty ie first root
root = temp;
}
else{
insert(root, temp);    // temp = struct node* key
}
break;
case 2:
if(root== NULL){
printf("Error");
}
else{
printf("Enter the element to be deleted");
scanf("%d",&a);
delete(root,a);
}
break;
case 3:
inorder(root);
break;
case 4:
preorder(root);
break;
case 5:
postorder(root);
break;
case 6: exit(0);
default: printf("Wrong option");
}
}
return 0;
}