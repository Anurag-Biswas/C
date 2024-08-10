#include<stdio.h>
int main()
{
	int arr[10];
	printf("Enter the array elements :");
	for(int i=0; i<10; i++)
	{
		scanf("%d\n", &arr[i]);
	}
	for(int j=0; j<10; j++)
	{
		printf("The array elements are: %d\n",arr[j]);
	}
	return 0;
}
