#include<iostream>
using namespace std ;

#define MAX_ACC 100

class ACCOUNT{
	int acc_no ;
	float balance ;
public:
	int get_account_no(){
		return acc_no ;
	}
	float get_balance(){
		return balance;
	}
	void update_balance(float amount){
		balance -= amount ;
	}
	void get_data(){
		cout << "Enter Account Number: ";
		cin >> acc_no ;
		cout << "Enter balance: " ;
		cin >> balance ;
	}
};

class ACCOUNT_LIST{
	int unique_acc_no(ACCOUNT a){
		for (int i=0 ; i<count ; i++){
			if(arr[i].get_account_no() == a.get_account_no())
				return 0;
		}
		return 1;
	}

public:
	int count ;
	ACCOUNT arr[MAX_ACC] ;
	ACCOUNT_LIST(){
		count = 0;
	}
	void add_account(){
		ACCOUNT a ;
		a.get_data();
		if (!unique_acc_no(a)){
			cout << "Account Exists\n";
			return ;
		}
		arr[count] = a ;
		count++ ;
	}
	void find_account(){
		int acc_no ;
		cout << "Enter Account Number: ";
		cin >> acc_no ;
		for (int i=0 ; i<count ; i++){
			if (arr[i].get_account_no() == acc_no){
				cout << "Account Number: " << acc_no << "\n" ;
				cout << "Balance: " << arr[i].get_balance() << "\n" ;
				return ;
			}
		}
		cout << "Account not found !\n";
	}
	void display_all(){
		for (int i=0 ; i<count ; i++){
			cout << "Account Number: " << arr[i].get_account_no() << "\n" ;
			cout << "Balance: " << arr[i].get_balance() << "\n" ;
		}
	}
};

class WITHDRAW{
	int acc_no ;
	float amount ;

public:
	WITHDRAW(ACCOUNT_LIST &a){
		cout << "Enter Account Number: ";
		cin >> acc_no ;
		cout << "Enter withdraw amount: ";
		cin >> amount ;
		for (int i=0 ; i<a.count ; i++){
			if (a.arr[i].get_account_no()==acc_no){
				if (a.arr[i].get_balance() >= amount){
					a.arr[i].update_balance(amount) ;
				}
				else{
					cout << "Not enough balance\n";
				}
				break ;
			}
		}
	}
};

int main(){
	ACCOUNT_LIST l1 ;
	l1.add_account();
	l1.add_account();
	l1.find_account();
	l1.display_all();
	WITHDRAW w1(l1);
	l1.display_all();
	return 0;
}