#include "MiniGame2.h"
int OTN[9]={1,2,3,4,5,6,7,8,9};

int NumGame(BOOL User_Select, BOOL User_Select2)
{
	clrsc();

	//1~9陛 緒腦啪爾罹颶
	//縛攪酈殮溘
	//摹鷗脹璋濠蒂爾罹邀
	//闡У攪曖璋濠陛釭褥
	//唸婁っ滌
	static int nPlay=0;
	BOOL bUserChoice=FALSE;

	int i=0,Comnum,Playernum;
	int WhoWin=0;
	fflush(stdin);
	numgameintro();//檣お煎



	do{
		if(User_Select==TRUE){
			CONSOLE_CURSOR_INFO CurInfo; //醴憮 橈擁晦
			CurInfo.dwSize=1;
			CurInfo.bVisible=FALSE;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
			clrsc();
			numgamemap(User_Select, User_Select2);//啪歜�飛�
			Playernum=userselect2();	Comnum=comselect2();

			WhoWin=ThinkResult(Playernum, Comnum, User_Select, User_Select2);
			Sleep(500);
		}
		else if(User_Select2==TRUE){
			CONSOLE_CURSOR_INFO CurInfo; //醴憮 橈擁晦
			CurInfo.dwSize=1;
			CurInfo.bVisible=FALSE;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
			clrsc();
			numgamemap(User_Select, User_Select2);//啪歜�飛�
			Playernum=userselect2_2();	Comnum=comselect2_2();

			WhoWin=ThinkResult(Playernum, Comnum, User_Select, User_Select2);
			Sleep(500);
		}
	}while(WhoWin==0);
	ShowResult(WhoWin, User_Select, User_Select2);
	Sleep(1000);
	clrsc();
	return WhoWin;
	
}

int userselect2()
{
	char select=FALSE;
	int Player=1;
	int i;
	
	while(select!=ENTER)
	{
		i=(rand()*17)%9+1;
		switch(i)
		{
		case 1 : Print1(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 2 : Print2(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 3 : Print3(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 4 : Print4(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 5 : Print5(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 6 : Print6(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 7 : Print7(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 8 : Print8(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 9 : Print9(5+(Player-1)*40,7,Player); Sleep(50); break;
		}
		
		if(_kbhit())
		{
			select=_getch();
			if(select==ENTER)
				break;
			
		}
		
	}
	return i;
}

int userselect2_2()
{
	char select=FALSE;
	int Player=2;
	int i;
	

	while(select!=ENTER)
	{
		i=(rand()*17)%9+1;
		switch(i)
		{
		case 1 : Print1(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 2 : Print2(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 3 : Print3(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 4 : Print4(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 5 : Print5(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 6 : Print6(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 7 : Print7(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 8 : Print8(5+(Player-1)*40,7,Player); Sleep(50); break;
		case 9 : Print9(5+(Player-1)*40,7,Player); Sleep(50); break;
		}
		
		if(_kbhit())
		{
			select=_getch();
			if(select==ENTER)
				break;
			
		}
		
	}
	return i;
}
int comselect2()
{
	int i;
	i=rand()%9+1;
	int Player=2;
	
		switch(i){
			case 1: Print1(5+(Player-1)*40,7,Player);
				break;
			case 2: Print2(5+(Player-1)*40,7,Player);
				break;
			case 3: Print3(5+(Player-1)*40,7,Player);
				break;				
			case 4: Print4(5+(Player-1)*40,7,Player);
				break;
			case 5: Print5(5+(Player-1)*40,7,Player); 
				break;
			case 6: Print6(5+(Player-1)*40,7,Player);
				break;
			case 7: Print7(5+(Player-1)*40,7,Player);
				break; 
			case 8: Print8(5+(Player-1)*40,7,Player);
				break;
			case 9: Print9(5+(Player-1)*40,7,Player);
				break;
		}
	
	return i;
}

int comselect2_2()
{
	int i;
	i=rand()%9+1;
	int Player=1;
	
		switch(i){
			case 1: Print1(5+(Player-1)*40,7,Player);
				break;
			case 2: Print2(5+(Player-1)*40,7,Player);
				break;
			case 3: Print3(5+(Player-1)*40,7,Player);
				break;				
			case 4: Print4(5+(Player-1)*40,7,Player);
				break;
			case 5: Print5(5+(Player-1)*40,7,Player); 
				break;
			case 6: Print6(5+(Player-1)*40,7,Player);
				break;
			case 7: Print7(5+(Player-1)*40,7,Player);
				break; 
			case 8: Print8(5+(Player-1)*40,7,Player);
				break;
			case 9: Print9(5+(Player-1)*40,7,Player);
				break;
		}
	
	return i;
}
void Print1(int x,int y,int Player)
{
int i;
	char S[][10][40]={{
					"               忙式忖    \n",
					"               /   弛    \n",
					"            忙戎   弛    \n",
					"            戌 忖  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"             忙戎  戌忖  \n",
					"             戌式式式戎  \n"
					},
					{
					"               忙式忖    \n",
					"               /   弛    \n",
					"            忙戎   弛    \n",
					"            戌 忖  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"               弛  弛    \n",
					"             忙戎  戌忖  \n",
					"             戌式式式戎  \n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print2(int x,int y,int Player)
{
int i;
	char S[][10][40]={{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"	     忙式式式式式戎  弛\n",
					"        弛  忙式式式式式戎\n",
					"        弛  弛            \n",
					"        弛  戌式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"	     忙式式式式式戎  弛\n",
					"        弛  忙式式式式式戎\n",
					"        弛  弛            \n",
					"        弛  戌式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					} 
					
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print3(int x,int y,int Player)
{
int i;
	char S[][10][40]={{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"        忙式式式式式戎  弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"        忙式式式式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n",
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"        忙式式式式式戎  弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"        忙式式式式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n",
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print4(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
					"              式式忖       \n",
					"            /     弛	    \n",
					"           /  ��  弛       \n",
					"          /  / 弛 弛       \n",
					"         弛 /  弛 弛       \n",
					"         弛戌式戎 戌式忖   \n",
					"         戌式式忖 忙式戎   \n",
					"               弛 弛       \n",
					"               弛 弛       \n",
					"               戌-戎       \n"
					},
					{
					"              式式忖       \n",
					"            /     弛	    \n",
					"           /  ��  弛       \n",
					"          /  / 弛 弛       \n",
					"         弛 /  弛 弛       \n",
					"         弛戌式戎 戌式忖   \n",
					"         戌式式忖 忙式戎   \n",
					"               弛 弛       \n",
					"               弛 弛       \n",
					"               戌-戎       \n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print5(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式式式戎\n",
					"        弛    弛          \n",
					"        弛    戌式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"        忙式式式式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式式式戎\n",
					"        弛    弛          \n",
					"        弛    戌式式式式忖\n",
					"        弛              弛\n",
					"        戌式式式式式忖  弛\n",
					"        忙式式式式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print6(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
				    "        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式式式戎\n",
					"        弛    弛          \n",
					"        弛    戌式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式忖  弛\n",
					"        弛    戌式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式式式戎\n",
					"        弛    弛          \n",
					"        弛    戌式式式式忖\n",
					"        弛              弛\n",
					"        弛    忙式式忖  弛\n",
					"        弛    戌式式戎  弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print7(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
					"        忙式式式式-忖    \n",
					"        弛         弛    \n",
					"        弛 忙-式忖 弛    \n",
					"        戌-戎   弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                戌-戎    \n"
					},
					{
					"        忙式式式式-忖    \n",
					"        弛         弛    \n",
					"        弛 忙-式忖 弛    \n",
					"        戌-戎   弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                弛 弛    \n",
					"                戌-戎    \n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print8(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛              弛\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        弛              弛\n",
					"        戌式式式式式式式戎\n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}
void Print9(int x,int y,int Player)
	{
int i;
	char S[][10][40]={{
					"        忙式式式式式式式忖\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    戌式戎\n"
					},
					{
					"        忙式式式式式式式忖\n",
					"        弛   忙式式忖   弛\n",
					"        弛   弛    弛   弛\n",
					"        弛   戌式式戎   弛\n",
					"        戌式式式式式忖  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    弛  弛\n",
					"                    戌式戎\n"
					}
	};
	
	for(i=0;i<10;i++)
	{
	SetCurPos(x,y+i);
	printf("%s",S[Player-1][i]);
	}
}

int ThinkResult(int Playernum, int Comnum, BOOL User_Select, BOOL User_Select2)
{
	int win;
	if(Playernum==9)
	{
		if(Comnum==1)
			win=2;
		else if((1<Comnum)&&(Comnum<9))
			win=1;
		else
			win=0;
	}
	else if(Playernum==1)
	{
		if(Comnum==9)
			win=1;
		else if((1<Comnum)&&(Comnum<9))
			win=2;
		else
			win=0;
	}
	else
		if(Comnum<Playernum)
			win=1;
		else if(Comnum>Playernum)
			win=2;
		else
			win=0;

		if((User_Select==TRUE)&&(win==1))
			return 1;
		else if((User_Select==TRUE)&&(win==2))
			return 2;
		else if((User_Select2==TRUE)&&(win==1))
			return 2;
		else if((User_Select2==TRUE)&&(win==2))
			return 1;
		else
			return 0;
}


void numgameintro()
{
	int i,result,nKey=1;
	for(i=1; i<10; i++)
	{
		switch(i){
		case 1 : Better_printf("1",35,11,7); break;
		case 2 : Better_printf("2",55,11,9); break;
		case 3 : Better_printf("3",15,11,10); break;
		case 4 : Better_printf("4",35,19,11); break;
		case 5 : Better_printf("5",35,3,12); break;
		case 6 : Better_printf("6",45,17,13); break;
		case 7 : Better_printf("7",25,17,14); break;
		case 8 : Better_printf("8",45,7,15); break;
		case 9 : Better_printf("9",25,7,10); break;
		}
		result=IntroSkip(nKey);
		Sleep(200*result);
	}
	for(i=1; i<5; i++)
	{
		switch(i){
		case 1 : Better_printf("璋濠啪歜殮棲棻.",29,9,15); break;
		case 2 : Better_printf("璋濠陛 緒腦啪爾罹韓陽.",26,10,15); break;
		case 3 : Better_printf("縛攪酈煎 堅腦衛賊腌棲棻.",25,11,15); break;
		case 4 : Better_printf("璋濠陛 堪戲賊 檜梢棲棻.",26,12,15); break;
		case 5 : Better_printf("欽, 1擎9蒂 檜望熱氈蝗棲棻..",24,13,15); break;
		}
		result=IntroSkip(nKey);
		Sleep(500*result);
	}

	Sleep(1000);
	int t;
		t=clock();
	for(i=0;i<40;i++){
		if(clock()-t>50)
			break;
		Better_printf("縛攪酈蒂 援腦賊 衛濛м棲棻",25,14,15);
		getchar();
	}
	clrsc();
}

void numgamemap(BOOL User_Select, BOOL User_Select2)
{
	int i;

	Better_printf("忙式式式式式式式式式式式式式式式式式成成式式式式式式式式式式式式式式式式式忖",1,1,15);
	
	for(i=2;i<21;i++)

	{
	Better_printf("弛",1,i,15);
	Better_printf("弛弛",37,i,15);
	Better_printf("弛",75,i,15);
	}
	Better_printf("戌式式式式式式式式式式式式式式式式式扛扛式式式式式式式式式式式式式式式式式戎",1,21,15);
	if(User_Select==TRUE){
	Better_printf("Ы溯檜橫 璋濠",12,3,15);
	Better_printf("闡У攪 璋濠",53,3,15);
	}
	else if(User_Select2==TRUE){
	Better_printf("闡У攪 璋濠",12,3,15);
	Better_printf("Ы溯檜橫 璋濠",53,3,15);
	}
	//罹晦梱雖 裘
}