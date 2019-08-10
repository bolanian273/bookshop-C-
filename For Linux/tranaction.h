#ifndef tranaction_H
#define tranaction_H

class tranaction:public welcome{		//class that deals with generating bill when some book is bought
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
 system("clear");
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
}
}}file.close();
if(count==0){
	cout<<"\n\n\n No Record Found"<<endl;
	goto s;
}
 i++;
 s:
 cout<<"\n\n\nDO you want to BUY again? y/n  ";

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
 		break;
 	}
 	default:{
 		cout<<"wrong input try again"<<endl;
 		goto s;
 	}}
 system("clear");
}};

#endif //tranaction