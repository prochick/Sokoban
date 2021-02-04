#include<iostream>
#include<cstdlib>
#include<conio.h>
#define Maplen 9
#define Mapwid 8
using namespace std;
char map[Mapwid][Maplen];//定义关卡地图的大小 
int a,b;//记录小人的位置 

void ReadTxt(int cnt,int *a,int *b);//读游戏关卡相应的地图文件
void ReadMap(int *a,int *b);//将地图打印在屏幕上 
int MainMenu();//主菜单 
void Help();//说明书 
void ChildMenu();//二级菜单 
void ThreeMenu();//三级菜单 
int Play(int cnt);//游戏规则 
int Up(int *a,int *b);//小人向上移动 
int Down(int *a,int *b);//小人向下移动
int Left(int *a,int *b);//小人向左移动
int Right(int *a,int *b);//小人向右移动

main()
{
	system("color 6");
	int flag=0;
	while(flag!=4)/*当flag=4是表示用户选择了退出游戏*/
	{
		system("cls");
		flag=MainMenu();
		if(flag==4)
		cout<<"您已成功退出！"<<endl;
	}
} 

void ReadTxt(int cnt,int *a,int *b) 
{
	FILE *fp;
	char c;
	int i=0,j=0;
	switch(cnt)
	{
		case 1:
			if((fp=fopen("关卡1.txt","r"))==NULL)
			{
				cout<<"文件读取失败！"<<endl;
				exit(1); 
			}	
			break;
		case 2:
			if((fp=fopen("关卡2.txt","r"))==NULL)
			{
				cout<<"文件读取失败！"<<endl;
				exit(1); 
			}	
			break;
		case 3:
			if((fp=fopen("关卡3.txt","r"))==NULL)
			{
				cout<<"文件读取失败！"<<endl;
				exit(1); 
			}	
			break;
		case 4:
			if((fp=fopen("关卡4.txt","r"))==NULL)
			{
				cout<<"文件读取失败！"<<endl;
				exit(1); 
			}	
			break;
		case 5:
			if((fp=fopen("关卡5.txt","r"))==NULL)
			{
				cout<<"文件读取失败！"<<endl;
				exit(1); 
			}	
			break;
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		if(c=='0')
		{
			map[i][j]=c;
			*a=i;
			*b=j;
		}
		else
			map[i][j]=c;
		j++;
		if(j==Maplen)
		{
			i++;
			j=0;
		}
		c=fgetc(fp);
	}
	fclose(fp);
}

void ReadMap(int *a,int *b)
{
	int i,j;
	system("cls");
	for(i=0;i<Mapwid;i++)
	{
		for(j=0;j<Maplen;j++)
		{
			if(map[i][j]=='0')
			{
				cout << "♀";
				*a=i;
				*b=j;
			}
			else if(map[i][j]=='1')
			{   
				cout << "★";
			}
			else if(map[i][j]=='2')
			{
				cout << "◎";
			}
			else if(map[i][j]=='3')
			{
				cout << "  ";
			}
			else if(map[i][j]=='4')
			{
				cout << "■";
			}
			else
			{
				putchar(map[i][j]);
			}
		}
	}
	cout << endl;
}

int MainMenu()
{
	int i;
	cout<<"-------------------------------------"<<endl;
	cout<<"              游戏菜单               "<<endl;
	cout<<"           1、闯关模式               "<<endl;
	cout<<"           2、关卡模式               "<<endl;
	cout<<"           3、说明帮助               "<<endl;
	cout<<"           4、退出游戏               "<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"请选择："<<endl;
	cin>>i;
	switch(i)
	{
		case 1:
			{
				int level=1,loop;
				while(level<=5)
				{
					loop=Play(level);
					if(loop==0)
					break;
					level++;
				}
				if(level<=5)
				cout<<"通关失败！共成功通过"<<level-1<<"关";
				else
				cout<<"恭喜你通关成功！"; 
				break;
			}
		case 2:
			{
				ChildMenu();
				break;
			}
		case 3:
			{
				Help();
				system("pause"); 
				break;
			}
		case 4:
			{
				break;
			}
	}
	return i;
	
}

void Help()
{
	system("cls");
	    cout<<"-----------------------------------"<<endl;
		cout<<"           ♀: 代表小人            "<<endl;
		cout<<"           ★: 代表箱子            "<<endl;
		cout<<"           ◎: 代表洞穴            "<<endl;
		cout<<"           ■: 代表墙壁            "<<endl;
		cout<<"       w/W/↑: 向上移动            "<<endl;
		cout<<"       s/S/↓: 向下移动            "<<endl;
		cout<<"       a/A/←: 向左移动            "<<endl;
		cout<<"       d/D/→: 向右移动            "<<endl;
		cout<<"请你移动小人把每个箱子推进洞穴里去 "<<endl;
		cout<<"-----------------------------------"<<endl;
}

void ChildMenu()
{
	int i;
	do{	
		system("cls");
		cout<<"-----------------------------------"<<endl;
		cout<<"            关卡选择               "<<endl;
		cout<<"           1、第一关               "<<endl;
		cout<<"           2、第二关               "<<endl;
		cout<<"           3、第三关               "<<endl;
		cout<<"           4、第四关               "<<endl;
		cout<<"           5、第五关               "<<endl;
		cout<<"           6、返回上一级           "<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"请选择："<<endl;
		cin>>i;
		switch(i)
		{
			case 1:
				{
					Play(1);
					break;
				}
			case 2:
				{
					Play(2);
					break;
				}
			case 3:
				{
					Play(3);
					break;
				}
			case 4:
				{
					Play(4);
					break;
				}
			case 5:
				{
					Play(5);
					break;
				}
		}
	}while(i!=6);
}

void ThreeMenu()
{
	cout<<"------------------------------------------------"<<endl;
	cout<<"               按R：重玩此关卡                  "<<endl; 
	cout<<"               按E：返回上一级                  "<<endl;
	cout<<"------------------------------------------------"<<endl;
}

int Play(int cnt)
{
	int jump,loop;
	do
	{
		jump=1;
		system("cls");
		loop=0;//用于判断是否闯关成功 
		ReadTxt(cnt,&a,&b);
		ReadMap(&a,&b);
		ThreeMenu();
		
		char ch;
		int step=0;
		while(1)
		{
			ch=getch();
			switch(ch)
			{
			  case 'w':
	          case 'W':
	          case  72:
				  {
					  step+=Up(&a,&b);
					  break;
				  }
			  case 'a':
			  case 'A':
			  case  75:
				  {
					  step+=Left(&a,&b);
					  break;
				  }
			  case 's':
			  case 'S':
			  case  80:
				  {
					  step+=Down(&a,&b);
					  break;
				  }
			  case 'd':
			  case 'D':
			  case  77:
				  {
					  step+=Right(&a,&b);
					  break;
				  }
			}
			switch(cnt)//判断洞是否被占用 
			{
				case 1:
					if(map[1][3]=='3')
					map[1][3]='2';
					if(map[3][6]=='3')
					map[3][6]='2';
					if(map[4][1]=='3')
					map[4][1]='2';
					if(map[6][4]=='3')
					map[6][4]='2';
					break;
				case 2:
					if(map[1][3]=='3')
					map[1][3]='2';
					if(map[1][4]=='3')
					map[1][4]='2';
					if(map[2][4]=='3')
					map[2][4]='2';
					if(map[3][5]=='3')
					map[3][5]='2';
					break;
				case 3:
					if(map[2][2]=='3')
					map[2][2]='2';
					if(map[3][2]=='3')
					map[3][2]='2';
					if(map[3][3]=='3')
					map[3][3]='2';
					break;
				case 4:
					if(map[1][1]=='3')
					map[1][1]='2';
					if(map[1][5]=='3')
					map[1][5]='2';
					if(map[3][5]=='3')
					map[3][5]='2';
					break;
				case 5:
					if(map[3][3]=='3')
					map[3][3]='2';
					if(map[3][2]=='3')
					map[3][2]='2';
					if(map[3][5]=='3')
					map[3][5]='2';
					if(map[5][5]=='3')
					map[5][5]='2';
					break;
			}
			ReadMap(&a,&b);
			ThreeMenu();
				
			switch(cnt)//判断是否胜利 
			{
				case 1:
					if(map[1][3]=='1'&&map[3][6]=='1'&&map[4][1]=='1'&&map[6][4]=='1') 
					loop=1;
					break;
				case 2:
					if(map[1][3]=='1'&&map[1][4]=='1'&&map[2][4]=='1'&&map[3][5]=='1') 
					loop=1;
					break;
				case 3:
					if(map[2][2]=='1'&&map[3][2]=='1'&&map[3][3]=='1') 
					loop=1;
					break;
				case 4:
					if(map[1][1]=='1'&&map[1][5]=='1'&&map[3][5]=='1') 
					loop=1;
					break;
				case 5:
					if(map[3][2]=='1'&&map[3][3]=='1'&&map[3][5]=='1'&&map[5][5]=='1') 
					loop=1;
					break;
			}	
			if(loop==1)
			{
				cout<<"恭喜第"<<cnt<<"关成功!"<<"共用"<<step<<"步"<<endl;
				system("pause");
				break;
			}
			if(ch=='E'||ch=='e')
			break;
			if(ch=='r'||ch=='R')
			{
				jump=0;
				break;
			}
		}
	}while(jump==0);
	
	return loop;
}

int Up(int *a,int *b)
{
	if(map[*a-1][*b]=='3'||map[*a-1][*b]=='2')
	{
		map[*a-1][*b]='0';
		map[*a][*b]='3';
		return 1;
	}
	
	if(map[*a-1][*b]=='1'&&(map[*a-2][*b]=='3'||map[*a-2][*b]=='2'))
	{
		map[*a-2][*b]='1';
		map[*a-1][*b]='0';
		map[*a][*b]='3';
		return 1;
	}
	return 0;
} 

int Down(int *a,int *b)
{
	if(map[*a+1][*b]=='3'||map[*a+1][*b]=='2')
	{
		map[*a+1][*b]='0';
		map[*a][*b]='3';
		return 1;
	}
	
	if(map[*a+1][*b]=='1'&&(map[*a+2][*b]=='3'||map[*a+2][*b]=='2'))
	{
		map[*a+2][*b]='1';
		map[*a+1][*b]='0';
		map[*a][*b]='3';
		return 1;
	}
	return 0;
}

int Left(int *a,int *b)
{
	if(map[*a][*b-1]=='3'||map[*a][*b-1]=='2')
	{
		map[*a][*b-1]='0';
		map[*a][*b]='3';
		return 1;
	}
	
	if(map[*a][*b-1]=='1'&&(map[*a][*b-2]=='3'||map[*a][*b-2]=='2'))
	{
		map[*a][*b-2]='1';
		map[*a][*b-1]='0';
		map[*a][*b]='3';
		return 1;
	}
	return 0;
}

int Right(int *a,int *b)
{
	if(map[*a][*b+1]=='3'||map[*a][*b+1]=='2')
	{
		map[*a][*b+1]='0';
		map[*a][*b]='3';
		return 1;
	}
	
	if(map[*a][*b+1]=='1'&&(map[*a][*b+2]=='3'||map[*a][*b+2]=='2'))
	{
		map[*a][*b+2]='1';
		map[*a][*b+1]='0';
		map[*a][*b]='3';
		return 1;
	}
	return 0;
}
