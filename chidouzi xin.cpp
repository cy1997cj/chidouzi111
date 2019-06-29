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
	printf("XXXXXXXXXXXX??XXXXXXXXXXXXX????????????????XXXXXXXXXXXXXXX??XXXXXXXXXXXX\n");?
	printf("X???????XXX??????????XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX??XXXXXXXXXXXX\n");?
	printf("X??XXX?
?
XX?
?
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX??
XXXXXXXXXXXX\n");?

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
