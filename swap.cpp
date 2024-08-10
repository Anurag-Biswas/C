#include<stdio.h>
void swap(int ,int);
void swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("Value of a and b = %d %d \n",a,b);
}
int main()
{
	int a,b,c;
	printf("Enter two numbers \n");
	printf("Before swapping = %d %d\n",a,b);
	swap(a,b);
	printf("After swapping = %d %d",a,b);
	return 0;
}
