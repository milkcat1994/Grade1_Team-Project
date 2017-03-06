#include "MainSource.h"

void main ()
{
	Intro();
	MainGame();
}

int MainGame()
{
	int Player=1, Player2=1;
	int Turn=1, PTurn=1, ATurn=1;				//게임 턴
	Land[0][0]=1; Land[4][4]=2;
	while((Player<12)||(Player2<12))
	{
		Make_Item(Use_Item,Use_Item2);
		while((PTurn<=Turn)||((Player>12)&&(Player2>12)))
		{
			DrawMap();	Color();	Check2();
			PrintHorse();		//말출력
			WhoLand=0;				//승부 초기화
			Better_printf("1P의 턴",55,6,15);
			if(PMoveHorse(&PTurn, &Turn))
			{
				if(Land[PY/4-1][PX/8-1]!=1)
				WhoLand=MGMain(User_Select, User_Select2);
				PTurn+=1;
			}
		}
		while(ATurn<=Turn)
		{
			DrawMap();	Color();	Check1();
			PrintHorse();
			WhereHorse(PX, PY);		//말 위치 저장
			Better_printf("2P의 턴",55,6,15);
			if(AMoveHorse(ATurn))
			{
				WhoLand=MGMain(User_Select, User_Select2);
				ATurn+=1;
			}
		}
	Turn++;
	
	}
	ShowResult_Last(&Player, &Player2);

	Minigame9999( 1 );
	return 0;
}

void DrawMap()	//전체적인 맵틀 표시 함수
{
	int x,y;

	for (x=0; x<HX+5; x++)
	{
		for (y=0; y<VY+5; y++)
		{
			board[x][y] = (y==0 || x==0 || y==4 || y==8 || y==12 || y==16 || y==20 || y==24 || x==4 || x==8 || x==12 || x==16 || x==20 || x==24) ? Wall : NCLand;	//격자 그리기
		}
	}
	for (x=0; x<HX+5; x++)
	{
		for (y=0; y<VY+5; y++)
		{
			SetCurPos(BX+x*2,BY+y);
			puts(Tile[board[x][y]]);		//Tile 포인터 함수 통해 땅 나타내기
		}
	}
	if(Use_Item==TRUE)
		Better_printf("1p 아이템 보유",55,13,15);
	if(Use_Item2==TRUE)
		Better_printf("2p 아이템 보유",55,14,15);
}

void PrintHorse()	//말 출력함수
{
	PrintPHorse(PX,PY);
	PrintAIHorse(AX,AY);
}
void PrintPHorse(int PX, int PY)	//플레이어 말 출력 함수
{
	SetCurPos(PX,PY);
	SetConsoleTextAttribute(hout, 12<<4);
	puts(Tile[2]);
	SetConsoleTextAttribute (hout, 15 );
}
void PrintAIHorse(int AX, int AY)	//컴퓨터의 말 출력 함수
{
	SetCurPos(AX,AY);
	SetConsoleTextAttribute(hout, 13<<4);
	puts(Tile[2]);
	SetConsoleTextAttribute (hout, 15 );
}
void PrintPBlank(int PX, int PY)	//이동뒤 자취 지우는 함수
{
	SetConsoleTextAttribute (hout, 15 );
	SetCurPos(PX,PY);
	puts(Tile[1]);
	SetCurPos(PX+1,PY);
	puts(Tile[1]);
}

int PMoveHorse(int* PTurn, int *Turn)	//플레이어 말 이동함수
{
	int nx=0,ny=0; //사용자의 칸 이동 횟수 감시 //이동 시 증가, 감소
	User_Select=FALSE;		User_Select2=TRUE;
	
	while(!User_Select)
	{
		if( _kbhit() )
			{
				MovePut = _getch();

				switch( MovePut )
				{
				case LEFT:
					if(nx>-1&&ny==0){
					if(SerchTile(PX, PY, MovePut)){
						PrintPBlank(PX,PY);	Color(); PX-=8;	PrintHorse(); Better_printf("1P의 턴",55,6,15);printf("%d",*PTurn);
						nx--;};
					}break;
				case RIGHT:
					if(nx<1&&ny==0){
					if(SerchTile(PX, PY, MovePut)){
						PrintPBlank(PX,PY);	Color(); PX+=8;	PrintHorse(); Better_printf("1P의 턴",55,6,15);printf("%d",*PTurn); 
					nx++;};
					}break;
				case UP:
					if(ny>-1&&nx==0){
					if(SerchTile(PX, PY, MovePut)){
						PrintPBlank(PX,PY);	Color(); PY-=4;	PrintHorse(); Better_printf("1P의 턴",55,6,15);printf("%d",*PTurn);
					ny--;};
					}break;
				case DOWN:
					if(ny<1&&nx==0){
					if(SerchTile(PX, PY, MovePut)){
						PrintPBlank(PX,PY);	Color(); PY+=4;	PrintHorse(); Better_printf("1P의 턴",55,6,15);printf("%d",*PTurn); 
					ny++;};
					}break;
				case 'p':
					Item_Intro(Use_Item,&PTurn, User_Select, User_Select2);	system("cls"); DrawMap(); Color();PrintHorse(); Better_printf("1P의 턴",55,6,15); printf("%d",*PTurn); 
					break;
				case 'l':
					if(*Turn==1){
					if(Land[PY/4-1][PX/8-1]==1) User_Select=FALSE;
					else {User_Select=TRUE; return TRUE;} break;
					}
					else {User_Select=TRUE; return TRUE;} break;
				}
			}

	}
}

int SerchTile(int PX, int PY, char MovePut)	//상대땅,벽일경우 통과 불과
{
	if(TRUE)
	{
		if((PX==8)&&(PY==4)&&((MovePut==LEFT)||(MovePut==UP)))
			return FALSE;
		if((PX==8)&&(PY==8)&&(MovePut==LEFT))
			return FALSE;
		if((PX==8)&&(PY==12)&&(MovePut==LEFT))
			return FALSE;
		if((PX==8)&&(PY==16)&&(MovePut==LEFT))
			return FALSE;
		if((PX==8)&&(PY==20)&&((MovePut==LEFT)||(MovePut==DOWN)))
			return FALSE;
		//=============================================================
		if((PX==16)&&(PY==4)&&(MovePut==UP))
			return FALSE;
		if((PX==16)&&(PY==20)&&(MovePut==DOWN))
			return FALSE;
		if((PX==24)&&(PY==4)&&(MovePut==UP))
			return FALSE;
		if((PX==24)&&(PY==20)&&(MovePut==DOWN))
			return FALSE;
		if((PX==32)&&(PY==4)&&(MovePut==UP))
			return FALSE;
		if((PX==32)&&(PY==20)&&(MovePut==DOWN))
			return FALSE;
		//==============================================================
		if((PX==40)&&(PY==4)&&((MovePut==RIGHT)||(MovePut==UP)))
			return FALSE;
		if((PX==40)&&(PY==8)&&(MovePut==RIGHT))
			return FALSE;
		if((PX==40)&&(PY==12)&&(MovePut==RIGHT))
			return FALSE;
		if((PX==40)&&(PY==16)&&(MovePut==RIGHT))
			return FALSE;
		if((PX==40)&&(PY==20)&&((MovePut==RIGHT)||(MovePut==DOWN)))
			return FALSE;
		//=========================================================//
		if((MovePut==LEFT)&&(PX!=8)&&(Land[PY/4-1][(PX-8)/8-1]==2))
			return FALSE;
		if((MovePut==RIGHT)&&(PX!=40)&&(Land[PY/4-1][(PX+8)/8-1]==2))
			return FALSE;
		if((MovePut==UP)&&(PY!=4)&&(Land[(PY-4)/4-1][PX/8-1]==2))
			return FALSE;
		if((MovePut==DOWN)&&(PY!=24)&&(Land[(PY+4)/4-1][PX/8-1]==2))
			return FALSE;
	}
	return TRUE;

}

void Color()	//땅표시함수
{
	InjectLand(PX, PY, AX, AY, WhoLand);
	DrawColor();
	
	CountLand();	SetCurPos(55,5);
	printf("%d 턴",Turn);
}
void InjectLand(int PX, int PY, int AX, int AY, int WhoLand)	//승패에 따라 Land에 땅소유권을 넣어주는 함수
{
	if((WhoLand==1)&&(User_Select==TRUE)&&(User_Select2==FALSE))
	{
		Land[PY/4-1][PX/8-1]=1;
	}
	
	if((WhoLand==2)&&(User_Select2==TRUE)&&(User_Select==FALSE))
	{
		Land[AY/4-1][AX/8-1]=2;
	}
}
void DrawColor()		//Land값을 이용해 소유한 땅 표시하는 함수
{
	int x,y;
	int a,b;
	for(a=8; a<=40; a+=8){
		for(b=4; b<=20; b+=4){
			if(Land[b/4-1][a/8-1]==1)	//Player
			{
				SetConsoleTextAttribute(hout, 10<<4);
				for(x=a;x<a+6;x++){
					for(y=b;y<b+3;y++){
						SetCurPos(x,y-1); puts(Tile[4]);
					}}
			}
			if(Land[b/4-1][a/8-1]==2)	//AI
			{
				SetConsoleTextAttribute(hout, 11<<4);
				for(x=a;x<a+6;x++){
					for(y=b;y<b+3;y++){
						SetCurPos(x,y-1); puts(Tile[5]);
					}}
			}
		}}
	SetConsoleTextAttribute (hout, 15 );
}

void CountLand()		//땅세는 함수~
{
	Player=0,Player2=0;
	int a,b;
	for(a=8; a<=40; a+=8){
		for(b=4; b<=20; b+=4){
			if(Land[b/4-1][a/8-1]==1)	//Player
				Player+=1;
			else if(Land[b/4-1][a/8-1]==2)	//AI
				Player2+=1;
		}}
	
	Better_printf("소유한 땅의 갯수",55,7,15);
	SetCurPos(55,8); printf("1P : %d",Player);
	SetCurPos(55,9); printf("2P : %d",Player2);
	SetCurPos(55,10); printf("남은 땅의 갯수 : %d",25-*Player-*Player2);
	
}

void WhereHorse(int PX, int PY)
{
	int a,b;
	for(a=8; a<=40; a+=8){
		for(b=4; b<=20; b+=4)
		{
			if(a==PX&&b==PY)
			PHorse[b/4-1][a/8-1]=1;
			else PHorse[b/4-1][a/8-1]=0;
		}
	}
	User_Select=FALSE;
}

int AMoveHorse(int ATurn)	//말 이동함수
{
	int nx=0,ny=0; //사용자의 칸 이동 횟수 감시 //이동 시 증가, 감소
	User_Select=TRUE; User_Select2=FALSE;
	while(!User_Select2)
	{
		if( _kbhit() )
			{ 

				MovePut2 = _getch();

				switch( MovePut2 )
				{
				case 'a':
					if(nx>-1&&ny==0){
					if(ASerchTile(AX, AY, MovePut2)){
						PrintPBlank(AX,AY);	Color(); AX-=8;	PrintHorse(); Better_printf("2P의 턴",55,6,15);printf("%d",ATurn);
						nx--;};
					}break;
				case 'd':
					if(nx<1&&ny==0){
					if(ASerchTile(AX, AY, MovePut2)){
						PrintPBlank(AX,AY);	Color(); AX+=8;	PrintHorse(); Better_printf("2P의 턴",55,6,15);printf("%d",ATurn); 
					nx++;};
					}break;
				case 'w':
					if(ny>-1&&nx==0){
					if(ASerchTile(AX, AY, MovePut2)){
						PrintPBlank(AX,AY);	Color(); AY-=4;	PrintHorse(); Better_printf("2P의 턴",55,6,15);printf("%d",ATurn); 
					ny--;};
					}break;
				case 's':
					if(ny<1&&nx==0){
					if(ASerchTile(AX, AY, MovePut2)){
						PrintPBlank(AX,AY);	Color(); AY+=4;	PrintHorse(); Better_printf("2P의 턴",55,6,15);printf("%d",ATurn); 
					ny++;};
					}break;
				case 'v':
					Item_Intro(Use_Item2,ATurn, User_Select, User_Select2);  system("cls"); DrawMap(); Color();PrintHorse(); Better_printf("2P의 턴",55,6,15);printf("%d",ATurn); 
					break;
				case 'b':
					if(Turn==1){
					if(Land[AY/4-1][AX/8-1]==2) User_Select2=FALSE;
					else {User_Select2=TRUE; return TRUE;} break;
					}
					else {User_Select2=TRUE; return TRUE;} break;
				}
			}

	}
}

int ASerchTile(int AX, int AY, char MovePut2)	//상대땅,벽일경우 통과 불과(또는 그 자리가 이미 먹힌 자리라면 이동 불가
{
	if(1)
	{
		if((AX==12)&&(AY==4)&&((MovePut2=='a')||(MovePut2=='w')))
			return FALSE;
		if((AX==12)&&(AY==8)&&(MovePut2=='a'))
			return FALSE;
		if((AX==12)&&(AY==12)&&(MovePut2=='a'))
			return FALSE;
		if((AX==12)&&(AY==16)&&(MovePut2=='a'))
			return FALSE;
		if((AX==12)&&(AY==20)&&((MovePut2=='a')||(MovePut2=='s')))
			return FALSE;
		//=============================================================
		if((AX==20)&&(AY==4)&&(MovePut2=='w'))
			return FALSE;
		if((AX==20)&&(AY==20)&&(MovePut2=='s'))
			return FALSE;
		if((AX==28)&&(AY==4)&&(MovePut2=='w'))
			return FALSE;
		if((AX==28)&&(AY==20)&&(MovePut2=='s'))
			return FALSE;
		if((AX==36)&&(AY==4)&&(MovePut2=='w'))
			return FALSE;
		if((AX==36)&&(AY==20)&&(MovePut2=='s'))
			return FALSE;
		//==============================================================
		if((AX==44)&&(AY==4)&&((MovePut2=='d')||(MovePut2=='w')))
			return FALSE;
		if((AX==44)&&(AY==8)&&(MovePut2=='d'))
			return FALSE;
		if((AX==44)&&(AY==12)&&(MovePut2=='d'))
			return FALSE;
		if((AX==44)&&(AY==16)&&(MovePut2=='d'))
			return FALSE;
		if((AX==44)&&(AY==20)&&((MovePut2=='d')||(MovePut2=='s')))
			return FALSE;
		//=========================================================//
		if((MovePut2=='a')&&(AX!=8)&&(Land[AY/4-1][(AX-8)/8-1]==1))
			return FALSE;
		if((MovePut2=='d')&&(AX!=40)&&(Land[AY/4-1][(AX+8)/8-1]==1))
			return FALSE;
		if((MovePut2=='w')&&(AY!=4)&&(Land[(AY-4)/4-1][AX/8-1]==1))
			return FALSE;
		if((MovePut2=='s')&&(AY!=24)&&(Land[(AY+4)/4-1][AX/8-1]==1))
			return FALSE;
	}

	return TRUE;

}

/************  바둑처럼 내 땅 표시 ************/
void Check1()
{
	
	int On=TRUE;
	int count=0;
	int what=-1;
	int i,x,y;
	int tempx=PX, tempy=PY;

	for(i=0;i<5;i++){
		if((PX==8+i*8 && PY==20) || (PX==8 && PY==4+i*4))
			what=0;
		else if((PX==8+i*8 && PY==4) || (PX==40 && PY==4+i*4))
			what=1;
	}


		if(what==0){
	while(count<20){
		
			for(y=0;y<5;y++){
					On=TRUE;
				for(x=0;x<4;x++){
					if(Land[y][x]==1)
						On=!On;
					if(Land[y][x]!=1 && Land[y-1][x]==1 && Land[y][x+1]==1 && On==TRUE){
						PX=8+8*(x);
						PY=4+4*(y);
						Color();
					}
				}
		}
			count++;
	}
		}
	count=0;
	if(what==1){
	while(count<20){
			for(y=0;y<i;y++){
				for(x=1;x<5;x++){

					if(Land[y][x]!=1 && Land[y+1][x]==1 && Land[y][x-1]==1){
						PX=8+8*(x);
						PY=4+4*(y);
						Color();
					}
				}
		}
			count++;
	}
		}

	
	for(y=0;y<5;y++)
		for(x=1;x<4;x++)
			if(Land[y][x]!=1 && Land[y][x+1]==1 && Land[y][x-1]==1 && Land[y-1][x]==1 && Land[y+1][x]!=1
				&& Land[y+1][x-1]==1 && Land[y+1][x+1]==1 && Land[y+2][x]==1){
				PX=8+8*(x);
				PY=4+4*(y);
				Color();
			}
			
	for(y=0;y<5;y++)
		for(x=1;x<4;x++)
			if(Land[y][x]!=1 && Land[y][x+1]==1 && Land[y][x-1]==1 && Land[y-1][x]==1 && Land[y+1][x]==1){
				PX=8+8*(x);
				PY=4+4*(y);
				Color();
			}
			PX=tempx;
			PY=tempy;
}
void Check2()
{
	
	int On=TRUE;
	int count=0;
	int what=-1;
	int i,x,y;
	int tempx=AX, tempy=AY;
	
	for(i=0;i<5;i++){
		if((AX==12+i*8 && AY==4) || (AX==44 && AY==4+i*4)){
			what=0; MessageBeep(MB_OK);}
		else if((AX==12+i*8 && AY==20) || (AX==12 && AY==4+i*4))
			what=1;
	}


		if(what==0){
	while(count<20){
		
			for(y=4;y>=0;y--){
					On=TRUE;
				for(x=4;x>0;x--){
					if(Land[y][x]==2)
						On=!On;
					if(Land[y][x]!=2 && Land[y+1][x]==2 && Land[y][x-1]==2 && On==TRUE){
						AX=12+8*(x);
						AY=4+4*(y);
						Color();
					}
				}
		}
			count++;
	}
		}
	count=0;
	if(what==1){
	while(count<20){
			for(y=0;y<5;y++){
				for(x=0;x<4;x++){

					if(Land[y][x]!=2 && Land[y-1][x]==2 && Land[y][x+1]==2){
						AX=12+8*(x);
						AY=4+4*(y);
						Color();
					}
				}
		}
			count++;
	}
		}

	
	for(y=4;y>=0;y--)
		for(x=1;x<4;x++)
			if(Land[y][x]!=1 && Land[y][x+1]==2 && Land[y][x-1]==2 && Land[y-1][x]==2 && Land[y+1][x]!=2
				&& Land[y+1][x-1]==2 && Land[y+1][x+1]==2 && Land[y+2][x]==2){
				PX=12+8*(x);
				PY=4+4*(y);
				Color();
			}
			
	for(y=4;y>=0;y--)
		for(x=3;x>=1;x--)
			if(Land[y][x]!=2 && Land[y][x+1]==2 && Land[y][x-1]==2 && Land[y-1][x]==2 && Land[y+1][x]==2){
				PX=12+8*(x);
				PY=4+4*(y);
				Color();
			}
			AX=tempx;
			AY=tempy;
}

void Item_Intro(BOOL onemore, int** TURN, BOOL User_Select, BOOL User_Select2)
{
	char want;
	BOOL Use=FALSE;
	if(onemore)
	{
		Better_printf("-아이템 사용-",25,10,15);
		Better_printf("한번 더! 아이템",25,11,15);
		Better_printf("사용하시려면 1번을 사용하지 않으시려면 2번을 눌러주세요\n",10,12,15);
	}
	while(!Use){
	if(onemore==TRUE)
	{
		if( _kbhit() )
		{
			want = _getch();

			if(want=='1'){
				**TURN=Item(**TURN); Use=TRUE; 
				if(User_Select==FALSE){
					Use_Item=FALSE;
				}
				else if(User_Select2==FALSE){
					Use_Item=FALSE;
				}
			}
			else if(want=='2')
			Use=TRUE;
		}
	}
	else 
	{
		Better_printf("아이템이 존재하지 않습니다.",25,10,15);
		Better_printf("엔터키를 눌러주세요!!",27,11,15);
		getchar(); Use=TRUE;
	}
	}
}

void Make_Item(BOOL Use_Item, BOOL Use_Item2)
{
	int P1_a,P1_b,P2_a,P2_b;
	int random,i;
	int arr[5];
	srand(time(NULL));
	random=rand();

	P1_a=(random*3)%5;
	P1_b=(random*15)%5;
	P2_a=(random*11)%5;
	P2_b=(random*17)%5;

	for(i=0; i<5; i++)
	{
		random=(rand()*17)%2;
		arr[i]=random;
	}
	if((arr[P1_a]==0)&&(arr[P1_b]==0))
		Use_Item=TRUE;
	if((arr[P2_a]==0)&&(arr[P2_b]==0))
		Use_Item2=TRUE;
}


void ShowResult_Last(int* Player,int* Player2)
{
	Better_printf("                                   ",22,9,15);
	Better_printf("  ===============================  ",22,10,15);
	if(*Player>*Player2)
	Better_printf("  ===   1P가 승리하였습니다   ===  ",22,11,15);
	else
	Better_printf("  ===   2P가 패배하였습니다   ===  ",22,11,12);
	Better_printf("  ===============================  ",22,12,15);
	Better_printf("                                   ",22,13,15);
	Sleep(2000);
	Better_printf(" === 패자의 역습이 시작됩니다 ===  ",22,11,15);
	Sleep(500);
	Better_printf(" ===           3              ===  ",22,11,5);
	Sleep(500);
	Better_printf(" ===           2              ===  ",22,11,4);
	Sleep(500);
	Better_printf(" ===           1              ===  ",22,11,12);
	Sleep(500);
	clrsc();
}