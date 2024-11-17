#include<stdio.h>
int stack[50], top= -1;
void push(int x){
	stack[++top]= x;
}
int pop(){
	return stack[top--];
}
void main() {
	char exp[50];
	char *e;
	int n1,n2,n3,num;
	printf("Enter postfix expression :\n ");
	scanf("%s",exp);
	e = exp;
	while (*e != '\0'){
		if (isdigit(*e)){
			num = *e - 48;
			push(num);
		}
		else{
			
			n1 = pop();
			n2 = pop();
			switch(*e){
				case '+':{
					n3 = n1 + n2 ;
					break;
				}
				case '-':{
					n3 = n1 - n2;
					break;
				}
				case '*':{
					n3 = n2*n1;
					break;
				}
				case '/':{
					n3 = n1/n2;
					break;
				} 
			}
			push(n3);
		}
		e++;
	}
	printf("%d",pop());
}
