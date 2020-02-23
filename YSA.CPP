#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

int a;

class yamuna
{
	int  age;
	char name[20],address[50];
	public:
	void aboutus();
	void sports();
	void facilities();
	void contactus();
	void membership();
};

class member
{
	char address[50],name[20],mem;
	int id,age;
	public:
	void getdata();
	void putdata();
	int getid();
};

void member::getdata()
{
	cout<<"ID (any 3 digit no.): ";
	cin>>id;
	cout<<"\nName: ";
	gets(name);
	cout<<"\nAge: ";
	cin>>age;
	cout<<"\nAddress: ";
	gets(address);
	switch(::a)
	{
		case 1:
			mem='m';
			break;
		case 2:
			mem='y';
			break;
		case 3:
			mem='l';
	}
}

void member::putdata()
{
	cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<address<<"\t\t\t"<<mem<<endl;
}

int member::getid()
{
	return(id);
}

member m;

void write_file()
{
	ofstream fout("member.dat",ios::app|ios::binary);
	m.getdata();
	fout.write((char*)&m,sizeof(m));
	fout.close();
}

void read_file()
{
	cout<<"\n\nID\tName\tAge\tAddress\t\tType\n";
	ifstream fin("member.dat",ios::binary);
	while(fin.read((char*)&m,sizeof(m)))
	{
		m.putdata();
	}
	fin.close();
}

void search()
{
	int p=-1;
	int n;
	ifstream fin("member.dat",ios::binary);
	cout<<"\nID: ";
	cin>>n;
	while(fin.read((char*)&m,sizeof(m)))
	{
		if(m.getid()==n)
		{
			cout<<"\n\nID\tName\tAge\tAddress\n";
			m.putdata();
			p++;
		}
	}
	if(p==-1)
	{
		cout<<"\n--Record Not Found--";
	}
	fin.close();
}

void modify()
{
	int p=-1,t=0;
	int n;
	cout<<"\nID: ";
	cin>>n;
	fstream fio("member.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&m,sizeof(m)))
	{
		t++;
		if(m.getid()==n)
		{
			m.getdata();
			fio.seekp((t-1)*sizeof(m),ios::beg);
			fio.write((char*)&m,sizeof(m));
			p++;
		}
	}
	if(p==-1)
	{
		cout<<"\n--Record Not Found--";
	}
	else
		cout<<"\nSuccess";
	fio.close();
}

void Delete()
{
	
	int p=-1;
	int n;
	ifstream fin("member.dat",ios::binary);
	ofstream fout("temp.dat",ios::binary);
	cout<<"\nID: ";
	cin>>n;
	while(fin.read((char*)&m,sizeof(m)))
	{
		if(m.getid()!=n)
		{
			fout.write((char*)&m,sizeof(m));
			p++;
		}
	}
	remove("member.dat");
	rename("temp.dat","member.dat");
	if(p==-1)
	{
		cout<<"\n--Record Not Found--";
	}
	else
		cout<<"\nSuccess";
	fin.close();
	fout.close();
}

void exit_mod()
{
	clrscr();
	cout<<"\t\tMade BY\n\n";
	cout<<"##      ##        ###         ####      # # # #   ##      ##  ######  ########\n";
	for(long int i=0;i<2000000;i++){}
	cout<<"##      ##       ## ##        ##  ##   #          ##      ##    ##       ##\n";
	for(i=0;i<2000000;i++){}
	cout<<"##      ##      ##   ##       ##   ##  #          ##      ##    ##       ##\n";
	for(i=0;i<2000000;i++){}
	cout<<"##########     ##     ##      ##  ##     # # #    ##########    ##       ##\n";
	for(i=0;i<2000000;i++){}
	cout<<"##      ##    ###########     ####             #  ##      ##    ##       ##\n";
	for(i=0;i<2000000;i++){}
	cout<<"##      ##   ##         ##    ##  #            #  ##      ##    ##       ##\n";
	for(i=0;i<2000000;i++){}
	cout<<"##      ##  ##           ##   ##    #   # # # #   ##      ##  ######     ##";
	cout<<"\n\n\n\t\tPress any Key to exit...";
	getch();
	exit(0);
}

void yamuna::aboutus()
{
	clrscr();

	char line[80];
	ifstream fin("YSA/about.txt");
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line<<'\n';
	}
	
	fin.close();
}

void p1()
{
	char line[80];
	ifstream fin("YSA/price1.txt");
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line;
	}
	fin.close();
}

void p2()
{
	char line[80];
	ifstream fin("YSA/price2.txt");
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line;
	}
	fin.close();
}

void file(char f[15])
{
	char fname[20]="YSA/";
	char line[80];
	strcat (fname,f);
	ifstream fin(fname);
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line<<'\n';
	}
	
	fin.close();
	cout<<"\n";
}

void yamuna::sports()
{
	
	int a;
	char e,b,c,d;

	sportmenu:
	clrscr();
	cout<<"\n\t******************************************\n"
	<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
	<<"\t------------------------------------------\n"
	<<"\n\t\t       ** SPORTS **\n\n"
	<<"\t1)CRICKET\n"
	<<"\t2)FOOTBALL\n"
	<<"\t3)BASKETBALL\n"
	<<"\t4)LAWN TENNIS\n"
	<<"\t5)SWIMMING\n"
	<<"\t6)ATHELETICS\n"
	<<"\t0)BACK\n\n"
	<<"\tEnter Your Choice: ";
	cin>>a;
	switch(int(a))
	{
		case 0:
			break;
		case 1:
			cricket:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\tC  R  I  C  K  E  T\n\n"
			<<"\tThe cricket academy also known a Gambhir's Academy has the privi-\n"
			<<"\tlage of hosting the Ranji Trophy in its YSA Stadium and is famous-\n"
			<<"\tfor producing legends like Sehwag, Ashish Nehra, Virat Kohli and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20): ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto cricket;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Ycricket:
				clrscr();
				cout<<"\t\t\t   C  R  I  C  K  E  T\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\tEnter Time shift(m-morning;e-evening): ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to re-enter";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Ycricket;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_crc.txt");
				cout<<"\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Cricket Kit"
				<<"\n\t\t2)Jersey"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;
			
			break;
		case 2:
			football:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\t   F  O  O  T  B  A  L  L\n\n"
			<<"\tThe football academy also known a Messi's Academy has the privi-\n"
			<<"\tlage of hosting the Asia Cup in  its  YSA Stadium and is famous-\n"
			<<"\tfor producing legends like Sunil Chhetri, Ronaldo,Ibrahimovic and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20) ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"
				<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto football;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Yfootball:
				clrscr();
				cout<<"\t\t\tF  O  O  O  T  B  A  L  L\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to re-enter";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Yfootball;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_fbl.txt");
				cout<<"\n\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Studs"
				<<"\n\t\t2)Jersey"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;
			
			break;
		case 3:
			basketball:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\tB  A  S  K  E  T  B  A  L  L\n\n"
			<<"\tThe basketball academy also known a Jordans Academy has the privi-\n"
			<<"\tlage of hosting the ABSI Cup in  its  YSA Stadium and is famous-\n"
			<<"\tfor producing legends like Kobe Bryant,Mahesh Bhatt,Fabregas and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20) ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"
				<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto basketball;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Ybasketball:
				clrscr();
				cout<<"\t\t\tB  A  S  K  E  T  B  A  L  L\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to re-enter";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Ybasketball;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_bbl.txt");
				cout<<"\n\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Basket Ball"
				<<"\n\t\t2)Jersey"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;

			break;
		case 4:
			lawntennis:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\tL  A  W  N  T  E  N  N  I  S\n\n"
			<<"\tThe Tennis  academy also known a Sania's Academy has the privi-\n"
			<<"\tlage of hosting the Delhi Cup in  its YSA Stadium and is famous-\n"
			<<"\tfor producing legends like Sania Mirza,Mahesh Bhupathi, Paes and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20) ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"
				<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto lawntennis;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Ylawntennis:
				clrscr();
				cout<<"\t\t\tL  A  W  N  T  E  N  N  I  S\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to re-enter";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Ylawntennis;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_tns.txt");
				cout<<"\n\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Racket"
				<<"\n\t\t2)Tennis balls"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;

			break;
		case 5:
			swimming:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\tS  W  I  M  M  I  N  G\n\n"
			<<"\tThe swimming academy also known a Daksh's Academy has the privi-\n"
			<<"\tlage of hosting the Delhi Trophy in its YSA Pools and is famous-\n"
			<<"\tfor producing legends like Tushar Makhija,Saurabh Jain,Apoorv and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20) ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"
				<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto swimming;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Yswimming:
				clrscr();
				cout<<"\t\t\tS  W  I  M  M  I  N  G\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to re-enter";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Yswimming;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_swm.txt");
				cout<<"\n\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Swimming Costume"
				<<"\n\t\t2)Gears"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;
		
			break;
		case 6:
			atheletics:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------\n"
			<<"\n\t\t       ** SPORTS **\n\n"
			<<"\t\t\tA  T  H  E  L  E  T  I  C  S\n\n"
			<<"\tThe atheletics academy also known a Bagla's Academy has the privi-\n"
			<<"\tlage of hosting the SRK  Trophy in its YSAm Tracks and is famous-\n"
			<<"\tfor producing legends like Shashank Sharma,Vidit Shah,Osama B and\n"
			<<"\tmany more.\n\n\n"
			<<"\tEnter your age(b/w 5-20) ";
			cin>>age;
			if(age>=5 && age<=12){
			cout<<"\tYour fees would be :- ";
			p1();
			cout<<"/- per month";}
			else if(age>12 && age<=20){
			cout<<"\tYour fees would be :- ";
			p2();
			cout<<"/- per month";}
			else
			{
				cout<<"\tYou have entered a wrong age\n"
				<<"\tPress y to re-enter your age ";
				cin>>b;
				if(b=='y'||b=='Y')
					goto atheletics;
				else
					goto sportmenu;
			}
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>c;
			if(c=='y')
			{
				Yatheletics:
				clrscr();
				cout<<"\t\t\tA  T  H  E  L  E  T  I  C  S\n\n"
				<<"\tEnter Your Name: ";
				cin>>name;
				cout<<"\n\n\tEnter Your Address: ";
				gets(address);
				cout<<"\n\n\tEnter Time shift(m-morning;e-evening) ";
				cin>>d;
				if(age>=5 && age<=12 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>=5 && age<=12 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time1.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else if(age>12 && age<=20 && d=='m')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("md.txt");
				}
				else if(age>12 && age<=20 && d=='e')
				{
					cout<<"\n\n\tYour timings are:- ";
					file("time2.txt");
					cout<<"\tYour days are:- ";
					file("ed.txt");
				}
				else
				{
					cout<<"\n\n\tYou have entered a wrong choice";
					cout<<"\n\n\tPress y to continue";
					cin>>e;
					if(e=='y'||e=='Y')
						goto Yatheletics;
					else
						goto sportmenu;
				}
				cout<<"\n\n\tFACULTY:\n";
				file("f_ath.txt");
				cout<<"\n\n\t EQUIPMENTS REQUIRED"
				<<"\n\t\t1)Shorts"
				<<"\n\t\t2)Sport shoes"
				<<"\n\n\n\n\t\t\tTHANK FOR JOINING OUR ACADEMY !!!"	
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto sportmenu;
				
			break;
		default:
			cout<<"\nWrong choice Entered";
	}
}

void yamuna::facilities()
{
	clrscr();

	char line[80];
	ifstream fin("YSA/facil.txt");
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line<<'\n';
	}
	
	fin.close();
}

void yamuna::contactus()
{
	clrscr();

	char line[80];
	ifstream fin("YSA/conus.txt");
	while(!fin.eof())
	{
		fin.getline(line,80);
		cout<<line<<'\n';
	}
	
	fin.close();
}

void yamuna::membership()
{
	void write_file();
	void read_file();
	void search();
	void modify();
	void Delete();
	int c;
	char b,d;
	Ymembership:
	clrscr();
	cout<<"\n\t******************************************\n"
	<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
	<<"\t------------------------------------------"
	<<"\n\t\t       ** MEMBERSHIP **\n\n"
	<<"\t1)MONTHLY MEMBERSHIP\n"
	<<"\t2)YEARLY MEMBERSHIP\n"
	<<"\t3)LIFETIME MEMBERSHIP\n"
	<<"\t4)FOR ADMINISTRATOR ONLY\n"
	<<"\t0)BACK\n\n"
	<<"\tEnter Your Choice: ";
	cin>>a;
	switch(int(a))
	{
		case 0:
			break;
		case 1:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------"
			<<"\n\t\t       ** MEMBERSHIP **\n\n"
			<<"\t\t\tM  O  N  T  H  L  Y\n\n"
			<<"\tMonthly membership is very usefull.\n"
			<<"\tIf you will take monthly membership then you can leave\n"
			<<"\tit any time if u want to. In this u will get some facilities\n"
			<<"\tlike you can do swimming any time free of cost.\n"
			<<"\tthe fees for monthly member ship is Rs.2500\month.\n";

			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>b;
			if(b=='y')
			{
				clrscr();
				cout<<"\n\t******************************************\n"
				<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
				<<"\t------------------------------------------"
				<<"\n\t\t       ** MEMBERSHIP **\n\n"
				<<"\t\t\t M  O  N  T  H  L  Y\n\n";
				write_file();
				cout<<"\n\n\t\t\tTHANKS FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto Ymembership;

			break;
		case 2:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------"
			<<"\n\t\t       ** MEMBERSHIP **\n\n"
			<<"\t\t\tY  E  A  R  L  Y\n\n"
			<<"\tYearly member ship is again a beneficial membersip.\n"
			<<"\tin this u pay every year no problem of month charges.\n"
			<<"\tIn this also you can do swimming any time & have 520hrs extra.\n"
			<<"\tFees for yearly membership is Rs.11000\annum only.\n";
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>b;
			if(b=='y')
			{
				clrscr();
				cout <<"\n\t******************************************\n"
				<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
				<<"\t------------------------------------------"
				<<"\n\t\t       ** MEMBERSHIP **\n\n"
				<<"\t\t\tY  E  A  R  L  Y\n\n";
				write_file();
				cout<<"\n\n\t\t\tTHANKS FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto Ymembership;
			
			break;
		case 3:
			clrscr();
			cout <<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------"
			<<"\n\t\t       ** MEMBERSHIP **\n\n"
			<<"\t\t\tL  I  F  E  T  I  M  E\n\n"
			<<"\tLifetime member ship is very beneficial.Moneywise and facilities as well\n"
			<<"\tIf u are interested in life time membership then carry ur id proof.\n"
			<<"\tFees for lifetime membership is for just Rs.60,000 once \n";
			cout<<"\n\n\n\tWould you like to join the academy?(press y-yes or n-no) ";
			cin>>b;
			if(b=='y')
			{
				clrscr();
				cout<<"\n\t******************************************\n"
				<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
				<<"\t------------------------------------------"
				<<"\n\t\t       ** MEMBERSHIP **\n\n"
				<<"\t\t\tL  I  F  E  T  I  M  E\n\n";
				write_file();
				cout<<"\n\n\t\t\tTHANKS FOR JOINING OUR ACADEMY !!!"
				<<"\n\n\tPress any key to continue";
				getch();
			}
			else
				goto Ymembership;
		
			break;
		case 4:
			clrscr();
			cout<<"\n\t******************************************\n"
			<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
			<<"\t------------------------------------------"
			<<"\n\t\tFOR ADMINISTRATOR ONLY\n";
			cout<<"\n\n\t1.Add Members"
			<<"\n\t2.Read Members"
			<<"\n\t3.Search Members"
			<<"\n\t4.Modify Members"
			<<"\n\t5.Delete Members"
			<<"\n\t0.Back\n"
			<<"\n\tEnter your selection: ";
			cin>>c;
			switch(int(c))
			{
				case 0:
					break;
				case 1:
					cout<<"Enter membership type(1 monthly,2 yearly,3 lifetime): ";
					cin>>a;
					write_file();
					break;
				case 2:
					read_file();
					break;
				case 3:
					search();
					break;
				case 4:
					modify();
					break;
				case 5:
					Delete();
					break;
				default:
					cout<<"n\Wrong choice Entered";
			}
			cout<<"\nPress any key to continue...";
			getch();
			break;
	}
}

void check(char f[15])
{
	char fname[20]="YSA/";
	strcat (fname,f);
	ifstream fin(fname);
	if(!fin)
	{
		cout<<"\n\tMissing File "<<fname<<" ...";
	}
	fin.close();
}

void main()
{
	mainmenu:
	
	int h;
	char ans='y';
	
	do
	{
		yamuna y;
		
		clrscr();
		cout<<"\n\t******************************************\n"
		<<"\tY A M U N A  S P O R T S  A C A D E M Y     \n"
		<<"\t------------------------------------------\n";
		check("about.txt");
		check("conus.txt");
		check("ed.txt");
		check("f_ath.txt");
		check("f_bbl.txt");
		check("f_crc.txt");
		check("f_fbl.txt");
		check("f_swm.txt");
		check("f_tns.txt");
		check("facil.txt");
		check("md.txt");
		check("price1.txt");
		check("price2.txt");
		check("time1.txt");
		check("time2.txt");
		
		cout<<"\n\n\tWELCOME TO YAMUNA SPORTS ACADEMY ! ! !\n\n"
		<<"\t1) ABOUT US\n"
		<<"\t2) SPORTS\n"
		<<"\t3) FACILITIES\n"
		<<"\t4) MEMBERSHIP\n"
		<<"\t5) CONTACT US\n"
		<<"\t0) EXIT\n\n"
		<<"\tENTER YOUR CHOICE: ";
		cin>>h;
		switch(int(h))
		{
			case 0:
				exit_mod();
			case 1:
				y.aboutus();
				break;
			case 2:
				y.sports();
				goto mainmenu;
				break;
			case 3:
				y.facilities();
				break;
			case 4:
				y.membership();
				goto mainmenu;
				break;
			case 5:
				y.contactus();
				break;
			default:
				cout<<"\nWrong choice entered";
				goto mainmenu;
		}
		cout<<"\nWant to continue?(y/n): ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	exit_mod();
}