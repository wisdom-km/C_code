#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"



void menu()
{
		printf("***************************************\n");
		printf("**********    1.play  0.exit  *********\n");
		printf("***************************************\n");

}

void game()
{	
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘的函数
	InitBoard(board, ROW, COL);
	DisplayBoard(board,ROW,COL);

	//下棋
	while (1) 
	{
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		printf("-------------------------------------------\n");
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') 
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		printf("-------------------------------------------\n");
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret = '*') 
	{
		printf("玩家赢了!\n");
	}
	else if (ret = '#') 
	{
		printf("电脑赢了!\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}


int main()
{	
	srand((unsigned int)time(NULL));//设置随机数的生成起点


	int input = 0;
	do
	{
		menu();//打印菜单
		printf("请选择：>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//printf("三子棋\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误");
			break;

		}
	} while (input);//打印菜单,input 为0不执行循环;do while 至少打印一次

	return 0;
}