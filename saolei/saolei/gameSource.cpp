#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void play()
{
flag:;
	int minecount = 0;
	printf("请输入埋雷的数量>>");
		scanf("%d",&minecount);
	if (minecount > (H - 2)*(L - 2)-1)
	{
		printf("雷太多了！！！\n");
		goto flag;
	}
	char Board[H][L];
	char ShowsBoard[H][L];
	clearBoard(Board,'0',H,L);
	clearBoard(ShowsBoard, ' ', H , L );
	setMines(Board, H - 2, L - 2, minecount);
	int win = 0;
	while (1)
	{
		int x, y;
		printBoard(ShowsBoard, H - 2, L - 2);
		puts("\n");
		//printBoard(Board, H - 2, L - 2);
		printf("请输入坐标\n");
		scanf("%d%d",&x,&y);
		if (x<1 || x>H - 2 || y < 1 || y > L - 2)
		{
			printf("坐标非法！\n");
			continue;
		}
		if (ShowsBoard[x][y] != ' ')
		{
			printf("这个点看过了，请换一个点！\n");
			continue;
		}
		if (Board[x][y] == '1')
		{
			printf("踩到雷了\n");
			for (int i = 1; i <= H-2; i++)
			for (int j = 1; j <= L - 2; j++)
			{
				if (Board[i][j] == '1')
					ShowsBoard[i][j] = '*';
			}
			ShowsBoard[x][y]='!';
			printBoard(ShowsBoard, H - 2, L - 2);

			break;
		}
		else
		{
			ShowsBoard[x][y] = getCount(Board,x,y) + '0';
			if (getCount(Board, x, y) == 0)
			{
				searchBoard(Board,ShowsBoard,'1',x,y,&win);

			}
			win++;
		}
		if (win == (H - 2)*(L - 2)-minecount)
		{
			printf("恭喜获胜！\n");
			for (int i = 1; i <= H - 2; i++)
			for (int j = 1; j <= L - 2; j++)
			{
				if (Board[i][j] == '1')
					ShowsBoard[i][j] = '*';
			}
			break;
		}

		
			
		
	}
	

}
void printBoard(char Board[H][L], int h, int l)
{
	for (int i = 1; i <= h; i++)
	{
		printf(" ");
		for (int j = 1; j <= l; j++)
		{
			printf(" -%d-",j);
		}
		puts("");
		printf("%d|",i);
		for (int j = 1; j <= l; j++)
		{
			printf(" %c |", Board[i][j]);
		}
		puts("");
		printf(" ");
		for (int j = 1; j <= l; j++)
		{
			printf(" ---");
		}
		puts("");

	}

		
}
void setMines(char Board[H][L], int h, int l, int count)
{
	srand((unsigned int)time(NULL));
	int counts = 0;
	while (counts < count)
	{
		int x = 1+rand() % h;
		int y = 1+rand() % l;
		if (Board[x][y] == '0')
		{
			Board[x][y] = '1';
			counts++;
		}
	}
}
int getCount(char Board[H][L], int x, int y)
{
	int countis = 0;
	for (int i = x - 1; i <= x + 1; i++)
	for (int j = y - 1; j <= y + 1; j++)
	{
		if (Board[i][j] == '1')
		countis++;
	}
	return countis;
}
void clearBoard(char Board[H][L], char ch, int h, int l)
{
	for (int i = 0; i < h; i++)
	for (int j = 0; j < l; j++)
		Board[i][j] = ch;
}
void searchBoard(char Board[H][L], char showsBoard[H][L], char ch, int x, int y, int *win)
{
	
	for (int i = x - 1; i <= x + 1; i++)
	for (int j = y - 1; j <= y + 1; j++)
	{
		if (showsBoard[i][j] == ' '&&(i>=1&&j>=1&&i<=H-2&&j<=L-2))
		{
			
			showsBoard[i][j] = getCount(Board, i, j) + '0';
			
			(*win)++;
			if (showsBoard[i][j] == '0')
			{
				searchBoard(Board, showsBoard, ch, i, j, win);
				
			}
		}
			
	}

}