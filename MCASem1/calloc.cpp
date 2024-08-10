#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int *arr = (int*)calloc(n,sizeof(int));
	if(arr==NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("You entered %d elements:\n",n);
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	free(arr);
	return 0;
}
