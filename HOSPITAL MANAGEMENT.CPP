#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include<iomanip.h>

//*******************************************************
//	CLASS NAME :  HOSPITAL
//*******************************************************
class hospital
{
  public:
   char name[20];
   char address[20];
   int age;
   void getdata();
   void show();
};

//*******************************************************
//	FUNCTIONS TO GET AND SHOW DATA
//*******************************************************

void hospital::getdata()
{
  cout<<"\n ENTER DETAILS ABOUT PATIENT YOU WANT TO ADD\" :\"";
  cout<<"\n\n\n\t\tEnter name of patient :\t";
  cin>>name;
  cout<<"\n\t\t Enter address of patient   :\t";
  cin>>address;
  //fflush(stdin);
  cout<<"\n\t\t Enter age of patient  :\t";
  cin>>age;
  fflush(stdin);
}
void hospital::show()
{
  int i;
  cout << name ;
  for(i=strlen(name);i<14;i++)
      cout <<" ";
  cout << address ;
  for(i=strlen(address);i<14;i++)
      cout <<" ";
  cout << age << endl;
}

//*******************************************************
//       	TO INVOKE WELCOME SCREEN
//*******************************************************

void graph()
{

    /* for (int c=0;c<150;++c)
     {
       setcolor(BLUE);
       fillellipse(325,240,c*1.5,c);
       delay(10);
     }  */
     setcolor(RED);
     settextstyle(7,0,5);
     outtextxy(150,200,"AXIS HOSPITAL");
     getch();
     clearviewport();
}

void main()
{
  clrscr();
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  graph();
  rectangle(10,10,630,470);
  setbkcolor(BLUE);
  rectangle(10,10,630,470);
  settextstyle(GOTHIC_FONT,0,4);
  setcolor(YELLOW);
  outtextxy(100,35,"Developed By:-");
  settextstyle(10,0,3);
  outtextxy(100,100," KUNAL LIMJE   XII B   ");
  outtextxy(100,200," MUKUL LADEKAR XII A ");
  outtextxy(100,300," ANKIT SHARMA  XII B ");
  getch();
  char s;
  hospital h1;
  z:
  fstream f;
  f.open("hospital",ios::in|ios::out|ios::app|ios::ate|ios::binary);
  clearviewport();
  settextstyle(10,HORIZ_DIR,3);
  setbkcolor(RED);
  rectangle(10,10,630,470);
  outtextxy(100,15,"HOSPITAL RECORDS :");
  settextstyle(SANS_SERIF_FONT,0,3);
  outtextxy(50,100,"1 . TO ADD NEW PAITENT");
  outtextxy(50,150,"2 . TO SHOW ALL RECORDS OF PATIENT");
  outtextxy(50,200,"3 . TO CHECK AVAILABILITY");
  outtextxy(50,250,"4 . TO MODIFY");
  outtextxy(50,300,"5 . TO DELETE");
  outtextxy(50,350,"6 . TO EXIT");
  int a;
  settextstyle(7,0,5);
  outtextxy(20,400, "ENTER YOUR CHOICE:");
  f.seekg(0);
  gotoxy(55,25);
  cin>>a;
  char x;
  gotoxy(1,1);
  switch (a)
  {
    //*******************************************************
    //	CASE       : 1
    //	DETAILS    : TO ADD NEW PAITIENT
   //*******************************************************
   case 1:
      gotoxy(1,1);
      clearviewport();
      rectangle(10,10,630,470);
      setbkcolor(RED);
      textbackground(13);
      textcolor(6);
      clrscr();
      fstream f;
      f.open("hospital ",ios::in|ios::out|ios::ate|ios::app|ios::binary);
      char ans;
      h1.getdata();
      f.write((char *)&h1,sizeof(h1));
      cout << "\nRecord Written :\n\n";
      settextstyle(7,0,1);
      outtextxy(250,410,"Do You Want To Continue:--");
      ans=getchar();
      if(ans=='Y' || ans=='y')
	 goto z;
      else
	 break;
      //*******************************************************
      //	CASE       : 2
      //	DETAILS    : TO SHOW ALL RECORDS OF HOSPITAL
      //*******************************************************
   case 2:
   {
    clearviewport();
   // rectangle(10,10,630,470);
    setbkcolor(LIGHTBLUE);
    textbackground(3);
    textcolor(6);
    cout<<"\n\n";
    fstream f;
    f.open("hospital",ios::in|ios::out|ios::ate|ios::app|ios::binary);
    char ans;
    f.seekg(0);
    int ctr=0;
    cout << "    Patient Name                Address              Age\n";
    cout << "    -----------------------------------------------------\n";
    while(f.read((char *)&h1,sizeof(h1)) )
    {
      ctr=ctr+1;
      if(ctr==8)   // For displaying 8 records per screen
      {
	 cout << "    ----------------------------------------\n";
	 getchar();
	 clrscr();
	 cout << "    Patient name        Address          Age\n";
	 cout << "    ----------------------------------------\n";
	 ctr=0;
      }
      h1.show();
      if(f.eof()==1)
      {
	 break;
      }
    }
    f.close();
    settextstyle(7,0,1);
    outtextxy(250,410,"Do You Want To Continue:");
    cin>>ans;
    if(ans=='y'|| ans=='Y')
       goto z;
    else
    {
       closegraph();
       exit(1);
    }
  }

  //*******************************************************
  //	CASE       : 3
  //	DETAILS    : TO CHECK AVAILABILITY
  //*******************************************************
  case 3:
  {
    gotoxy(60,25);
    clearviewport();
    rectangle(10,10,630,470);
    setbkcolor(DARKGRAY);
    textbackground(3);
    textcolor(5);
    clrscr();
    char ans;
    ifstream f;
    hospital h1;
    char name[20];
    char address[20];
    int age;
    f.open("hospital",ios::in|ios::binary);
    cout<<"\n\n\n          Enter patient name whose record to be seen  :";
    cin>>name;
    do
    {
      f.read((char *)&h1,sizeof(h1));
      if(f.eof()==1) {break;}
      if(strcmp(h1.name,name)==0)
      {
	cout<<"\n                  Name     :"<<h1.name;
	cout<<"\n                 Address  :"<<h1.address;
	cout<<"\n                 Age      :"<<h1.age;
	getchar();
      }
    }while(f);
    f.close();
    //  a:
    settextstyle(7,0,1);
    outtextxy(250,410,"Do You Want To Continue:");
    ans=getchar();
    if(ans=='Y'||ans=='y')
	goto z;
    else
      break;
   }

   //*******************************************************
   //	CASE       : 4
   //	DETAILS    : TO MODIFY A RECORD
   //*******************************************************
   case 4:
   {
     clearviewport();
     rectangle(10,10,630,470);
     setbkcolor(BROWN);
     setcolor(WHITE);
     clrscr();
     char ans;
     fstream f;
     hospital h1;
     char name[20];
     char address[20];
     int age;
     f.open("hospital",ios::in|ios::binary);
     cout<<"\n";
     cout<<" Enter patient name whose record to be changed  :";
     cin>>name;
     do
     {
       f.read((char *)&h1,sizeof(h1));
       if(f.eof()==1)
       {
       break;
       }
       if(strcmp(h1.name,name)==0)
       {
	 cout<<"\n        Name     :"<<h1.name;
	 cout<<"\n        Address   :"<<h1.address;
	 cout<<"\n        Age       :"<<h1 .age;
	 getchar();
	 cout<<"\n                 Enter New patient" ;
	 cout<<"\n\n      Enter the patient name  :";
	 cin>>name;
	 cout<<"\n        Enter address of patient    :";
	 cin>>address;
	 cout<<"\n        Enter age of patient :";
	 cin>>age;
	 strcpy(h1.name,name);
	 strcpy(h1.address,address);
	 h1.age=age;
	 int l=f.tellg();
	 f.close();
	 f.open("hospital",ios::out|ios::binary|ios::ate);
	 f.seekg(l-sizeof(h1));
	 f.write((char *)&h1,sizeof(h1));
       }
     }while(f);
     f.close();
     settextstyle(7,0,1);
     outtextxy(250,410,"Do You Want To Continue:");
     ans=getchar();
     if(ans=='Y'||ans=='y')
       {goto z;}
     else
       break;
   }
   //*******************************************************
   //	CASE       : 5
   //	DETAILS    : TO DELETE A PATIENT RECORD
   //*******************************************************
   case 5:
   {
     clearviewport();
     rectangle(10,10,630,470);
     setbkcolor(BROWN);
     setcolor(WHITE);
     char name[20];
     f.close();
     f.open("video",ios::in|ios::ate|ios::binary);
     settextstyle(7,0,3);
     outtextxy(200,30,"DELETING:-");
     cout<<"\n\n\n\n\n\n     Enter The  Patient You Want To Delete:\t";
     fflush(stdin);
     cin>>name;
     f.seekg(0);
     int k=0;
     do
     {
       f.close();
       f.open("hospital",ios::in|ios::ate|ios::binary);
       f.seekg(k);
       fflush(stdin);
       f.read((char *)&h1,sizeof(h1));
       if(f.eof())
	  break;
       if(strcmp(h1.name,name)==0)
       {
	 k+=46;
	 continue;
       }
       else
       {
	 f.close();
	 f.open("hospital2",ios::out|ios::ate|ios::binary);
	 f.write((char*)&h1, sizeof h1);
	 k+=46;
       }
     }while(f);
     f.close();
     remove ("hospital");
     rename ("hospital2","hospital");
     cout<<"\n\n\n\n\n\tPress Any Key...";
     getch();
     goto
     z;
   }
   //*******************************************************
   //	CASE       : 6
   //	DETAILS    : TO EXIT
   //*******************************************************
  case 6:
  {
      fflush(stdin);
      clearviewport();
      rectangle(10,10,630,470);
      setbkcolor(LIGHTBLUE);
      setcolor(RED);
      window(10,10,40,11);
      settextstyle(8,0,4);
      outtextxy(100,200,"\"THANKS FOR VISITING\"");
      getch();
      closegraph();
      exit(1);

  }
  default:
    goto z;
  }
}
