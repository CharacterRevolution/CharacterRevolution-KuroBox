#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <conio.h>
#include <bios.h>

#define WINDOWS

#ifdef WINDOWS
#include <Windows.h>
#endif

using namespace std;
// using namespace std::corono;  https://zhuanlan.zhihu.com/p/137626056  这C++11的新特性咋不支持捏

#define CHAR_PIXEL 16
#define CHAR_NUM_WIDTH 40
#define CHAR_NUM_HEIGHT 20

int FRAME_RATE_BASE = 5; // 视情况增加到8，再窄不好除了，局刷我不知道怎么搞

void refresh(int xmin, int ymin, int xmax, int ymax, int mat[CHAR_NUM_WIDTH][CHAR_NUM_HEIGHT])
{
	int width = xmax - xmin;
	// for i in : for j in : {gotoxy();print()}

	//void gotoxy(int x, int y) { COORD pos = {x,y}; HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(hOut, pos); }
	//https://blog.csdn.net/dfsrewgf/article/details/121993007
}

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
			if (duration_tmp >= 1000 / FRAME_RATE_BASE)
			{
				flag_timeout = true; //每个循环检查一次以模拟定时器
				cout << "当前距上次刷新时间为" << duration_tmp << endl;
			}
			string tmp = "";
			//cin >> tmp;
			//cout << "检测到用户输入" << tmp<<endl;
			
			//怎么不打断主循环的检测用户输入,有人建议用kbhit(),另有人建议bioskey(1)（虚拟键盘能用吗）
			//if (tmp != "")
			//{
			//	flag_userinput == true;
			//}
			if (bioskey(1)==true)
			{
				flag_userinput == true;
				cout << "用户输入！！！刷" << endl;
			}
			if ((flag_timeout == true && flag_waitmode==false) || flag_userinput == true)
			{
				flag_allow_global_refresh = true;
				cout << "满足刷新条件可以刷新" << endl;
			}
		} while (flag_allow_global_refresh == false);

		//按理说如果是删掉就是最大帧率来整了，接下来考虑用计时器代替手动打断或者完全不打断，不打断纯自己无限刷的话效果相当惊人
	}
	
	
	return 0;
}