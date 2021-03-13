#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void menu()
{
      printf("*************************************\n");
	  printf("******   1.play    2.exit     *******\n");
	  printf("*************************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	Initboard(board,ROW,COL);
	Displayboard(board,ROW,COL);
	while (1)
	{
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret !='C')
		{
			break;
		}
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret !='C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，从新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}