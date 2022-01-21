#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int CHAR_PIXEL = 16;
int CHAR_NUM_WIDTH = 40;
int CHAR_NUM_HEIGHT = 20;

int main(int argc, char* argv[])
{
	int PIXEL_WIDTH = CHAR_NUM_WIDTH * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int PIXEL_HEIGHT = CHAR_NUM_HEIGHT * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int i = 0;
	int j = 0;
	while (1)
	{
		clock_t start, stop;
		start = clock();
		system("cls");
		for (i = 0; i < CHAR_NUM_HEIGHT; ++i)
		{
			for (j = 0; j < CHAR_NUM_WIDTH; ++j)
			{
				if (i == 0 || i == CHAR_NUM_HEIGHT - 1)
				{
					cout << "■";
				}
				else if (j == 0 || j == CHAR_NUM_WIDTH - 1)
				{
					cout << "■";
				}
				else
				{
					cout << "□";
				}
			}
			cout << endl;
		}
		stop = clock();
		int duration = stop - start;
		cout << duration << endl;
		cout << "全屏重绘" << endl;
		cout << "当前容许帧率为" << (double)1000 / duration << "  fps" << endl;
		system("pause"); //按理说如果是删掉就是最大帧率来整了，接下来考虑用计时器代替手动打断或者完全不打断，不打断纯自己无限刷的话效果相当惊人
	}
	
	
	return 0;
}