#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"MainHeader.h"
#include"Re_Boss.h"
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE); 

#define HX 16	//가로길이
#define VY 16	//세로길이
#define BX 6	//가로 여백
#define BY 2	//세로 여백

enum Tile{Wall,NCLand,Horse,AILand,PLand};	//순서대로 각각 0~4까지 자동 저장

void Intro();
//=============전체적인 틀,소유권 표시=============//
void DrawMap();			//맵틀 그리기
void Color();
void InjectLand(int PX, int PY, int AX, int AY, int WhoLand);	//이겼다면 Land에 해당 숫자 삽입
void DrawColor();	//Land[][]에 따라 색깔 칠하기
void CountLand();								//땅 갯수 새기
int board[HX+6][VY+6];	//전체적 게임판

//==================말출력,이동====================//
void PrintHorse();
void PrintPHorse(int PX, int PY);		//1p 말 출력
void PrintPBlank(int PX, int PY);		//1p 말 자리 지우기
int PMoveHorse(int* PTurn, int* Turn);		//말 이동
int PHorse[5][5]={};	//말의 위치
void WhereHorse(int PX, int PY); //말의 위치 입력 함수
int SerchTile(int PX, int PY, char MovePut);	//이동 가능 여부 판단
//void AIMove();
void PrintAIHorse(int AX, int AY);		//2p 말 출력
int AMoveHorse(int ATurn);		//말 이동
int ASerchTile(int AX, int AY, char MovePut2);	//이동 가능 여부 판단

int MainGame();			//메인게임
int MGMain(BOOL User_Select, BOOL User_Select2);			//미니게임
int Item(int argc);
int WhoLand;		//게임을 통해 결정되는 땅번호
int Land[5][5]={};		//0이면 빈땅, 1이면 플레이어, 2이면 컴퓨터
BOOL User_Select;		BOOL User_Select2;
int PX=8,PY=4,AX=44,AY=20;
int X=8, Y=4, G=44, H=20;

char MovePut, MovePut2;
char *Tile[]={"※"," ","  ","△"," "," "};//Wall,NCLand,PHorse,AIHorse,PLand,AILand 추후 수정계획

void ShowResult_Last(int* Player, int* Player2);
/******/
void Check1();
void Check2();
void Item_Intro(BOOL onemore, int** TURN, BOOL User_Select, BOOL User_Select2);	//아이템 사용
int Item(int*** TURN);
void Make_Item(BOOL Use_Item, BOOL Use_Item2);

BOOL Use_Item=TRUE,Use_Item2=TRUE;