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
void printlefthand();//���� ���ʰ���ų��
void printmiddlehand();//���� �������ų��
void printrighthand();//���� �����ʰ���ų��
void erase(int x);//�����ո�������
void eraseface();//�������
void chamintro(int x,int y);//��Ʈ��

int Selecthand(int );//�ռ���
int cham_main(BOOL User_Select, BOOL User_Select2);
void table();