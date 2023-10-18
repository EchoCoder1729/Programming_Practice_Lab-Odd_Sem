#include<stdlib.h>
#include<stdio.h>

//Implementing Q3 i) in Q4

static int rows ;
static int cols ;

void get_dim(){
	printf("Enter number of rows: ");
	scanf("%d",&rows);
	printf("Enter number of columns: ");
	scanf("%d",&cols);
}

int (*allocate())[]{
	int (*arr)[cols];
	arr = malloc(rows*sizeof(*arr));
	return arr;
}

void get_val(int (*arr)[cols]){
	printf("Enter the elements:\n");
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			scanf("%d",&arr[i][j]);
		}
	}
}

void print_val(int (*arr)[cols]){
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			printf("%d|",arr[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	get_dim();
	int (*a)[cols];
	a=allocate();
	get_val(a);
	print_val(a);
	return 0;
}