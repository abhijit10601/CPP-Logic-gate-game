      #include<iostream>
       #include<conio.h>
       #include<process.h>
       #include<stdio.h>
       #include<string.h>
       #include<fstream>
      using namespace std;


       void create();
       void check(char uid[]);
       int display(char uid[]);
       int clear(char uid[]);
       void ttnot(char uid[]);
       void ttand(char uid[]);
       void ttor(char uid[]);
       void ttnand(char uid[]);
       void ttnor(char uid[]);
       class Game
       { private:
	 int n1,n2;
	 int and1,and2,and3,and4;
	 int or1,or2,or3,or4;
	 int nand1,nand2,nand3,nand4;
	 int nor1,nor2,nor3,nor4;
	 public:
	 void enternot()
	 { int sc=0;
	   cout<<" Enter values(0/1) \n";
	   cout<<" a:-";cin>>n1;
	   if(n1==1)
	   sc++;
	   cout<<" b:-";cin>>n2;cout<<endl;
	   if(n2==0)
	   sc++;
	   cout<<"  Score = "<<sc<<" out of 2";
	 }
	 void enterand()
	 {int sc=0;
	  cout<<" Enter values(0/1) \n";
	  cout<<" c:-";cin>>and1;
	  if(and1==0)
	  sc++;
	  cout<<" d:-";cin>>and2;
	  if(and2==0)
	  sc++;
	  cout<<" e:-";cin>>and3;
	  if(and3==0)
	  sc++;
	  cout<<" f:-";cin>>and4;
	  if(and4==1)
	  sc++;
	   cout<<" Score ="<<sc<<" out of 4\n";
	 }

	 void enteror()
	 {  int sc=0;
	   cout<<" Enter values(0/1) \n";
	   cout<<" g:-";cin>>or1;
	   if(or1==0)
	   sc++;
	   cout<<" h:-";cin>>or2;
	   if(or2==1)
	   sc++;
	   cout<<" i:-";cin>>or3;
	   if(or3==1)
	   sc++;
	   cout<<" j:-";cin>>or4;
	   if(or4==1)
	   sc++;
	   cout<<" Score = "<<sc<<" out of 4\n";

	 }
	 void enternand()
	 { int sc=0;
	   cout<<" Enter values(0/1) \n";
	   cout<<" k:-";cin>>nand1;
	   if(nand1==1)
	   sc++;
	   cout<<" l:-";cin>>nand2;
	   if(nand2==1)
	   sc++;
	   cout<<" m:-";cin>>nand3;
	   if(nand3==1)
	   sc++;
	   cout<<" n:-";cin>>nand4;
	   if(nand4==0)
	   sc++;
	   cout<<" Score = "<<sc<<" out of 4\n";
	 }
	 void enternor()
	 { int sc=0;
	   cout<<" Enter values(0/1) \n";
	   cout<<" o:-";cin>>nor1;
	   if(nor1==1)
	   sc++;
	   cout<<" p:-";cin>>nor2;
	   if(nor2==0)
	   sc++;
	   cout<<" q:-";cin>>nor3;
	   if(nor3==0)
	   sc++;
	   cout<<" r:-";cin>>nor4;
	   if(nor4==0)
	   sc++;
	   cout<<" Score = "<<sc<<" out of 4\n";
	   }


       };
       class Account
       { private:
	 char name[20],id[20];
	 int age;
	 char contact[20];
	 public:
	 void input()
	 {cout<<"\n Enter user id:-";
	  gets(id);
	  cout<<" Enter name :-";
	  gets(name);
	  cout<<" Enter your age :-";
	  cin>>age;
	  cout<<" Enter your contact :-";
	  gets(contact);
	  }
	 void output()
	 { cout<<endl;
	   cout<<" +++++++++++++++++++++++ \n";
	   cout<<" +   Account details   + \n";
	   cout<<" +++++++++++++++++++++++ \n";
	   cout<<"  Name:-";puts(name);
	   cout<<"  Age:-"<<age;cout<<endl;
	   cout<<"  Contact:-";puts(contact);
	   }
	char *Rid()
	{return id;}

       };
       void create() //account function 1
       { ofstream fout("DATA.dat",ios::binary);
	 Account A;
	 A.input();
	 fout.write((char*)&A,sizeof(A));
	 fout.close();
       }
       int display(char uid[]) //account function 3
       { Account A;
	 ifstream fin("DATA.dat",ios::binary);
	 fin.read((char*)&A,sizeof(A));
	 if(strcmp(uid,A.Rid())==0)
	 { A.output();
	 return 1;}
	 else
	 {cout<<" NO SUCH RECORD FOUND !!!\n";}
	 fin.close();
       }
       int clear(char uid[]) //account function 4
       { ifstream fin("DATA.dat",ios::binary);
	 ofstream fout("x.dat",ios::binary);
	 Account A;
	 fin.read((char*)&A,sizeof(A));
	 if(strcmp(uid,A.Rid())==0)
	 {fout.write((char*)&A,sizeof(A));
	 remove("DATA.dat");
	 return 1;}
	 else
	 {return 0;}
	 fin.close();fout.close();

	}

	void ttnot(char uid[])//tt for not
       { Account A;Game G;
	 ofstream fout("DATA.dat",ios::binary);
	 ifstream fin("DATA.dat",ios::binary);
	 fout.write((char*)&G,sizeof(G));
	 G.enternot();
	 fout.close(); fin.close();
	 }
	void ttand(char uid[])//tt for and
       { Account A;Game G;
	 ofstream fout("DATA.dat",ios::binary);
	 fout.write((char*)&G,sizeof(G));
	 G.enterand();
	 fout.close();
	 }
	void ttor(char uid[])//tt for or
       { Account A;Game G;
	 ofstream fout("DATA.dat",ios::binary);
	 fout.write((char*)&G,sizeof(G));
	 G.enteror();
	 fout.close();
	 }

       void ttnand(char uid[])//tt for nand
       { Account A;Game G;
	 ofstream fout("DATA.dat",ios::binary);
	 fout.write((char*)&G,sizeof(G));
	 G.enternand();
	 fout.close();
	 }

	void ttnor(char uid[])//tt for nor
       { Account A;Game G;
	 ofstream fout("DATA.dat",ios::binary);
	 fout.write((char*)&G,sizeof(G));
	 G.enternor();
	 fout.close();
	 }

	 void check(char uid[])
	 { Account A;
	   ifstream fin("DATA.dat",ios::binary);
	   fin.read((char*)&A,sizeof(A));
	   if(strcmp(uid,A.Rid())==0)
	   {cout<<" ACCOUNT EXIST!!!\n";}
	   else
	   {cout<<" NO  SUCH ACCOUNT EXIST!!!\n";

	   exit(0);
	   }
	 }

       int main()
       { cout<<"\n   WELCOME TO LOGIC GATE TUTORIAL LESSONS\n";
	 cout<<" ________________________________________ \n";
				  MENU:
	 cout<<"++++++++++++++++++++++++++++++++++++++++++\n";
	 cout<<"+               M  E  N  U               +\n";
	 cout<<"++++++++++++++++++++++++++++++++++++++++++\n";
	 cout<<"+         1) Account settings            +\n";
	 cout<<"+         2) Know about logic gates      +\n";
	 cout<<"+         3) Play truth table game       +\n";
	 cout<<"+         4) Show truth table solution   +\n";
	 cout<<"+         5) Exit                        +\n";
	 cout<<"++++++++++++++++++++++++++++++++++++++++++\n";
	 cout<<" ENTER YOUR CHOICE (1/2/3/4/5):-";
	 int a;cin>>a;
	 if(a==1) //Accounts
	 {                   ACCOUNT:
	 cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
	 cout<<"+           ACCOUNT SETTINGS            +\n";
	 cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
	 cout<<"+        1) Create account              +\n";
	 cout<<"+        2) Update account              +\n";
	 cout<<"+        3) Display account             +\n";
	 cout<<"+        4) Delete Account              +\n";
	 cout<<"+++++++++++++++++++++++++++++++++++++++++\n";
			    IN:
	 cout<<" Enter your choice (1/2/3/4):-";
	 int a1;cin>>a1;
	 if(a1==1)
	 { create();}
	 else if(a1==2)
       { cout<<"\n Enter id:-";
	 char u1[20];int k;
	 gets(u1);
	 k=clear(u1);
	 if(k==1)
	 {cout<<"\n Enter new details\n";}
	 else
	 {cout<<"\n NO SUCH RECORD FOUND!!!\n";
	 goto IN; }

	 create();

       }
	 else if(a1==3)
	 {cout<<"\n Enter id:-";
	  char u2[20];
	  gets(u2);
	  display(u2);}
	 else if(a1==4)
	 {cout<<"\n Enter id for deletion:-";
	  char u3[20];int k;
	  gets(u3);
	  k=clear(u3);
	  if(k==1)
	  cout<<"\n RECORD DELETED!!!\n";
	  else
	  cout<<"\n NO SUCH RECORD FOUND!!!\n";

	  }

	cout<<"\n Return to Menu or Account settings(m/a):-";
	char r1;cin>>r1;
	if(r1=='m'||r1=='M')
	{goto MENU;}
	else if(r1=='a'||r1=='A')
	{goto ACCOUNT;}


	   }

	else if(a==2)//2) logic gates
	{cout<<endl;
	 cout<<"A logic gate is simply an electronic circuit which";
	 cout<<" operates on one or more input signals to produce an";
	 cout<<" an output signal. Logic gates can be constructed from";
	 cout<<" diodes, transistors, resistors and switches connected";
	 cout<<" in such a way that circuit output is the result of basic";
	 cout<<" logic operations (NOT,AND,OR) performed on the input.";
		     LOGIC:
	 cout<<"\n Types of logic gates are shown :-\n";
	 cout<<" 1) NOT gate\n";
	 cout<<" 2) AND gate\n";
	 cout<<" 3) OR gate\n";
	 cout<<" 4) NAND gate\n";
	 cout<<" 5) NOR gate\n";
	 cout<<" Choose the gate to know about(1-5):-";
	 int a2;cin>>a2;
	 if(a2==1)
	 {
	 cout<<"\n NOT(') gate:- It accepts one input .";
	 cout<<" The output is the complement of the given  input.";
	 cout<<" \n\n Example:- X=A'";
	 cout<<endl; cout<<"\n LOGIC CIRCUIT:-\n";
	 cout<<" ----|>o----"<<endl;

	}
	else if(a2==2)
	{
	cout<<"\n AND(.) gate:- It can have two or more than two inputs";
	cout<<" and produces only one output. It is a logic circuit that";
	cout<<" requires all inputs to be 1 at the same time in order for";
	cout<<" the output to be 1. If any one input is 0 then output is 0.";
	cout<<"\n\n Example:- X=A.B";
	cout<<endl; cout<<"\n LOGIC CIRCUIT:-\n";
	cout<<"     __      \n";
	cout<<"....|  )     \n";
	cout<<"    |   }----\n";
	cout<<"....|__)     \n";
	}
	else if(a2==3)
	{
	cout<<"\n\n OR(+) gate:- It  can have two or more than inputs";
	cout<<" and produces only one output. The  output is one if any";
	cout<<" of its output is 1.";
	cout<<"\n\n Example:- X=A+B";
	cout<<endl;cout<<"\n LOGIC CIRCUIT:-\n";
	cout<<"     __ ......  \n";
	cout<<"----<__C......  \n";
	}
	else if(a2==4)
	{
	cout<<"\n NAND gate:- This is the logic circuit that will produce";
	cout<<" the output as 1 when any or all inputs are 0 and the output";
	cout<<" will be 0 when all the inputs are 1. NAND gate is constructed";
	cout<<" using AND gate followed by NOT gate.";
	cout<<"\n\n Example:- X=(A.B)' ";
	cout<<endl;cout<<"\n LOGIC CIRCUIT:-\n";
	cout<<"     ____        \n";
	cout<<"....|     )      \n";
	cout<<"    |      }O----\n";
	cout<<"....|____ )      \n";

	}
	else if(a2==5)
	{
	cout<<"\n NOR gate:- This is a logic circuit , that will produce";
	cout<<" 1 output only when both inputs are 0. If any input is one,";
	cout<<" then output will be zero.NOR gate can have more than 2 inputs";
	cout<<" but the output will be one.NOR gate is OR gate followed by NOT gate";
	cout<<"\n\n Example:- X=(A+B)' ";
	cout<<endl;cout<<"\n LOGIC CIRCUIT:-\n";
	cout<<"      __ ......  \n";
	cout<<"----O<__C......  \n";


	}
	else
	{cout<<"\n Choose between 1-5\n";
	 goto LOGIC;}

	cout<<"\n Return to menu or types of logic gates(m/l) :-";
	char r2; cin>>r2;
	if(r2=='m'||r2=='M')
	{goto MENU;}
	else if(r2=='l'||r2=='L')
	{goto LOGIC;}
	else
       { cout<<"\n CHOOSE m or l !!!\n";}

	}
       else if(a==3)  //truth table game
       { int a3;char ac;
	cout<<"\n WELCOME TO TRUTH TABLE GAME\n";
	cout<<" Got an account(y/n):-";
	cin>>ac;
	if(ac=='y'||ac=='Y')
	{       char id[20]; char choose;
	cout<<"**if id is false game will exit...**\n";
	cout<<"  Enter your id:-";gets(id);
		  check(id);
		       TRUTH:
	cout<<" +++++++++++++++++++++++++\n";
	cout<<" +    Choose the gate    +\n";
	cout<<" +++++++++++++++++++++++++\n";
	cout<<" +     1)  NOT Gate      +\n";
	cout<<" +     2)  AND Gate      +\n";
	cout<<" +     3)  OR Gate       +\n";
	cout<<" +     4)  NAND Gate     +\n";
	cout<<" +     5)  NOR Gate      +\n";
	cout<<" +++++++++++++++++++++++++\n";
	cout<<" Your choice(1-5):-";
	int t;cin>>t;
	if(t==1)
	{ cout<<" +++++++++++++++++++++++\n";
	  cout<<" +    A    +     A'    +\n";
	  cout<<" +++++++++++++++++++++++\n";
	  cout<<" +    0    ->    a     +\n";
	  cout<<" +    1    ->    b     +\n";
	  cout<<" +++++++++++++++++++++++\n";
	  ttnot(id);    r:
	  cout<<" Return to menu or game(m/g):-";
	  char t1;cin>>t1;
	  if(t1=='m'||t1=='M')
	  {goto MENU;}
	  else if(t1=='g'||t1=='G')
	  {goto TRUTH;}
	  else
	  {cout<<" CHOOSE BETWEN m/g !!!";
	   goto r;}

	}
	else if(t==2)
	{ cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   A   +   B   +   (A.B)    +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   0   +   0   +     c      +\n";
	  cout<<" +   0   +   1   +     d      +\n";
	  cout<<" +   1   +   0   +     e      +\n";
	  cout<<" +   1   +   1   +     f      +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  ttand(id);    r1:
	  cout<<" Return to menu or game(m/g):-";
	  char t1;cin>>t1;
	  if(t1=='m'||t1=='M')
	  {goto MENU;}
	  else if(t1=='g'||t1=='G')
	  {goto TRUTH;}
	  else
	  {cout<<" CHOOSE BETWEN m/g !!!";
	   goto r1;}

	}
	else if(t==3)
	{ cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   A   +   B   +   (A+B)    +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   0   +   0   +     g      +\n";
	  cout<<" +   0   +   1   +     h      +\n";
	  cout<<" +   1   +   0   +     i      +\n";
	  cout<<" +   1   +   1   +     j      +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  ttor(id);   r2:
	  cout<<" Return to menu or game(m/g):-";
	  char t1;cin>>t1;
	  if(t1=='m'||t1=='M')
	  {goto MENU;}
	  else if(t1=='g'||t1=='G')
	  {goto TRUTH;}
	  else
	  {cout<<" CHOOSE BETWEN m/g !!!";
	   goto r2;}

	}
	else if(t==4)
	{ cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   A   +   B   +   (A.B)'   +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   0   +   0   +     k      +\n";
	  cout<<" +   0   +   1   +     l      +\n";
	  cout<<" +   1   +   0   +     m      +\n";
	  cout<<" +   1   +   1   +     n      +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  ttnand(id);   r3:
	  cout<<" Return to menu or game(m/g):-";
	  char t1;cin>>t1;
	  if(t1=='m'||t1=='M')
	  {goto MENU;}
	  else if(t1=='g'||t1=='G')
	  {goto TRUTH;}
	  else
	  {cout<<" CHOOSE BETWEN m/g !!!";
	   goto r3;}
	}
       else if(t==5)
       {  cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   A   +   B   +   (A+B)'   +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  cout<<" +   0   +   0   +     o      +\n";
	  cout<<" +   0   +   1   +     p      +\n";
	  cout<<" +   1   +   0   +     q      +\n";
	  cout<<" +   1   +   1   +     r      +\n";
	  cout<<" ++++++++++++++++++++++++++++++\n";
	  ttnor(id); r4:
	  cout<<" Return to menu or game(m/g):-";
	  char t1;cin>>t1;
	  if(t1=='m'||t1=='M')
	  {goto MENU;}
	  else if(t1=='g'||t1=='G')
	  {goto TRUTH;}
	  else
	  {cout<<" CHOOSE BETWEN m/g !!!";
	   goto r4;}

       }
       else
       {cout<<"\n CHOOSE BETWEEN 1-5!!!\n";
	goto TRUTH;}

       }
       else
       {cout<<" Get an account first!!!\n";
       goto MENU;}

	}
       else if(a==4) //tt solutions
       {                    q:
	 cout<<"\n Do  you have an account(y/n):- ";
	 char tt;cin>>tt;
	 if(tt=='y'||tt=='Y')
	 {cout<<"\n***if id is false tutorial lesson will end***\n";
	  cout<<"\n Enter id:-"; char id[20];
	   gets(id);check(id);    l:
	  cout<<"\n Choose the gate to see it's 2 input truth table\n";
	  cout<<" ++++++++++++++++++++++++\n";
	  cout<<" +     1) NOT Gate      +\n";
	  cout<<" +     2) AND Gate      +\n";
	  cout<<" +     3) OR Gate       +\n";
	  cout<<" +     4) NAND Gate     +\n";
	  cout<<" +     5) NOR Gate      +\n";
	  cout<<" ++++++++++++++++++++++++\n";
	  int opt;cout<<" Your choice :-";cin>>opt;
	  if(opt==1)
	  {cout<<endl;
	   cout<<"     NOT Gate   \n";
	   cout<<" +++++++++++++++\n";
	   cout<<" +   A  +  A'  +\n";
	   cout<<" +++++++++++++++\n";
	   cout<<" +   0  +  1   +\n";
	   cout<<" +   1  +  0   +\n";
	   cout<<" +++++++++++++++\n";
		      soln1:
	   cout<<" Return to menu or Truth table(m/t):-";
	   char o1;cin>>o1;
	   if(o1=='m'||o1=='M')
	   {goto MENU;}
	   else if(o1=='t'||o1=='T')
	   {goto l;}
	   else
	   {cout<<"\n Choose between m/t !!!\n";
	    goto soln1;}
	  }
	  else if(opt==2)
	  {cout<<"        AND Gate        \n";
	   cout<<" +++++++++++++++++++++++\n";
	   cout<<" +  A  +  B  +  (A.B)  +\n";
	   cout<<" + +++++++++++++++++++++\n";
	   cout<<" +  0  +  0  +    0    +\n";
	   cout<<" +  0  +  1  +    0    +\n";
	   cout<<" +  1  +  0  +    0    +\n";
	   cout<<" +  1  +  1  +    1    +\n";
	   cout<<" +++++++++++++++++++++++\n";
		      soln2:
	   cout<<" Return to menu or Truth table(m/t):-";
	   char o2;cin>>o2;
	   if(o2=='m'||o2=='M')
	   {goto MENU;}
	   else if(o2=='t'||o2=='T')
	   {goto l;}
	   else
	   {cout<<"\n Choose between m/t !!!\n";
	    goto soln2;}
	    }

	  else if(opt==3)
	  {cout<<"        OR  Gate        \n";
	   cout<<" +++++++++++++++++++++++\n";
	   cout<<" +  A  +  B  +  (A+B)  +\n";
	   cout<<" + +++++++++++++++++++++\n";
	   cout<<" +  0  +  0  +    0    +\n";
	   cout<<" +  0  +  1  +    1    +\n";
	   cout<<" +  1  +  0  +    1    +\n";
	   cout<<" +  1  +  1  +    1    +\n";
	   cout<<" +++++++++++++++++++++++\n";
	       soln3:
	   cout<<" Return to menu or Truth table(m/t):-";
	   char o3;cin>>o3;
	   if(o3=='m'||o3=='M')
	   {goto MENU;}
	   else if(o3=='t'||o3=='T')
	   {goto l;}
	   else
	   {cout<<"\n Choose between m/t !!!\n";
	    goto soln3;}
	    }

	  else if(opt==4)
	  {cout<<"        NAND  Gate        \n";
	   cout<<" +++++++++++++++++++++++\n";
	   cout<<" +  A  +  B  +  (A.B)' +\n";
	   cout<<" + +++++++++++++++++++++\n";
	   cout<<" +  0  +  0  +    1    +\n";
	   cout<<" +  0  +  1  +    1    +\n";
	   cout<<" +  1  +  0  +    1    +\n";
	   cout<<" +  1  +  1  +    0    +\n";
	   cout<<" +++++++++++++++++++++++\n";
	    soln4:
	   cout<<" Return to menu or Truth table(m/t):-";
	   char o4;cin>>o4;
	   if(o4=='m'||o4=='M')
	   {goto MENU;}
	   else if(o4=='t'||o4=='T')
	   {goto l;}
	   else
	   {cout<<"\n Choose between m/t !!!\n";
	    goto soln4;}
	    }

	  else if(opt==5)
	  {cout<<"        NOR  Gate        \n";
	   cout<<" +++++++++++++++++++++++\n";
	   cout<<" +  A  +  B  +  (A+B)' +\n";
	   cout<<" + +++++++++++++++++++++\n";
	   cout<<" +  0  +  0  +    1    +\n";
	   cout<<" +  0  +  1  +    0    +\n";
	   cout<<" +  1  +  0  +    0    +\n";
	   cout<<" +  1  +  1  +    0    +\n";
	   cout<<" +++++++++++++++++++++++\n";
	     soln5:
	   cout<<" Return to menu or Truth table(m/t):-";
	   char o5;cin>>o5;
	   if(o5=='m'||o5=='M')
	   {goto MENU;}
	   else if(o5=='t'||o5=='T')
	   {goto l;}
	   else
	   {cout<<"\n Choose between m/t !!!\n";
	    goto soln5;}
	    }
	    else
	    {cout<<"\n Choose between 1-5!!!\n";
	      goto l;}



	    }
	 else if(tt=='n'||tt=='N')
	 {cout<<"\n Get an account first!!!\n";
	   goto  MENU;}
	  else
	 {cout<<"\n Choose between y/n !!!\n";
	  goto q;
	 }
       }


       else if(a==5)  //exit
       {
       exit(0);
       }
       else
       {cout<<"\n Choose between 1-5!!!\n";
       goto MENU;}

       getch();
       return 0;
       }
