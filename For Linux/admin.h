#ifndef admin_H
#define admin_H

class admin:public welcome{			//class to confirm identity before going to admin specific tasks console
private:
	 welcome w;
	 char user[20];
	 char *pass;
	 
	 int ch;
public:
	admin(){
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<setw(70)<<BOLD(FGRN("User Name : "));cin>>user;
		pass = getpass(BOLD(FGRN("\n\n\t\t\t\t\t Password  : ")));
		fstream fi("pass.bin",ios::in|ios::binary);
		while(fi.read((char *)&w,sizeof(w)) ){
			  	if(strcmp(w.name,user)==0){
			  		if(strcmp(w.author,pass)==0){
			  		system("clear");
					controls cc;
			}
			else if(strcmp(w.author,pass)!=0){
				system("clear");
				cout<<"\n\n\n\n\n\n"<<setw(85)<<DARK(FCYN("Incorrect Password"))<<"\n\n\n"<<endl;
				cin.get();
				cout<<setw(106)<<UNDL(FCYN("If you forgot your credentials contact the developer please"))<<endl;
				cout<<"\n\n\n\n\n\nPress Enter/Return Key to Continue";
				cin.get();
				system("clear");
			}
			
			}
			else if(strcmp(w.name,user)!=0){
				system("clear");
				cout<<"\n\n\n\n\n\n"<<setw(85)<<DARK(FCYN("Incorrect User Name"))<<"\n\n\n"<<endl;
				cin.get();
				cout<<setw(106)<<UNDL(FCYN("If you forgot your credentials contact the developer please"))<<endl;
				cout<<"\n\n\n\n\n\nPress Enter/Return Key to Continue";
				cin.get();
				system("clear");
		}
	    fi.close();}}
		
		
	};
#endif 			// end admin
