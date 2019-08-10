#ifndef checking_H
#define checking_H

class checking:public welcome{									//class to check a specific book record
private:
	welcome w;
	welcome w1;
	char ans;
public:
	checking(){
		start:
 ifstream file("book.bin",ios::binary);
 int count =0;
 cout<<endl<<setw(78)<<"      Enter book name whose record to be searched"<<endl;
 cout<<setw(81)<<" -------------------------------------------\n\n\n"<<endl;
 cout<<BOLD(DARK(BLINK(FRED(" **NOTICE: DON'T USE SPACES WHILE WRITING BOOK NAME** \n\n\n\n\n\n"))));
 cout<<setw(50)<< "Book Name: ";
 cin>>w1.name;
 system("clear");
 while(file.read((char *)&w,sizeof(w))){
 if(strcmp(w.name,w1.name)==0){
 cout<<"\n\n";	
 w.show();
count++;}}
file.close();
if(count==0){
	cout<<"\n\n\n No Record Found"<<endl;} 
s:
 cout<<"\n\n\nDO you want to search again? y/n  ";

 cin>> ans;
 switch (ans)
 {
 	case 'y':
 	{
 		system("clear");
 		goto start;
 	}
 	case 'n':
 	{
 		system("clear");
 		break;
 	}
 	default:{
 		cout<<"wrong input try again"<<endl;
 		goto s;
 	}
 }

}};

#endif