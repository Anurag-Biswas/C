#include<stdio.h>
int main()
{
	int n,i,j,isPrime;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Prime numbers between %d to %d\n", 1,n);
	for(i=2;i<=n;i++)
	{
		isPrime=0;
	
	for(j=2;j<=i/2;j++)
	{
		if(i%j==0)
		{
			isPrime=1;
			break;
		}
	}
	if(isPrime==0 && n!=1)
		printf("%d\n", i);
	}
}

