#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<windows.h> 
#include<stdlib.h>
#include<mmsystem.h>   // Win32Api Header File 
#include"MainHeader.h"
#include"resource.h"

static HWND  hConWnd;
HWND BCX_Bitmap(int face,HWND=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0);
HWND GetConsoleWndHandle(void);
int ChamGame(BOOL User_Select, BOOL User_Select2);

void im(int face);
void printlefthand();//손이 왼쪽가리킬때
void printmiddlehand();//손이 가운데가리킬때
void printrighthand();//손이 오른쪽가리킬때
void erase(int x);//원래손모양지우기
void eraseface();//얼굴지우기
void chamintro(int x,int y);//인트로

int Selecthand(int );//손선택
int cham_main(BOOL User_Select, BOOL User_Select2);
void table();