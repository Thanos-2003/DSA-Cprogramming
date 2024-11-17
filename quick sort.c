#include<stdio.h>
void swap(int *a,int *b){
	int temp =*a;
	*a = *b;
	*b = *a;
}
int partition(int array[],int low,int high){
	int p= array[high];
	int i = low-1;
	for(int j = low; j<high;j++){
		if(array[j]<=p){
			i++;
			swap(&array[i],&array[j]);
		}
	}
	swap(&array[i+1],&array[high]);
	return (i+ 1);
}
void quicksort(int array[],int first, int last){
	if(first<last){
		int loc = partition(array,first,last);
		quicksort(array,first,loc-1);
		quicksort(array,loc+1,last);
	}
}
int main(){
	int i,a[100],size;
	scanf("%d",&size);
	printf("Enter the element:\n");
	for( i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,size-1);
	for(i=0;i<size;i++)
	 printf("%d",a[i]);
}