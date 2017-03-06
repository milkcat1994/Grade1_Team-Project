#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"MainHeader.h"
#include"Re_Boss.h"
HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE); 

#define HX 16	//���α���
#define VY 16	//���α���
#define BX 6	//���� ����
#define BY 2	//���� ����

enum Tile{Wall,NCLand,Horse,AILand,PLand};	//������� ���� 0~4���� �ڵ� ����

void Intro();
//=============��ü���� Ʋ,������ ǥ��=============//
void DrawMap();			//��Ʋ �׸���
void Color();
void InjectLand(int PX, int PY, int AX, int AY, int WhoLand);	//�̰�ٸ� Land�� �ش� ���� ����
void DrawColor();	//Land[][]�� ���� ���� ĥ�ϱ�
void CountLand();								//�� ���� ����
int board[HX+6][VY+6];	//��ü�� ������

//==================�����,�̵�====================//
void PrintHorse();
void PrintPHorse(int PX, int PY);		//1p �� ���
void PrintPBlank(int PX, int PY);		//1p �� �ڸ� �����
int PMoveHorse(int* PTurn, int* Turn);		//�� �̵�
int PHorse[5][5]={};	//���� ��ġ
void WhereHorse(int PX, int PY); //���� ��ġ �Է� �Լ�
int SerchTile(int PX, int PY, char MovePut);	//�̵� ���� ���� �Ǵ�
//void AIMove();
void PrintAIHorse(int AX, int AY);		//2p �� ���
int AMoveHorse(int ATurn);		//�� �̵�
int ASerchTile(int AX, int AY, char MovePut2);	//�̵� ���� ���� �Ǵ�

int MainGame();			//���ΰ���
int MGMain(BOOL User_Select, BOOL User_Select2);			//�̴ϰ���
int Item(int argc);
int WhoLand;		//������ ���� �����Ǵ� ����ȣ
int Land[5][5]={};		//0�̸� ��, 1�̸� �÷��̾�, 2�̸� ��ǻ��
BOOL User_Select;		BOOL User_Select2;
int PX=8,PY=4,AX=44,AY=20;
int X=8, Y=4, G=44, H=20;

char MovePut, MovePut2;
char *Tile[]={"��"," ","  ","��"," "," "};//Wall,NCLand,PHorse,AIHorse,PLand,AILand ���� ������ȹ

void ShowResult_Last(int* Player, int* Player2);
/******/
void Check1();
void Check2();
void Item_Intro(BOOL onemore, int** TURN, BOOL User_Select, BOOL User_Select2);	//������ ���
int Item(int*** TURN);
void Make_Item(BOOL Use_Item, BOOL Use_Item2);

BOOL Use_Item=TRUE,Use_Item2=TRUE;