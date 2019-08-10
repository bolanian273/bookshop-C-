#ifndef dell_H
#define dell_H

class dell:public welcome{									//class to remove specific book record from book file
private:
	welcome w;
	ifstream infile;
	ofstream outfile;
	char name[20];
public:
	dell(){
		system("clear");
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
        if(count==0){
	cout<<"\n\n\n No Record Found"<<endl;
}
s: 		
cout<<"\n\n\nDO you want to delete another record? y/n  ";
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
 	}}
 
	
}};

#endif		//end dell
