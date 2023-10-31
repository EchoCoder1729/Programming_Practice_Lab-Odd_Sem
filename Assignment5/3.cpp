#include<iostream>
#include <cstdlib>

using namespace std ;

class employee{
protected:
	int emp_id ;
	char name[31];
	char designation[15];
	float basic_pay;
public:
	employee(){
		cout << "Enter emp details\n";
		cin >> emp_id ;
		cin >> name ;
		cin >> designation ;
		cin >> basic_pay;
	}
	virtual void get_salary() = 0;
};

class permanent : public employee{
	float n = basic_pay ;
	float salary = n + 0.3*n + 0.8*n ;
public:
	void get_salary(){
		cout << salary << endl;
	}
};

class contractual : public employee{
	float allowance ;
	float salary = basic_pay + allowance ;	
public:
	contractual(){
		cout << "Enter allowance: ";
		cin >> allowance ;
		salary = basic_pay + allowance ;
	}
	void get_salary(){
		cout << salary << endl ;
	}
};

int main(){
	employee *ptr ;
	permanent p ;
	contractual c ;
	ptr = &p ;
	ptr -> get_salary();
	ptr = &c ;
	ptr -> get_salary();
	return 0;
}