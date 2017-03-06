#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h> //COORD
#include<stdlib.h>
#include<mmsystem.h>
#include"MainHeader.h"

int NumGame(BOOL User_Select, BOOL User_Select2);	//게임 메인
int userselect2();
int comselect2();
int userselect2_2();
int comselect2_2();

void ShowSelImage(int i,int Player);

void Print1(int x,int y,int Player);
void Print2(int x,int y,int Player);
void Print3(int x,int y,int Player);
void Print4(int x,int y,int Player);
void Print5(int x,int y,int Player);
void Print6(int x,int y,int Player);
void Print7(int x,int y,int Player);
void Print8(int x,int y,int Player);
void Print9(int x,int y,int Player);

int ThinkResult(int Playernum, int Comnum, BOOL User_Select, BOOL User_Select2);

void numgameintro();//인트로
void numgamemap(BOOL User_Select, BOOL User_Select2);//맵