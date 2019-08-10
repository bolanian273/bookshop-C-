#ifndef showall_H
#define showall_H

class showall:public welcome{						//class to show all records of the book
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
system("clear");
file.close();
}
};

#endif 		//end showall
