#include<iostream>
using namespace std ;

void swap( int &a, int &b){
	int t = a ;
	a = b ;
	b = t ;
}

int main(void){
	int x = 3 , y = 4 ;
	cout << x << "|" << y << "\n" ;
	swap(x,y);
	cout << x << "|" << y << "\n" ;
	return 0;
}