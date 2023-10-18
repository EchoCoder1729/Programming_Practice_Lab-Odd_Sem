#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int n;
char **arr;
int *age;

void allocate(){
	arr = (char **)malloc(n*sizeof(char *));
	for(int i=0 ; i<n ; i++){
		*(arr+i) = (char *)malloc(31*sizeof(char));
	}
	age = (int *)malloc(n*sizeof(int));
}

void input(){
	for(int i=0 ; i<n ; i++){
		printf("Enter name and age of %d\n",i+1);
		scanf("%s",arr[i]);
		scanf("%d",&age[i]);
	}
}

void sort(){
	char temp[31];
	int t;
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0 ; j<n-i-1 ; j++){
			if(age[j]>age[j+1]){
				t=age[j+1];
				age[j+1]=age[j];
				age[j]=t;
				strcpy(temp,arr[j+1]);
				strcpy(arr[j+1],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}
}

void display(){
	for(int j=0; j<n ; j++){
		printf("Name %s|",arr[j]);
		printf("Age %d",age[j]);
		printf("\n");
	}
}

int main(void){
	printf("Enter the number of names: ");
	scanf("%d",&n);
	allocate();
	input();
//	display();
	sort();
	display();
	return 0;
}