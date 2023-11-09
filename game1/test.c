#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("***1.play  0.exit****\n");
	printf("*********************\n");
}

void game()
{
	char ret = 0;
	//创建个数组存储棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//棋盘展开
	DisplayBoard(board,ROW,COL);
	//开始下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("You win!\n");
	}
	else if (ret = '#')
	{
		printf("You lose!\n");
	}
	else
		printf("Game over!A draw!");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose(1 or 0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit the game\n");
			break;
		default:
			printf("wrong choise\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}