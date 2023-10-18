#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int *arr;
	int n;
	printf("Enter size of array : ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements\n");
	for(int i=0; i<n; i++){
		int p;
		scanf("%d",&p);
		arr[i]=p;
	}
	for(int j=0; j<n; j++){
		printf("%d ",*(arr+j));
	}
	printf("\n");
	return 0;
}