#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int j = 0;
	int i = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';//©��
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;

	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���Ϣ
		//---|---|---
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1) {
					printf("|");
				}

			}
			printf("\n");//ע�ⲻҪ����һ��forѭ������
		}
	}

}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������>");
	while (1)
	{
		printf("����������>");
		scanf_s("%d %d",&x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			
			}
			else {
				printf("���´�����\n");
			}
		}
		else {
			printf("�����������\n");
		}
	}
}
void ComeputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row;//0-2

		y = rand() & col;//0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
				break;
		}
	}
}
void menu()
{
	printf("*******************\n");
	printf("****  1.play   ****\n");
	printf("****  2.exit   ****\n");
	printf("*******************\n");
	printf("*******************\n");

}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char If_Win(char board[ROW][COL], int row, int col)
{
	//�ж���
	int i = 0;
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];//������һ�����µ����� 
		}
	}
	//��
	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//������һ�����µ����� 
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))//�ж��Ƿ��ڴ�����
	{
		return 'Q';

	}//��Ϸ����
	return 'C';
	
}
