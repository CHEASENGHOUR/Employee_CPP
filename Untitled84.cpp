#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;
class Employee{
	private:
		int id;
		float salary;
		char name[20],gender[20],position[20];
	public:
		Employee(){
			id = 0;
			strcpy(name, "Null");
			strcpy(gender, "Null");
			strcpy(position, "Null");
			salary = 0;
		}
		void Input(){
			cout<<"\t\tEnter ID : ";cin>>id;
			cout<<"\t\tEnter Name : ";cin.ignore();
			cin.getline(name,20);
			cout<<"\t\tEnter Gender : ";
			cin.getline(gender,20);
			cout<<"\t\tEnter Position : ";
			cin.getline(position,20);
			cout<<"\t\tEnter Salary :  ";
			cin>>salary;
		}
		void Output(){
			cout<<setw(13)<<id
				<<setw(15)<<name
				<<setw(16)<<gender
				<<setw(20)<<position
				<<setw(15)<<salary<<"$"
				<<endl;
		}
		char *getName(){
			return name;
		}
		int getId(){
			return id;
		}
		float getSalary(){
			return salary;
		}
};
void Head(){
	cout<<endl<<endl
		<<setw(13)<<"ID"
		<<setw(15)<<"Name"
		<<setw(16)<<"Gender"
		<<setw(20)<<"Position"
		<<setw(16)<<"Salary"
		<<endl;
}
void Button(){
	cout<<"\n\n\t\t----------------------------------------------------------"<<endl;
	cout<<"\t\t|           [ Enter ]                   [ Escape ]       |"<<endl; 
	cout<<"\t\t----------------------------------------------------------"<<endl;
}
int main(){
	Employee emp[50];
	int i,j,n,op;
	do{
		system("cls");
		cout<<"\t\t------------------------- Menu ---------------------------"<<endl;
		cout<<"\t\t|                    [1]. INPUT                          |"<<endl;
		cout<<"\t\t|                    [2]. OUTPUT                         |"<<endl;
		cout<<"\t\t|                    [3]. SEARCH                         |"<<endl;
		cout<<"\t\t|                    [4]. UPDATE                         |"<<endl;
		cout<<"\t\t|                    [5]. INSERT                         |"<<endl;
		cout<<"\t\t|                    [6]. DELETE                         |"<<endl;
		cout<<"\t\t|                    [7]. ADD                            |"<<endl;
		cout<<"\t\t|                    [8]. SORT                           |"<<endl;
		cout<<"\t\t----------------------------------------------------------"<<endl;
		cout<<"\n\n              	  Choose Your Option : ";cin>>op;
		switch(op){
			case 1:{
				system("cls");
				cout<<"\n\n\n\t\tHow many Employee you wanna put? : ";
				cin>>n;
				for(i = 0 ; i < n ; i++){
					cout<<"\t\t----------| "<<i+1<<" Employee |----------"<<endl;
					emp[i].Input();
				}
				Button();
			}break;
			case 2:{
				system("cls");
				Head();
				for(i = 0 ; i < n ; i++){
					emp[i].Output();
				}
				Button();
			}break;
			case 3:{
				system("cls");
				int Search;
				cout<<endl<<endl<<"\t\tEnter ID to Search : ";
				cin>>Search;
				bool k = false;
				Head();
				for(i = 0 ; i < n ; i++){
					if(Search == emp[i].getId()){
						emp[i].Output();
						k = true;
					}
				}
				if(k == false) cout<<"\n\t\t\t\t\t Search Not Found !!!"<<endl;
				else cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
			case 4:{
				system("cls");
				char Up[20];
				cout<<endl<<endl<<"\t\tEnter Name to Update : ";
				cin.ignore();
				cin.getline(Up,20);
				bool k = false;
				for(i = 0 ; i < n ; i++){
					if(strcmp(Up,emp[i].getName())==0){
						cout<<"\t\t----------| "<<i+1<<" Employee |----------"<<endl;
						emp[i].Input();
						k = true;
					}
				}
				if(k == false) cout<<"\n\t\t\t\t\t Search Not Found !!!"<<endl;
				else cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
			case 5:{
				system("cls");
				int In;
				cout<<endl<<endl<<"\t\tEnter Id for Search : ";
				cin>>In;
				bool k = false;
				for(i = 0 ; i < n ; i++){
					if(In == emp[i].getId()){
						for(j = n ; j >= i ; j--){
							emp[j] = emp[j - 1];
						}
						n++;
						k = true;
						cout<<"\t\t----------| Employee |----------"<<endl;
						emp[i].Input();
						break;
					}
				}
				if(k == false) cout<<"\n\t\t\t\t\t Search Not Found !!!"<<endl;
				else cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
			case 6:{
				system("cls");
				Head();
				for(i = 0 ; i < n ; i++){
					emp[i].Output();
				}
				char Del[20];
				cout<<endl<<endl<<"\t\tEnter Name Employee to Delete : ";
				cin.ignore();cin.getline(Del, 20);
				bool k = false;
				for(i = 0 ; i < n ; i++){
					if(strcmp(Del, emp[i].getName())==0){
						for(j = i ; j < n ; j++){
							emp[j] = emp[j + 1];
						}
						n--;
						k = true;
					}
				}
				if(k == false) cout<<"\n\t\t\t\t\t Search Not Found !!!"<<endl;
				else cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
			case 7:{
				system("cls");
				int add;
				cout<<endl<<endl<<"\t\tAdd More Employee : ";
				cin>>add;
				for(i = n ; i < n + add ; i++){
					cout<<"\t\t----------| "<<i+1<<" Employee |----------"<<endl;
					emp[i].Input();
				}
				n += add;
				cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
			case 8:{
				system("cls");
				for(i = 0 ; i < n ; i++){
					for(j = i + 1 ; j < n ; j++){
						if(emp[i].getSalary() < emp[j].getSalary()){
							Employee temp = emp[i];
							emp[i] = emp[j];
							emp[j] = temp;
						}
					}
				}
				cout<<"\n\t\t\t\t\t Success !!!"<<endl;
				Button();
			}break;
		}
	}while(getch() != 27);
}
