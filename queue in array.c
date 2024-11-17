#include<stdio.h>
#include<stdlib.h>
#define max 5

int enqueue();
int dequeue();
int display();
int queue[max];
int front = -1, rear = -1;

void main(){
	int a;

	while(1){
		printf("operation done in the queue:\n1.enqueue\t2.dequeue\t3.display\t4.exit\n");
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
int enqueue() {
	int e;
	printf("enter the element enter into the queue :\n");
	scanf("%d",&e);
	if (rear==max-1)
	printf("overflow!!\n");
	else{
		if(front == -1)
		front = 0;
		rear += 1;
		queue[rear]=e;
	}
	return 0;
}
int dequeue(){
	if(front== -1)
	printf("underflow!!\n");
	else{
		printf("deleted : %d\n\n", queue[front]);
		front += 1;
		if (front > rear)
		front = rear = -1;
	}
	return 0;	
}
int display(){
	if (front== -1)
	printf("underflow!!\n");
	else{
		printf("the element in queue:\t");
		for (int i=front;i<=rear;i++){
	
			printf("%d\t\",queue[i]);
		}
	}
	return 0;
}
	              