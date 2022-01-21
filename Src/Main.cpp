#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <time.h>

using namespace std;
// using namespace std::corono;  https://zhuanlan.zhihu.com/p/137626056  这C++11的新特性咋不支持捏

int CHAR_PIXEL = 16;
int CHAR_NUM_WIDTH = 40;
int CHAR_NUM_HEIGHT = 20;

int FRAME_RATE = 5; // 视情况增加到8，再窄不好除了，局刷我不知道怎么搞

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
		bool flag_timeout = false;//所以我怎么整计时器呢？
		bool flag_userinput = false;//Keyboard or mouse Input, "system("pause")" 算用户打断
		bool flag_allow_global_refresh = false;
		do
		{
			if (flag_timeout == true || flag_userinput == false)
			{
				flag_allow_global_refresh = true;
			}
		} while (flag_allow_global_refresh == false);

		//按理说如果是删掉就是最大帧率来整了，接下来考虑用计时器代替手动打断或者完全不打断，不打断纯自己无限刷的话效果相当惊人
	}
	
	
	return 0;
}