#include<stdio.h>
#include<stdlib.h>
static int rows;
static int cols;

//Implementing 2d array using pointer to an array

int (*f1())[]{
	int (*arr)[cols];
	arr = malloc(rows*sizeof(*arr));
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	return arr;
}

//Implementing 2d array using array of pointers
//Can I deal with *arr[rows] in my function
//Do I need to put "rows" within the [] ?
//Another implementation of array of pointers could be using a 2d array of pointers.

int **f2(){
	int **arr = malloc(rows*sizeof(int *));
	for( int i=0; i<rows ; i++){
		arr[i]=malloc(cols*sizeof(int));
	}
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	return arr;
}

int main(void){
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	printf("Enter number of columns: ");
	scanf("%d",&cols);
	int **a;
	a=f2();
	int (*b)[cols];
	b=f1();
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}