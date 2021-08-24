#include<process.h>
#include<dos.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
class employee
{
int eid;
char nm[25];
char dept[25];
char ad[25];
int pn;
float sal;
public:
void out();
void mo();
void in();
int rid();
float rsa()
{return(sal);}
void rsi(float m)
{sal=m;
cout<<"\n BONUS GIVEN : "<<sal<<endl;
}
};
	class re//for request
	{
	int id;
	char r[200];
	public:
	void rr()
	{cout<<setw(30)<<"REQUEST LETTER"<<endl;
	cout<<"ENTER YOUR ID : ";
	cin>>id;
	cout<<"\n ENTER THE COMPLAINT :(without pressing enter ) ";
	gets(r);
	}
	void rs()
	{cout<<setw(30)<<"REQUEST LETTER"<<endl;
	cout<<"THE ID : "<<id;
	cout<<"\n THE COMPLAINT :(without pressing enter )\n ";
	puts(r);
	}
	};
void ad();
void del();
void mod();
void so();
void admin();
void menu();
void req();
void em();
void se();
int employee::rid()
{return(eid);
}
/*search funct*/
void se()
{int n;char ch;employee y;
cout<<setw(35)<<"SEARCH";
cout<<"\n ENTER THE EMPLOYEE ID TO BE SEARCHED :- ";
cin>>n;
ifstream fin("emp.dat",ios::in|ios::binary);
clrscr();
while(fin.read((char*)&y,sizeof(y)))
{fin.read((char*)&y,sizeof(y));
if(y.rid()==n)
{cout<<"\n \t\t SEARCHED RESULTS \n";
 y.out();cout<<endl;
 system("pause");}
};
fin.close();
}
/*request funct*/
void req()
{clrscr();
cout<<"\n\t\t ENTER REQUEST :- \n\n\n";
re r1;
ofstream fout("request.dat",ios::out|ios::binary|ios::app);
r1.rr();
fout.write((char*)&r1,sizeof(r1));
fout.close();
}
	void rsq()
	{
	re r1;  clrscr();
	cout<<"\n\t\t THE REQUESTS ARE :- \n\n\n";
	ifstream fin("request.dat",ios::in|ios::binary);
	while(fin.read((char*)&r1,sizeof(r1)))
	{
	fin.read((char*)&r1,sizeof(r1));
	r1.rs();
	cout<<setw(45);system("pause");
	cout<<endl;};
	}

/*for insertion */
void employee::in()
{
cout<<"\n ENTER THE ID :- ";cin>>eid;
cout<<"\n ENTER THE NAME :- ";gets(nm);
cout<<"\n ENTER THE DEPARTMENT :- ";gets(dept);
cout<<"\n ENTER THE ADDRESS OF THE EMPLOYEE :-";gets(ad);
cout<<"\n ENTER THE PHONE NUMBER OF THE EMPLOYEE :-";cin>>pn;
cout<<"\n ENTER THE SALARY :- ";cin>>sal;
}
void ad()
{employee e,y;
cout<<setw(35)<<"ADMISSION";
ifstream fin("emp.dat",ios::in|ios::binary);
ofstream fout("temp.dat",ios::out|ios::binary);
char last='y';
cout<<"\n ENTER THE INFORMATION OF NEW EMPLOYEE ";
e.in();
while(!fin.eof())
{fin.read((char*)&y,sizeof(y));
if(e.rid()<=y.rid())
{fout.write((char*)&e,sizeof(e));
last='n';
break;}
else
fout.write((char*)&y,sizeof(y));
}
if(last=='y')
fout.write((char*)&e,sizeof(e));
else if(fin)
{while(!fin.eof())
{fin.read((char*)&y,sizeof(y));
fout.write((char*)&y,sizeof(y));
}
}
fin.close();
fout.close();
remove("emp.dat");
rename("temp.dat","emp.dat");
}
/* delete */
void employee::out()
{
cout<<"\n  THE ID :- ";cout<<eid;
cout<<"\n  THE NAME :- ";puts(nm);
cout<<"\n  THE DEPARTMENT :- ";puts(dept);
cout<<"\n  THE ADDRESS OF THE EMPLOYEE :-";puts(ad);
cout<<"\n  THE PHONE NUMBER OF THE EMPLOYEE :-"<<pn;
cout<<"\n  THE SALARY :- "<<sal;
}

void del()
{int n;char ch,c='n';employee e,y;
cout<<setw(35)<<"DELETION";
cout<<"\n ENTER THE EMPLOYEE ID TO BE DELETED :- ";
cin>>n;
ifstream fin("emp.dat",ios::in|ios::binary);
ofstream fout("temp.dat",ios::out|ios::binary);
while(fin.read((char*)&y,sizeof(y)))
{
fin.read((char*)&y,sizeof(y));
if(y.rid()==n)
{c='y';
cout<<"\n WANTS TO DELETE ?(y/n) \n";
 y.out();
 cout<<endl<<"\t\t"<<"ENTER YES(Y) AND NO(N)_______";
 cin>>ch;
 clrscr();
 cout<<setw(35)<<"DELETION"<<endl;
 if(ch=='n')
fout.write((char*)&e,sizeof(e));
cout<<"\n SUCESSFULLY DELETED \n";
}
else
{fout.write((char*)&y,sizeof(y));
cout<<"\n NO RECORD DELETED \n";
}
};
fout.close();
fin.close();
remove("emp.dat");
rename("temp.dat","emp.dat");
if(c=='n'||c=='N')
cout<<"\n THE RECORD NOT FOUND \n ";
}
/*to modify */
void employee::mo()
{
cout<<"\n ENTER THE NAME :- ";gets(nm);
cout<<"\n ENTER THE DEPARTMENT :- ";gets(dept);
cout<<"\n ENTER THE ADDRESS OF THE EMPLOYEE :-";gets(ad);
cout<<"\n ENTER THE PHONE NUMBER OF THE EMPLOYEE :-";cin>>pn;
cout<<"\n ENTER THE SALARY :- ";cin>>sal;
}
void mod()
{int n,i;employee y;
fstream fio("emp.dat",ios::in|ios::out|ios::binary);
 cout<<setw(35)<<"MODIFY"<<endl;
 cout<<"ENTER THE EMPLOYEE ID TO BE UPDATED :- ";
 cin>>i;
 while(fio.read((char*)&y,sizeof(y)))
 {n=fio.tellg();
 fio.read((char*)&y,sizeof(y));
 if(y.rid()==i)
 {y.out();cout<<"\n WANTS TO MODIFY THIS RECORD :- \n";
 fio.seekg(n);
 y.mo();
 fio.write((char*)&y,sizeof(y));
 }
};
 fio.close();}
/*BONUS*/
void bonus()
{clrscr();
employee y;int i;double p,n;char x='n';
cout<<setw(35)<<"\n\n\t**BONUS**\n";
fstream fio("emp.dat",ios::in|ios::out|ios::binary);
cout<<"\n ENTER THE ID TO GIVE BONUS : ";
cin>>i;
cout<<"\n ENTER THE BONUS PERCENT : ";cin>>p;
while(fio.read((char*)&y,sizeof(y)))
{int a=fio.tellg();
fio.read((char*)&y,sizeof(y));
if(y.rid()==i)
{x='y';
cout<<"\nTHE SALARY WAS : "<<y.rsa()<<endl;
n=y.rsa()+y.rsa()*(p/100);
y.rsi(n);}
fio.seekg(a);
fio.write((char*)&y,sizeof(y));
;} fio.close();
if(x=='n')
cout<<"\n\t\t THE RECOEDDOES NOT EXISTS \n";
system("pause");
}
/*show all*/
void so()
{employee y;
ifstream fin("emp.dat",ios::in|ios::binary);
if(!fin)cout<<"\n THE FILE IS EMPTY :: \n";
fin.seekg(0);
while(fin.read((char*)&y,sizeof(y)))
{clrscr();
cout<<"\n\t\t\t EMPLOYEES ARE ---\n ";
fin.read((char*)&y,sizeof(y));
cout<<setw(35)<<"EMPLOYEE ID :: "<<y.rid();
y.out();cout<<endl<<endl;
system("pause");
};
fin.close();
}
char pas[20]="d",p[20];
void admin()
{int c;char ch='y';
clrscr();
while(ch=='y'||ch=='Y')
{
clrscr();
cout<<setw(25)<<"\n\n\t\t**WELCOME TO ADMINISTRATOR ACCOUNT**"<<endl;
cout<<"\n\t\t1. || ADD EMPLOYEE \n";
cout<<"\t\t2. || DELETE EMPLOYEE \n";
cout<<"\t\t3. || MODIFY EMPLOYEE \n";
cout<<"\t\t4. || SHOW ALL DETAILS \n";
cout<<"\t\t5. || SEARCH DETAILS \n";
cout<<"\t\t6. || VIEW REQUEST \n";
cout<<"\t\t7. || GIVE BONUS \n";
cout<<"\t\t8. || CHANGE PASSWORD \n";//only during the run
cout<<"\t\t9. || DELETE ALL RECORDS \n";
cout<<"\t\t10.|| RETURN TO MAIN MENU \n";
cout<<"\t\t11.|| EXIT \n";
cout<<"\n\t\t\t THE CHOICE IS : ";
cin>>c;
clrscr();
switch(c)
{case 8:cout<<"\n\t\t\t CHANGE PASSWORD \n\n";
cout<<"\n ENTER THE NEW PASSWORD :";gets(p);
strcpy(pas,p);cout<<"\nPASWORD HAS BEEN CHANGED \n";break;
case 1:	ad();
break;
case 2:del();
break;
case 3:mod();
break;
case 4:so();
break;
case 6:rsq();
break;
case 11:exit(0);break;
case 5:se();
break;
case 7:bonus();break;
case 9:char h='n';
cout<<"\n ARE YOU SURE TO DELETE THE FILE ?(y/n) ";cin>>h;
if(h=='y'||h=='Y')
{remove("emp.dat");cout<<"\n FILE REMOVED :\n";}
else cout<<"\n FILE SAVED !! ";
break;
case 10:menu();break;
default :cout<<"\n WRONG CHOICE WANTS TO TRY AGAIN ? (y/n) ";
	 cin>>ch;
}
cout<<"\n\t\t\tREDIRECTING TO MENU \n";
sleep(2);};
}
	void em()
	{int c;char ch='y';
	clrscr();
	while(ch=='y'||ch=='Y')
	{system("pause");
	clrscr();
	cout<<setw(25)<<"\n\n\t**WELCOME TO EMPLOYEE ACCOUNT**"<<endl;
	cout<<"\n\t\t1.SEARCH DETAILS \n";
	cout<<"\t\t2.ENTER REQUEST \n";
	cout<<"\t\t3.RETURN TO MAIN MENU \n";
	cout<<"\t\t4.EXIT \n";
	cout<<"\t\t\tTHE CHOICE IS : ";
	cin>>c;
	switch(c)
	{
	case 1:se();
	break;
	case 3:menu();break;
	case 2:req();
	break;
	case 4:exit(0);break;
	default :cout<<"\n WRONG CHOICE WANTS TO TRY AGAIN ? (y/n) ";
	 cin>>ch;
	}};
	}
		void fig()
			  {
			  cout<<"\n\n\t\t\t    ******   "<<endl;
			  cout<<"\t\t\t   | >  * |  "<<endl;
			  cout<<"\t\t\t   |  __  |  "<<endl;
			  cout<<"\t\t\t    ******   "<<endl;
			  cout<<"\t\t\t       *     "<<endl;
			  cout<<"\t\t\t     *****\n\n   "<<endl;
			  }
void menu()
{clrscr();
int ch;char pass[20];char c='y';
while(c=='y'||c=='Y')
{  clrscr();
cout<<"\n\n"<<setw(45)<<"**LOGIN**"<<endl;
cout<<"\n\t\t\t=========================";
cout<<"\n\t\t\t|| 1. || ADMINISTRATOR ||";
cout<<"\n\t\t\t|| 2. || EMPLOYEE      ||";
cout<<"\n\t\t\t|| 3. || TO EXIT       ||";
cout<<"\n\t\t\t=========================";
cout<<"\n\t\t\t\t THE CHOICE IS :: ";
cin>>ch;
clrscr();cout<<"\n\n"<<setw(35)<<"**LOGIN**"<<endl;
switch(ch)
{case 1:{fig();
cout<<setw(40)<<"**ADMINISTRATOR**\n"<<endl;
	cout<<setw(23)<<"PASSWORD :- ";
	gets(pass);
	if(strcmp(pass,pas)==0)
	{admin();
	}
	else
	cout<<"\n THE PASSWORD IS WRONG :";
	 }break;
case 2:{fig();
	cout<<setw(40)<<" **EMPLOYEE**\n\n";
	cout<<setw(40)<<"   WELCOME  \n\n";system("pause");
	em();}  break;
 case 3:exit(4);break;
 default:{cout<<"\n WRONG CHOICE ::";
	  cout<<"\n WANTS TO TRY AGAIN ?(y/n) ";
	 cin>>c;}
 }};}
	void intro()
{        cout<<"================================================================================";
	 cout<<"||"<<setw(44)<<"EMPLOYEE MANAGEMENT"<<setw(34)<<"||";
	 cout<<"================================================================================";
	 sleep(1);
	  cout<<"||"<<setw(78)<<"||";
	 sleep(1);
	 cout<<"||"<<setw(30)<<"         SCHOOL :: TEMPLETON ACADEMY INTERNATIONAL "<<setw(27)<<"||";
	 sleep(1);
	 cout<<"||"<<setw(78)<<"||";
	 sleep(1);
	 cout<<"||"<<setw(55)<<"MADE BY :: 1=>DEEPAK BAJETHA "<<setw(23)<<"||";
	 sleep(1);
	 cout<<"||"<<setw(55)<<"2=>JUNAID AJAZ "<<setw(23)<<"||";
	 sleep(1);
	 cout<<"||"<<setw(52)<<"               "<<setw(26)<<"||";
	 cout<<"================================================================================";}
void main()
 {clrscr();
  intro();
   sleep(2);
  menu();
 getch();}