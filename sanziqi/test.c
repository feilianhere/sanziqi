
#include "game.h"

void game()
{
	char board[3][3] = { 0 };
	char ret = 0;
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);//��ӡ���̽��
		ret=If_Win(board,ROW,COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		ComeputerMove(board, ROW, COL);//��������
		DisplayBoard(board, ROW, COL);//��ӡ���̽��
		ret=If_Win(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}

	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}//���Ӯ ��*��
//����Ӯ��#��
//ƽ�֡�Q��
//������C��
int main()
{
	srand((unsigned int)time(NULL));//������������������
	int input = 0;
	do {
		menu();//��ӡ�˵�
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸģ��
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;
		}

	} while (input);
		return 0;
}