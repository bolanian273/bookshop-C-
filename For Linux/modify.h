#ifndef modify_H
#define modify_H

class modify:public welcome{										//class to modify a specific record in book file 
private:
	 welcome w;
	 char name[20];
	 int a = -1;
public:
	modify(){
		system("clear");
 start:
 cout<<setw(78)<<"      Enter book name whose record to be Modified"<<endl;
 cout<<setw(81)<<" -------------------------------------------\n\n\n"<<endl;
 cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 cout<<setw(50)<< "Book Name: ";
 cin>>name;
 system("clear");
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
char ans;
 cin>> ans;
 switch (ans)
 {
 	case 'y':
 	{
 		system("clear");
 		goto start;
 	}
 	case 'n':
 	{	system("clear");
 		break;

 	}
 	default:{
 		system("clear");
 		cout<<"wrong input try again"<<endl;
 		goto s;
 	}}}};

#endif 		//end modify
