#include<iostream>
using namespace std ;

class STACK{
	int size ;
	int *arr ;
	int sp ;
	bool overflow(){
		return (sp >= size);
	}
	bool underflow(){
		return (sp < 0);
	}
	public :
	STACK(){
		cout << "Enter size of stack: ";
		cin >> size ;
		sp = -1 ;
		arr = new int[size];
	}
	~STACK(){
		delete[] arr;
	}
	void push(){
		int n ;
		cout << "Enter element to add: " ;
		cin >> n;
		sp++;
		if (overflow()){
			cout << "overflow\n" ;
			sp--;
		}
		else
			arr[sp] = n ;
	}
	void pop(){
		int n;
		if(underflow())
			cout << "underflow\n";
		else{
			cout << arr[sp] << "\n";
			sp--;
		}
	}
};

int main(void){
	STACK s1;
	s1.push();
	s1.pop();
	s1.pop();
	return 0;
}