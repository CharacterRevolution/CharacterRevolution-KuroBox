#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <time.h>

using namespace std;
// using namespace std::corono;  https://zhuanlan.zhihu.com/p/137626056  这C++11的新特性咋不支持捏

int CHAR_PIXEL = 16;
int CHAR_NUM_WIDTH = 40;
int CHAR_NUM_HEIGHT = 20;

int FRAME_RATE = 1; // 视情况增加到8，再窄不好除了，局刷我不知道怎么搞

int main(int argc, char* argv[])
{
	int PIXEL_WIDTH = CHAR_NUM_WIDTH * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int PIXEL_HEIGHT = CHAR_NUM_HEIGHT * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int i = 0;
	int j = 0;
	while (1)
	{
		clock_t start, stop;
		clock_t start_tmp, stop_tmp;
		start = clock();
		start_tmp = start;
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
		bool flag_timeout = false;
		bool flag_userinput = false;//Keyboard or mouse Input, "system("pause")" 算用户打断
		bool flag_waitmode = true;//对于用户无操作的情况进行判定，不操作的话就不刷新
		bool flag_allow_global_refresh = false;

		do
		{
			stop_tmp = clock();
			int duration_tmp = stop_tmp - start_tmp;
			if (duration_tmp >= 1000 / FRAME_RATE)
			{
				flag_timeout = true; //每个循环检查一次以模拟定时器
			}
			if ((flag_timeout == true || flag_userinput == true)&& flag_waitmode==false)
			{
				flag_allow_global_refresh = true;
			}
		} while (flag_allow_global_refresh == false);

		//按理说如果是删掉就是最大帧率来整了，接下来考虑用计时器代替手动打断或者完全不打断，不打断纯自己无限刷的话效果相当惊人
	}
	
	
	return 0;
}