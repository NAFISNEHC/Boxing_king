#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <iomanip>
#include <windows.h>
#pragma comment( lib, "winmm.lib" )
#define KEY_DOWN( VK_NONAME ) ( (GetAsyncKeyState( VK_NONAME ) & 0x8000) ? 1 : 0)	//键盘监听设置
#define Width 1200				//画布宽
#define Height 600				//画布高
using namespace std;

bool	flag	= 0;				//开局朝右
int	x	= 84;				//横坐标
int	y	= 370;				//竖坐标
int	i;					//循环变量
int 	j;					//循环变量


/*****************定义加载类******************/
class load
{
public:

	load();					//构造函数


	void loading();				//加载进度图
	
	
	void loadBJ();				//加载背景图


	void loadImg();				//加载行走图


	void loadStop();			//加载站立图


	void loadQuan();			//加载轻拳图


	void loadTui();				//加载轻踢图

	
	void loadDun();				//加载下蹲图


	void loadDunQ();			//加载蹲拳图


	void loadDunT();			//加载蹲踢图


	void loadSkip();			//加载跳跃图


	void loadSkipQ();			//加载跳拳图


	void loadSkipT();			//加载跳踢图


	void loadMiss();			//加载闪避图


	void loadPow();				//加载爆气图


	void loadSkillone();			//加载技能1图


	void loadSkilltwo();			//加载技能2图


protected:
	char Loadbuff[512];			//进度缓冲数组

	char Rbuff[512];			//右行走缓冲数组
	char Lbuff[512];			//左行走缓冲数组

	char RStopbuff[512];			//右站立缓冲数组
	char LStopbuff[512];			//左站立缓冲数组

	char RQuanbuff[512];			//右轻拳缓冲数组
	char LQuanbuff[512];			//左轻拳缓冲数组

	char RTuibuff[512];			//右轻踢缓冲数组
	char LTuibuff[512];			//左轻踢缓冲数组

	char RDunbuff[512];			//右下蹲缓冲数组
	char LDunbuff[512];			//左下蹲缓冲数组

	char RDunTbuff[512];			//右蹲踢缓冲数组
	char LDunTbuff[512];			//左蹲踢缓冲数组

	char RDunQbuff[512];			//右蹲拳缓冲数组
	char LDunQbuff[512];			//左蹲拳缓冲数组

	char RSkipbuff[512];			//右跳跃缓冲数组
	char LSkipbuff[512];			//左跳跃缓冲数组

	char RSkipQbuff[512];			//右跳拳缓冲数组
	char LSkipQbuff[512];			//左跳拳缓冲数组

	char RSkipTbuff[512];			//右跳踢缓冲数组
	char LSkipTbuff[512];			//左跳踢缓冲数组

	char RMissbuff[512];			//右闪避缓冲数组
	char LMissbuff[512];			//左闪避缓冲数组

	char RPowbuff[512];			//右爆气缓冲数组
	char LPowbuff[512];			//左爆气缓冲数组

	char RSkillonebuff[512];		//右技能1缓冲数组
	char LSkillonebuff[512];		//左技能1缓冲数组

	char RSkilltwobuff[512];		//右技能2缓冲数组
	char LSkilltwobuff[512];		//左技能2缓冲数组

	char Rymbuff[512];			//右行走掩码缓冲数组
	char Lymbuff[512];			//左行走掩码缓冲数组

	char RStopymbuff[512];			//右站立掩码缓冲数组
	char LStopymbuff[512];			//左站立掩码缓冲数组

	char RQuanymbuff[512];			//右轻拳掩码缓冲数组
	char LQuanymbuff[512];			//左轻拳掩码缓冲数组

	char RTuiymbuff[512];			//右轻踢掩码缓冲数组
	char LTuiymbuff[512];			//左轻踢掩码缓冲数组

	char RDunymbuff[512];			//右下蹲掩码缓冲数组
	char LDunymbuff[512];			//左下蹲掩码缓冲数组

	char RDunTymbuff[512];			//右蹲踢掩码缓冲数组
	char LDunTymbuff[512];			//左蹲踢掩码缓冲数组

	char RDunQymbuff[512];			//右蹲拳掩码缓冲数组
	char LDunQymbuff[512];			//左蹲拳掩码缓冲数组

	char RSkipymbuff[512];			//右跳跃掩码缓冲数组
	char LSkipymbuff[512];			//左跳跃掩码缓冲数组

	char RSkipQymbuff[512];			//右跳拳掩码缓冲数组
	char LSkipQymbuff[512];			//左跳拳掩码缓冲数组

	char RSkipTymbuff[512];			//右跳踢掩码缓冲数组
	char LSkipTymbuff[512];			//左跳踢掩码缓冲数组

	char RMissymbuff[512];			//右闪避掩码缓冲数组
	char LMissymbuff[512];			//左闪避掩码缓冲数组

	char RPowymbuff[512];			//右爆气掩码缓冲数组
	char LPowymbuff[512];			//左爆气掩码缓冲数组

	char RSkilloneymbuff[512];		//右技能1掩码缓冲数组
	char LSkilloneymbuff[512];		//左技能1掩码缓冲数组

	char RSkilltwoymbuff[512];		//右技能2掩码缓冲数组
	char LSkilltwoymbuff[512];		//左技能2掩码缓冲数组

	char BJbuff[512];			//背景缓冲数组

	IMAGE Load[13];				//加载图数组

	IMAGE Rimg[6];				//右行走图数组
	IMAGE Limg[6];				//左行走图数组

	IMAGE RStop[17];			//右站立图数组
	IMAGE LStop[17];			//左站立图数组

	IMAGE RQuan[6];				//右轻拳图数组
	IMAGE LQuan[6];				//左轻拳图数组
	
	IMAGE RTui[9];				//右轻踢图数组
	IMAGE LTui[9];				//左轻踢图数组

	IMAGE RDun[3];				//右下蹲图数组
	IMAGE LDun[3];				//左下蹲图数组

	IMAGE RDunT[7];				//右蹲踢图数组
	IMAGE LDunT[7];				//左蹲踢图数组

	IMAGE RDunQ[7];				//右蹲拳图数组
	IMAGE LDunQ[7];				//左蹲拳图数组

	IMAGE RSkip[17];			//右跳跃图数组
	IMAGE LSkip[17];			//左跳跃图数组

	IMAGE RSkipQ[4];			//右跳拳图数组
	IMAGE LSkipQ[4];			//左跳拳图数组

	IMAGE RSkipT[5];			//右跳踢图数组
	IMAGE LSkipT[5];			//左跳踢图数组

	IMAGE RMiss[10];			//右闪避图数组
	IMAGE LMiss[10];			//左闪避图数组

	IMAGE RPow[19];				//右爆气图数组
	IMAGE LPow[19];				//左爆气图数组

	IMAGE RSkillone[19];			//右技能1图数组
	IMAGE LSkillone[19];			//左技能1图数组

	IMAGE RSkilltwo[47];			//右技能2图数组
	IMAGE LSkilltwo[47];			//左技能2图数组

	IMAGE Rimgym[6];			//右行走掩码图数组
	IMAGE Limgym[6];			//左行走掩码图数组

	IMAGE RStopym[17];			//右站立掩码图数组
	IMAGE LStopym[17];			//左站立掩码图数组

	IMAGE RQuanym[6];			//右轻拳掩码图数组
	IMAGE LQuanym[6];			//左轻拳掩码图数组

	IMAGE RTuiym[12];			//右轻踢掩码图数组
	IMAGE LTuiym[12];			//左轻踢掩码图数组

	IMAGE RDunym[3];			//右下蹲掩码图数组
	IMAGE LDunym[3];			//左下蹲掩码图数组

	IMAGE RDunTym[7];			//右蹲踢掩码图数组
	IMAGE LDunTym[7];			//左蹲踢掩码图数组

	IMAGE RDunQym[7];			//右蹲拳掩码图数组
	IMAGE LDunQym[7];			//左蹲拳掩码图数组

	IMAGE RSkipym[17];			//右跳跃掩码图数组
	IMAGE LSkipym[17];			//左跳跃掩码图数组

	IMAGE RSkipQym[4];			//右跳拳掩码图数组
	IMAGE LSkipQym[4];			//左跳拳掩码图数组

	IMAGE RSkipTym[5];			//右跳踢掩码图数组
	IMAGE LSkipTym[5];			//左跳踢掩码图数组

	IMAGE RMissym[10];			//右闪避掩码图数组
	IMAGE LMissym[10];			//左闪避掩码图数组

	IMAGE RPowym[19];			//右爆气掩码图数组
	IMAGE LPowym[19];			//左爆气掩码图数组

	IMAGE RSkilloneym[19];			//右技能1掩码图数组
	IMAGE LSkilloneym[19];			//左技能1掩码图数组

	IMAGE RSkilltwoym[47];			//右技能2掩码图数组
	IMAGE LSkilltwoym[47];			//左技能2掩码图数组

	IMAGE BJ[15];				//背景图数组

	IMAGE JM;				//界面图
	IMAGE XT;				//血条图
};


/*****************定义动作派生类******************/
class Action:virtual public load		//公有继承虚基类加载类
{
public:
	void Quan();				//轻拳


	void Tui();				//踢腿


	void DunQ();				//蹲拳


	void DunT();				//蹲踢


	void Dun();				//下蹲


	void Skip();				//跳跃
};


/*****************定义技能派生类******************/
class Skill:virtual public load			//公有继承虚基类加载类
{
public:
	void Skillone();			//技能1

	
	void Skilltwo();			//技能2

	
	void Pow();				//爆气

	
	void Miss();				//闪避
};


/*****************定义方向派生类******************/
class Direction:public Action, public Skill	//公有继承动作类和技能类
{
public:
	void Left();				//左行


	void Right();				//右行
};


/*****************定义菜单派生类******************/
class Menu:private Direction			//公有继承方向类
{
public:
	Menu();					//构造函数


	void Set();				//初始化设置


	void Operate();				//人物操纵
};


/*****************加载游戏******************/
void load::loading()
{
	int j = 3; 
	initgraph( Width, Height );		//设置画布

	//加载游戏进度
	while(j--)
	for(i=0;i<=12;i++)
	{
		memset( Loadbuff, 0, 512 );
		sprintf( Loadbuff,_T( "E:\\加载 (%d).jpg" ), i + 1 );
		loadimage( &Load[i], Loadbuff, 167, 15, true );
		putimage( 520, 300, &Load[i] );
		Sleep(50);
	}
}


/*****************加载背景******************/
void load::loadBJ()
{
	int n	= 100;
	
	for(i=0;i<=14;i++)
	{
		//加载背景图片
		memset( BJbuff, 0, 512 );
		sprintf( BJbuff,_T( "E:\\背景 (%d).jpg" ), i + 1 );
		loadimage( &BJ[i], BJbuff, Width, Height, true );
		Sleep(50);
	}
}


/*****************加载行走******************/
void load::loadImg()
{
	for(i=0;i<=5;i++)
	{
		//加载右行走图片
		memset( Rbuff, 0, 512 );
		memset( Rymbuff, 0, 512 );
		sprintf( Rbuff,_T( "E:\\走路右 (%d).jpg" ), i + 1 );
		sprintf( Rymbuff,_T( "E:\\走路右ym (%d).jpg" ), i + 1 );
		loadimage( &Rimg[i], Rbuff, 108, 190, true );
		loadimage( &Rimgym[i], Rymbuff, 108, 190, true );
		
		//加载左行走图片
		memset( Lbuff, 0, 512 );
		memset( Lymbuff, 0, 512 );
		sprintf( Lbuff,_T( "E:\\走路 (%d).jpg" ), i + 1 );
		sprintf( Lymbuff,_T( "E:\\走路左ym (%d).jpg" ), i + 1 );
		loadimage( &Limg[i], Lbuff, 108, 190, true );
		loadimage( &Limgym[i], Lymbuff, 108, 190, true );
	}
}


/*****************加载站立******************/
void load::loadStop()
{
	for(i=0;i<=16;i++)
	{
		//加载右站立图片
		memset( RStopbuff, 0, 512 );
		memset( RStopymbuff, 0, 512 );
		sprintf( RStopbuff,_T( "E:\\站立右 (%d).jpg" ), i + 1 );
		sprintf( RStopymbuff,_T( "E:\\站立右ym (%d).jpg" ), i + 1 );
		loadimage( &RStop[i], RStopbuff, 110, 190, true );
		loadimage( &RStopym[i], RStopymbuff, 110, 190, true );
			
		//加载左站立图片
		memset( LStopbuff, 0, 512 );
		memset( LStopymbuff, 0, 512 );
		sprintf( LStopbuff,_T( "E:\\站立 (%d).jpg" ), i + 1 );
		sprintf( LStopymbuff,_T( "E:\\站立左ym (%d).jpg" ), i + 1 );
		loadimage( &LStop[i], LStopbuff, 110, 190, true );
		loadimage( &LStopym[i], LStopymbuff, 110, 190, true );
	}
}


/*****************加载轻拳******************/
void load::loadQuan()
{
	for(i=0;i<=5;i++)
	{
		//加载右轻拳图片
		memset( RQuanbuff, 0, 512 );
		memset( RQuanymbuff, 0, 512 );
		sprintf( RQuanbuff,_T( "E:\\轻拳右 (%d).jpg" ), i + 1 );
		sprintf( RQuanymbuff,_T( "E:\\轻拳右ym (%d).jpg" ), i + 1 );
		loadimage( &RQuan[i], RQuanbuff, 135, 190, true );
		loadimage( &RQuanym[i], RQuanymbuff, 135, 190, true );

		//加载左轻拳图片
		memset( LQuanbuff, 0, 512 );
		memset( LQuanymbuff, 0, 512 );
		sprintf( LQuanbuff,_T( "E:\\轻拳 (%d).jpg" ), i + 1 );
		sprintf( LQuanymbuff,_T( "E:\\轻拳左ym (%d).jpg" ), i + 1 );
		loadimage( &LQuan[i], LQuanbuff, 135, 190, true );
		loadimage( &LQuanym[i], LQuanymbuff, 135, 190, true );
	}
}


/*****************加载轻踢******************/
void load::loadTui()
{
	for(i=0;i<=8;i++)
	{
		//加载右踢腿图片
		memset( RTuibuff, 0, 512 );
		memset( RTuiymbuff, 0, 512 );
		sprintf( RTuibuff,_T( "E:\\踢腿右 (%d).jpg" ), i + 1 );
		sprintf( RTuiymbuff,_T( "E:\\踢腿右ym (%d).jpg" ), i + 1 );
		loadimage( &RTui[i], RTuibuff, 195, 190, true );
		loadimage( &RTuiym[i], RTuiymbuff, 195, 190, true );

		//加载左踢腿图片
		memset( LTuibuff, 0, 512 );
		memset( LTuiymbuff, 0, 512 );
		sprintf( LTuibuff,_T( "E:\\踢腿 (%d).jpg" ), i + 1 );
		sprintf( LTuiymbuff,_T( "E:\\踢腿左ym (%d).jpg" ), i + 1 );
		loadimage( &LTui[i], LTuibuff, 195, 190, true );
		loadimage( &LTuiym[i], LTuiymbuff, 195, 190, true );

	}
}


/*****************加载下蹲******************/
void load::loadDun()
{
	for(i=0;i<=8;i++)
	{
		//加载右蹲图片
		memset( RDunbuff, 0, 512 );
		memset( RDunymbuff, 0, 512 );
		sprintf( RDunbuff,_T( "E:\\下蹲右 (%d).jpg" ), i + 1 );
		sprintf( RDunymbuff,_T( "E:\\下蹲右ym (%d).jpg" ), i + 1 );
		loadimage( &RDun[i], RDunbuff, 110, 190, true );
		loadimage( &RDunym[i], RDunymbuff, 110, 190, true );

		//加载左蹲图片
		memset( LDunbuff, 0, 512 );
		memset( LDunymbuff, 0, 512 );
		sprintf( LDunbuff,_T( "E:\\下蹲 (%d).jpg" ), i + 1 );
		sprintf( LDunymbuff,_T( "E:\\下蹲左ym (%d).jpg" ), i + 1 );
		loadimage( &LDun[i], LDunbuff, 110, 190, true );
		loadimage( &LDunym[i], LDunymbuff, 110, 190, true );
	}
}


/*****************加载蹲拳******************/
void load::loadDunQ()
{
	for(i=0;i<=6;i++)
	{
		//加载右蹲拳图片
		memset( RDunQbuff, 0, 512 );
		memset( RDunQymbuff, 0, 512 );
		sprintf( RDunQbuff,_T( "E:\\蹲拳右 (%d).jpg" ), i + 1 );
		sprintf( RDunQymbuff,_T( "E:\\蹲拳右ym (%d).jpg" ), i + 1 );
		loadimage( &RDunQ[i], RDunQbuff, 134, 122, true );
		loadimage( &RDunQym[i], RDunQymbuff, 134, 122, true );

		//加载左蹲拳图片
		memset( LDunQbuff, 0, 512 );
		memset( LDunQymbuff, 0, 512 );
		sprintf( LDunQbuff,_T( "E:\\蹲拳 (%d).jpg" ), i + 1 );
		sprintf( LDunQymbuff,_T( "E:\\蹲拳左ym (%d).jpg" ), i + 1 );
		loadimage( &LDunQ[i], LDunQbuff, 134, 122, true );
		loadimage( &LDunQym[i], LDunQymbuff, 134, 122, true );
	}
}


/*****************加载蹲踢******************/
void load::loadDunT()
{
	for(i=0;i<=6;i++)
	{
		//加载右蹲踢图片
		memset( RDunTbuff, 0, 512 );
		memset( RDunTymbuff, 0, 512 );
		sprintf( RDunTbuff,_T( "E:\\蹲踢右 (%d).jpg" ), i + 1 );
		sprintf( RDunTymbuff,_T( "E:\\蹲踢右ym (%d).jpg" ), i + 1 );
		loadimage( &RDunT[i], RDunTbuff, 170, 127, true );
		loadimage( &RDunTym[i], RDunTymbuff, 170, 127, true );

		//加载左蹲踢图片
		memset( LDunTbuff, 0, 512 );
		memset( LDunTymbuff, 0, 512 );
		sprintf( LDunTbuff,_T( "E:\\蹲踢 (%d).jpg" ), i + 1 );
		sprintf( LDunTymbuff,_T( "E:\\蹲踢左ym (%d).jpg" ), i + 1 );
		loadimage( &LDunT[i], LDunTbuff, 170, 127, true );
		loadimage( &LDunTym[i], LDunTymbuff, 170, 127, true );
	}
}


/*****************加载跳跃******************/
void load::loadSkip()
{
	for(i=0;i<=12;i++)
	{
		//加载右跳图片
		memset( RSkipbuff, 0, 512 );
		memset( RSkipymbuff, 0, 512 );
		sprintf( RSkipbuff,_T( "E:\\跳右 (%d).jpg" ), i + 1 );
		sprintf( RSkipymbuff,_T( "E:\\跳右ym (%d).jpg" ), i + 1 );
		loadimage( &RSkip[i], RSkipbuff, 210, 350, true );
		loadimage( &RSkipym[i], RSkipymbuff, 210, 350, true );

		//加载左跳图片
		memset( LSkipbuff, 0, 512 );
		memset( LSkipymbuff, 0, 512 );
		sprintf( LSkipbuff,_T( "E:\\跳 (%d).jpg" ), i + 1 );
		sprintf( LSkipymbuff,_T( "E:\\跳左ym (%d).jpg" ), i + 1 );
		loadimage( &LSkip[i], LSkipbuff, 210, 350, true );
		loadimage( &LSkipym[i], LSkipymbuff, 210, 350, true );
	}
}


/*****************加载跳踢******************/
void load::loadSkipT()
{
	for(i=0;i<=4;i++)
	{
		//加载右跳踢图片
		memset( RSkipTbuff, 0, 512 );
		memset( RSkipTymbuff, 0, 512 );
		sprintf( RSkipTbuff,_T( "E:\\跳踢右 (%d).jpg" ), i + 1 );
		sprintf( RSkipTymbuff,_T( "E:\\跳踢右ym (%d).jpg" ), i + 1 );
		loadimage( &RSkipT[i], RSkipTbuff, 204, 349, true );
		loadimage( &RSkipTym[i], RSkipTymbuff, 204, 349, true );

		//加载左跳踢图片
		memset( LSkipTbuff, 0, 512 );
		memset( LSkipTymbuff, 0, 512 );
		sprintf( LSkipTbuff,_T( "E:\\跳踢 (%d).jpg" ), i + 1 );
		sprintf( LSkipTymbuff,_T( "E:\\跳踢左ym (%d).jpg" ), i + 1 );
		loadimage( &LSkipT[i], LSkipTbuff, 204, 349, true );
		loadimage( &LSkipTym[i], LSkipTymbuff, 204, 349, true );
	}
}


/*****************加载跳拳******************/
void load::loadSkipQ()
{
	for(i=0;i<=3;i++)
	{
		//加载右跳拳图片
		memset( RSkipQbuff, 0, 512 );
		memset( RSkipQymbuff, 0, 512 );
		sprintf( RSkipQbuff,_T( "E:\\跳拳右 (%d).jpg" ), i + 1 );
		sprintf( RSkipQymbuff,_T( "E:\\跳拳右ym (%d).jpg" ), i + 1 );
		loadimage( &RSkipQ[i], RSkipQbuff, 212, 343, true );
		loadimage( &RSkipQym[i], RSkipQymbuff, 212, 343, true );

		//加载左跳拳图片
		memset( LSkipQbuff, 0, 512 );
		memset( LSkipQymbuff, 0, 512 );
		sprintf( LSkipQbuff,_T( "E:\\跳拳 (%d).jpg" ), i + 1 );
		sprintf( LSkipQymbuff,_T( "E:\\跳拳左ym (%d).jpg" ), i + 1 );
		loadimage( &LSkipQ[i], LSkipQbuff, 212, 343, true );
		loadimage( &LSkipQym[i], LSkipQymbuff, 212, 343, true );
	}
}


/*****************加载闪避******************/
void load::loadMiss()
{
	for(i=0;i<=9;i++)
	{
		//加载右闪避图片
		memset( RMissbuff, 0, 512 );
		memset( RMissymbuff, 0, 512 );
		sprintf( RMissbuff,_T( "E:\\闪避右 (%d).jpg" ), i + 1 );
		sprintf( RMissymbuff,_T( "E:\\闪避右ym (%d).jpg" ), i + 1 );
		loadimage( &RMiss[i], RMissbuff, 272, 190, true );
		loadimage( &RMissym[i], RMissymbuff, 272, 190, true );

		//加载左闪避图片
		memset( LMissbuff, 0, 512 );
		memset( LMissymbuff, 0, 512 );
		sprintf( LMissbuff,_T( "E:\\闪避 (%d).jpg" ), i + 1 );
		sprintf( LMissymbuff,_T( "E:\\闪避左ym (%d).jpg" ), i + 1 );
		loadimage( &LMiss[i], LMissbuff, 272, 190, true );
		loadimage( &LMissym[i], LMissymbuff, 272, 190, true );
	}
}


/*****************加载爆气******************/
void load::loadPow()
{
	for(i=0;i<=18;i++)
	{
		//加载右爆气图片
		memset( RPowbuff, 0, 512 );
		memset( RPowymbuff, 0, 512 );
		sprintf( RPowbuff,_T( "E:\\爆气右 (%d).jpg" ), i + 1 );
		sprintf( RPowymbuff,_T( "E:\\爆气右ym (%d).jpg" ), i + 1 );
		loadimage( &RPow[i], RPowbuff, 237, 190, true );
		loadimage( &RPowym[i], RPowymbuff, 237, 190, true );

		//加载左爆气图片
		memset( LPowbuff, 0, 512 );
		memset( LPowymbuff, 0, 512 );
		sprintf( LPowbuff,_T( "E:\\爆气 (%d).jpg" ), i + 1 );
		sprintf( LPowymbuff,_T( "E:\\爆气左ym (%d).jpg" ), i + 1 );
		loadimage( &LPow[i], LPowbuff, 237, 190, true );
		loadimage( &LPowym[i], LPowymbuff, 237, 190, true );
	}
}


/*****************加载技能1******************/
void load::loadSkillone()
{
	for(i=0;i<=18;i++)
	{
		//加载右技能1图片
		memset( RSkillonebuff, 0, 512 );
		memset( RSkilloneymbuff, 0, 512 );
		sprintf( RSkillonebuff,_T( "E:\\技能1右 (%d).jpg" ), i + 1 );
		sprintf( RSkilloneymbuff,_T( "E:\\技能1右ym (%d).jpg" ), i + 1 );
		loadimage( &RSkillone[i], RSkillonebuff, 305, 350, true );
		loadimage( &RSkilloneym[i], RSkilloneymbuff, 305, 350, true );

		//加载左技能1图片
		memset( LSkillonebuff, 0, 512 );
		memset( LSkilloneymbuff, 0, 512 );
		sprintf( LSkillonebuff,_T( "E:\\技能1 (%d).jpg" ), i + 1 );
		sprintf( LSkilloneymbuff,_T( "E:\\技能1左ym (%d).jpg" ), i + 1 );
		loadimage( &LSkillone[i], LSkillonebuff, 305, 350, true );
		loadimage( &LSkilloneym[i], LSkilloneymbuff, 305, 350, true );
	}
}


/*****************加载技能2******************/
void load::loadSkilltwo()
{
	for(i=0;i<=46;i++)
	{
		//加载右技能2图片
		memset( RSkilltwobuff, 0, 512 );
		memset( RSkilltwoymbuff, 0, 512 );
		sprintf( RSkilltwobuff,_T( "E:\\技能2右 (%d).jpg" ), i + 1 );
		sprintf( RSkilltwoymbuff,_T( "E:\\技能2右ym (%d).jpg" ), i + 1 );
		loadimage( &RSkilltwo[i], RSkilltwobuff, 305, 325, true );
		loadimage( &RSkilltwoym[i], RSkilltwoymbuff, 305, 325, true );

		//加载左技能2图片
		memset( LSkilltwobuff, 0, 512 );
		memset( LSkilltwoymbuff, 0, 512 );
		sprintf( LSkilltwobuff,_T( "E:\\技能2 (%d).jpg" ), i + 1 );
		sprintf( LSkilltwoymbuff,_T( "E:\\技能2左ym (%d).jpg" ), i + 1 );
		loadimage( &LSkilltwo[i], LSkilltwobuff, 305, 325, true );
		loadimage( &LSkilltwoym[i], LSkilltwoymbuff, 305, 325, true );
	}
}


/*****************自动调用各加载******************/
load::load()
{
	loading();
	
	loadBJ();

	loadImg();

	loadStop();

	loadQuan();

	loadTui();

	loadDun();

	loadDunQ();

	loadDunT();

	loadSkip();

	loadSkipQ();

	loadSkipT();

	loadMiss();

	loadPow();

	loadSkillone();

	loadSkilltwo();
}


/*****************左行走******************/
void Direction::Left()
{
	int j;
	flag = 1;		//方向设置为左
	for(j=0;j<=5;j++)
	{
		if( KEY_DOWN( 'A' ) )	//监听是否按键
		{
			//行进触发
			if( KEY_DOWN( 'J' ) )
			{
				Quan();
			}
			else if( KEY_DOWN( 'K' ) )
			{
				Tui();
			}
			else if( KEY_DOWN( 'W' ) )
			{
				Skip();
			}
			else if( KEY_DOWN( 'L') )
			{
				Miss();
			}
			else if( KEY_DOWN( 'U' ) )
			{
				Skillone();
			}
			else if( KEY_DOWN( 'I' ) )
			{
				Skilltwo();
			}
			else
			{
				putimage( 0, 0, &BJ[j] );
				putimage( 15, 20, &XT );		//刷新血条
				putimage( x + 1, y, &Limgym[j], SRCAND );
				putimage( x, y, &Limg[j], SRCPAINT );
			}

			if( x > -10 )		//位置更新
				x -= 15;

			Sleep(65);		//时间间隔
		}
	}
}


/*****************右行走******************/
void Direction::Right()
{
	int j;
	flag = 0;		//方向设置为右
	for(j=0;j<=5;j++)
	{
		if( KEY_DOWN( 'D' ) )		//监听是否按键
		{
			//行进触发
			if( KEY_DOWN( 'J' ) )
			{
				Quan();
			}
			else if( KEY_DOWN( 'K' ) )
			{
				Tui();
			}
			else if( KEY_DOWN( 'W' ) )
			{
				Skip();
			}
			else if( KEY_DOWN( 'L' ) )
			{
				Miss();
			}
			else if( KEY_DOWN( 'U' ) )
			{
				Skillone();
			}
			else if( KEY_DOWN( 'I' ) )
			{
				Skilltwo();
			}
			else
			{
				putimage( 0, 0, &BJ[j] );
				putimage( 15, 20, &XT );		//刷新血条
				putimage( x - 1, y, &Rimgym[j], SRCAND );
				putimage( x, y, &Rimg[j], SRCPAINT );
			}

			if ( x < 1100 )		//位置更新
				x += 15;

			Sleep(65);		//时间间隔
		}
	}
}


/*****************轻拳******************/
void Action::Quan()
{
	int j;
	for(j=0;j<=5;j++)
	{
		if( flag )		//判断方向
		{
			//左轻拳
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 24, y, &LQuanym[j], SRCAND );
			putimage( x - 25, y, &LQuan[j], SRCPAINT );

			Sleep(45);		//时间间隔
		}
		else
		{
			//右轻拳
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 1, y, &RQuanym[j], SRCAND );
			putimage( x, y, &RQuan[j], SRCPAINT );

			Sleep(45);		//时间间隔
		}
	}
}


/*****************轻踢******************/
void Action::Tui()
{
	int j;
	for(j=0;j<=8;j++)
	{
		if( flag )		//判断方向
		{
			//左踢腿
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 83, y, &LTuiym[j], SRCAND );
			putimage( x - 85, y, &LTui[j], SRCPAINT );

			Sleep(45);		//时间间隔
		}
		else
		{
			//右踢腿
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 2, y, &RTuiym[j], SRCAND );
			putimage( x, y, &RTui[j], SRCPAINT );

			Sleep(45);		//时间间隔
		}
	}
}


/*****************蹲踢******************/
void Action::DunT()
{
	int j;
	for(j=0;j<=6;j++)
	{
		if( flag )		//判断方向
		{
			//左踢
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 53, y + 58, &LDunTym[j], SRCAND );
			putimage( x - 54, y + 60, &LDunT[j], SRCPAINT );
			
			Sleep(40);		//时间间隔
		}
		else
		{
			//右踢
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 5, y + 58, &RDunTym[j], SRCAND );
			putimage( x - 4, y + 60, &RDunT[j], SRCPAINT );

			Sleep(40);		//时间间隔
		}
	}
}


/*****************蹲拳******************/
void Action::DunQ()
{
	int j;
	for(j=0;j<=6;j++)
	{
		if( flag )		//判断方向
		{
			//左轻拳
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 30, y + 65, &LDunQym[j], SRCAND );
			putimage( x - 32, y + 67, &LDunQ[j], SRCPAINT );

			Sleep(30);		//时间间隔
		}
		else
		{
			//右轻拳
			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x + 2, y + 65, &RDunQym[j], SRCAND );
			putimage( x + 3, y + 67, &RDunQ[j], SRCPAINT );

			Sleep(30);		//时间间隔
		}
	}
}


/*****************下蹲******************/
void Action::Dun()
{
	int j;
	if( flag )		//判断方向
	{
		putimage( x + 2, y, &LDunym[0], SRCAND );
		putimage( x, y, &LDun[0], SRCPAINT );
	}
	else
	{
		putimage( x - 1, y, &RDunym[0], SRCAND );
		putimage( x, y, &RDun[0], SRCPAINT );
	}

	//保持下蹲
	while( KEY_DOWN( 'S' ) )		//监听是否按键
	{
		for(j=9;j<=10;j++)
		{
			if( KEY_DOWN( 'S' ) )
			{
				if( flag )
				{	
					//左蹲
					putimage( 0, 0, &BJ[j] );
					putimage( 15, 20, &XT );		//刷新血条
					putimage( x + 2, y, &LDunym[1], SRCAND );
					putimage( x, y, &LDun[1], SRCPAINT );

					//行为触发
					if( KEY_DOWN( 'K' ) )
					DunT();
					else if( KEY_DOWN( 'J' ) )
					DunQ();

					Sleep(60);		//时间间隔
				}
				else
				{
					//右蹲
					putimage( 0, 0, &BJ[j] );
					putimage( 15, 20, &XT );		//刷新血条
					putimage( x - 1, y, &RDunym[1], SRCAND );
					putimage( x, y, &RDun[1], SRCPAINT );
					
					//刷新循环变量
					if(i == 15)
						i = 0;
					else
						i++;

					//行为触发
					if( KEY_DOWN( 'K' ) )
					DunT();
					else if( KEY_DOWN( 'J' ) )
					DunQ();

					Sleep(60);		//时间间隔
				}
			}
		}
	}
}


/*****************跳跃******************/
void Action::Skip()
{
	int j;
	while( KEY_DOWN( 'W' ) )		//监听是否按键
	{
		for(j=0;j<=12;j++)
		{
			if( flag )		//判断方向
			{	
				//行为触发
				if( KEY_DOWN( 'J' ) && j == 10 )
				{
					for(i=0;i<=3;i++)
					{
						putimage( 0, 0, &BJ[i] );
						putimage( 15, 20, &XT );		//刷新血条
						putimage( x - 65, y - 157, &LSkipQym[i], SRCAND );
						putimage( x - 65, y - 157, &LSkipQ[i], SRCPAINT );

						Sleep(55);		//时间间隔
					}
					break;
				}
				else if( KEY_DOWN( 'K' ) && j == 10 )
				{
					for(i=0;i<=4;i++)
					{
						putimage( 0, 0, &BJ[i] );
						putimage( 15, 20, &XT );		//刷新血条
						putimage( x - 65, y - 157, &LSkipTym[i], SRCAND );
						putimage( x - 65, y - 157, &LSkipT[i], SRCPAINT );

						Sleep(55);		//时间间隔
					}
					break;
				}

				//左跳后半部分
				putimage( 0, 0, &BJ[j] );
				putimage( 15, 20, &XT );		//刷新血条
				putimage( x - 65, y - 157, &LSkipym[j], SRCAND );
				putimage( x - 65, y - 157, &LSkip[j], SRCPAINT );

				//检测空中平移
				if( KEY_DOWN ( 'A' ) )
				{
					if( x > 0 )		//位置更新
						x -= 13;
				}
				else if ( KEY_DOWN ( 'D' ) )
				{
					if( x < 1100 )		//位置更新
						x += 13;
				}

				Sleep(50);		//时间间隔
			}
			else
			{
				//行为触发
				if( KEY_DOWN( 'J' ) && j==10 )
				{
					for(i=0;i<=3;i++)
					{
						putimage( 0, 0, &BJ[i] );
						putimage( 15, 20, &XT );		//刷新血条
						putimage( x - 35, y - 157, &RSkipQym[i], SRCAND );
						putimage( x - 35, y - 157, &RSkipQ[i], SRCPAINT );

						Sleep(55);		//时间间隔
					}
					break;
				}
				else if( KEY_DOWN( 'K' ) && j==10 )
				{
					for(i=0;i<=4;i++)
					{
						putimage( 0, 0, &BJ[i] );
						putimage( 15, 20, &XT );		//刷新血条
						putimage( x - 35, y - 157, &RSkipTym[i], SRCAND );
						putimage( x - 35, y - 157, &RSkipT[i], SRCPAINT );

						Sleep(55);		//时间间隔
					}
					break;
				}

				//右跳后半部分
				putimage( 0, 0, &BJ[j] );
				putimage( 15, 20, &XT );		//刷新血条
				putimage( x - 35, y - 157, &RSkipym[j], SRCAND );
				putimage( x - 35, y - 157, &RSkip[j], SRCPAINT );

				//检测空中平移
				if( KEY_DOWN ( 'A' ) )
				{
					if( x > 0 )		//位置更新
						x -= 10;
				}

				//右移
				else if( KEY_DOWN ( 'D' ) )
				{
					if( x < 1100 )		//位置更新
						x += 10;
				}

				Sleep(50);		//时间间隔
			}
		}
	}
}


/*****************技能1******************/
void Skill::Skillone()
{
	int j;
	for(j=0;j<=18;j++)
	{
		if( flag )		//判定方向
		{
			//左技能1
			if( j > 14 )
				putimage( 0, 0, &BJ[j-15]);
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			if( x <= 80 && j >= 4 )		//位置边界检测更新
				x += 10;

			putimage( x - 160, y - 160, &LSkilloneym[j], SRCAND );
			putimage( x - 160, y - 160, &LSkillone[j], SRCPAINT );

			Sleep(50);		//时间间隔
		}
		else
		{
			//右技能1
			if( j > 14 )
				putimage( 0, 0, &BJ[j-15]);
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			if( x >= 960 && j >= 4 )		//位置边界检测更新
				x -= 10;

			putimage( x + 20, y - 160, &RSkilloneym[j], SRCAND );
			putimage( x + 20, y - 160, &RSkillone[j], SRCPAINT );

			Sleep(50);		//时间间隔
		}
	}

	//判定方向位置更新
	if( flag )
		x -= 90;
	else
		x += 150;
}


/*****************技能2******************/
void Skill::Skilltwo()
{
	int j;
	for(j=0;j<=46;j++)
	{
		if( flag )		//判定方向
		{
			//左技能2

			//循环变量刷新
			if( j > 14 && j < 30 )
				putimage( 0, 0, &BJ[j-15] );
			else if( j > 29 && j < 45)
				putimage( 0, 0, &BJ[j-30] );
			else if( j > 44 )
				putimage( 0, 0, &BJ[j-45] );
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			if( x <= 80 && j >= 25 && j <= 31 )		//位置边界检测更新
				x += 20;

			putimage( x - 160, y - 140, &LSkilltwoym[j], SRCAND );
			putimage( x - 160, y - 140, &LSkilltwo[j], SRCPAINT );

			Sleep(40);		//时间间隔
		}
		else
		{
			//右技能2

			//循环变量刷新
			if( j > 14 && j < 30 )
				putimage( 0, 0, &BJ[j-15] );
			else if( j > 29 && j < 45 )
				putimage( 0, 0, &BJ[j-30] );
			else if( j > 44 )
				putimage( 0, 0, &BJ[j-45] );
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			if( x >= 1010 && j >= 25 && j <= 31 )		//位置边界检测更新
				x -= 15;
			putimage( x - 35, y - 141, &RSkilltwoym[j], SRCAND );
			putimage( x - 35, y - 140, &RSkilltwo[j], SRCPAINT );

			Sleep(40);		//时间间隔
		}
	}

	//判定方向位置更新
	if( flag )
		x -= 80;
	else
		x += 80;
}


/*****************爆气******************/
void Skill::Pow()
{
	int j;
	for(j=0;j<=18;j++)
	{
		if( flag )		//判定方向
		{
			//左爆气

			//循环变量刷新
			if( j > 14 )
				putimage( 0, 0, &BJ[j-15]);
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条	
			putimage( x - 70, y, &LPowym[j], SRCAND );
			putimage( x - 70, y, &LPow[j], SRCPAINT );

			Sleep(35);		//时间间隔
		}
		else
		{
			//右爆气

			//循环变量刷新
			if( j > 14 )
				putimage( 0, 0, &BJ[j-15]);
			else
				putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 50, y, &RPowym[j], SRCAND );
			putimage( x - 50, y, &RPow[j], SRCPAINT );

			Sleep(35);		//时间间隔
		}
	}
}


/*****************闪避******************/
void Skill::Miss()
{
	int j;
	for(j=0;j<=9;j++)
	{
		if( flag )		//判定方向
		{
			//左闪避

			//位置边界检测更新
			if( x < 125 )
				x += 14;

			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x - 160, y, &LMissym[j], SRCAND );
			putimage( x - 160, y, &LMiss[j], SRCPAINT );

			Sleep(50);		//时间间隔
		}
		else
		{
			//右闪避

			//位置边界检测更新
			if(x>965)
				x-=14;

			putimage( 0, 0, &BJ[j] );
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x, y, &RMissym[j], SRCAND );
			putimage( x, y, &RMiss[j], SRCPAINT );

			Sleep(50);		//时间间隔
		}
	}

	//判定方向位置更新
	if( flag )
		x -= 140;
	else
		x += 140;
}


/*****************设置******************/
void Menu::Set()
{
	while (1)
	{
		loadimage( &JM, "E:\\界面.jpg", Width, Height) ;		//加载开始界面
		putimage( 0, 0, &JM );
		PlaySound( "E:\\界面音乐.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );		//播放开始音乐

		while( getch() == 13 )		//按回车进入游戏
		Operate();
	}
}


/*****************人物操纵******************/
void Menu::Operate()
{
	char	op;
	int j	= 4;
	initgraph( Width, Height );		//设置画布
	PlaySound( "E:\\开打.wav", NULL, SND_FILENAME | SND_ASYNC );		//播放开打音乐

	while( j-- )
	{
		for(i=0;i<=16;i++)
		{
			putimage( 0, 0, &BJ[i] );
			if( i > 14 )
				putimage( 0, 0, &BJ[i-15]);
			putimage( 15, 20, &XT );		//刷新血条
			putimage( x + 1, y, &RStopym[i], SRCAND );
			putimage( x, y, &RStop[i], SRCPAINT );
			Sleep(50);
		}
	}

	PlaySound( "E:\\背景音乐.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );		//播放背景音乐
	while ( op != 27 )		//判断需要退出游戏
	{
		//监听是否按键
		while( !KEY_DOWN( 'A' ) && !KEY_DOWN( 'D' ) && !KEY_DOWN( 'J' ) && !KEY_DOWN( 'K' ) && !KEY_DOWN( 'S' ) && !KEY_DOWN( 'W' ) && !KEY_DOWN( 'O' ) && !KEY_DOWN( 'U' ) && !KEY_DOWN( 'I' ) )
		{
			for(j=0;j<=16;j++)
			{	
				if( !KEY_DOWN( 'A' ) && !KEY_DOWN( 'D' ) && !KEY_DOWN( 'J' ) && !KEY_DOWN( 'K' ) && !KEY_DOWN( 'S' ) && !KEY_DOWN( 'W' ) && !KEY_DOWN( 'O' ) && !KEY_DOWN( 'U' ) && !KEY_DOWN( 'I' ) )
				{	
					if( flag )			//判断方向
					{
						//循环变量刷新
						if( j > 14 )
							putimage( 0, 0, &BJ[j-15]);
						else
							putimage( 0, 0, &BJ[j] );
						putimage( 15, 20, &XT );		//刷新血条
						//左站立
						putimage( x + 2, y, &LStopym[j], SRCAND );
						putimage( x, y, &LStop[j], SRCPAINT );

						Sleep(60);		//时间间隔
					}
					else
					{
						//循环变量刷新
						if( j > 14 )
							putimage( 0, 0, &BJ[j-15]);
						else
							putimage( 0, 0, &BJ[j] );
						putimage( 15, 20, &XT );		//刷新血条
						//右站立
						putimage( x - 2, y, &RStopym[j], SRCAND );
						putimage( x, y, &RStop[j], SRCPAINT );

						Sleep(60);		//时间间隔
					}
				}
			}
		}
		op = getch();
		switch ( op )	//进行人物操作
		{
		case 'a':
		case 'A': while ( KEY_DOWN( 'A' ) )		//监听按键

				  Left();		//左行走

				  putimage( 0, 0, &BJ[j] );		//刷新背景与站立
				  putimage( 15, 20, &XT );		//刷新血条
				  putimage( x + 1, y, &LStopym[0], SRCAND );
				  putimage( x, y, &LStop[0], SRCPAINT );

				  flag = 1;		//定方向

				  break;

		case 'd':
		case 'D': while ( KEY_DOWN( 'D' ) )		//监听按键

				  Right();		//右行走

				  putimage( 0, 0, &BJ[j] );		//刷新背景与站立
				  putimage( 15, 20, &XT );		//刷新血条
				  putimage( x - 1, y, &RStopym[0], SRCAND );
				  putimage( x, y, &RStop[0], SRCPAINT );

			   	  flag = 0;		//定方向

				  break;

		case 's':
		case 'S': Dun();		//下蹲

				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					  putimage( x + 2, y, &LDunym[2], SRCAND );
					  putimage( x, y, &LDun[2], SRCPAINT );

					  putimage( x + 1, y, &LStopym[0], SRCAND );
					  putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					  putimage( x - 1, y, &RDunym[2], SRCAND );
					  putimage( x, y, &RDun[2], SRCPAINT );

					  putimage( x - 1, y, &RStopym[0], SRCAND );
					  putimage( x, y, &RStop[0], SRCPAINT );
				  }

				  break;
   
		case 'w':
		case 'W': Skip();		//跳跃
					
				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;
				
		case 'j':
		case 'J': while ( KEY_DOWN( 'J' ) )		//监听按键

				  Quan();		//轻拳

				  putimage( 0, 0, &BJ[j] );		//刷新背景
   				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;
				
		case 'k':
		case 'K': while ( KEY_DOWN( 'K' ) )		//监听按键

				  Tui();		//轻踢
				  
				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;
				
		case 'o':
		case 'O': if ( KEY_DOWN( 'O' ) )		//监听按键

				  Pow();		//爆气

				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;
				
		case 'u':
		case 'U': if ( KEY_DOWN( 'U' ) )		//监听按键

				  Skillone();		//技能1

				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条
	
				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;

		case 'i':
		case 'I': if ( KEY_DOWN( 'I' ) )		//监听按键

				  Skilltwo();		//技能2

				  putimage( 0, 0, &BJ[j] );		//刷新背景
				  putimage( 15, 20, &XT );		//刷新血条

				  if( flag )		//判断方向
				  {
					   putimage( x + 1, y, &LStopym[0], SRCAND );
					   putimage( x, y, &LStop[0], SRCPAINT );
				  }
				  else
				  {
					   putimage( x - 1, y, &RStopym[0], SRCAND );
					   putimage( x, y, &RStop[0], SRCPAINT );
				  }
				  break;

		default: break;		//无效按键跳出
		}
	}
}


/*****************自动调用设置******************/
Menu::Menu()
{
	Set();
}


/*****************实例化对象******************/
int main()
{
	Menu wing;
	return 0;
}
