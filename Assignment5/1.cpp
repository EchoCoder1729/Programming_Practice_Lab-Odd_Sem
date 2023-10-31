#include<iostream>
#include <cstdlib>

using namespace std ;
#define MAX_STUDENTS 50
#define MAX_SUBJECTS 50
#define MAX_SELECTION 100

//Create an overflow management system as well

class student{
	int roll ;
	char name[31];
public:
//Unique roll check not given
	// student(){
	// 	cin >> roll ;
	// 	cin >> name ;
	// }
	int get_roll(){
		return roll ;
	}
	char* get_name(){
		return name;
	}
	void set_student(){
		cin >> roll ;
		cin >> name ;
	}
};

class stlist{
	int count = 0 ;
	student student_list[MAX_STUDENTS];
public:
	void add_student(){
		student s ;
		s.set_student();
		student_list[count++]= s ;
	}
	student find_student(int roll){
		int flag = 1 ;
		for (int i=0 ; i < count; i++){
			if (student_list[i].get_roll() == roll){
				flag = 0 ;
				return student_list[i] ;
			}
		}
		if (flag){
			cout << "Not Found\n";
			// exit(0);
		}
	}
};

class subject{
	int scode ;
	char sname[31];
public:
//Unique scode check not given
	// subject(){
	// 	cin >> scode ;
	// 	cin >> sname ;
	// }
	void set_subject(){
		cin >> scode ;
		cin >> sname ;
	}
	int get_code(){
		return scode;
	}
	char* get_sname(){
		return sname;
	}
};

class sublist{
	int count = 0 ;
	subject subject_list[MAX_SUBJECTS];
public:
	void add_subject(){
		subject sub ;
		sub.set_subject();
		subject_list[count++]=sub;
	}
	subject find_subject(int scode){
		int flag = 1 ;
		for (int i=0 ; i < count; i++){
			if (subject_list[i].get_code() == scode){
				flag = 0 ;
				return subject_list[i] ;
			}
		}
		if (flag){
			cout << "Not Found\n";
			// exit(0);
		}
	}
};

class selection{
public:
	int roll;
	int scode;
	// selection(){
	// 	cin >> roll ;
	// 	cin >> scode ;
	// }	
	void set_selection(){
		cin >> roll ;
		cin >> scode ;
	}
};

class selection_list{
	int count = 0 ;
	selection selection_list[MAX_SELECTION];
public:
	void add_selection(){
		selection s ;
		s.set_selection();
		selection_list[count++] = s ;
	}
	void find_subjects_by_roll(int roll,stlist l1, sublist l2){
		student st = l1.find_student(roll);
		cout << st.get_name() << endl ;
		for (int i=0 ; i<count ; i++){
			if (selection_list[i].roll == roll){
				subject sub = l2.find_subject(selection_list[i].scode);
				cout << sub.get_sname() << endl ;
			}
		}
	}

	void find_students_by_scode(int scode, stlist l1, sublist l2){
		subject sub = l2.find_subject(scode);
		cout << sub.get_sname() << endl ;
		for (int i=0 ; i<count ; i++){
			if (selection_list[i].scode == scode){
				student st = l1.find_student(selection_list[i].roll);
				cout << st.get_name() << endl ;
			}
		}
	}
};

class student_subject{
public:
	static void menu(){
		stlist l1 ;
		sublist l2 ;
		selection_list l3 ;
		int ch ;
		do{
			cout << "Enter choice\n";
			cout << "1. Add Student\n";
			cout << "2. Add Subject\n";
			cout << "3. Make a selection\n";
			cout << "4. Find students by subject\n";
			cout << "5. Find subject by students\n";
			cout << "6. Exit\n";
			cout << "Enter choice: ";
			cin >> ch ;
			switch(ch){
				case 1:
					l1.add_student(); break;
				case 2:
					l2.add_subject(); break;
				case 3:
					l3.add_selection(); break;
				case 4:
					cout << "Enter subject code: ";
					int scode ;
					cin >> scode ;
					l3.find_students_by_scode(scode,l1,l2); break;
				case 5:
					cout << "Enter roll: ";
					int roll;
					cin >> roll ;
					l3.find_subjects_by_roll(roll,l1,l2); break;
				case 6:
					break;
			}
		}while(ch != 6);
	}
};

int main(){
	student_subject::menu();
	return 0;
}