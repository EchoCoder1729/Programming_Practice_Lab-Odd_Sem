#include<stdio.h>
#include<stdlib.h>

struct student{
	int roll ;
	char name[31];
	int score[5];
};

FILE *fp, *fp_tmp;

void addRecord(){
	struct student st;
	fp = fopen("students.dat","r+");
	if (fp==NULL) fp = fopen("students.dat","w");
	printf("Input the roll number: ") ;
	scanf("%d",&st.roll);
//	Unique roll number check
	struct student stu ;
	fseek(fp,0,SEEK_SET);
	while (fread(&stu, sizeof(struct student),1,fp)){
		if(stu.roll == st.roll){
			printf("Roll Number already exists. Choose a different roll number.\n");
			return ;
		}
	}
	printf("Input the name: ");
	scanf("%s",st.name);
	printf("Input the scores: ");
	for (int i=0 ; i<5 ; i++){
		scanf("%d",&st.score[i]);
	}

	fseek(fp, 0, SEEK_END);
	fwrite(&st,sizeof(struct student),1,fp);
	fclose(fp);
	printf("Record added successfully.\n");
}

void displayRecord(){
	struct student st;
	fp = fopen("students.dat","r");
	fseek(fp, 0,SEEK_SET);
	while(fread(&st, sizeof(struct student),1,fp)){
		int total = 0;
		for (int i=0; i<5; i++){
			total += st.score[i];
		}
		printf("Roll %d, Name %s, Total %d\n",st.roll,st.name,total);
	}
	fclose(fp);
}

void searchRecord(){
	fp = fopen("students.dat","r");
	int roll ;
	printf("Enter Roll Number: ");
	scanf("%d",&roll);
	struct student st;
	fseek(fp, 0,SEEK_SET);
	while(fread(&st, sizeof(struct student),1,fp)){
		if(st.roll == roll){
			int total = 0;
			for (int i=0; i<5; i++){
				total += st.score[i];
			}
			printf("Roll %d, Name %s, Total %d\n",st.roll,st.name,total);
		}
	}
	fclose(fp);
}

void editRecord(){
	fp = fopen("students.dat","r+");
	int roll , pos=0 ,flag = 0;
	printf("Enter Roll Number: ");
	scanf("%d",&roll);
	struct student st;
	struct student stu;
	fseek(fp, 0,SEEK_SET);
	while(fread(&st, sizeof(struct student),1,fp)){
		if(st.roll == roll ){
			flag = 1;
			printf("Roll %d, Name %s\n",st.roll,st.name);
			stu.roll = roll ;
			printf("Enter new Name");
			scanf("%s",stu.name);
			printf("Enter new makrs: ");
			for(int j=0 ; j<5 ; j++){
				scanf("%d",&stu.score[j]);
			}
			fseek(fp,pos,0);
			fwrite(&stu,sizeof(struct student),1,fp);
			break;
		}
		pos = ftell(fp);
	}
	if (flag) printf("Record updated Successfully\n");
	else printf("Record not found\n");
	fclose(fp);
}

void deleteRecord(){
	fp = fopen("students.dat","r");
	fp_tmp = fopen("tmp.dat","w");
	int r ,flag = 0 ;
	struct student st;
	printf("enter roll to be deleted: ");
	scanf("%d",&r);
	while(fread(&st,sizeof(struct student),1,fp)){
		if (st.roll != r){
			fwrite(&st,sizeof(struct student),1,fp_tmp);
		}
		else flag = 1;
	}
	if (!flag) printf("Record not found\n");
	else printf("Record deleted\n");
	fclose(fp_tmp);
	fclose(fp);
	system("copy tmp.dat students.dat");
	system("del tmp.dat");
}

int main(void){

	int choice;
	do{
		printf("1. Add Record\n");
		printf("2. Display Record\n");
		printf("3. Search Record\n");
		printf("4. Edit Record\n");
		printf("5. Delete Record\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);

		switch(choice){
		case 1:
			addRecord(); break;
		case 2:
			displayRecord(); break;
		case 3:
			searchRecord(); break;
		case 4:
			editRecord(); break;
		case 5:
			deleteRecord(); break;
		}
	}while(choice != 6);
	return 0;
}