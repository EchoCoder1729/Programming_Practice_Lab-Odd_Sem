#include<stdio.h>
#include<stdlib.h>
static int n ;
//how is int a[n] legal ?!
//Here length of the string is NOT dynamically allocated, but there is scope for that too.
struct student{
	char name[31] ;
	int age ;
};
//I am returning a pointer instead of accepting one as parameter, such is the norm of C.
struct student *allocate(){
	//int n; //Local n
	printf("Enter number of names: ");
	scanf("%d",&n) ;
	struct student *arr = malloc(n*sizeof(struct student)) ;
	for(int i=0 ; i<n ; i++){
		printf("Enter name %d\n",i+1);
		scanf("%s",arr[i].name) ;
		getchar();
		printf("Enter age %d\n",i+1);
		scanf("%d",&arr[i].age);
	}
	return arr ;
}
void display(struct student *arr){
	for ( int i=0 ; i<n ; i++ ){
		printf("Name: %s ",arr[i].name);
		printf("Age: %d", arr[i].age);
		printf("\n");
	}
}
//There is a potential to use pointer to a function for generic sorting
//Bubble sort is used and new array is used to store the sorted array, which could have been avoided if some pointer could be passed as parameter, not yet grasping that concept.
struct student *sort(struct student *arr){
	struct student t ;
	for(int i=0 ; i<n-1 ; i++ ){
		for(int j=0 ; j<n-i-1 ; j++){
			if(arr[j].age>arr[j+1].age){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
	struct student *new = malloc(n*sizeof(struct student)) ;
	new = arr ;
	return new;
}
int main(void){
	struct student *s;
	s=allocate();
//	display(s);
	s=sort(s);
	display(s);
	return 0;
}