#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
int main()
{
	while (1)
	{
		int option;
		printf("1 ��ʼ 2 �˳�\n");
		option = getchar();
		switch (option)
		{
		case '1':play(); break;
		case '2':return 0; break;
		case '3':printf("��������ȷ�Ĳ�����\n"); break;
		}
	}
	
	return 0;
}