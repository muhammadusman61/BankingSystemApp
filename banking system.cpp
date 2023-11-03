#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
class Bank{
	private:
		int accounts,ok;
		struct persons{
		    string NAME;
			int ID, contect;
			int cash;
		}persons[500];
	public:
		Bank(){
			int accounts=0;
		}
		void options();
		void newaccount();
		void accountslist();
		void updateaccount();
		void accountdetail();
		void transaction();
		void delet();
};
void Bank::options(){
	char ch;
	while(1){
	cout<<endl<<"ENTER YOUR CHOICE"<<endl
	<<"Press the number accourding to your requirment."<<endl
	<<"1. Creat a new account"<<endl
	<<"2. Show the accounts list"<<endl
	<<"3. Update accounts information"<<endl
	<<"4. Check the detail of accounts"<<endl
	<<"5. Perform transactions"<<endl
	<<"6. Remove accounts"<<endl
	<<"7. Exit from function"<<endl;
	ch=getch();
	switch(ch){
		case'1':
			Bank::newaccount();
			break;
		case '2':
			Bank::accountslist();
			break;
		case '3':
			Bank::updateaccount();
			break;
		case '4':
			Bank::accountdetail();
			break;
		case '5':
			Bank::transaction();
			break;
		case '6':
			Bank::delet();
			break;
	 }
  }	
}
void Bank::newaccount(){
	cout<<endl<<"Enter the data of person  "<<accounts+1<<endl;
	cout<<"Enter his name"<<endl;
	cin>>persons[accounts].NAME;
	cout<<"Enter his id"<<endl;
	cin>>persons[accounts].ID;
	cout<<"Enter his contect number"<<endl;
	cin>>persons[accounts].contect;
	cout<<"Enter the cash"<<endl;
	cin>>persons[accounts].cash;
	cout<<"done"<<endl;
	accounts++;
}
void Bank::accountslist(){
	for(int x=0;x<accounts;x++){
		cout<<"Data of person"<<x+1<<endl;
		cout<<"Name: "<<persons[x].NAME<<endl;
		cout<<"ID: "<<persons[x].ID<<endl;
		cout<<"Contect: "<<persons[x].contect<<endl;
		cout<<"Cash: "<<persons[x].cash<<endl;
		
	if(x==accounts-1){
		cout<<"No such record found."<<endl;
	}
		break;
	}
}
void Bank::updateaccount(){
	cout<<"Enter the Id of account you want to update"<<endl;
	cin>>ok;
	for(int x=0;x<accounts;x++){
		if(ok==persons[x].ID){
			cout<<"Current data"<<endl;
		cout<<"Data of person"<<x+1<<endl;
		cout<<"Name: "<<persons[x].NAME<<endl;
		cout<<"ID: "<<persons[x].ID<<endl;
		cout<<"Contect: "<<persons[x].contect<<endl;
		cout<<"Cash: "<<persons[x].cash<<endl;
		    cout<<"Enter new data"<<endl;
	    cout<<"Enter his name"<<endl;
	    cin>>persons[x].NAME;
	    cout<<"Enter his id"<<endl;
	    cin>>persons[x].ID;
	    cout<<"Enter his contect number"<<endl;
	    cin>>persons[x].contect;
	    cout<<"Enter the cash"<<endl;
	    cin>>persons[x].cash;
		}
	}
}
void Bank::accountdetail(){
	cout<<"Enter the ID of account that you want to check"<<endl;
	cin>>ok;
	for(int x=0;x<accounts;x++){
		if(ok==persons[x].ID){
			cout<<"Here is your required data"<<endl;
		cout<<"Data of person"<<x+1<<endl;
		cout<<"Name: "<<persons[x].NAME<<endl;
		cout<<"ID: "<<persons[x].ID<<endl;
		cout<<"Contect: "<<persons[x].contect<<endl;
		cout<<"Cash: "<<persons[x].cash<<endl;
	}
  }
}
void Bank::transaction(){
	char ch;
	int ook;
	cout<<"Enter account ID for transaction"<<endl;
	cin>>ok;
	for(int x=0;x<accounts;x++){
		if(ok==persons[x].ID){
		cout<<"Data of person"<<x+1<<endl;
		cout<<"Name: "<<persons[x].NAME<<endl;
		cout<<"ID: "<<persons[x].ID<<endl;
		cout<<"Contect: "<<persons[x].contect<<endl;
		cout<<"Avalible Cash: "<<persons[x].cash<<endl;
		cout<<"Press 1 to deposite cash"<<endl;
		cout<<"Press 2 to withdraw cash"<<endl;
		ch=getch();
		switch(ch){
			case '1':
				cout<<"How much cash you want to deposite"<<endl;
				cin>>ook;
				persons[x].cash=+ook;
				cout<<"Your new cash is: "<<persons[x].cash<<endl;
				break;
			case '2':
				back:
				cout<<"How much cash you want to withdraw"<<endl;
				cin>>ook;
				if(ook<persons[x].cash){
					cout<<"You have only: "<<persons[x].cash<<endl;
					Sleep(4000);
					goto back;
				}
				persons[x].cash-=ook;
				cout<<"Your new cash is: "<<persons[x].cash<<endl;
				break;
			default:
				cout<<"Wrong input."<<endl;
				break;
		 }
		}
	if(x==accounts-1){
		cout<<"No such record found."<<endl;
		break;
	}
	}
}
void Bank::delet(){

	char ch;
	cout<<"Press 1 to specific account."<<endl;
	cout<<"Press 2 to all accounts."<<endl;
	ch=getch();
	switch(ch){
		case '1':
			cout<<"Enter ID of account you want to delete"<<endl;
			cin>>ok;
			for(int x=0;x<accounts;x++){
				if(ok==persons[x].ID){
					for(int y=x;y<accounts;y++){
						persons[y].NAME=persons[y+1].NAME;
						persons[y].ID=persons[y+1].ID;
						persons[y].contect=persons[y+1].contect;
						persons[y].cash=persons[y+1].cash;
						accounts--;
						cout<<"Your required data is deleted"<<endl;
					}
				}
			}
		    break;
		case '2':
			accounts=0;
			cout<<"All accounts are deleted."<<endl;
			break;
			
	}
}
int main(){
	Bank a;
	a.options();
	return 0;
}
