/* A programme in 'C' for the allotement of study centres
to new B.Tech students in IIIT Nagpur
filename IIIT.C*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<alloc.h>
#include"projectc\project.h"

void main()
{
int i,count,n,choice;
struct student *stu,*temp,*head,*current;
char* menu_item[25]={" New Entry"," Display Student"," List of Exam Centres "," Exit"};
enum boolean data_entry=false;
stu=(struct student*)malloc(sizeof(struct student));
head=stu;

start:
/*menu system*/
clrscr();
_setcursortype(_NOCURSOR);
textcolor(YELLOW);
gotoxy(22,2);cprintf("INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, NAGPUR");
gotoxy(30,4);cprintf("Students Admission System");
gotoxy(22,23);cprintf("Software Developed by UTKARSH PATEL");
textcolor(LIGHTGRAY);
box(1,6,80,22);
choice=popup(25,11,55,16,menu_item,4);

switch(choice)
{
case 0 : {
	/*creation of a linked list of students*/
	do
	{
		if(entry(stu)==false)
		break;
		data_entry=true;
		/*check for vacant seat in the centre*/
		check:
		i=0;
		while(stu->centre_code!=atoi(code[i]))
		{
			i++;
		}
		current=head;
		count=1;
		while(current!=stu)
		{
			if(current->centre_code==stu->centre_code)
			count++;
			current=current->next;
		}

		if(count>capacity[i])
		{
			box(10,10,70,13);
			textcolor(BLINK+WHITE);
			gotoxy(11,11);
			cprintf("    Capacity Overflow ! Capacity of %s is %d only",name[i],capacity[i]);
			textcolor(WHITE);
			gotoxy(11,12);
			cprintf("             Select another nearest study centre");
			textcolor(LIGHTGRAY);
			n=popup(30,14,50,18,name,MAX_CENTRE);
			stu->centre_code=atoi(code[n]);
			strcpy(stu->centre_name,name[n]);
			goto check;
		}

		temp=(struct student*)malloc(sizeof(struct student));
		stu->next=temp;
		stu=temp;
	} while(true);

	stu->next=NULL;
	}
	goto start;

case 1 : {
	/*display students data */
	clrscr();
	if(data_entry==false)
	{
		textcolor(WHITE+BLINK);
		gotoxy(30,12);cprintf("No display list available !");
		textcolor(LIGHTGRAY);
		getch();
		goto start;
	}
	stu=head;
	i=0;
	while(stu->next!=NULL)
	{
		i++;
		printf("\n%d. %s\t%s\t",i,stu->name,stu->add.state);
		printf("%s\t%d\t%s",stu->course,stu->centre_code,stu->centre_name);
		stu=stu->next;
	}
	getch();
	}
	goto start;

case 2 : {
	clrscr();
	textcolor(YELLOW);
	gotoxy(22,2);cprintf("INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, NAGPUR");
	gotoxy(30,4); cprintf("List of Examination Centres");
	gotoxy(14,23);cprintf("Press UP and DOWN arrow key to scroll and ENTER key to exit");
	textcolor(LIGHTGRAY);
	box(1,6,80,22);
	popup(30,11,50,16,name,MAX_CENTRE);
	}
	goto start;
case 3 : {
	clrscr();
	gotoxy(35,12); printf("T H A N K S . . .");
	delay(700);
	}
}  /*end of switch statement*/
_setcursortype(_NORMALCURSOR);
} /*end of main*/
