#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*front,*rear,*temp,*front1 ;
void enqueue();
void dequeue();
void display();
void main(){
	int a;

	while(1){
		printf("\n\noperation done in the queue:\n1.enqueue\t2.dequeue\t3.display\t4.exit\n");
		scanf("%d",&a);
		switch(a){
			case 1:{
				enqueue();	
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				printf("\n\nelements persent in the queue:\t");
				display();
				break;
			}
			case 4:{
				exit(0);
			}
		}
	}
}
void enqueue(){
	if( rear  == NULL){
	struct node *rear = (struct node*)malloc(sizeof(struct node));
	printf("\n\nEnter the value:");
	scanf("%d",&rear->data);
	rear->next = NULL;
	front = rear;}
	else{
		struct node * temp = (struct node*)malloc(sizeof(struct node));
		printf("\n\nEnter the value:");
		scanf("%d",&temp->data);
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}
}
void dequeue(){
	front1 = front;
	if(temp == NULL){
		printf("\n\nERROR");
		return;
	}
	else{
		if(front1->next != NULL){
			front1 = front1->next;
			printf("\n\nDequeue : %d",front->data);
			free(front);
			front = front1;
		}
		else{
			printf("\n\nDequeue : %d",front->data);
			free(front);
			front =NULL;
			rear = NULL;
		}
	}
}
void display(){
	front1 = front;
	if( (front1  == NULL) && (rear == NULL)){
	printf("\n\n Queue is empty");
	return ;}
	while(front1->next != rear){
		printf("%d-->",front1->data);
		front1= front1->next;
	}
	if(front1 == rear)
	printf("%d-->NULL",front1->data);
}