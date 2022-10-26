#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//思路
//1.框架（全局变量、数据初始化、用户输入、输出、无关、画面）
//2、顺序 

//提问：游戏结束；图文；不同游戏模式如速度、数量变化； 

// 全局变量
int position_x,position_y; // 飞机位置
int bullet_x,bullet_y; // 子弹位置
int enemy_x,enemy_y; // 敌机位置
int high,width; //  游戏画面尺寸
int score; // 得分


//避免清屏闪烁问题 
void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor() // 用于隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};  // 第二个值为0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void startup() // 数据初始化
{
	high = 20;
	width = 30;
	position_x = high/2;
	position_y = width/2;
	bullet_x = -2;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	score = 0;

	HideCursor(); // 隐藏光标
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 光标移动到原点位置，以下重画清屏
	int i,j;
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==position_x) && (j==position_y))
				printf("*");  //   输出飞机*
			else if ((i==enemy_x) && (j==enemy_y))
				printf("@");  //   输出敌机@
			else if ((i==bullet_x) && (j==bullet_y))
				printf("|");  //   输出子弹|
			else
				printf(" ");  //   输出空格
		}
		printf("\n");
	}
	printf("得分：%d\n",score);
}	

void updateWithoutInput()  // 与用户输入无关的更新
{	
    //发射子弹后自动上移 
	if (bullet_x>-1)
		bullet_x--; 
	//击中-加分-新敌机-子弹消失 
	if ((bullet_x==enemy_x) && (bullet_y==enemy_y))  
	{
		score++;                
		enemy_x = -1;           
		enemy_y = rand()%width;
		bullet_x = -2;    
		
	}
	//未击中 -消失-新敌机 
	if (enemy_x>high)   
	{
		enemy_x = -1;           
		enemy_y = rand()%width;
	}
	
	// 控制敌机下落速度，但保证控制速度不变 
	static int speed = 0;  
	if (speed<20)
		speed++;
	if (speed == 20)
	{
		enemy_x++;			
		speed = 0;
	}
}

void updateWithInput()  // 与用户输入有关的更新
{
	char input;
	if(kbhit())  // 判断是否有输入
	{
		input = getch();  // <conio.h> 
		
		if (input == 'w')
	    	position_x--;  // 位置上移
		if (input == 's')
			position_x++;  // 位置下移
		if (input == 'a')   
			position_y--;  // 位置左移
		if (input == 'd')
			position_y++;  // 位置右移
	
		if (input == ' ')  // 发射子弹
		{
			bullet_x = position_x-1;  // 发射子弹的初始位置在飞机的正上方
			bullet_y = position_y;
		}
		
	}
}

int main()
{
	startup();  // 数据初始化	
	while (1) //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
 
	return 0;
}

