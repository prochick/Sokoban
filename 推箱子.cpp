#include<iostream>
#include<cstdlib>
#include<conio.h>
#define Maplen 9
#define Mapwid 8
using namespace std;
char map[Mapwid][Maplen];//����ؿ���ͼ�Ĵ�С 
int a,b;//��¼С�˵�λ�� 

void ReadTxt(int cnt,int *a,int *b);//����Ϸ�ؿ���Ӧ�ĵ�ͼ�ļ�
void ReadMap(int *a,int *b);//����ͼ��ӡ����Ļ�� 
int MainMenu();//���˵� 
void Help();//˵���� 
void ChildMenu();//�����˵� 
void ThreeMenu();//�����˵� 
int Play(int cnt);//��Ϸ���� 
int Up(int *a,int *b);//С�������ƶ� 
int Down(int *a,int *b);//С�������ƶ�
int Left(int *a,int *b);//С�������ƶ�
int Right(int *a,int *b);//С�������ƶ�

main()
{
	system("color 6");
	int flag=0;
	while(flag!=4)/*��flag=4�Ǳ�ʾ�û�ѡ�����˳���Ϸ*/
	{
		system("cls");
		flag=MainMenu();
		if(flag==4)
		cout<<"���ѳɹ��˳���"<<endl;
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
			if((fp=fopen("�ؿ�1.txt","r"))==NULL)
			{
				cout<<"�ļ���ȡʧ�ܣ�"<<endl;
				exit(1); 
			}	
			break;
		case 2:
			if((fp=fopen("�ؿ�2.txt","r"))==NULL)
			{
				cout<<"�ļ���ȡʧ�ܣ�"<<endl;
				exit(1); 
			}	
			break;
		case 3:
			if((fp=fopen("�ؿ�3.txt","r"))==NULL)
			{
				cout<<"�ļ���ȡʧ�ܣ�"<<endl;
				exit(1); 
			}	
			break;
		case 4:
			if((fp=fopen("�ؿ�4.txt","r"))==NULL)
			{
				cout<<"�ļ���ȡʧ�ܣ�"<<endl;
				exit(1); 
			}	
			break;
		case 5:
			if((fp=fopen("�ؿ�5.txt","r"))==NULL)
			{
				cout<<"�ļ���ȡʧ�ܣ�"<<endl;
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
				cout << "��";
				*a=i;
				*b=j;
			}
			else if(map[i][j]=='1')
			{   
				cout << "��";
			}
			else if(map[i][j]=='2')
			{
				cout << "��";
			}
			else if(map[i][j]=='3')
			{
				cout << "  ";
			}
			else if(map[i][j]=='4')
			{
				cout << "��";
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
	cout<<"              ��Ϸ�˵�               "<<endl;
	cout<<"           1������ģʽ               "<<endl;
	cout<<"           2���ؿ�ģʽ               "<<endl;
	cout<<"           3��˵������               "<<endl;
	cout<<"           4���˳���Ϸ               "<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"��ѡ��"<<endl;
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
				cout<<"ͨ��ʧ�ܣ����ɹ�ͨ��"<<level-1<<"��";
				else
				cout<<"��ϲ��ͨ�سɹ���"; 
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
		cout<<"           ��: ����С��            "<<endl;
		cout<<"           ��: ��������            "<<endl;
		cout<<"           ��: ����Ѩ            "<<endl;
		cout<<"           ��: ����ǽ��            "<<endl;
		cout<<"       w/W/��: �����ƶ�            "<<endl;
		cout<<"       s/S/��: �����ƶ�            "<<endl;
		cout<<"       a/A/��: �����ƶ�            "<<endl;
		cout<<"       d/D/��: �����ƶ�            "<<endl;
		cout<<"�����ƶ�С�˰�ÿ�������ƽ���Ѩ��ȥ "<<endl;
		cout<<"-----------------------------------"<<endl;
}

void ChildMenu()
{
	int i;
	do{	
		system("cls");
		cout<<"-----------------------------------"<<endl;
		cout<<"            �ؿ�ѡ��               "<<endl;
		cout<<"           1����һ��               "<<endl;
		cout<<"           2���ڶ���               "<<endl;
		cout<<"           3��������               "<<endl;
		cout<<"           4�����Ĺ�               "<<endl;
		cout<<"           5�������               "<<endl;
		cout<<"           6��������һ��           "<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"��ѡ��"<<endl;
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
	cout<<"               ��R������˹ؿ�                  "<<endl; 
	cout<<"               ��E��������һ��                  "<<endl;
	cout<<"------------------------------------------------"<<endl;
}

int Play(int cnt)
{
	int jump,loop;
	do
	{
		jump=1;
		system("cls");
		loop=0;//�����ж��Ƿ񴳹سɹ� 
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
			switch(cnt)//�ж϶��Ƿ�ռ�� 
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
				
			switch(cnt)//�ж��Ƿ�ʤ�� 
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
				cout<<"��ϲ��"<<cnt<<"�سɹ�!"<<"����"<<step<<"��"<<endl;
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
