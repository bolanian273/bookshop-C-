#ifndef welcome_H
#define welcome_H

class welcome{												//class with universal components
public:
char name[20];
char author[20];
int a;
int b;
void show(){
 cout<<"                                           ----------------------------------\n\n";	
 cout<<setw(55)<<"                   Name    : "<<name<<endl;
 cout<<"\n                                           ----------------------------------\n\n";
 cout<<setw(55)<<"                   Author  : "<<author<<endl;
 cout<<"\n                                           ----------------------------------\n\n";
 cout<<setw(55)<<"                   Copies  : "<<a<<endl;
 cout<<"\n                                           ----------------------------------\n\n";
 cout<<setw(58)<<"                     Price   : Rs "<<b<<endl;
 cout<<"\n                                           ----------------------------------\n\n";
}
void getdata(){
cout<<"\n\n\n\t\t        ***ENTER DETAILS ABOUT BOOK***  ";
 cout<<"\n\n\n\tEnter Name Of Book    : ";
 cin>>name;
 cout<<"\n\tEnter Name Of Author  : ";
 cin>>author;
 cout<<"\n\tEnter No. Of Copies   : ";
 cin>>a;
 cout<<"\n\tENTER The Price       : ";
 cin>>b;
}};
#endif 		//welcome
