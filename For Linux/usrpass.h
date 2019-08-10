#ifndef usrpass_H
#define usrpass_H

class usrpass:public welcome{									//class to change username and password
private:
	welcome w;
	char user[20],*pass;
public:
	usrpass(){
		    system("clear");
 		    cout<<setw(78)<<"      Enter Old Username and Password"<<endl;
            cout<<setw(87)<<"-------------------------------\n\n\n\n\n\n\n\n\n"<<endl;
            cout<<setw(70)<<BOLD(FGRN("User Name : "));cin>>user;
   	        pass = getpass(BOLD(FGRN("\n\n\t\t\t\t\t Password  : ")));
		    ifstream file("pass.bin",ios::binary);
 		    file.seekg(0);
 	        int count = 0;
            while(file.read((char*)&w,sizeof(w))){
         										if(strcmp(w.name,user)==0){
         										if(strcmp(w.author,pass)==0){
 												ofstream fi("pass.bin",ios::binary|ios::trunc);
 												system("clear");
 												cout<<"\n\t\t\t\t\t        ***New Record***  \n\n\n\n";
 												cout<<setw(40)<<BOLD(FYEL("User Name : "));cin>>w.name;
 												cout<<setw(40)<<BOLD(FYEL("Password  : "));cin>>w.author;
 												fi.write((char*)&w,sizeof(w));
 												count++;
 												fi.close();}
												}file.close();
												if(count==0){ system("clear");
												cin.get();
												cout<<"\n\n\n\n\n"<<setw(80)<<DARK(UNDL("Something Didn't Matched"))<<endl;
 												cout<<endl<<setw(79)<<DARK(UNDL("Better Luck Next Time"));
 												cout<<"\n\n\n\n\nPress Enter/Return Key to Continue";
 												cin.get();
 												system("clear"); 
 												break;}
 												system("clear");
 												cin.get();
 												cout<<"\n\n\n\t\t\t\t\t"<<DARK("Changed Successfully");
 												cout<<"\n\n\n\n\nPress Enter/Return Key to Continue";
 												cin.get();	
 												system("clear");
 }}};

#endif		//end usrpass
