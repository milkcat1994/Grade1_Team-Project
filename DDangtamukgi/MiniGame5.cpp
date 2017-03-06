#include "MiniGame5.h"


int nPlay=0;

char Otherhand_Default[][50]={
	"      /     │      │     │      │     │",
	"     │     │      │|   /│      │     │",
	"     │     │      ││ ││      │     │",
	"     │     │      ││ ││      │     /",
	"      ───│      │-   -│      │──",
	"            └─■─┘     └─■─┘"
};
char Otherhand_LeftUp[][50]={
	"      /     │      │     │      │     │",
	"     │     │      │|   //│      │    │",
	"     │     │      ││ │/│  ■  │    │",
	"     │     │      ││ │/└───┘    /",
	"      ───│      │-   -───────",
	"            └─■─┘          "
};
char Otherhand_RightUp[][50]={
	"      /     │      │     │      │     │",
	"     │    │      │/|   /│      │     │",
	"     │    │  ■  │/│ ││      │     │",
	"     │    └───┘/│ ││      │     /",
	"      ────────-   -│      │──",
	"                           └─■─┘"
};
char Otherhand_DoubleUp[][50]={
	"      /     │      │     │      │     │",
	"     │    │      │/|   //│      │    │",
	"     │    │  ■  │/│ │/│  ■  │    │",
	"     │    └───┘/│ │/└───┘    /",
	"      ────────-   -───────",
	"                                "
};
char Myhand_Default[][50]={
	"            ┌─■─┐     ┌─■─┐",
	"        ──│      │-   -│      │──",
	"      ／    │      ││ ││      │    │",
	"     │     │      ││ ││      │    │",
	"     │     │      │/   |│      │    │",
	"     │     │      │     │      │    / "
};
	char Myhand_LeftUp[][50]={
	"                           ┌─■─┐",
	"        ───────-   -│      │──",
	"      ／   ┌───┐/│ ││      │    │",
	"     │    │  ■  │/│ ││      │    │",
	"     │    │      │//   |│      │    │",
	"     │     │      │     │      │    /"
};
char Myhand_RightUp[][50]={
	"            ┌─■─┐               ",
	"        ──│      │-   -───────",
	"      ／    │      ││ │/┌───┐   │",
	"     │     │      ││ │/│  ■  │   │",
	"     │     │      │/   |/│      │   │",
	"     │     │      │     │      │    / "
};
char Myhand_DoubleUp[][50]={
	"                                          ",
	"        ───────-   -───────",
	"      ／   ┌───┐/│ │/┌───┐   │",
	"     │    │  ■  │/│ │/│  ■  │   │",
	"     │    │      │//   |/│      │   │",
	"     │     │      │     │      │    / "
};


int ZeroGame(BOOL User_Select, BOOL User_Select2)
{
	int whowin;
	clrsc(); nPlay+=1;
	CONSOLE_CURSOR_INFO CurInfo; //커서 없애기
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);

	DrawZeroIntro();	//인트로
	whowin=PlayWithHands(User_Select, User_Select2);	//본격게임
	system("cls");
	return whowin;
}

/*<<<<<<<<<<<<<  본격 게임  >>>>>>>>>>>>>>*/
int PlayWithHands(BOOL User_Select, BOOL User_Select2)
{
	const int pHand_Left=17,pHand_Top=19;			//손을 출력 할위치
	int i;	//포문 셔틀
	int nWhat=0;	//화면 깜빡임 방지
	int bHelp=FALSE;	//도움말 (필요 없다, 혹시 몰라서 놔두었다)
	int myselnum=0;	//내가 들어올린 손가락 갯수
	int gap=0;			// (내가 외친 숫자) - (상대가 들어올린 손가락 갯수)

	Better_printf("게임 설명 : H 키",0,0,8);                            //  ─┐
	for(i=0;i<6;i++)													//    │
			Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15); //	  ├─>  초기 화면
	for(i=0;i<6;i++)													//    │
			Better_printf(Otherhand_Default[i],pHand_Left,0+i,15);		//  ─┘

	while(1){ //키보드 입력 받아서 작동하는 루프
		if( (GetKeyState(72) & 0x8000) && !(bHelp) ){ // H키 누르면 도움말 출력( Help() ) 후 화면 다시 그리기( for(;;) )
			//bHelp=TRUE;
			Help();
			for(i=0;i<6;i++)
			Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15);
			for(i=0;i<6;i++)
			Better_printf(Otherhand_Default[i],pHand_Left,0+i,15);
		}
		/***************   A, D 키 입력 받기   **************/
		if( (GetKeyState(65) & 0x8000) && !(GetKeyState(68) & 0x8000) && !(nWhat==1) ){		
			for(i=0;i<6;i++)
				Better_printf(Myhand_LeftUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=1;	myselnum=1;
		}
		if( (GetKeyState(68) & 0x8000) && !(GetKeyState(65) & 0x8000) && !(nWhat==2) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_RightUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=2;	myselnum=1;
		}
		if( (GetKeyState(65) & 0x8000) && (GetKeyState(68) & 0x8000) && !(nWhat==3) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_DoubleUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=3;	myselnum=2;
		}
		if( !(GetKeyState(65) & 0x8000) && !(GetKeyState(68) & 0x8000) && !(nWhat==0) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15);
			nWhat=0;	myselnum=0;
		}
		/****************************************************/
		 
		/***************   숫자 입력 받기   **************/ 
		if( GetKeyState(49) & 0x8000 || GetKeyState(0x61) & 0x8000 ){ gap=Shouting(1); break; }			//Shouting() 로 외치는 시늉 출력하고
		else if( GetKeyState(50) & 0x8000 || GetKeyState(0x62) & 0x8000 ){ gap=Shouting(2); break; }	//상대의 손가락을 랜덤으로 출력하여
		else if( GetKeyState(51) & 0x8000 || GetKeyState(0x63) & 0x8000 ){ gap=Shouting(3); break; }	//자신이 외친 숫자와 상대의 올린 손가락 갯수의
		else if( GetKeyState(52) & 0x8000 || GetKeyState(0x64) & 0x8000 ){ gap=Shouting(4); break; }	//차이를 반환.  그 반환값을 gap에 대입한다
		else if( GetKeyState(48) & 0x8000 || GetKeyState(0x60) & 0x8000 ){ gap=Shouting(0); break; }
	}
	//printf("나: %d,  차이: %d",myselnum,gap);

	if(myselnum==gap){	//그 반환 값이 내가 올린 손가락 갯수와 일치 할 경우
		printf("이김");	//승리
		Sleep(2000);
		if(User_Select==TRUE)
			return 1;
		else if(User_Select2==TRUE)
			return 2;
	}
	else
	{
		printf("짐");	//그렇지 않을경우 패배
		Sleep(2000);
		return 0;
	}
	
}

void Help()
{
	const int pHelp_Mid=38, pHelp_Top=5;
	int i;
	char cESC;

	char help[][100]={"*혹시 '제로 게임'을 모르세요?","숫자를 외치면,","엄지 손가락을 들어올릴 수 있습니다.","\n",
		"여러분과 상대가 들어올린 엄지의 총 합이","외친 숫자와 일치 할 경우,",
	    "숫자를 외친 사람은 승리합니다.","\n","여기에서는 숫자가 일치 하지 않을 경우,","패배합니다.","왼쪽 엄지 들기 : A 키, 오른쪽 엄지 들기 : D키, 외치기 : 숫자(0∼4) 키"};
	

	Appear(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,NULL);
	Better_printf(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,10);

	for(i=1;i<10;i++){
		Appear(help[i],pHelp_Mid-strlen(help[i])/2,pHelp_Top+2+i,150);
	}
	Better_printf(help[10],pHelp_Mid-strlen(help[10])/2,pHelp_Top+13,11);
	Better_printf("ESC 키를 눌러 도움말 지우기",pHelp_Mid-strlen(help[10])/2,pHelp_Top+15,8);
	
	while(1){
	if( _kbhit() ){
		if( cESC=_getch() == 27 )
			break;
	}
	}

	Fade(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,30);

	for(i=1;i<10;i++){
		Fade(help[i],pHelp_Mid-strlen(help[i])/2,pHelp_Top+2+i,30);
	}
	Fade(help[10],pHelp_Mid-strlen(help[10])/2,pHelp_Top+13,30);
	Fade("ESC 키를 눌러 도움말 지우기",pHelp_Mid-strlen(help[10])/2,pHelp_Top+15,30);
}

int Shouting(int selnum)
{
	int OtherSel=0;			//상대가 고를 손가락 모양
	int OtherCount=0;		//상대가 올린 엄지 손가락 수
	int i;

	char *ShoutWhat="";
	switch(selnum){
	case 0: ShoutWhat="제로!"; break;
	case 1: ShoutWhat="하나!"; break;
	case 2: ShoutWhat="둘!  "; break;
	case 3: ShoutWhat="셋!  "; break;
	case 4: ShoutWhat="넷!  "; break;
	}
	Better_printf("  |    ",2,21,15);
	Better_printf("  |  /",2,22,15);
	Better_printf("   /  -- --",2,23,15);
	Better_printf(ShoutWhat,9,21,15);

	srand(time(NULL));
	OtherSel=rand()%3;
	switch(OtherSel){
	case 0: for(i=0;i<6;i++)
			Better_printf(Otherhand_Default[i],17,0+i,15); break;
	case 1: if(OtherSel=rand()%2){
				for(i=0;i<6;i++)
				Better_printf(Otherhand_LeftUp[i],17,0+i,15); 
			} else {
				for(i=0;i<6;i++)
				Better_printf(Otherhand_RightUp[i],17,0+i,15);
			} OtherCount=1; break;
	case 2: for(i=0;i<6;i++)
			Better_printf(Otherhand_DoubleUp[i],17,0+i,15);
		OtherCount=2;
	}



	return selnum-OtherCount;
}

void DrawZeroIntro()
{
	int bkbhit=1;
	int changing=0;
	int color;
	int count=0;
	int i;
	int appeartime=0;
	char str_ZERO[][200]={
		"┌────────┒  ┌───────┒ ┌───────┒ ┌───────┒",
		"┕━━━━━━┑  ┃  │  ┏━━━━━┛ │  ┏━━━┑  ┃ │ ┏━━━━┑ ┃",
		"              /  //   │  ┃             │  ┃      │  ┃ │ ┃        │ ┃",
		"            /  //     │  ┃             │  ┖───┘  ┃ │ ┃        │ ┃",
		"          /  //       │  ┖─────┒ │  ┏━━━━━┛ │ ┃        │ ┃",
		"        /  //         │  ┏━━━━━┛ │  ┖─────┒ │ ┃        │ ┃",
		"      /  //           │  ┃             │  ┏━━━┑  ┃ │ ┃        │ ┃",
		"    /  //             │  ┃             │  ┃      │  ┃ │ ┃        │ ┃",
		"  /    ──────┒ │  ┖─────┒ │  ┃      │  ┃ │ ┖────┘ ┃",
		" ┕━━━━━━━━┛ ┕━━━━━━━┛ ┕━┛      ┕━┛ ┕━━━━━━━┛"
	};
	Better_printf("\n",10,10,12);
	/********************색깔 알록달록~***************/
	while(changing<28){
	for(i=0;i<10;i++){
		if( _kbhit() )
			bkbhit=0;
		color=15-changing-i;
		if(color<-1)
			color+=12;

		Better_printf("",0,0,color);
		SetCurPos(1,7+i);
		printf("%s",str_ZERO[i]);
	}
	changing++;

	Sleep(100*bkbhit);
	}

	Sleep(500*bkbhit);
	/***********************/
	count=color=0;
	while(count<18){
		for(i=0;i<10;i++){
			Better_printf(str_ZERO[i],1,7+i,color);
		}
		switch(++count){
		case 1: color=8; break;
		case 2: color=7; break;
		case 3: color=15; break;
		case 15: color=7; break;
		case 16: color=8; break;
		case 17: color=0; 
		}
		Sleep(150*bkbhit);
	}
	if((bkbhit==0)&&(nPlay!=1))
		appeartime=1;

	system("cls");
	Appear("왼쪽 엄지 들기 : 키보드 A 버튼",20,9,appeartime);
	Appear("오른쪽 엄지 들기 : 키보드 D 버튼",20,11,appeartime);
	Appear("숫자 외치기 : 키보드 숫자 버튼",20,13,appeartime);
	Sleep(1000*bkbhit);
	Fade("왼쪽 엄지 들기 : 키보드 A 버튼",20,9,appeartime);
	Fade("오른쪽 엄지 들기 : 키보드 D 버튼",20,11,appeartime);
	Fade("숫자 외치기 : 키보드 숫자 버튼",20,13,appeartime);

	system("cls");
}
/*
int AskWhatNum()
{
	int i;
	char cInput;
	char num0[][40]={" ┌───────┐"," │              │"," │   ┌──┐   │"," │   │    │   │",
					" │   │    │   │"," │   │    │   │"," │   │    │   │",
					" │   └──┘   │"," │              │"," └───────┘",
					};
	char num1[][40]={"          ┌─┐    ","          /   │   ","       ┌┘   │    ",
					"       └ ┐  │    ","          │  │    ","          │  │    ",
					"          │  │    ","          │  │    ","        ┌┘  └┐  ","        └───┘  "
	};
	char num2[][40]={"  ┌───────┐",
					 "  │              │",
					 "  └─────┐  │",
					 "              │  │",
					 "  ┌─────┘  │",
					 "  │  ┌─────┘",
					 "  │  │            ",
					 "  │  └─────┐",
					 "  │              │",
					 "  └───────┘"
	};
	char num3[][40]={"  ┌───────┐","  │              │","  └─────┐  │",
					"              │  │","  ┌─────┘  │","  └─────┐  │",
					"              │  │","  ┌─────┘  │","  │              │","  └───────┘",
	};
	char num4[][40]={
		" ┌─┐  ┌─┐    ",
		" │  │  │  │    ",
		" │  │  │  │    ",
		" │  │  │  │    ",
		" │  │  │  │    ",
		" │  └─┘  └─┐",
		" └───┐  ┌─┘",
		"         │  │    ",
		"         │  │    ",
		"         └─┘    "
					};
	char oh[][8]={
		"┌─┐",
		"│  │",
		"│  │",
		"│  │",
		"│  │",
		"│  │",
		"└─┘",
		"┌─┐",
		"└─┘"
	};

	const int str_top=5;
	const int str_left=38;
	int sel=-1,bsel=0;

	Better_printf("키보드로 숫자 입력 후 엔터 꾺 눌러주세요",0,0,8);
	Better_printf("○│",str_left-26,10,7);
	Better_printf("ㅗ│치고 싶은 숫자 : ",str_left-26,11,7);
	Better_printf("( 0 ∼ 4 중에 )",str_left-23,13,7);
	//SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	while( !bsel ){
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
		if( _kbhit() )
		{
			switch(cInput=_getch()){
			case '0': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); } for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num0[i]);} Better_printf("제로!",str_left+25,str_top,11); sel=0; break;
			case '1': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num1[i]);} Better_printf("하나!",str_left+25,str_top,11); sel=1; break;
			case '2': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num2[i]);} Better_printf("둘!  ",str_left+25,str_top,11); sel=2; break;
			case '3': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num3[i]);} Better_printf("셋!  ",str_left+25,str_top,11); sel=3; break;
			case '4': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num4[i]);} Better_printf("넷!  ",str_left+25,str_top,11); sel=4; break;
			case 13 : if(sel!=-1) bsel=TRUE;
			}
			
		}
		SetCurPos(0,0);
	}
	return sel;
}
*/
void Appear(char *str, int x, int y, int speed)
{
	int count=0,i,color=0;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
	printf("%s",str);
	switch(++count){
	case 1: color=8; break;
	case 2: color=7; break;
	case 3: color=15;
	}
	Sleep(speed);
	}
}

void Fade(char *str, int x, int y, int speed)
{
	int count=0,i,color=15;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
	printf("%s",str);
	count++;
	switch(count){
	case 1: color=7; break;
	case 2: color=8; break;
	case 3: color=0;
	}
	Sleep(speed);
	}
}
