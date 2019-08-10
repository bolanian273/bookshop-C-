#ifndef check_H
#define check_H

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
				system("clear");
				break;
			}
			default:{
				cout<<"wrong input try again\n\n\n"<<endl;
				goto start;
			}
		}
	}

	};

#endif 		//end check
