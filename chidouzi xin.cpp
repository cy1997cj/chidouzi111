#include "graphics.h"
#include "stdlib.h"
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
#define ESC 0x011b
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
 }
 snow[100];
 int snownum=0;
 struct play you,them[5];
 void *save;
 int sum=0;//�Զ��Ӹ��� 
 int change=10;
 //0douzi  1kongdi  2qiang   3ziji   4diren  
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


int xx[5][2];//���˷���Ľṹ�� 
int false=0;//��Ӯ 
void levelchoose(int x)
{
	int j,k;
	switch(x)
	{
		case 1:break;
		case 2:for(j=0;j<15;j++)
		for(k=0;k<20;k++)
		a[j][k]=b[j][k];
		break;
		case 3:for(j=0;j<15;j++)
		for(k=0;k<20;k++)
		a[j][k]=c[j][k];
		break;
		default:break;
	}
}

//������� 
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
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("X         XXXXXX   XXXXXXXX       XXX   XXXX   XXXXX   XXXXXX   XXXXX  X\n");
	printf("X  XXXXX  XXXXXX   XXXXXXX   XXX  XXX   XXXX   XXXXX   XXXXXX   XXXXX  X\n");
	printf("X  XXXXXX  XXXXX   XXXXXXX  XXXXX  XX    XX    XXXXX   XXXXXX    XXXX  X\n");
	printf("X  XXXXXX  XXXX  X  XXXXX  XXXXXX  XX    XX    XXXX  X  XXXXX    XXXX  X\n");
	printf("X  XXXXXX  XXXX  X  XXXXX  XXXXXX  XX    XX    XXXX  X  XXXXX  X  XXX  X\n");
	printf("X  XXXXXX  XXXX  X  XXXXX  XXXXXXXXXX  X XX X  XXXX  X  XXXXX  X  XXX  X\n");
	printf("X  XXXXX  XXXX  XXX  XXXX  XXXXXXXXXX  X    X  XXX  XXX  XXXX  XX  XX  X\n");
	printf("X         XXXX  XXX  XXXX  XXXXXXXXXX  X    X  XXX  XXX  XXXX  XX  XX  X\n");
	printf("X  XXXXXXXXXXX       XXXX  XXXXXX  XX  X    X  XXX       XXXX  XXX  X  X\n");
	printf("X  XXXXXXXXXX  XXXXX  XXX  XXXXXX  XX  X    X  XX  XXXXX  XXX  XXXX    X\n");
	printf("X  XXXXXXXXXX  XXXXX  XXXX  XXXX   XX  XXXXXX  XXXXX  XXX  XXXX    X\n");
	printf("X  XXXXXXXXXX  XXXXX  XXXX   XXX  XXX  XX  XXXX  XXXXX  XXX  XXXXX   X\n");
	printf("X  XXXXXXXXX  XXXXXXX  XXXX      XXXX  XX  XX     XXXXXXX  XX  XXXXX   X\n");	

}


void instruction()
{
	printf("           ******************************\n");
	printf("           *        GAME INSTRUCTIONS        *\n");
	printf("           ******************************\n");
	printf("                   WELCOME TO PACMAN WORLD!\n\n");
	printf("Press up,down,left,right to play.\n");
	printf("Press Esc to quit it.\n");
	printf("Press space to reset the game when you are playing.\n");
	printf("How to win the game:\n");
	printf("\tlf you have aten all of the yellow peans without being in the same location with the green enemy , you win !\n");
	printf("\tlf you are in the same location with the green enemy ,you lose !\n");
	printf("Please choose game level number form 1 to 3 and pres Enter key to start game :\n");
	 
}

void TimeDelay(unsigned long microsec)
{
	union REGS r;
	r.h.ah=0x86;
	r.x.cx=microsec>>16;
	r.x.dx=microsec;
	int86(0x15,&r,&r);
}

//�Զ��Ӻ��� 
drawblackdou(int x,int y)
{
	setcolor(0);
	circle(100+y*20,100+x*20,3);
	sum++;//�Ե����Ӽ�һ 
	a[x][y]=1;//�Գ���ͨƽ�� 
}

//���� 
void pr()
{
	int s[15]={0,100,150,200,50,150,250,300,250,300,250,150,100,250,350};
	setcolor(change/10);//��ӭ����ɫ 
	settextstyle(0,0,4);//����
	//�����ӭ�� 
	outtextxy(20,200,"WELCOME TO OUR GAME!!");
	outtextxy(20,250,"Press Space key to");
	outtextxy(20,300,"continue...");
	sound(s[change/10]);
	
}

//���Ŷ������� 
void DrawSnow()
{
	int i;
	int sx[62];
	setinestyle(SOLID_LINE,O,THICK_WIDTH);
	
	//������ɫѩ���������� 
	line(1,1,9,9);
	line(0,5,10,5);
	line(9,1,1,9);
	save=malloc(200);
	getimage(0,0,10,10,save);
	cleardevice();// ���� 
	randomize();//������ 
	for(i=0;i<62;i++)//ѩ��λ�� 
	sx[i]=(i+2)*10;
	
	//����������ѩ 
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
		
		//Pr���������ӭ������ 
		Pr();
		//����ѩ�� 
		if(snownum!=100) 
		snownum++;
		setfillstyle(SOLID_FILL,15);
		for(i=0;i<snownum;i++)
		{
			snow[i].y+=snow[i].speed;
			putimage(snow[i].x,snow[i].y,save,COPY_PUT);
			if(snow[i].y>500) 
			snow[i].y=10-random(200);
			 
		}
		change++;
		if(change==140)
		change=10;
	}
	nosound();
	cleardevice();
	
}

//ͼ��ϵͳ��ʼ�� 
void Init(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc");
	cleardevice();
	
}

// ��ʼ 
begain()
{
	int i,j;
	sleep(1);
	for(i=0;i<15;i++)
	for(j=0;j<20;j++)
	//ǽ 
	if(a[i][j]==2)
	{
		setfillstyle(SOLID_FILL,BLUE);
		bar(100+j*20-10,100+i*20+10,100+j*20+10,100+i*20-10);
		
	}
	//�Լ� 
	else if(a[i][j]==3)
	{
		setcolor(RED);
		circle(100+j*20,100+i*20,9);
		
	}
	//���� 
	else if(a[i][j]==4)
	{
		setcolor(GREEN);
		circle(100+j*20,100+i*20,9);
	}
	//���� 
		else if(a[i][j]==0)
		{
			setcolor(YELLOW);
			circle(100+j*20,100+i*20,3);
			
		}
		
		//�������� 
		you.x=5;
		you.y=9;
		them[0].x=2;them[0].y=15;
		them[1].x=4;them[1].y=1;
		them[2].x=8;them[2].y=16;
		them[3].x=12;them[3].y=13;
		them[4].x=13;them[4].y=7;
}

//�����ƶ�λ�� 
void movethem(struct play *them)
{
	int i,loop;
	randomize();
	for(i=0;i<5;i++)
	{
		if(you.x==them[i].x&&(them[i].y+1)==you.y)
		them[i].y++;
		else if(you.x==them[i].x&&(them[i].y-1)==you.y)
		them[i].y--;
		else if(you.y==them[i].y&&(them[i].x+1)==you.x)
		them[i].x++;
		else if(you.y==them[i].y&&(them[i].x-1)==you.x)
		them[i].x--;
		else
		{
		loop: //����ֵ 
		xx[i][0]=rand()%4+1;
		if(xx[i][0]==1&&xx[i][1]==2||xx[i][0]==2&&xx[i][1]==1)
		goto loop;
		if(xx[i][0]==3&&xx[i][1]==4||xx[i][0]==4&&xx[i][1]==3)
		goto loop;
		xx[i][1]==xx[i][0];
		if(xx[i][0]==1)//�ĸ����� 
		{
			them[i].x--;
			if(a[them[i].x][them[i].y]==2)//��ǽ����ԭ�� 
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
} 

//�����ƶ��ж� 
fun(struct play *them)
{
	int i; 
	//ɾ������ԭ��λ�� 
	setcolor(0);
	for(i=0;i<5;i++0)
	circle(them[i].y*20+100,them[i].x*20+100,9);
	movethem(them);
	
}
win()//ʤ�� 
{
	cleardevice();
	settextstyle(0,0,4);
	while(!kbhit())
	{
		setcolor(rand()%13+1);
		outtextxy(200,200,"YOU WIN!");
		delay(1000);
		
	}
}

//ʧ�� 
false1()
{
cleardevice();
settextstyle(0,0,4);
while(!kbhit())
{
	setcolor(rand()%13+1);
	outtextxy(180,200,"GAME OVER!");
	delay(1000);
	
 } 
 }
 //�ж��Ƿ�ʧ�� 
 loseyes()
 {
 	int i;
 	for(i=0;i<5;i++)
 	if(them[i].x==you.x&&them[i].y==you.y)
 	false=1;
 	
 }
 
 main()
 {
 	int gd=DETECT,gm;
 	int key,i,loop,jump;
 	int choice;
 	initgraph(&gd,&gm,"c:\\tc");
 	cleardevice();
 	DrawSnow();
 	hello();
 	getchar();
 	instruction();
 	scanf("%d",&choice);
 	levelchoose(choice);
 	getchar();
 	loop:
 		init();
 		begain();
 		while(!kbhit())
 		{
 			//�ػ����� 
 			for(i=0;i<5;i++)
 			setfillstyle(SOLID_FILL,GREEN);
 			circle(them[i].y*20+100,them[i].x*20+100,9);
 			TimeDelay(280000);
 			for(i=0;i<5;i++)
 			if(them[i].x==you.x&&them[i].y==you.y)
 			false=1;
 			loseyes();//�ж��Ƿ�ʧ�� 
 			if(false)
 			break;
 			key=bioskey(0);
 			setcolor(0);//ɾ���Լ�ԭ����λ�� 
 			circle(100+you.y*20,100+you.x*20,9);
 			fun(them);//�������
			  
 			if(key==ESC)
 			break;
 			if (key==SPACE)//SPACE���¿�ʼ 
 			goto loop;
 			
 			//�ж��Ƿ�Ե����������� 
 			else if(key==UP)
 			{
 				you.x--;
 				if(a[you.x][you.y]==2)
 				you.x++;
 				else if(a[you.x][you.y]==0)
 				drawblackdou(you.x,you.y);
 				
			 }
			 else if(key==DOWN)
			 {
			 	you.x++;
				 if(a[you.x][you.y]==2)
				 you.x--;
				 else if(a[you.x][you.y]==0)
				 drawblackdou(you.x,you.y);
			 }
			 else if(key==RIGHT)
			 {
			 	you.y++;
				 if(a[you.x][you.y]==2)
				 you.y--;
				 else if(a[you.x][you.y]==0)
				 drawblackdou(you.x,you.y);
			 }
			 else if(key==LEFT)
			 {
			 	you.y--;
				 if(a[you.x][you.y]==2)
				 you.y++;
				 else if(a[you.x][you.y]==0)
				 drawblackdou(you.x,you.y);
			 }
			 if(sum==50)
			 break;
			 //�ٴλ����Լ���λ�� 
			 setcolor(RED);
			 circle(100+you.y*20,100+you.x*20,9);
			 for(i=0;i<5;i++)
			 {
			 	setcolor(GREEN);
			 	circle(them[i].y*20+100,them[i].x*20+100,9);
			 	
			 }
			 setcolor(RED);
			 //�ж��Լ��Ƿ��������� 
			 loseyes();
			 if(false)
			 break;
		 }
		 
		 //�������ӻ�ʤ 
		 if(sum==50)
		 
		 	{
			 win();
			 getch();
		 	} 
		 
		 if(false)
		 {
		 	false1();
		 	getch();
		 	
		 }
		 closegraph();
 }
