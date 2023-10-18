#include<stdio.h>
#include<stdlib.h>
struct student{
	int roll;
	char name[31];
	int score;
};
struct node{
	struct student s ;
	struct node *next;
};
void add(struct node **head){
	struct node *s_new;
	s_new=(struct node *)malloc(sizeof(struct node));
	printf("Enter roll: ");
	scanf("%d",&s_new->s.roll);
	printf("Enter name: ");
	getchar();
	fgets(s_new->s.name,31,stdin);
	printf("Enter score: ");
	scanf("%d",&s_new->s.score);
	if(*head==NULL) *head = s_new ;
	else{
		struct node *h = *head ;
		while(h->next!=NULL) h=h->next;
		h->next = s_new ;
	}
}
void display(struct node *head){
	while(head!=NULL){
		printf("Roll %d\n",head->s.roll);
		printf("Name %s",head->s.name);
		printf("Score %d\n",head->s.score);
		head = head->next ;
	}
}
void delete(struct node **head){
	int roll;
	printf("Enter roll number to delete: ");
	scanf("%d",&roll);
	struct node *prev=*head, *cur=*head;
	if (*head==NULL){
		printf("No List\n");
	}
	else{
		if((*head)->s.roll == roll){
			*head = (*head)->next;
			free(cur);
		}
		else{
			cur = (*head)->next;
			while(cur!=NULL){
				if (cur->s.roll == roll){
					prev->next = cur->next;
					free(cur);
					break;
				}
				else{
					prev=cur;
					cur = cur->next;
				}
			}
			if (cur==NULL) printf("Not Found\n");
		}
	}
}
int main(void){
	struct node *head = NULL ;
	add(&head);
	display(head);
	delete(&head);
	display(head);
	return 0;
}