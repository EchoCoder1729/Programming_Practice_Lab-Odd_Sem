#include<stdio.h>
#include<stdlib.h>

//static int n ;
int get_dim(){
	int n;
	printf("Enter the size of 1D array: ");
	scanf("%d",&n);
	return n;
}

int *allocate(int n){
	int *arr=(int *)malloc(n*sizeof(int));
	return arr ;
}

void values(int *arr,int n){
	printf("Enter the values: \n");
	for (int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}
}

void print_val(int *arr,int n){
	for (int i=0 ; i<n ; i++){
		printf("%d|",arr[i]);
	}
}

int main(void){
	int n;
	int *a;
	n=get_dim();
	a=allocate(n);
	values(a,n);
	print_val(a,n);
	return 0;
}