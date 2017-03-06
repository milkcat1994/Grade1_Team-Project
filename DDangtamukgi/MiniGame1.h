#include<stdio.h>
#include<conio.h>
#include<windows.h> //COORD
#include<time.h>
#include"mainheader.h"

 //커서 이동, 글자 색

int SRPGame(BOOL User_Select, BOOL User_Select2);		//게임 메인

int ComSelect();	//AI의 선택과정
void UserSelect(int *eNow,int *eTemp);	//사용자의 선택과정

void DrawMinigame();	//인트로
void MoveSelection(int x,int y,int i,BOOL _switch,int Player);	//선택변경시
void ShowSelImage(int i,int Player);	//플레이어 손가락 모양 출력


void PrintS(int x,int y,int pos);	//가위(손모양)		
void PrintR(int x,int y,int pos);	//바위(손모양)
void PrintP(int x,int y,int pos);	//보(손모양)
