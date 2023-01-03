#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;
struct Toxay
{
	int x;
	int y;
};
struct payler
{
	Toxay xy[999];
	int see;
};
struct Maper
{
	char open[12][12];
};
void ChuSHiHua(Maper *map)
{
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			map->open[i][j]=' ';
		}
	}
	return ;
}
int ZhuCaiDan()
{
	int Butr=2;
	while(true)
	{
	 string CaiDan[10][10];
	 CaiDan[1][3]="TicTacTOE";
	 CaiDan[2][1]="MultiplayerGame";
	 CaiDan[3][1]="AiBattle";
	 CaiDan[4][1]="Set";
	 CaiDan[5][1]="Esc";
	 CaiDan[Butr][2]="*";
	 for(int i=0;i<10;i++)
	 {
		 for(int j =0;j<10;j++)
		 {
			 cout << CaiDan[i][j];
		 }
		 cout << endl;
	 }
	 if(getch()=='w')
	 {
		 Butr--;
	 }
	 if(getch()=='s')
	 {
		 Butr++;
	 }
	 if(getch()==13)
	 {
		 system("cls");
		 return Butr;
	 }
	 system("cls");
	}
}
void DingHuaDuoRen()
{
	for(int i=0;i<=100;i++)
	{
		system("cls");
		cout << i << "......Loding";
		Sleep(10);
	}
	cout << "\nMulti player Game" << endl;
	Sleep(2000);
	system("cls");
	return ;
}
void DiTuZuoHua(Maper *m)
{
	for(int i=0;i<12;i++)
	{
	   m->open[i][3]='$';
	   m->open[i][8]='$';
	   m->open[3][i]='$';
	   m->open[8][i]='$';
	}
	return ;
}
int CaiPan(payler *p,int a1,int a2)
{
	for(int i=0;i<p->see;i++)
	{
		if(p->xy[i].y==a1)
		{
			if(p->xy[i].x==a2)
			{
				return 1024;
			}
		}
	}
	return  0;
}
int TheWin(Maper *m)
{
	int a1=1,a2=5,a3=10;
	if(m->open[a1][a1]==m->open[a2][a1]&&m->open[a1][a1]==m->open[a3][a1])
	{if(m->open[a1][a1]==' '){goto Q1;}
		return 1902;}
	Q1:
	if(m->open[a1][a1]==m->open[a2][a2]&&m->open[a1][a1]==m->open[a3][a3])
	{if(m->open[a1][a1]==' '){goto Q2;}
		return 1902;}
	Q2:
	if(m->open[a1][a1]==m->open[a1][a2]&&m->open[a1][a1]==m->open[a1][a3])
	{if(m->open[a1][a1]==' '){goto Q3;}
		return 1902;}
	Q3:
	if(m->open[a1][a2]==m->open[a2][a2]&&m->open[a1][a2]==m->open[a3][a2])
	{if(m->open[a1][a2]==' '){goto Q4;}
		return 1902;}
	Q4:
	if(m->open[a1][a3]==m->open[a2][a3]&&m->open[a1][a3]==m->open[a3][a3])
	{if(m->open[a1][a3]==' '){goto Q5;}
		return 1902;}
	Q5:
	if(m->open[a2][a1]==m->open[a2][a2]&&m->open[a2][a1]==m->open[a2][a3])
	{if(m->open[a2][a1]==' '){goto Q6;}
		return 1902;}
	Q6:
	if(m->open[a3][a1]==m->open[a3][a2]&&m->open[a3][a1]==m->open[a3][a3])
	{if(m->open[a3][a1]==' '){goto Q7;}
		return 1902;}
	Q7:
	return 0;
}
void DuoRenPk(payler *p,Maper *m)
{
	DingHuaDuoRen();
	 DiTuZuoHua(&*m);
	 int a1,a2,caip=0,win=0;
	 p->see=1;
	while(true)
	{
		for(int i=0;i<12;i++)
		{
			for(int i1=0;i1<12;i1++)
			{
				cout << m->open[i][i1];
			}
			cout << endl;
		}
		cin >> a1;
		cin >> a2;
		if(a1==2)
		{
			a1=5;
		}
		if(a1==3)
		{
			a1=10;
		}
		if(a2==2)
		{
			a2=5;
		}
		if(a2==3)
		{
			a2=10;
		}
		p->xy[p->see].x=a2,p->xy[p->see].y=a1;
		if(p->see%2==0)
		{
			m->open[p->xy[p->see].y][p->xy[p->see].x]='X';
		}else{m->open[p->xy[p->see].y][p->xy[p->see].x]='O';}
		caip=CaiPan(&*p,a1,a2);
		if(caip==1024)
		{
			getch();
			system("cls");
			cout<< "You Lost[Repeated The Flag]"<<endl;
			return ;
		}
		win=TheWin(&*m);
		if(win==1902)
		{
			getch();
			system("cls");
			cout<< "You Win"<<endl;
     		return ;
		}
		p->see++;
		system("cls");
	}
	
}
void AiSped(payler *p,Maper *m)
{
	Alpe:
	int c2=1+rand()%3;
	int c1=1+rand()%3;
	if(c2==2){c2=5;}
	if(c2==3){c2=10;}
		if(c1==2){c1=5;}
			if(c1==3){c1=10;}
			if(m->open[c2][c1]=='O')
			{
				goto Alpe;
			}else{p->xy[p->see].x=c2,p->xy[p->see].y=c1;}
			m->open[p->xy[p->see].x][p->xy[p->see].y]='X';
			p->see++;
}
void ToAiBatol(payler *p,Maper *m)
{
	DiTuZuoHua(&*m);
	int a1,a2,caip=0,win=0;
	p->see=1;
	while(true)
	{
	 for(int i=0;i<12;i++)
	 {
		for(int i1=0;i1<12;i1++)
		{
			cout << m->open[i][i1];
		}
		cout << endl;
	 }
	 cin >> a1;
	 cin >> a2;
	 if(a1==2)
	 {
		a1=5;
	 }
	 if(a1==3)
	 {
		a1=10;
	 }
	 if(a2==2)
	 {
		a2=5;
	 }
	 if(a2==3)
	 {
		a2=10;
	 }
	  p->xy[p->see].x=a2,p->xy[p->see].y=a1;
	  if(p->see%2==0)
	 {
		m->open[p->xy[p->see].y][p->xy[p->see].x]='X';
	 }else{m->open[p->xy[p->see].y][p->xy[p->see].x]='O';}
	 caip=CaiPan(&*p,a1,a2);
	 if(caip==1024)
	 {
		 getch();
		system("cls");
		cout<< "You Lost[Repeated The Flag]"<<endl;
		return ;
	 }
	 win=TheWin(&*m);
	 if(win==1902)
	 {
		 getch();
		system("cls");
		cout<< "You Win"<<endl;
		return ;
	 }
	 p->see++;
	 system("cls");
	 AiSped(&*p,&*m);
    }
}
int main()
{
	int Gherd;
    payler ply;
	Maper map;
	ChuSHiHua(&map);
	Gherd=ZhuCaiDan();
	switch (Gherd) {
	case 2:
		system("cls");
		DuoRenPk(&ply,&map);
		break;
	case 3:
		system("cls");
		ToAiBatol(&ply,&map);
		break;
	case 4:
		cout << "Optimizing<@_@?>" << endl;
		getch();
		return 0;
		break;
	case 5:
		cout << "Thanks For Using<@_@?>" << endl;
		getch();
		return 0;
		break;
	default:
		break;
	}
}
