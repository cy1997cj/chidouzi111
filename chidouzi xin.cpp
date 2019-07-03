#include "graphics.h"
#include "stdio.h"
#include "dos.h"
#include "bios.h"
#include "stdio.h"
#include "time.h"
#include "graphics.h"
#include "conio.h"
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0xO110
#define ENTER 0x1c0d
#define SPACE 0x3920

struct play
{
	int x;
	int y;
 } ;
 struct Snow
 {
 	int x;
 	int y;
 	int speed;
 }snow[100];
 intsnownum=0;
 struct play you,them[5];
 void *save;
 int sum=0;
 int change=10;
 int a[15][20]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,2,
2,1,2,2,2,1,1,2,1,1,0,0,0,1,1,4,1,1,0,2,
2,1,1,0,2,1,1,2,0,1,1,2,2,2,2,2,0,0,0,2,
2,4,1,0,2,1,1,2,1,1,1,0,1,1,1,1,0,1,1,2,
2,1,2,1,2,1,1,2,1,3,2,2,1,1,1,1,2,2,1,2,
2,1,2,1,2,1,1,1,1,1,1,1,1,0,0,0,1,1,1,2,
2,1,2,1,0,1,1,1,1,2,1,0,1,2,2,2,1,1,1,2,
2,1,0,1,0,1,2,1,1,2,1,0,1,2,1,1,4,1,1,2,
2,1,0,2,0,1,2,1,1,2,1,0,1,2,1,1,1,1,1,2,
2,1,0,2,1,1,2,1,1,2,1,0,2,2,1,0,0,0,1,2,
2,1,1,2,1,1,2,1,1,2,1,0,2,1,1,2,2,1,1,2,
2,1,2,2,1,2,2,1,1,1,1,0,1,4,1,2,0,0,1,2,
2,1,0,0,0,0,0,4,0,1,1,0,1,1,1,1,0,0,1,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};


  int b[15][20]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
  2,1,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,2,
  2,1,2,2,2,2,1,2,1,1,0,0,0,1,1,4,1,1,0,2,
  2,1,1,0,2,2,1,2,0,1,2,2,2,2,2,2,0,0,0,2,
  2,4,1,0,2,1,1,2,1,1,1,0,1,1,2,1,0,1,1,2,
  2,1,2,1,2,1,1,2,2,3,2,2,1,1,2,1,2,2,1,2,
  2,1,2,1,2,2,1,1,1,1,1,1,1,0,0,0,1,1,1,2,
  2,2,2,1,0,2,1,1,1,2,1,0,1,2,2,2,1,1,1,2,
  2,2,0,1,0,2,2,1,1,2,1,0,1,2,2,1,4,1,1,2,
  2,1,0,2,0,1,2,1,2,2,0,1,2,1,1,1,1,1,1,2,
  2,1,0,2,1,1,2,1,1,2,1,0,2,2,1,0,0,0,1,2,
  2,1,1,2,1,1,2,1,1,2,1,0,2,1,2,2,2,1,1,2,
  2,1,2,2,1,2,2,2,1,1,1,0,1,4,1,2,0,0,1,2,
  2,1,0,0,0,0,0,4,0,1,1,0,1,1,1,1,0,0,1,2,
  2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
 
 int c[15][20]={2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
 2,1,1,0,0,0,0,0,1,0,0,0,1,1,2,1,1,1,0,2,
 2,1,2,2,2,1,1,2,2,1,0,0,0,1,2,4,1,1,0,2,
 2,1,1,0,2,2,1,2,0,1,2,2,2,2,2,2,0,0,0,2,
 2,4,1,0,2,1,1,2,1,1,1,0,1,1,1,1,0,1,1,2,
 2,1,2,1,2,1,2,2,1,3,2,2,1,1,1,1,2,2,1,2,
 2,1,2,1,2,1,1,1,1,1,1,1,1,0,0,0,1,1,1,2, 
 2,1,2,1,0,2,1,1,1,2,2,0,1,2,2,2,1,1,1,2,
 2,2,0,1,0,1,2,1,2,2,1,0,1,2,1,1,4,1,1,2,
 2,2,0,2,0,1,2,1,1,2,1,0,1,2,2,1,1,1,1,2,
 2,2,0,2,1,1,2,2,1,2,1,0,2,2,1,0,0,0,1,2,
 2,1,1,2,1,1,2,1,1,2,2,0,2,1,1,2,2,2,1,2,
 2,1,2,2,1,2,2,1,2,1,1,0,1,4,1,2,0,0,1,2,
 2,1,0,0,0,0,0,4,0,1,1,0,1,1,1,1,0,0,1,2,
 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
}

int xx[5][2];
int false=0;
voidlevelchoose(int x)
{
	int j,k;
	switch(x)
	{
		case 1:break;
		case 2:for(j=0;j<15;j++)
		for(k=0;k<20;k++)
		a[j][k]=b[j][k];
		break;
		default:break;
	}
}
void hello()
{
	printf("XXXXXXXXXXXX  XXXXXXXXXXXXX            XXXXXXXXXXXXXXX  XXXXXXXXXXXX\n");
	printf("X       XXX          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXX\n");
	printf("X  XXX      XX       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("X  XXX  X   XXXXXXXXXXXXXXXX              XXXXXXXXXXXXXXXX  XXXXXXXXXXXX\n");
	printf("X  XXX  X  XXXXXXXXXXXXXXXXX  XXXXXXXXXX  XXXXXXXXXXXXXXXX  XXXXXXXXXXXX\n"); 
	printf("X  XXX  XXX        XXXXXXXXX  XXXXXXXXXX  XXXXXXXXXXXXXXX    XXXXXXXXXXX\n");
	printf("X  XXX  XXXXXXX   XXXXXXXXXX  XXXXXXXXXX  XXXXXXXXXXXXXXX    XXXXXXXXXXX\n");
	printf("X  XXX  XXXXXX  XXXXXXXXXXXX              XXXXXXXXXXXXXX  XX  XXXXXXXXXX\n");
	printf("X       XXXX   XXXXXXXXXXXXXXX XXXXXXX XXXXXXXXXXXXXXXX  XXXX  XXXXXXXXX\n");
	printf("X  XXX  XXX  XXXXXXXXXXXXXXXXX  XXXXXX  XXXXXXXXXXXXXX  XXXXXX  XXXXXXXX\n");
	printf("X  XXX  XXX  XXXXXX  XXXXXXXXXX  XXXX   XXXXXXXXXXXXX   XXXXXXX  XXXXXXX\n");
	printf("XXXXXXXXXX  XXXXXXX  XXXXXXXXXX XXXXX  XXXXXXXXXXXXX   XXXXXXXX    XXXXX\n");
	printf("XXXXXXXXXXX  XXXXX   XXXXXXXXXXXXXXX  XXXXXXXXXXXX    XXXXXXXXXX    XXXX\n");

}

void instruction()
{
	printf("           ******************************\n");
	printf("           *        GAME INSTRUCTIONS        *\n");
	printf("           ******************************\n");
	printf("                   WELCOME TO PACMAN WORLD!\n\n");
	printf("Press up,down,left,right to play.\n");
	printf("Press Esc to quit it.\n");
	printf("Press space to reset the game when you are playing.\n";)
	printf("How to win the game:\n");
	printf("tlf you have aten all of the yellow peans without being in the same location with the green enemy , you win !\n");
	printf("tlf you are in the same location with the green enemy ,you lose !\n");
	printf("Please choose game level number form 1 to 3 and pres Enter key to start game :\n");
	 
}

voidTimeDelay(unsigned long microsec)
{
	unoin REGSS r;
	r.h.ah=0x86;
	r.x.cx=microsec>>16;
	r.x.dx=microsec;
	int86(0x15,&r,&r);
}

drawblackdou(int x,int y)
{
	set color(0);
	circle(100+y*20,100+x*20,3);
	sum++;
	a[x][y]=1;
}

void pr()
{
	int s[15]={0,100,150,200,50,150,250,300,250,300,250,150,100,250,350};
	set color(change/10);
	set textstyle(0,0,4);
	outtextxy(20,200,"WELCOME TO OUR GAME!!");
	outtextxy(20,250,"Press Space key to");
	outtextxy(20,300,"continue...");
	sound(s[change/10]);
	
}
void DrawSnow()
{
	int i;
	int x[62];
	set inestyle(SOLID_LINE,O,THICK_WIDTH);
	line(1,1,9,9);
	line(0,5,0,5);
	line(9,1,1,9);
	save=malloc(200);
	getimage(0,0,10,10,save);
	cleardevice();
	randomize();
	for(i=0;i<62;i++)
	sx[i]=(i+2)*10;
	while(!kbhit())
	{
		Pr();
		if(snownum!=100)
		{
			snow[snownum].speed=2+random(5);
			i=random(62);
			snow[snownum].x=sx[i];
			snow[snownum].y=10-random(100);
		}
		for(i=0;i<snownum;i++)
		putimage(snow[i].x,snow[i].y,save,COPY_PUT);
		delay(100);
		cleardevice();
		Pr();
		if(snownum!=100) snownum++;
		setfillstyle(SOLID_FILL,15);
		for(i=0;i<snownum;i++)
		{
			snow[i].y+=snow[i].speed;
			putimage(snow[i].x,snow[i].y,save,COPY_PUT);
			if(snow[i].y>500) snow[i].y=10-random(200);
			 
		}
		change++;
		if(change==140)
		change=10;
	}
	nosoung();
	cleardevice();
	
}
voidInit(void)
{
	intgd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc");
	cleardevice();
	
}
begain()
{
	int i,j;
	sleep(1);
	for(i=0;i<15;i++)
	for(j=0;j<20;j++)
	if(a[i][j]==2)
	{
		setfillstyle(SOLID_FILL,BLUE);
		bar(100+j*20-10,100+i*20+10,100+j*20+10,100+i*20-10);
		
	}
	else if(a[i][j]==3)
	{
		setcolor(RED);
		circle(100+j*20,100+i*20,9);
		
	}
	else if(a[i][j]==4)
	{
		setcolor(GREEN);
		circle(100+j*20,100+i*20,9);
	}
		else if(a[i][j]==0)
		{
			setcolor(YELLOW);
			circle(100+j*20,100+i*20,3);
			
		}
		you.x=5;you.y=9;
		them[0].x=2;them[0].y=15;
		them[1].x=4;them[1].y=1;
		them[2].x=8;them[2].y=16;
		them[3].x=12;them[3].y=13;
		them[4].x=13;them[4].y=7;
}
voidmovethem(struct play *them)
{
	int i,loop;
	randomize();
	for(i=0;i<5;i++)
	{
		if(you.x==them[i].x&&(them[i].y+1)==you.y)
		them[i].y++;
		else if(you.x==them[i].x&&(them[i].y-1)==you.y)
		them[i].y--;
		else if(you.y==them[i].y&&(them[i].x-1)==you.x)
		them[i].x++;
		else if(you.y==them[i].y&&(them[i].x-1)==you.x)
		them[i].x--;
		else
		{
		loop: 
		xx[i][0]=rand()%4+1;
		if(xx[i][0]==1&&xx[i][1]==2||xx[i][0]==2&&xx[i][1]==1)
		goto loop;
		if(xx[i][0]==3&&xx[i][1]==4||xx[i][0]==4&&xx[i][1]==3)
		goto loop;
		xx[i][1]==xx[i][0];
		if(xx[i][0]==1)
		{
			them[i].x--;
			if(a[them[i].x][them[i].y]==2)
			{
				them[i].x++;
				goto loop;
			}
		}
		else if(xx[i][0]==2)
		{
				them[i].x++;
			if(a[them[i].x][them[i].y]==2)
			{
				them[i].x--;
				goto loop;
			}
		}
		
		else if(xx[i][0]==3)
		{
				them[i].y++;
			if(a[them[i].x][them[i].y]==2)
			{
				them[i].y--;
				goto loop;
			}
		}
			else if(xx[i][0]==4)
		{
				them[i].y--;
			if(a[them[i].x][them[i].y]==2)
			{
				them[i].y++;
				goto loop;
			}
		}
	}
}

