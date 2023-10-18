#include<iostream>
using namespace std ;

class APPLICANT{
	static int last_id ;
	int app_id ;
	char name[31];
	int score ;
	public :
	APPLICANT(){
		app_id = last_id + 1 ;
		last_id++ ;
	}
	void get_data(){
		cout << "Enter name: " ;
		cin >> name ;
		cout << "Enter score: " ;
		cin >> score ;
	}
	void show_data(){
		cout << "Name: " << name << "\n" ;
		cout << "Score: " << score << "\n" ;
	}
	static void number_of_applicants(){
		cout << "Number of Applicants: " << last_id <<"\n" ;
	}
};

int APPLICANT::last_id = 0 ;

int main(void){
	APPLICANT a1,a2;
	a1.get_data();
	a1.show_data();
	APPLICANT::number_of_applicants();
	return 0;
}