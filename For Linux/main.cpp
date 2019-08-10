#include "header.h"

using namespace std;

class run{					//class with the main screen with choices to choose from
private:
	int choice;
public:

run(){
	system("clear");
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
	system("clear");
		tranaction t;
}
else if(choice==2){
	system("clear");
		showall s;
}
else if(choice==3){
	system("clear");
		checking c;
}
else if(choice==4){
	system("clear");
		admin a;
}
else if(choice>=5||choice==0){
		system("clear");
		cout<<"\n\n\n\n\n"<<setw(85)<<DARK(FMAG("THANKS FOR VISITING"))<<"\n\n\n"<<endl;
		cin.get();
	    cout<<setw(89)<<DARK(FMAG(UNDL("A PROJECT BY")))<<endl;
	    cout<<"\n\n\n"<<setw(87)<<BOLD(FGRN(BLINK(UNDL("J1F17ASCS0025"))))<<setw(53)<<BOLD(FGRN(BLINK(UNDL("NABEEL YOUSAF"))))<<endl;
	    cout<<"\n"<<setw(79)<<FCYN(BLINK(UNDL("J1F17ASCS0012")))<<setw(45)<<FCYN(BLINK(UNDL("ZARYAB ARSHAD")))<<endl;
	    cout<<"\n\n\n"<<setw(62)<<UNDL("J1F17ASCS0023")<<setw(26)<<UNDL("UMAIR AHMED")<<endl;
	    cout<<"\n"<<setw(62)<<UNDL("J1F17ASCS0024")<<setw(29)<<UNDL("TAIMOOR ZAHEER")<<endl;
 		cout<<"\n\n\n"<<"Press Enter/Return Key to EXIT......";
 		cin.get();
	break;}
}}};



int main(){
	run r;						//calling run class constructor to start the process
	return 0;
}