// 三子棋
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
	int map[3][3]={
	{0,0,0},
	{0,0,0},
	{0,0,0},
};
	int player=1,x,y,i,j;
void drawmap(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d",map[i][j]);
			}
		printf("\n");
		}
		
	}
void playgame()
{
	printf("请玩家%d输入坐标(x,y):",player);
	scanf("%d,%d",&x,&y);
	i=x-1;
	j=y-1;
	if (map[i][j]==0&&(i>=0&&i<=2)&&(j>=0&&j<=2))
	{
		map[i][j]=player;
	}
	else if(i<0||i>2||j<0||j>2)
	{
		printf("超出范围啦！");
		printf("\n");
		playgame();
	}
	else
	{
		printf("这个位置已经被占啦！");
		printf("\n");
		playgame();
	}
	
	
}
int win(){
	if ((map[0][0]==map[0][1]&&map[0][1]==map[0][2]||map[0][0]==map[1][0]&&map[2][0]==map[1][0])&&map[0][0]!=0)
	{
		return map[0][0];	
	}
	else if ((map[1][0]==map[1][1]&&map[1][1]==map[1][2]||map[0][1]==map[1][1]&&map[1][1]==map[2][1]||map[0][0]==map[1][1]&&map[1][1]==map[2][2]||map[0][2]==map[1][1]&&map[1][1]==map[2][0])&&map[1][1]!=0)
	{
		return map[1][1];
	}
	else if((map[2][0]==map[2][1]&&map[2][1]==map[2][2]||map[0][2]==map[1][2]&&map[1][2]==map[2][2])&&map[2][2]!=0)
	{	
		return map[2][2];
	}
	else
	{
		return 0;
	}
}

int whetherfull()
{
	int is0=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j= 0; j < 3; j++)
		{
			if (map[i][j]==0)
			{
				is0=is0+1;
			}
			
		}
		
	}
	if (is0==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
	
}
int main(){
	int cwin=0,cwhetherfull=1;
	printf("注意，本游戏x表示行y表示列");
	system("pause");
	while (cwin==0&&cwhetherfull==1)
	{
		system("cls");
		drawmap();
		x=0;
		y=0;
		playgame();
		player=player%2+1;
		cwin=win();
	}
	if (cwin=1)
	{
		printf("玩家1赢啦！");
	}
	else if (cwin=2)
	{
		printf("玩家2赢啦！");
	}
	else if (cwin=0)
	{
		printf("平局哦，再来一把吧！");
	}
	system("pause");
}