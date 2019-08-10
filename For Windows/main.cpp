#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include "color.h"

using namespace std;

class welcome{								//class with universal components
public:
	char name[20];
	char author[20];
	int a;
	int b;
void show(){
 		cout<<"                                           ----------------------------------\n\n";	
 		cout<<setw(55)<<"                   Name    : "<<name<<endl;
 		cout<<"\n                                           ----------------------------------\n\n";
 		cout<<setw(55)<<"                   Author  : "<<author<<endl;
 		cout<<"\n                                           ----------------------------------\n\n";
 		cout<<setw(55)<<"                   Copies  : "<<a<<endl;
 		cout<<"\n                                           ----------------------------------\n\n";
 		cout<<setw(58)<<"                     Price   : Rs "<<b<<endl;
 		cout<<"\n                                           ----------------------------------\n\n";
}
void getdata(){
			cout<<"\n\n\n\t\t        ***ENTER DETAILS ABOUT BOOK***  ";
 			cout<<"\n\n\n\tEnter Name Of Book    : ";
 			cin>>name;
 			cout<<"\n\tEnter Name Of Author  : ";
 			cin>>author;
 			cout<<"\n\tEnter No. Of Copies   : ";
 			cin>>a;
 			cout<<"\n\tENTER The Price       : ";
 			cin>>b;
}};

class add:public welcome{						//class to add data to book file	
private:
	welcome w;
public:
	add(){ start:
		system("CLS");
		cout<<setw(78)<<"      Enter the New Record"<<endl;
        cout<<setw(79)<<"--------------------\n"<<endl;
        cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 		w.getdata();
		fstream file("book.bin",ios::in|ios::out|ios::ate|ios::app|ios::binary);
		file.write((char *)&w,sizeof(w));
		s:
		cout<<"\n\n\nDO you want to add another record? y/n  ";
		char ans;
 		cin>> ans;
 		switch (ans){
 			case 'y':{
 				system("CLS");
 				goto start;
 			}
 			case 'n':{	
 				system("CLS");
 				break;
			}
 			default:{
 				system("CLS");
 				cout<<"wrong input try again"<<endl;
 				goto s;
 			}
		}
		 file.close();
		}};

class modify:public welcome{						//class to modify a specific record in book file 
private:
	welcome w;
	char name[20],ans;
	int a = -1;
public:
	modify(){
		    system("CLS");
 			start:
 			cout<<setw(78)<<"      Enter book name whose record to be Modified"<<endl;
 			cout<<setw(81)<<" -------------------------------------------\n\n\n"<<endl;
 			cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 			cout<<setw(50)<< "Book Name: ";
 			cin>>name;
 			system("CLS");
 			fstream file("book.bin",ios::in|ios::out|ios::binary|ios::ate);
 			file.seekg(0);
 			int count = 0;
 			while(file.read((char*)&w,sizeof(w))){
 												if(strcmp(w.name,name)==0){
 																		w.show();
 																		cout<<"\n\t\t\t\t\t        ***New Record***  ";
 																		w.getdata();
 																		int pos = a * sizeof(w);
 																		file.seekp(pos,ios::cur);
 																		file.write((char*)&w,sizeof(w));
 																		count++;
 												}
			} file.close();
 			if(count==0){cout<<"\n\n\n No Record Found"<<endl;}
			s:
 			cout<<"\n\n\nDO you want to modify another record? y/n  ";
 			cin>> ans;
 			switch (ans){
 				case 'y':{
 					system("CLS");
 					goto start;
 				}
 				case 'n':{	
 					system("CLS");
 					break;
 				}
 				default:{
 					system("CLS");
 					cout<<"wrong input try again"<<endl;
 					goto s;}
			}
}};

class dell:public welcome{						//class to remove specific book record from book file
private:
	welcome w;
	ifstream infile;
	ofstream outfile;
	char name[20],ans;
public:
	dell(){
		system("CLS");
		start:
		int count =0;
		cout<<setw(78)<<"      Enter book name whose record to be Delete"<<endl;
        cout<<setw(81)<<"   -----------------------------------------\n\n\n"<<endl;
        cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
        cout<<setw(50)<< "Book Name: ";
		cin>>name;
		infile.open("book.bin",ios::binary);
		outfile.open("temp.bin",ios::out|ios::binary);
		while(infile.read((char*)&w,sizeof(w))){
											if(strcmp(w.name,name)!=0){
											outfile.write((char*)&w,sizeof(w));
											count++;
											}
		}
		infile.close();
		outfile.close();
        remove ("book.bin.");
        rename ("temp.bin","book.bin");
        if(count==0){cout<<"\n\n\n No Record Found"<<endl;}
		s: 		
		cout<<"\n\n\nDO you want to delete another record? y/n  ";
 		cin>> ans;
 		switch (ans){
 			case 'y':{
 				system("CLS");
 				goto start;
 			}
 			case 'n':{	
 				system("CLS");
 				break;
			}
 			default:{
 				system("CLS");
 				cout<<"wrong input try again"<<endl;
 				goto s;}
 		}
}};

class usrpass:public welcome{					//class to change username and password
private:
	welcome w;
	char user[20],pass[20];
public:
	usrpass(){
		    system("CLS");
 		    cout<<setw(78)<<"      Enter Old Username and Password"<<endl;
            cout<<setw(87)<<"-------------------------------\n\n\n\n\n\n\n\n\n"<<endl;
            cout<<setw(70)<<BOLD(FGRN("User Name : "));cin>>user;
   	        cout<<setw(70)<<BOLD(FGRN("Password  : "));cin>>pass;
		    ifstream file("pass.bin",ios::binary);
 		    file.seekg(0);
 	        int count = 0;
            while(file.read((char*)&w,sizeof(w))){
         										if(strcmp(w.name,user)==0){
         																if(strcmp(w.author,pass)==0){
 																		ofstream fi("pass.bin",ios::binary|ios::trunc);
 																		system("CLS");
 																		cout<<"\n\t\t\t\t\t        ***New Record***  \n\n\n\n";
 																		cout<<setw(40)<<BOLD(FYEL("User Name : "));cin>>w.name;
 																		cout<<setw(40)<<BOLD(FYEL("Password  : "));cin>>w.author;
 																		fi.write((char*)&w,sizeof(w));
 																		count++;
 																		fi.close();}
												}file.close();
												if(count==0){ 
															system("CLS");
															cin.get();
															cout<<"\n\n\n\n\n"<<setw(80)<<DARK(UNDL("Something Didn't Matched"))<<endl;
 															cout<<endl<<setw(79)<<DARK(UNDL("Better Luck Next Time"));
 															cout<<"\n\n\n\n\nPress Enter/Return Key to Continue";
 															cin.get();
 															system("CLS");
 															break;}
 												system("CLS");
 												cin.get();
 												cout<<"\n\n\n\t\t\t\t\t"<<DARK("Changed Successfully");
 												cout<<"\n\n\n\n\nPress Enter/Return Key to Continue";
 												cin.get();
 												system("CLS");
 			}
}};

class showall:public welcome{					//class to show all records of the book
private:
	welcome w;
public:
 	showall(){
			cout <<"Sr#" << setw(20) << "Name of the Book"<< setw(30) << "Author's Name"<< setw(26) << "COPIES"<< setw(16)<<"Price"<< endl;
			cout <<"--------------------------------------------------------------------------------------------------"<<endl;
			fstream file("book.bin",ios::in|ios::binary);
			int i =0;
			while(file.read((char *)&w,sizeof(w)) ){ ++i;
						cout <<"\n"<< i << setw(22) << w.name << setw(30) << w.author << setw(25) << w.a << setw(15) <<"Rs "<<w.b << endl;
			}
			cin.get();
			cout<<"\n\n\n\npress enter/return key to for main menu......";
			cin.get();
			system("CLS");
			file.close();
	}
};


class check:public welcome{					//class to check a specific book record
private:
	welcome w;
	welcome w1;
	char ans;
public:
	check(){
		start:
 		ifstream file("book.bin",ios::binary);
 		int count =0;
 		cout<<endl<<setw(78)<<"      Enter book name whose record to be searched"<<endl;
 		cout<<setw(81)<<" -------------------------------------------\n\n\n"<<endl;
 		cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 		cout<<setw(50)<< "Book Name: ";
 		cin>>w1.name;
 		system("CLS");
 		while(file.read((char *)&w,sizeof(w))){
 											if(strcmp(w.name,w1.name)==0){
 																	cout<<"\n\n";	
 																	w.show();
																	count++;
											}
		}file.close();
		if(count==0){cout<<"\n\n\n No Record Found"<<endl;} 
		s:
 		cout<<"\n\n\nDO you want to search again? y/n  ";
		cin>> ans;
 		switch (ans){
 			case 'y':{
 				system("CLS");
 				goto start;
 			}
 			case 'n':{
 				system("CLS");
 				break;
 			}
 			default:{
 				cout<<"wrong input try again"<<endl;
 				goto s;
 			}
 		}
}};

class controls{		//class to transfer control to certain part of program related to admin specfic tasks
private:
	int ans;
public:
	controls(){
			start:
			cout<<setw(80)<<BOLD(BLINK(FCYN("###########")))<<endl;
 			cout<<setw(80)<<BOLD(BLINK(FCYN("Admin Power")))<<endl;
 			cout<<setw(80)<<BOLD(BLINK(FCYN("###########")))<<"\n\n\n\n"<<endl;
			cout<<"1. Add a Book"<<endl;
			cout<<"2. Modify a record"<<endl;
			cout<<"3. Delete a record"<<endl;
			cout<<"4. Change Username & Password"<<endl;
			cout<<"5. Exit to Main Menu"<<endl;
			cout<<"\n\n Enter your choice : ";
			cin>>ans;
			switch(ans){
				case 1:{
					add aa;
					goto start;
				}
				case 2:{
					modify mm;
					goto start;
				}
				case 3:{
					dell dd;
					goto start;
				}
				case 4:{
					usrpass up;
					goto start;
				}
				case 5:{
					system("CLS");
					break;
				}
				default:{
					cout<<"wrong input try again\n\n\n"<<endl;
					goto start;
				}
			}
}};

class admin:public welcome{				//class to confirm identity before going to admin specific tasks console
private:
	 welcome w;
	 char user[20];
	 char pass[20];
	 int ch;
public:
	admin(){
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<setw(70)<<BOLD(FGRN("User Name : "));cin>>user;
		cout<<setw(70)<<BOLD(FGRN("Password  : "));cin>>pass;
		fstream fi("pass.bin",ios::in|ios::binary);
		while(fi.read((char *)&w,sizeof(w)) ){
			  					if(strcmp(w.name,user)==0){
			  							if(strcmp(w.author,pass)==0){
			  									system("CLS");
												controls cc;
										}
										else if(strcmp(w.author,pass)!=0){
												system("CLS");
												cout<<"\n\n\n\n\n\n"<<setw(85)<<DARK(FCYN("Incorrect Password"))<<"\n\n\n"<<endl;													cin.get();
												cout<<setw(106)<<UNDL(FCYN("If you forgot your credentials contact the developer please"))<<endl;
												cout<<"\n\n\n\n\n\nPress Enter/Return Key to Continue";
												cin.get();
												system("CLS");
										}
			
								}
								else if(strcmp(w.name,pass)!=0){
										system("CLS");
										cout<<"\n\n\n\n\n\n"<<setw(85)<<DARK(FCYN("Incorrect User Name"))<<"\n\n\n"<<endl;
										cin.get();
										cout<<setw(106)<<UNDL(FCYN("If you forgot your credentials contact the developer please"))<<endl;
										cout<<"\n\n\n\n\n\nPress Enter/Return Key to Continue";
										cin.get();
										system("CLS");
								}fi.close();
	    }
}};

class tranaction:public welcome{				//class that deals with generating bill when some book is bought
private:
	welcome w;
	welcome w1;
	char ans;
	int t=0,i=1;

public:
	tranaction(){
		start:
		fstream file("book.bin",ios::in|ios::binary);
		int count=0;
		cout<<endl<<setw(78)<<"      Enter book name to be Sold"<<endl;
 cout<<setw(81)<<"             --------------------------\n\n\n"<<endl;
 cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 cout<<setw(38)<< "Book Name : " ;
 cin>>w1.name;
 cout<<endl<<setw(38)<<"Copies    : ";
 cin>>w1.a;
 		while(file.read((char *)&w,sizeof(w))){
 if(strcmp(w.name,w1.name)==0){
 	if(w1.a<=w.a){
 system("CLS");
cout <<"Sr#"<< setw(20) << "Name of the Book"<< setw(30) << "Author's Name"<< setw(26) << "COPIES"<< setw(16)<<"Price"<< endl;
cout <<"-----------------------------------------------------------------------------------------------------"<<endl;
cout <<i<<setw(23) << w.name << setw(30) << w.author << setw(23) << w1.a << setw(15) <<"Rs "<<w.b << endl;
cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
cout<<"\n\n\n"<<setw(60)<<									"Grand Total = Rs "<<(w.b*w1.a)+t;
cout<<""<<endl;
t=(w.b*w1.a)+t;
count++;}
else{
	cout<<"\n\n\n"<<setw(38)<<BOLD(FYEL("Maximum of "<<w.a<<" Stock Available\n\n"));
	goto s;
}}}file.close();
if(count==0){
	cout<<"\n\n\n No Record Found"<<endl;
}i++;
 s:
 cout<<"\n\n\nDO you want to BUY again? y/n  ";

 cin>> ans;
 switch (ans)
 {
 	case 'y':
 	{
 		system("CLS");
 		goto start;
 	}
 	case 'n':
 	{
 		break;
 	}
 	default:{
 		cout<<"wrong input try again"<<endl;
 		goto s;
 	}}
 system("CLS");
}};


class run{							//class with the main screen with choices to choose from
private:
	int choice;
public:

run(){
	system("CLS");
	while (true){
 cout<<setw(76)<<"***************************"<<endl;		
 cout<<setw(75)<<"Welcome to the BookShop "<<endl;
 cout<<setw(76)<<"***************************"<<endl<<endl;	
 cout<<setw(50)<<BOLD(FMAG("#########"))<<endl;
 cout<<setw(50)<<BOLD(FMAG("Home Page"))<<endl;
 cout<<setw(50)<<BOLD(FMAG("#########"))<<"\n\n\n\n"<<endl;
 cout<<"\tWHAT DO U WANT TO DO ?\n";
 cout<<"\t----------------------\n"<<endl;
 cout<<"1 . TO BUY"<<endl;
 cout<<"2 . TO SHOW ALL BOOKS"<<endl;
 cout<<"3 . TO CHECK AVAILABILITY"<<endl;
 cout<<"4 . For Admin Only"<<endl;
 cout<<"5 . TO EXIT"<<endl;
 cout<<"Enter your choice : ";
 cin>>choice;
if (choice==1){
	system("CLS");
		tranaction t;
}
else if(choice==2){
	system("CLS");
		showall s;
}
else if(choice==3){
	system("CLS");
		check c;
}
else if(choice==4){
	system("CLS");
		admin a;
}
else if(choice>=5||choice==0){
	system("CLS");
		cout<<"\n\n\n\n\n"<<setw(85)<<DARK(FMAG("THANKS FOR VISITING"))<<"\n\n\n"<<endl;
		cin.get();
	    cout<<setw(89)<<DARK(FMAG(UNDL("A PROJECT BY")))<<endl;
	    cout<<"\n\n\n"<<setw(79)<<FGRN(BLINK(UNDL("J1F17ASCS0025")))<<setw(45)<<FGRN(BLINK(UNDL("NABEEL YOUSAF")))<<endl;
	    cout<<"\n"<<setw(79)<<FCYN(BLINK(UNDL("J1F17ASCS0012")))<<setw(45)<<FCYN(BLINK(UNDL("ZARYAB ARSHAD")))<<endl;
	    cout<<"\n\n\n"<<setw(62)<<UNDL("J1F17ASCS0023")<<setw(26)<<UNDL("UMAIR AHMED")<<endl;
	    cout<<"\n"<<setw(62)<<UNDL("J1F17ASCS0024")<<setw(29)<<UNDL("TAIMOOR ZAHEER")<<endl;
 		cout<<"\n\n\n"<<"Press Enter/Return Key to EXIT......";
 		cin.get();
	break;}
}}};



int main(){
	run r;									//calling run class constructor to start the process
	return 0;
}