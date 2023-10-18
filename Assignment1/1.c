#include<stdio.h>
int main(void)
{
	int a ;
	int *p = &a ;
	int **pp = &p ;
	printf("Enter value of the integer \n");
	scanf("%d",p) ;
	printf("%d , %d\n", *p , **pp) ;
}