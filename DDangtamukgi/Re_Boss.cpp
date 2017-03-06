// 벨런스 조정 필요해

#include "Re_Boss.h"
#include "Utility.h"

int coolTime;
char BossDefault1[][16]=
{
	"          \n",
	"          \n",
	"  __      \n",//6 2 6
	" /' │    \n",
	" └ ┘    \n",
	" │||│   \n",
	" │||│   \n",
	" ├∪┤   \n",
	" │ |│   \n",
	" │ |│   \n",
	"└─┘┘  \n",
	"          \n",
	"          \n"
};
char BossDefault2[][16]=
{
	"		  \n",
	"		  \n",
	"  __	  \n",//6 2 6
	" /' │	  \n",
	" └ ┘	  \n",
	" │||│  \n",
	" │||│  \n",
	" ├∪┤  \n",
	" │  /	  \n",
	"  ＼│	  \n",
	" └ㅡ┘  \n",
	"		  \n",
	"		  \n"
};
/*
char BossAttack[][16]=
{
	"            \n",
	"      |||   \n",//6 2 6
	"     /♥│  \n",
	"     └ ┘  \n",
	" ○─┤││ \n",
	" ○──┘│ \n",
	"     ├─┤ \n",
	"     │ |│ \n",
	"     │ |│ \n",
	"    └─┘┘\n",
	"            \n",
	"            \n"
};
*/
pos me = { 6, 11 };

int Minigame9999( int level )		//매개변수로 난이도의 정도를 받아 난이도 조정한다. 낮을수록 쉽다.
{
	int ME_COLOR = 15;		//플레이어 출력 색깔
	const int BOSS_COLOR = 15;
	const char ME_STR[] = "●";		//플레이어 출력 모양
	int numOfAttack = 50;						
	int count = 0;						//각각 함수의 호출 속도를 조절하기 위한 변수
	int attackIndex=0, i;					//현재 활성화 된 '눈초리'의 갯수, 포문 셔틀
	int will= 10, willCount=0;
	int smallHP=1000, bigHP=1000;
	int myLeftAttack = 20 ;
	int ch;
	myattack myAttackAry[200];

	coolTime = 70;

	attack attackAry[50];
	
	Boss boss = { 53 , 7 , 1 ,  coolTime, 9999 } ;

	Better_printf2("조작 방법 : h",0,0,7);
	Better_printf2("이상한 글자 출력 될 시 한/영 키 를 눌러요",32,0,7);
	for( i=0 ; i<50 ; i++)
		myAttackAry[i].on = FALSE;
	Better_printf2( ME_STR, me.x, me.y, ME_COLOR);			//플레이어 출력

	while( 1 )
	{
		count ++;

		if( count%10 == 0 )
			ME_COLOR = 15;
		Better_printf2( ME_STR, me.x, me.y, ME_COLOR);			//플레이어 출력

		if ( _kbhit() )
		{
			ch = _getch();
			if ( ch == VK_RETURN )
			{
				if ( boss.mode == 1 )
				{
					boss.mode = 2;
				}
				else if ( boss.mode == 2 )
				{
					boss.mode = 1;
					for( i=0 ; i<=attackIndex ; i++ )	
						{
						SetDxy( &attackAry[attackIndex], me, boss.mode  );			
						}
				}
			}
			
			else if ( ch == 'h' ) //|| ch == 'H' )
			{
				Better_printf2("도움말 없애기 : ESC",0,0,7);
				Help2();
				ch = 0;
				Better_printf2("조작 방법 : h         ",0,0,7);
			}
				
		}

		if ( GetKeyState(VK_SPACE) & 0x8000 && myLeftAttack > 0 )
		{
			LaunchMyAttack( me, myAttackAry );
			myLeftAttack--;
		}
		MoveMyAttack( myAttackAry, &boss );

			

		CharMove( &me.x, &me.y, ME_COLOR, ME_STR );  // 플레이어 이동 함수
		if( count%10 == 0 )
		{
			BossMove( &boss.x, &boss.y );
			DrawBoss( boss, 13 );
		}

		if( count%coolTime == 0 && attackIndex+1 < numOfAttack )	// coolTime마다
		{
			InitAttack( &attackAry[++attackIndex], boss, coolTime, me );		// '눈초리'를 하나씩 활성화 해 간다
		}

		
		if ( boss.mode == 1 )
		{
			for( i=0 ; i<=attackIndex ; i++ )		// 첫번째 '눈초리'부터 마지막 '눈초리'까지 쭉 돌면서
			{
				if ( CheckHit( &attackAry[i], me ) )
				{
					ME_COLOR = 12;
					smallHP-=13;
				}
				AttackMove( &attackAry[i], boss );			// '눈초리' 이동해주고
			}
		}

		else if ( boss.mode == 2 )
		{
			for( i=0 ; i<=attackIndex ; i++ )		// 첫번째 '눈초리'부터 마지막 '눈초리'까지 쭉 돌면서
			{
				SetDxy( &attackAry[i], me, boss.mode );	// dx, dy 다시 설정해주고
				if ( CheckHit( &attackAry[i], me ) )
				{
					ME_COLOR = 12;
					smallHP-=27;
				}
					//break;		// ( 만약 '눈초리' 랑 플레이어의 위치가 같아서 FALSE가 반환되면 지게된다 )
				AttackMove( &attackAry[i], boss );			// '눈초리' 이동해주고
			}
		}

		ChargeLeftAttack( &myLeftAttack );
		ShowLeftAttack( myLeftAttack, 5, 21 );

		ShowHPBar( smallHP, 5, 22, "남은 체력 : " );
		ShowHPBar( boss.hp, 50, 22, "남은 체력 : ");

		if ( smallHP < 1 )
		{
			return 1;		//조그만 놈( 땅따먹기에서 이긴사람 )이 이길경우 return 1;
		}
		else if ( bigHP < 1 )
		{
			return 0;		//큰 놈( 땅따먹기에서 진 사람 )이 이길경우 return 0;
		}

		Sleep(20);
	}

	return 0;
}




void CharMove( int* x, int* y, int color,  const char* character )		// 방향키 누르면 플레이어 이동
{
	const int LIMIT_LEFT = 3, LIMIT_RIGHT = 27, LIMIT_TOP = 5, LIMIT_BOTTOM = 20;
	static int count = 0;

	if( ( GetKeyState( 'A' ) & 0x8000 ) && ( *x>LIMIT_LEFT ) )
	{
		Better_printf2("  " , *x, *y, color);
		(*x)--;
		Better_printf2( character, *x, *y, color);
	}
	if( ( GetKeyState( 'D' ) & 0x8000 ) && ( *x<LIMIT_RIGHT ) )
	{
		Better_printf2("  " , *x, *y, color);
		(*x)++;
		Better_printf2( character, *x, *y, color);
	}

	if( ( GetKeyState( 'W' ) & 0x8000 ) && ( *y>LIMIT_TOP ) )
	{
		if( count%2 == 0 )
		{
			Better_printf2("  " , *x, *y, color);
			(*y)--;
			Better_printf2( character, *x, *y, color);
			count++;
		}
		else
		{
			count++;
		}

		
	}
	if( ( GetKeyState( 'S' ) & 0x8000 ) && ( *y<LIMIT_BOTTOM ) )
	{
		if( count%2 == 0 )
		{
			Better_printf2("  " , *x, *y, color);
			(*y)++;
			Better_printf2( character, *x, *y, color);
			count++;
		}
		else
		{
			count++;
		}
	}
}

void BossMove( int* x, int* y )	
{
	const int LIMIT_LEFT = 30, LIMIT_RIGHT = 65, LIMIT_TOP = 1, LIMIT_BOTTOM = 21-10;
	static int count = 0;

	if( ( GetKeyState( VK_LEFT ) & 0x8000 ) && ( *x>LIMIT_LEFT ) )
	{
		(*x)--;
	}
	if( ( GetKeyState( VK_RIGHT ) & 0x8000 ) && ( *x<LIMIT_RIGHT ) )
	{
		(*x)++;
	}

	if( ( GetKeyState( VK_UP ) & 0x8000 ) && ( *y>LIMIT_TOP ) )
	{
		if( count%2 == 0 )
		{
			(*y)--;
			count++;
		}
		else
		{
			count++;
		}

		
	}
	if( ( GetKeyState( VK_DOWN ) & 0x8000 ) && ( *y<LIMIT_BOTTOM ) )
	{
		if( count%2 == 0 )
		{
			(*y)++;
			count++;
		}
		else
		{
			count++;
		}
	}
}


int SetDxy( attack* pattack, pos _me, int mode )		// 전달된 '눈초리'의 dx, dy ( 일정 시간당 이동할 '눈초리'의 방향과 거리 ) 설정
{
	double width = pattack->x -  _me.x;
	double height = pattack->y - _me.y;
	int Hello = 30;     //직선 공격일때만 해놔요

	/*
	if		 ( width == 0  && height != 0 )		{ pattack->dx = 0;	pattack->dy = ( height>0 ) ? width / Hello * ( -1 )  : width / Hello * ( +1 ) ; }
	else if ( height == 0 && width != 0  )		{ pattack->dy = 0;	pattack->dx = ( width >0 ) ? height / Hello * ( -1 )  : height / Hello * ( +1 ) ; }
	else
	{
		if ( abs( width ) > abs( height ) )
		{
			pattack->dx = ( width>0 ) ? width / Hello / 2 * ( -1 )  : width / Hello / 2 * ( +1 ) ;
			pattack->dy = -height / Hello ;//abs( width );
		}
		else if ( abs( width ) < abs( height ) )
		{
			pattack->dy = ( height>0 ) ? height / Hello * ( -1 )  : height / Hello * ( +1 ) ;
			pattack->dx = -width / Hello ; //abs( height );
		}
		else if (abs( width ) == abs( height ) )
		{
			pattack->dx = ( width>0 ) ? width / Hello * ( -1 )  : width / Hello * ( +1 ) ;
			pattack->dy = ( height>0) ? height / Hello * ( -1 )  : height / Hello * ( +1 ) ; 
		}
		
	}
	*/
	if( mode == 1 )
	{
		pattack->dx = -1;
		pattack->dy = height / (( width / pattack->dx ) );
	}

	
	else 
	{	
		if		 ( width == 0  && height != 0 )		{ pattack->dx = 0;	pattack->dy = ( height>0 ) ? -1 : +1 ; }
		else if ( height == 0 && width != 0  )		{ pattack->dy = 0;	pattack->dx = ( width >0 ) ? -1 : +1 ; }
		else
		{
			if ( abs( width ) > abs( height ) )
			{
				pattack->dx = ( width>0 ) ? -1 : +1 ;
				pattack->dy = -height/abs( width );
			}
			else if ( abs( width ) < abs( height ) )
			{
				pattack->dy = ( height>0 ) ? -1 : +1 ;
				pattack->dx = -width/abs( height );
			}
			else if (abs( width ) == abs( height ) )
			{
				pattack->dx = ( width>0 ) ? -1 : +1 ;
				pattack->dy = ( height>0) ? -1 : +1 ;
			}
			
		}
	}
	return TRUE;
}

void AttackMove( attack* pattack, Boss from )
{
	static int dyCount = 0;
	const char CHAR_ATTACK[] = "♥";
	const char CHAR_ERASE[] = "  ";
	const int ATTACK_COLOR = 13;
	int (*Func) (attack* pattack);

	Func = ( from.mode == 1 ) ? LineAttackCheckInit : FollowAttackCheckInit;
	

	Better_printf2( CHAR_ERASE, (int)pattack->x, pattack->y, ATTACK_COLOR );
	if ( from.mode == 1 )
	{
		pattack->x += ( pattack->dx ) * 1;
		pattack->y += ( pattack->dy ) * 1; 
	}
	else if ( from.mode == 2 )
	{
		pattack->x += ( pattack->dx ) * 0.5;
		pattack->y += ( pattack->dy ) * 0.1; 
		( pattack->leftTimeToInit )--;
	}
	
	
	Better_printf2( CHAR_ATTACK, (int)pattack->x, pattack->y, ATTACK_COLOR );

	 

	if( CheckInit( from , pattack ) == TRUE )
	{
		Better_printf2( CHAR_ERASE, (int)pattack->x, pattack->y, 15);
		InitAttack( pattack, from, coolTime, me );
	}
}

void InitAttack( attack* pattack, Boss boss, int _coolTime, pos _me )
{
	const int MAXTIMETOINIT = 300;
	pattack->x = boss.x;
	pattack->y = boss.y+5;
	SetDxy( pattack, _me, 1 );

	pattack->leftTimeToInit = MAXTIMETOINIT;
}

int CheckInit( Boss boss , attack* pattack )
{
	if( boss.mode == 1 )
		return LineAttackCheckInit( pattack );
	else if ( boss.mode == 2 )
		return FollowAttackCheckInit( pattack );
}


int FollowAttackCheckInit( attack* pattack )
{
	if( pattack->leftTimeToInit <= 0 )
		return TRUE;
	else 
		return FALSE;
}


int LineAttackCheckInit( attack* pattack )
{
	if ( pattack->x < 3 || pattack->x > 67 || pattack->y < 3 || pattack->y > 21 )
		return TRUE;
	else 
		return FALSE;
}


int CheckHit( attack* pattack, pos me )
{
	if ( (int)(pattack->x -  me.x) == 0 && (int)(pattack->y - me.y) == 0 )
		{
			return TRUE;		
		}
	else 
		return FALSE;
}

void ShowHPBar( int hp, int x, int y, char* str )
{
	SetCurPos2( x, y );
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
	printf("%s", str);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
	printf(" %d      ", hp);
}

void LaunchMyAttack( pos me , myattack* pmyattack)
{
	int i;
	for( i=0 ; i<100 ; i++ )
	{
		if( pmyattack[i].on == FALSE)
			break;
	}
	pmyattack[i].x = me.x+2;
	pmyattack[i].y = me.y;
	pmyattack[i].on = TRUE;
}

void MoveMyAttack( myattack* pmyattack, Boss* boss )
{
	int i;
	for( i=0 ; i<100 ; i++)
	{
		if( pmyattack[i].on == TRUE )
		{
			Better_printf2( "  ", pmyattack[i].x, pmyattack[i].y, 15 );
			pmyattack[i].x += 1;
			if ( pmyattack[i].x > 62 )
			{
				pmyattack[i].on = FALSE;
			}
			else if ( pmyattack[i].y >=  boss->y && pmyattack[i].y <= boss->y + 10 && pmyattack[i].x >= boss->x )
			{
				boss->hp -= 5;
				Better_printf2( "⊙", pmyattack[i].x, pmyattack[i].y, 12 );
			}

			else
			{
				Better_printf2( "*", pmyattack[i].x, pmyattack[i].y, 15 );
			}
		}

	}

}

void ChargeLeftAttack( int* leftAttack )
{
	static int count;

	if( count%10 == 0 )
		(*leftAttack) ++;
	count++;
}

void ShowLeftAttack( int leftAttack, int x, int y )
{
	char left[15];
	char leftstr[11] = "남은 별 : ";
	_itoa_s( leftAttack, left, 10 );
	strcat_s( left, strlen( left ) + 3, "  " );

	Better_printf2( leftstr, x, y, 11 );
	Better_printf2( left, x + strlen( leftstr ), y, 15 );
}

void DrawBoss( Boss boss, int line )
{
	int i;
	const int COLOR = 15;
	static int count = 0;
	static BOOL b1 = TRUE;

	if ( b1 == TRUE )
	{
		for( i=0 ; i<line ; i++ )
		{
			Better_printf2( BossDefault1[i], boss.x, boss.y+i, COLOR );
		}
	}
	else if ( b1 == FALSE )
	{
		for( i=0 ; i<line ; i++ )
		{
			Better_printf2( BossDefault2[i], boss.x, boss.y+i, COLOR );
		}
	}

	if ( ++count == 3 )
	{
		count = 0;
		b1 = !b1;
	}

}


void Help2()
{
	int speed = 70, speed2 = speed/2;
	int color1 = 11, color2 = 12;

	Appear2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 4, speed, color1);
	Appear2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 9, speed, color1);
	Appear2( "- 이긴 사람 -", 5, 5, speed, color1 );
	Appear2( "방향 키  :  상 - W   하 - S   좌 - A   우 - D", 5, 7, speed, color1 );
	Appear2( "공격 : SPACE", 5, 8, speed, color1 );
	
	Sleep( 500 );

	Appear2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 9, speed, color2);
	Appear2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 14, speed, color2);
	Appear2( "- 진 사람 -", 5, 10, speed, color2 );
	Appear2( "방향 키  :  상 -↑   하 -↓   좌 -←   우 -→", 5, 12, speed, color2 );
	Appear2( "공격방식 바꾸기 : ENTER", 5, 13, speed, color2 );
	
	while( 1 )
	{
		if ( _kbhit() && _getch() == VK_ESCAPE )
		{
			Fade2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 4, speed2, color1);
			Fade2( "- 이긴 사람 -", 5, 5, speed2, color1 );
			Fade2( "방향 키  :  상 - W   하 - S   좌 - A   우 - D", 5, 7, speed2, color1 );
			Fade2( "공격 : SPACE", 5, 8, speed2, color1 );
			Fade2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 9, speed2, color1);
		
			//Fade2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 9, speed2, color2);
			Fade2( "- 진 사람 -", 5, 10, speed2, color2 );
			Fade2( "방향 키  :  상 -↑   하 -↓   좌 -←   우 -→", 5, 12, speed2, color2 );
			Fade2( "공격방식 바꾸기 : ENTER", 5, 13, speed2, color2 );
			Fade2( "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =", 5, 14, speed2, color2);
			break;
		}
			
	}

}
