#ifndef add_H
#define add_H

class add:public welcome{												//class to add data to book file						
private:
	welcome w;
public:
	add(){ start:
		system("clear");
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
 	}

 }
		 file.close();
		}};

#endif //end add
