#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front = -1, rear = -1 ;
void enqueue();
void dequeue();
void display();
void main(){
	int a;

	while(1){
		printf("operation done in the circular queue:\n1.enqueue\t2.dequeue\t3.display\t4.exit\n");
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
	int x;
	if(front == 0 && rear == max-1 || front == rear + 1){
		printf("overflow!!\n\n");
	}
	if(front = -1){
		front =0;
		rear =0;
	}
	else{
		if(rear=max-1){
			rear=0;
		}
		else{
			printf("\n\nenter the element enter in the queue: ");
			scanf("%d",&x);
			rear += 1;
			queue[rear]=x;
		}
	}
}