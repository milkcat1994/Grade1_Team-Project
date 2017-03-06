#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>


typedef struct _charPos
{
	int x;
	int y;
} pos;

typedef struct _myAttack
{
	int x;
	int y;
	int on;
} myattack;

typedef struct _boss
{
	int x;
	int y;
	int mode;
	int coolTime;
	int hp;
} Boss;

typedef struct _heart
{
	double x, dx;
	double y, dy;
	int leftTimeToInit;
} heart;



typedef heart attack;

int Minigame9999( int level );

void CharMove( int* x, int* y, int color, const char* character );
void BossMove( int* x, int* y )	;

void DrawBoss( Boss boss, int line );

int SetDxy( attack* pattack, pos _me, int mode );
void AttackMove( attack* pattack, Boss from );

int CheckInit( Boss boss, attack* pattack );

int FollowAttackCheckInit( attack* pattack );
int LineAttackCheckInit( attack* pattack );

void DestroyAttack( attack* pattack, Boss boss );
void InitAttack( attack* pattack, Boss boss, int _coolTime, pos _me );

int CheckHit( attack* pattack, pos me );
void ShowHPBar( int hp, int x, int y, char* str );

void LaunchMyAttack( pos , myattack* );
void MoveMyAttack( myattack* , Boss* );

void ChargeLeftAttack( int* leftAttack );
void ShowLeftAttack( int leftAttack, int x, int y );

void IntroEye();
void Help2();