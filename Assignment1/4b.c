#include<stdio.h>
#include<stdlib.h>

//This is doing Q4 in ref to Q3 ii)

static int rows;
static int cols;

void get_dim(){
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	printf("Enter number of columns: ");
	scanf("%d",&cols);
}

int **allocate(){
	int **arr=(int **)malloc(rows*sizeof(int *));
	for (int i=0 ; i<rows ; i++){
		arr[i] = (int *)malloc(cols*sizeof(int));
	}
	return arr;
}

void get_val(int **arr){
	printf("Enter the values: \n");
	for (int i=0 ; i<rows ; i++){
		for (int j=0 ; j<cols ; j++){
			scanf("%d",&arr[i][j]);
		}
	}
}

void print_val(int **arr){
	for (int i=0 ; i<rows ; i++){
		for (int j=0 ; j<cols ; j++){
			printf("%d|",arr[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int **a;
	get_dim();
	a=allocate();
	get_val(a);
	print_val(a);
	return 0;
}
