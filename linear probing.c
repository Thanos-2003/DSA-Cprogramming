#include<stdio.h>
#include<stdlib.h>
#define max 10
int h[max];
void insert(){
	int key,index,i,hkey;
	printf("Enter a value to insert into hash table:");
	scanf("%d",&key);
	hkey = key % max;
	for(i=0;i<max;i++){
		index= (hkey+i)%max;
		if(h[index]==NULL){
			h[index]=key;
			break;
		}
	}
	if(i == max)
	printf("element cannot be inserted");
}
void display(){
	int i;
	printf("\n element in the hash table are \n");
	for(i=0;i<max;i++){
		printf("\n at index %d \t value = %d",i,h[i]);
	}
}
int main(){
	int opt;
	while(1){
		printf("enter the option:\n1.insert\n2.display");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}