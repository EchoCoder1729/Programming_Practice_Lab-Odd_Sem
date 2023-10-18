#include<stdio.h>
#include<stdlib.h>

static int n ;

struct student{
	int roll;
	char name[31];
	float score;
};

struct student *list;

void allocate(){
	list=(struct student *)malloc(n*sizeof(struct student));
}

void input(){
	for(int i=0 ; i<n ; i++){
		printf("Enter roll: ");
		scanf("%d",&list[i].roll);
		printf("Enter name:\n");
		scanf("%s",list[i].name);
		printf("Enter score: ");
		scanf("%f",&list[i].score);
	}
}

void sort(int (*fp)(int a,int b)){
	struct student temp;
	for(int i=0 ; i<n-1 ; i++){
		for(int j=0; j<n-i-1 ; j++){
			if(fp(list[j].score,list[j+1].score)){
				temp = list[j+1];
				list[j+1]=list[j];
				list[j]=temp;
			}
		}
	}
}

int compare_asc(int a, int b){
	if (a>b) return 1;
	else return 0;
}

int compare_desc(int a,int b){
	if (a<b) return 1;
	else return 0;
}

void display(){
	for(int i=0 ; i<n ; i++){
		printf("Roll: %d|",list[i].roll);
		printf("Name: %s|",list[i].name);
		printf("Score: %f|",list[i].score);
		printf("\n");
	}
}

int main(void){
	printf("Enter number of students: ");
	scanf("%d",&n);
	allocate();
	input();
//	display();
	sort(compare_desc);
	display();
	return 0;
}