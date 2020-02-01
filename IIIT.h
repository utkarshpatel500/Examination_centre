/*header file IIIT.H
programmer UTKARSH PATEL */
#define MAX_CENTRE 6

struct address
	{ char street[20];
	  char post[15];
	  char dist[15];
	  char state[15];
	  char pin[10];
	};

struct student
	{ char name[20];
	  int age;
	  struct address add;
	  int centre_code;
	  char centre_name[15];
	  char course[20];
	  char session[15];
	  struct student* next;
	};

/*initialization of centre code,name and capacity*/
char* code[MAX_CENTRE]={"2708","2709","2710","2711","2712","2713"};
char* name[MAX_CENTRE]={"Nagpur","Allahabad","Jabalpur","Lucknow","Kurnool","Guwahati"};
int capacity[MAX_CENTRE]={2,2,2,2,2,2};

/*enumeration declaration*/
enum boolean{false,true};

/*prototypes of the function*/
void box(int,int,int,int);
enum boolean entry(struct student*);
int popup(int,int,int,int,char* [],int);

/*function declaration*/
void box(int x1,int y1,int x2,int y2)
{
	int i;
	gotoxy(x1,y1);putch(201);
	for(i=x1+1;i<x2;i++)
	putch(205);
	putch(187);
	for(i=y1+1;i<y2;i++)
	{
		gotoxy(x1,i);putch(186);
		gotoxy(x2,i);putch(186);
	}
	gotoxy(x1,i);putch(200);
	for(i=x1+1;i<x2;i++)
	putch(205);
	putch(188);
}

/*function declaration*/
enum boolean entry(struct student* s)
{
	int a;
	clrscr();
	_setcursortype(_SOLIDCURSOR);
	textcolor(GREEN);
	gotoxy(20,2);cprintf("INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, NAGPUR");
	gotoxy(30,4);cprintf("STUDENT DATA ENTRY");
	box(1,6,80,22);
	textcolor(LIGHTGRAY);
	gotoxy(5,8);cprintf("Name : ");
	gotoxy(50,8);cprintf("Age : ");
	gotoxy(5,10);cprintf("Address : ");
	gotoxy(10,12);cprintf("Street : ");
	gotoxy(10,13);cprintf("Post Office : ");
	gotoxy(10,14);cprintf("District : ");
	gotoxy(10,15);cprintf("State : ");
	gotoxy(10,16);cprintf("Pin Code : ");
	gotoxy(5,18);cprintf("Center Code : ");
	gotoxy(50,18);cprintf("Center : ");
	gotoxy(5,20);cprintf("Course Code : ");
	gotoxy(50,20);cprintf("Session : ");

	fflush(stdin);

	gotoxy(13,8);gets(s->name);
	if(*s->name=='\0') return false;
	gotoxy(56,8);scanf("%d",&s->age);
	fflush(stdin);
	gotoxy(20,12);gets(s->add.street);
	gotoxy(26,13);gets(s->add.post);
	gotoxy(25,14);gets(s->add.dist);
	gotoxy(23,15);gets(s->add.state);
	gotoxy(27,16);gets(s->add.pin);
	a=popup(20,18,28,22,code,MAX_CENTRE);
	_setcursortype(_SOLIDCURSOR);
	s->centre_code=atoi(code[a]);
	gotoxy(20,18);printf("%d",s->centre_code);
	for(a=0;a<MAX_CENTRE;a++)
	if (s->centre_code==atoi(code[a])) break;
	strcpy(s->centre_name,name[a]);
	gotoxy(60,18);printf("%s",s->centre_name);
	gotoxy(20,20);gets(s->course);
	gotoxy(65,20);gets(s->session);
	_setcursortype(_NOCURSOR);
	return true;
}

/*function declaration*/
int popup(int l,int t,int r,int b,char* item[],int size)
{
	void* bx;
	int i,k,bk,min,loc,lk,lbk;
	char ch;
	_setcursortype(_NOCURSOR);
	bx=malloc((b-t)*(r-l));
	gettext(l,t,r,b,bx);
	box(l,t,r,b);
	k=0,bk=1,min=0,loc=0,lk=0,lbk=1;
	do
	{
		loc=0;
		for(i=min;i<min+(b-t-1);i++)
		{
			gotoxy(l+1,t+1+loc++);
			cprintf("%-*s",strlen(item[i])+r-1-(l+strlen(item[i])),item[i]);
		}
		textcolor(BLACK);
		textbackground(LIGHTGRAY);
		gotoxy(l+1,t+lk+1);
		cprintf("%-*s",strlen(item[k])+r-1-(l+strlen(item[k])),item[k]);
		textcolor(LIGHTGRAY);
		textbackground(BLACK);
		gotoxy(l+1,t+lbk+1);
		cprintf("%-*s",strlen(item[bk])+r-1-(l+strlen(item[bk])),item[bk]);
		fflush(stdin);
		ch=getch();
		if(ch==(char)0+(char)80&&k<size-1)
		{
			bk=k,k=k+1;
			if(min+b-t-2<size-1&&lk==b-t-2)
			min++;
			else
			lbk=lk,lk++;
		}
		if(ch==(char)0+(char)72&&k>0)
		{
			bk=k,k=k-1;
			if(min>0&&lk==0)
			min--;
			else
			lbk=lk,lk--;
		}
	}while(ch!='\r');
	puttext(l,t,r,b,bx);
	free(bx);
	return k;
}


