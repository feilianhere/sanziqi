
#include "game.h"

void game()
{
	char board[3][3] = { 0 };
	char ret = 0;
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);//打印棋盘结果
		ret=If_Win(board,ROW,COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		ComeputerMove(board, ROW, COL);//电脑下棋
		DisplayBoard(board, ROW, COL);//打印棋盘结果
		ret=If_Win(board, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	else
	{
		printf("平局\n");
	}
}//玩家赢 ‘*’
//电脑赢‘#‘
//平局‘Q‘
//继续’C‘
int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do {
		menu();//打印菜单
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏模块
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}

	} while (input);
		return 0;
}