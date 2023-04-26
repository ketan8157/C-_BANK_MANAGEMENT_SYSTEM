#include "iostream"
#include "cstdlib"
#include "time.h"
using namespace std;

int bankPage()
{     cout<<endl;
	cout<<"[##########################################################]"<<endl;
	cout<<endl;
	int x;
	cout<< "Select any Of Option :"<< endl;
	cout<< "1. Open a New Account "<<endl;
	cout<<"2. Show Account Details "<<endl;
	cout<<"3. Deposit/Credit the Amount in Account "<<endl;
	cout<<"4. Withdraw/Debit the Amount from the Account" <<endl;
	cout<<"5. To exit"<<endl;
	cout<<endl;
	cout<<"Selected Option :-  ";
	cin >> x;
	cout<<endl;
	cout<<"[##########################################################]"<<endl;
	return x;
	
}
class Bank
{
	private:
	 	unsigned short int pin;
	 	string name ,fname,number,ifsc;
	 	static double amount;
	 	signed int  long acc_number;
	 	signed int  long acc()
		 {
		 	signed int  long random=1;
		 	srand(time(0));
			do
			{
			random *= RAND_MAX;
			random +=rand();	
			}while(random < 1000000000);
			return random;
	 	
		 }
	 	
	 
	public:
		Bank()
		{
		//cout<<"constructor created"<<endl;	
		}
		 void Acc_create(string na,string fn,string n,unsigned short int p);
		void AccDetail(signed int  long accNumber,unsigned short int AccPIN);
		void Credit_amt(signed int  long accNumber,double amt);
		void Debit_amt(signed int  long accNumber,unsigned short int pin,double amt);
	 	
};
double Bank::amount=0.0;
void Bank::Acc_create(string na,string fn,string n,unsigned short int p)
{
		
	name=na;
	fname=fn;
	number=n;
	pin=p;
	acc_number=acc();
	ifsc="BMS-83CA1";
	cout<<"||-- Account Created Succesfully --||"<<endl;
	cout<<endl;
	cout<<"Your Account Number is :- "<<acc_number<<endl;
	
}
void Bank::AccDetail(signed int  long accNumber,unsigned short int AccPIN)
{
	if (accNumber==acc_number && AccPIN==pin)
	{
		cout<<endl;
		cout<<"-------------------------------------------" <<endl;
		cout<<"You Bank details are :- " <<endl;
		cout<<endl;
		cout<< "Name/son of :- "<<name<<"/"<<fname<<endl ;
		cout<< "Mobile Number :- " <<number<<endl;
		cout<< "Account Number:- "<<acc_number<<endl;
		cout<< "IFSC code :- "<<ifsc<<endl;
		cout<<"PIN :- "<<pin<<endl;
		cout<<"Account Balance :- || "<<amount <<" ||"<<endl;
		cout<<"-------------------------------------------" <<endl;
	}
	else if (accNumber!=acc_number || AccPIN!=pin)
	{

	 cout<<" _______________________________"<<endl;
	 cout<<"| Invalid Account Number & PIN  |"<<endl;
	 cout<<"|_______________________________|"<<endl;
	}
}

void Bank::Credit_amt(signed int  long accNumber,double amt)
{ if (acc_number==accNumber)
{
	amount=amount+amt;
	cout<<"NEW BALANCE IS :- "<<amount<<endl;
	
}
else
{
	cout<<"NOT A VALID USER.!!!!"<<endl;
}

	
}

void Bank::Debit_amt(signed int  long accNumber,unsigned short int pin,double amt)
{
	if (acc_number==accNumber && pin==pin)
	{
		if (amount>=amt)
		{
			amount=amount-amt;
			cout<<" A Amount of "<<amt <<" is Debit from your account"<<endl;
			cout<<endl;
			cout<<"Available Balance is :- "<<amount<<endl;
		}
		else cout<<"!!!--INSUFFICENT BALANCE--!!!"<<endl;
	}
	else cout<<"INCORRECT ACCOUNT NUMBER & PIN .!!!!"<<endl;
}
 
main()
{
	
	unsigned short int pin, x;
	string name,fname,number;
	double amt;
	signed int  long accNumber;
	Bank ketan;
	cout<<"---------------BANK MANAGEMENT SYSTEM-------------"<<endl;
	
	x=bankPage();
	while(x==1 || x==2 || x==3 || x==4)
	{
	if (x==1)
	{
		cin.ignore();
		cout<<"_______________________________"<<endl;
		cout<<"-----Account Creation Form-----"<<endl;
		cout<<"_______________________________"<<endl;
		cout<<"a. Enter your Name :- ";
		getline(cin , name);
		cout<<"b. Enter your Mobile Number  => ";
		cin>>number;
		cout<<"c. Enter your Father Name => ";
		cin.ignore();
		getline(cin,fname);
		cout<<"d. Create a 4 digit PIN Number => " ;
		cin>>pin;
		
		ketan.Acc_create(name,fname,number,pin);
		x=bankPage();
		
	}
	
	else if (x==2)
	{
		
		cout<<"_______________________________"<<endl;
		cout<<"----- Account Details -----"<<endl;
		cout<<"_______________________________"<<endl;
		cout<<endl;
		cout<<"a. Enter your Account Number  => ";
		cin>>accNumber;
		cout<<"b. Enter your Account PIN No.  => ";
		cin>>pin;
		cout<<endl;
		ketan.AccDetail(accNumber,pin);
		x=bankPage();
	}
	else if(x==3){
		cout<<"_______________________________"<<endl;
		cout<<"----- CREDIT/DEPOSIT Amount -----"<<endl;
		cout<<"_______________________________"<<endl;
		cout<<endl;
		cout<<"a. Enter your Account Number  => ";
		cin>>accNumber;
		cout<<"a. Enter the Amount you want to Credit/Deposit => ";
		cin>>amt;
		ketan.Credit_amt(accNumber,amt);
		x=bankPage();
	}
	
	else if(x==4){
		cout<<"_______________________________"<<endl;
		cout<<"----- DEBIT/WITHDRAW Amount -----"<<endl;
		cout<<"_______________________________"<<endl;
		cout<<endl;
		cout<<"a. Enter your Account Number  => ";
		cin>>accNumber;
		cout<<"a. Enter your Account PIN No.  => ";
		cin>>pin;
		cout<<"a. Enter the Amount you want to Debit/Withdraw => ";
		cin>>amt;
		ketan.Debit_amt(accNumber,pin,amt);
		x=bankPage();
	}
	
}
if (x==5)
{
	cout<<endl;
	cout<<" ________________________________________________________"<<endl;
	cout<<"|           THANKS FOR USING OUR BANK SERVICES           |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	
	return 0;
}
else 
{
	cout<< "\\\\\\\\\\\\\\\   SELECT A VALID OPTION  //////////////////"<<endl;
	x=bankPage();
	}	
}
