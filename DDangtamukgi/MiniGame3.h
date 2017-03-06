#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include"MainHeader.h"

int CardGame(BOOL User_Select, BOOL User_Select2);
void WindowMain();

LRESULT CALLBACK CardProc1(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK CardProc2(HWND,UINT,WPARAM,LPARAM);


void DrawOnConsole();


int WhoWin(BOOL User_Select, BOOL User_Select2, BOOL PlayerP, BOOL Player2P);