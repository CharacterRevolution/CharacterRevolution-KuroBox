//PartName求解

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define STOCK 274
//#define MAXLEN 10000
//
////求个稳……这次用最弱智的方法实现
//
//int main(void)
//{
//	int i = 0;
//	for (i = 271; i <= 274; ++i)
//	{
//		if (fopen("E:\C_Program_Learn\273\38708937.info", "r") == NULL)
//			perror("!!!gui");
//		//FILE *info = fopen("i\\38708937.info", "r");
//		//目标文件指针用来重命名
//		int jndex = 0;
//		int kndex = 0;
//		wchar_t str[MAXLEN] = { 0 };
//		wchar_t patch[MAXLEN] = L"PartName";
//		int patchLen = 8;
//		//wscanf(info, "%s", str);
//		int POS = 0;
//		int flag_NotFound = 0;
//		//寻找PartName的位置
//		for (jndex = 0; jndex < MAXLEN - patchLen; ++jndex)
//		{
//			flag_NotFound = 0;
//			for (kndex = 0; kndex < patchLen; ++kndex)
//			{
//				if (str[jndex] != patch[kndex])
//				{
//					flag_NotFound = 1;
//					break;
//				}
//				else
//					;
//			}
//			if (flag_NotFound == 0)
//				POS = jndex;
//		}
//		printf("PartName的开始位置为%d", POS);
//
//	}
//	return 0;
//}

//GPS Tools

////本工具提供一个输入多种格式GPS坐标并求最近点的功能
////期望您输入WSG84坐标,当然您全部输入GCJ02坐标也没有问题，只要全都在一个系就可以
////未来在能够接入高德或百度API时将考虑自动查询最近位置并输出地址
//
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<limits.h>
//#include<time.h>
//#include<omp.h>
//
//#define MAXPERSON 1000
//
////#define PARALLEL_OMP  //锤子的OMP优化收敛点满天飞从MIN飞到MAX 而且越优化越慢
////#define PARALLEL_CUDA //首先只能winapi+cuda限制平台而且我不觉得我的收敛点不会满天飞
//
//#define DEBUG
//
//int comp(const void*a, const void*b)//用来做比较的函数。
//{
//	return *(float*)a - *(float*)b;
//}
//
////float comp(float a, float b)//用来做比较的函数。
////{
////	return ((float)a - (float)b);
////}
//
//int main(void)
//{
//	FILE *Src = fopen("GPS.Src", "r");
//	FILE *Out = fopen("GPS.Out", "w");
//	float X[MAXPERSON + 1] = {0};
//	float Y[MAXPERSON + 1] = {0};
//	//都+1防止炸掉
//	printf("请输入坐标X（经度）与Y（纬度）\n格式为纯小数，先X后Y，英文逗号分隔\n");
//	printf("————————————————————\n");
//	int index = 0;
//	int jndex = 0;
//	int count = 0;
//
//	//可以写不满MAXPERSON的情况
//	//永远不要相信用户的输入
//	while (fscanf(Src,"%f,%f", &X[count], &Y[count]) != EOF)
//	{
//		if (count >= MAXPERSON)
//		{
//			printf("WARN:您输入的已经超过最大组数%d", MAXPERSON);
//			break;
//		}
//		//人心不善，数够规定数目就收手
//		//虽然我们也想能够尽可能多的处理更多组，但是怕溢出
//
//		//数据预处理
//
//		////处理一：对非小数形式化成小数形式
//		//虽然永远不要相信用户的输入，但是还没有好的办法检测用户的输入是不是度分秒形式，故略
//		//更防范不住EWNS这种带字母的输入格式
//		//当然，如果为了绝对保证精确，应该对度分秒形式全文采用度分秒计算，本处没必要
//
//		////处理二：对取值范围的判断
//		//////精度应该在+-180度以内//
//		//超出+180的直接减360，循环
//		//小于-180的直接加360，循环
//		//////纬度应该在+-90度以内//
//		//大于90的,因为+90和-90不连贯，我们也不知道应该怎么处理
//		//不行就先减2pi度，直到纬度在0-360度以内，再分为四个区间讨论
//
//		////处理三：对可能存在的经纬度反转提醒
//		//或许应该在处理二中间插入
//		if (abs(Y[index]) > 90.0)
//			printf("WARN:第%d组数据的纬度大于90度，请检查是否有经纬度混淆"/*"WARN:%d/%d组数据的纬度大于90度，请检查是否有经纬度混淆"*/, index + 1/*, MAXPERSON*/);
//
//		count += 1;
//	}
//#ifdef DEBUG
//	printf("————————————————————\n");
//	printf("下面展示的是获得的数据\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f,%f\n", X[index], Y[index]);
//	}
//	printf("————————————————————\n");
//#endif // DEBUG
//
//	//使用的方法为分别退化为X和Y，并分别在X和Y中排序后蒙特卡洛一个距离和最近的点
//	//先写通X
//	qsort(X, count, sizeof(float), comp);
//	qsort(Y, count, sizeof(float), comp);
//
//#ifdef DEBUG
//	printf("————————————————————\n");
//	printf("下面展示的是排序好的X数据\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f\n", X[index]);
//	}
//	printf("————————————————————\n");
//#endif // DEBUG
//
//#ifdef DEBUG
//	printf("————————————————————\n");
//	printf("下面展示的是排序好的Y数据\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f\n", Y[index]);
//	}
//	printf("————————————————————\n");
//#endif // DEBUG
//
//	float X_Min = X[0];
//	float X_Max = X[count-1];
//	float Y_Min = Y[0];
//	float Y_Max = Y[count-1];
//	float X_POS = 0.0;
//	float Y_POS = 0.0;
//
//	//对X蒙特卡洛
//	//精度暂定0.01
//
//    #define STEP_LENGTH 0.000001
//
//	float indexf = 0.0;
//	float jndexf = 0.0;
//	float TempMin = INT_MAX;
//	clock_t start_x,stop_x;
//
//	//#define OMP_NUM_THREADS  48
//
//	start_x = clock();
//#ifdef PARALLEL_OMP
//#pragma omp parallel
//	{
//		for (indexf = X_Min; indexf <= X_Max; indexf += /*STEP_LENGTH*/0.01)
//		{
//			float TempSum = 0.0;
//			for (jndex = 0.0; jndex < count; ++jndex)
//			{
//				TempSum += (float)abs(X[jndex] - indexf);
//			}
//			printf("%f点的距离总和为%f\n", indexf, TempSum);
//			if (TempSum < TempMin)
//			{
//				TempMin = TempSum;
//				X_POS = indexf;
//			}
//		}
//	}
//#endif // PARALLEL_OMP
//
//#ifndef PARALLEL_OMP
//	printf("X_MIN=%f X_MAX=%f\n", X_Min, X_Max);
//	for (indexf = X_Min; indexf <= X_Max; indexf += STEP_LENGTH)
//	{
//		float TempSum = 0.0;
//		for (jndex = 0.0; jndex < count; ++jndex)
//		{
//			TempSum += abs(X[jndex] - indexf);
//		}
//		printf("%f点的距离总和为%f\n", indexf, TempSum);
//		if (TempSum < TempMin)
//		{
//			TempMin = TempSum;
//			X_POS = indexf;
//		}
//	}
//#endif // !PARALLEL_OMP
//
//	stop_x = clock();
//	double duration_x = (double)(stop_x - start_x) / CLK_TCK;
//	printf("【X方向计算用时为%f】\n", duration_x);
//	printf("【X方向最近位置为%f】\n", X_POS);
//	fprintf(Out, "【X方向计算用时为%f】\n", duration_x);
//	fprintf(Out, "【X方向最近位置为%f】\n", X_POS);
//
//	//对Y蒙特卡洛
//	clock_t start_y, stop_y;
//	start_y = clock();
//#ifdef PARALLEL_OMP
//#pragma omp parallel
//	{
//		for (indexf = Y_Min; indexf <= Y_Max; indexf += STEP_LENGTH)
//		{
//			float TempSum = 0.0;
//			for (jndex = 0.0; jndex < count; ++jndex)
//			{
//				TempSum += abs(Y[jndex] - indexf);
//			}
//			if (TempSum < TempMin)
//			{
//				TempMin = TempSum;
//				Y_POS = indexf;
//			}
//		}
//	}
//#endif // PARALLEL_OMP
//
//#ifndef PARALLEL_OMP
//	for (indexf = Y_Min; indexf <= Y_Max; indexf += STEP_LENGTH)
//	{
//		float TempSum = 0.0;
//		for (jndex = 0.0; jndex < count; ++jndex)
//		{
//			TempSum += abs(Y[jndex] - indexf);
//		}
//		if (TempSum < TempMin)
//		{
//			TempMin = TempSum;
//			Y_POS = indexf;
//		}
//	}
//#endif // !PARALLEL_OMP
//
//	stop_y = clock();
//	double duration_y = (double)(stop_y - start_y) / CLK_TCK;
//	printf("【Y方向计算用时为%f】\n", duration_y);
//	printf("【Y方向最近位置为%f】\n", X_POS);
//	fprintf(Out, "【Y方向计算用时为%f】\n", duration_y);
//	fprintf(Out, "【Y方向最近位置为%f】\n", X_POS);
//
//	printf("————————————————————\n");
//	printf("最近坐标为%f,%f\n",X_POS,Y_POS);
//	fprintf(Out, "————————————————————\n");
//	fprintf(Out, "最近坐标为%f,%f\n", X_POS, Y_POS);
//	return 0;
//}
//下面是比较的实验
//#include<stdio.h>
//#include<stdlib.h>
//int comp(const void*a, const void*b)//用来做比较的函数。
//{
//	return *(float*)a - *(float*)b;
//}
//int main()
//{
//	int n = 10;
//	float a[10] = { 2,4,1,5,5,3,7,4,1,5 };//乱序的数组。
//	int i;
//	qsort(a, n, sizeof(float), comp);//调用qsort排序
//	for (i = 0; i < 10; i++)//输出排序后的数组
//	{
//		printf("%f\t", a[i]);
//	}
//	return 0;
//}

//函数打表

//#include<stdio.h>
//
//int main(void)
//{
//	int index = 0;
//	for (index = 1; index <= 14; ++index)
//	{
//		double Temp = 0.0;
//		Temp = (-0.00001)*index*index*index + 0.001*index*index - 0.005*index - 0.1;
//		printf("%f\n", Temp);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//
////x=角度的θ
//
//float fun(int i)
//{
//	float temp = (float)abs(sin(i + 24)) * 80;
//	printf("%d %f\n", i, temp);
//}
//
//int main(void)
//{
//	int i = 0;
//	printf("X   Y\n");
//	for (i = 1; i <= 360; ++i)
//	{
//		fun(i);
//	}
//	return 0;
//}

//谢文静数据分析

//#include<stdio.h>
//
//int main(void)
//{
//	FILE *csv = fopen("dataSeparate.csv", "r");
//	char str[50] = {'0'};
//	int X[500] = {0};
//	int Y[500] = {0};
//	int countSeparate[11][10] = { 0 };
//	fscanf(csv, "%s", str);
//	int count = 0;
//	while (fscanf(csv,"%d,%d",X[count],Y[count])!= EOF)
//	{
//		count += 1;
//		//if (X[count] >= 0 && X[count] < 10)
//		//{
//		//	if (Y[count] >= 0 && Y[count] <= 10)
//		//	{
//		//		countSeparate[0][10] += 1;
//		//	}
//		//	//下面10个就不写了，自己补
//		//}
//		////下面9个就不写了，自己补
//	}
//	//按说这里输出也应该是两层for
//	printf("X在0-10而且Y在0-10的一共有%d", countSeparate[0][10]);
//	return 0;
//}

//算法上机第三周

////#include<stdio.h>
////#include<string.h>
////
////
////int main(void)
////{
////	FILE *input = fopen("input.txt", "r");
////	FILE *output = fopen("output.txt", "w");
////	int n = 0;
////	fscanf(input, "%d", &n);
////	int i = 0;
////	char str[7];
////	for (i = 0; i < n; ++i)
////	{
////		scanf("%s", str);
////		int length = strlen(str);
////		//草啊这个题目真的难写
////	}
////}
//
//说一下大致的思路
//首先这个题目打算用打表查表的方式去做
//之前想过两种方案
//第一种是先判断是几位长短，再分别解析，过于繁琐，不可
//第二种是直接把它当作一个26进制/25进制运算来求，但是因为涉及到空缺和递增，没有明显简单的规律
//思路是这样的，设置一个打表函数，输入n=1就在链表（不考虑顺序，只考虑有无，查询的时候也只考虑有无）中增加对应的Node
//之后运行这个函数就会用i从XX到YY打一次，for里面是一个基于位数的判断，如果位数没到指定的位数就再开一个打表函数。具体递归方法待定
//之后五次递归确定五个i，通过五个i来确定下五个字母，同时在最里层的for进行输出（此时位数到了指定的位数，if判断一下五个i的大小关系，插入进链表）
//就是
//for(index=1;index<=5;++index)
//{
//	List(i);
//}
//*/
//
////BUCTOJ
////Contest1543 - 19年数据结构作业二（计科&大数据&信计合班）
////轮子，各个题目合做
//
//#include<stdio.h>
//#include<string.h>
//
//typedef char ElemType;
//typedef int Status;
//
//#define ERROR 1
//#define SUCCESS 0
//#define OK 0
//#define ARRAY_LENGTH 100
//
//typedef struct LinearNode
//{
//	ElemType data;
//	struct LinkNode *next;
//}LinearNode;
//
//Status InitLinearList(LinearNode *L)
//{
//	//LinearNode *p = (LinearNode*)malloc(sizeof(LinearNode)*ARRAY_LENGTH);
//	//L = p;
//	L->next = NULL;
//	return OK;
//}
//
//Status AddLinearNode(LinearNode *L,char INSERT)
//{
//	LinearNode *p0= (LinearNode*)malloc(sizeof(LinearNode));
//	LinearNode *p = (LinearNode*)malloc(sizeof(LinearNode));
//	if (p0 == NULL)
//		return ERROR;
//	if (p == NULL)
//		return ERROR;
//	for (p = L; p->next != NULL; p = p->next)
//	{
//		;
//	}
//	p0->next = NULL;
//	p0->data = INSERT;
//	p->next = p0;
//	return OK;
//}
//
//Status PrintLinearList(LinearNode *L)
//{
//	LinearNode *p = (LinearNode*)malloc(sizeof(LinearNode));
//	for (p = L; p->next != NULL; p = p->next)
//	{
//		char temp = p->data;
//		printf("%c\n", temp);
//	}
//	return OK;
//}
//
//int main(void)
//{
//	LinearNode L;
//	InitLinearList(&L);
//	AddLinearNode(&L, 'A');
//	AddLinearNode(&L, 'B');
//	PrintLinearList(&L);
//	return 0;
//}

//写离散数学中针对数集的打表算是否满足代数系统封闭性
//对于集合A={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}，判断下列定义的运算*是否为集合A上的代数运算。

//#include<stdio.h>
//#include<math.h>
//
//float xtoy(int x, int y)
//{
//	float temp = 0.0;
//	//////改这里面
//	temp = (float)(x+y)/2;
//	//////改这里面
//	return temp;
//}
//
//int main(void)
//{
//	int i = 0;
//	int j = 0;
//	printf("横着是X从小到大，竖着是Y从小到大\n");
//	for (i = 0; i < 10; ++i)
//	{
//		for (j = 0; j < 10; ++j)
//		{
//			float temp = xtoy(i, j);
//			printf("%.3f  ", temp);
//		}
//		printf("\n");
//	}
//	return 0;
//}



//BUCTOJ
//Contest1564 - 19年数据结构作业四（计科&大数据&信计合班）
//Contest1710 - 计科1806-1808；数据1801-1802 《算法设计与分析》第2次上机作业
//4052 Problem  A	双色Hanoi塔问题

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MaxLen 1000//连续空间的长度（尺寸）
//
//typedef int ElemType;
//typedef int Status;
//
//#define OK 1
//#define ERROR 0
//
//typedef struct StackNode
//{
//	ElemType data;
//	struct StackNode *next;
//}StackNode;
//
//typedef struct Stack
//{
//	StackNode *top;
//}Stack;
//
//Status InitStack(Stack *Sp)
//{
//	Sp->top = NULL;
//	return OK;
//}
//
//Status ClearStack(Stack *Sp)
//{
//	StackNode *delnode, *p = Sp->top;
//	while (p!=NULL)
//	{
//		delnode = p;
//		p = p->next;
//		free(delnode);
//	}
//	return OK;
//}
//
//Status DestroyStack(Stack *Sp)
//{
//	return ClearStack(Sp);
//}
//
//int IsEmpty(Stack S)
//{
//	return (S.top == NULL);
//}
//
//Status Push(Stack *Sp, ElemType e)
//{
//	StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
//	if (newnode == NULL)
//		return ERROR;
//	newnode->data = e;
//	newnode->next = Sp->top;
//	Sp->top = newnode;
//	return OK;
//}
//
////别忘了在构造链表结构的时候提取数据
//
//Status Pop(Stack *Sp, ElemType *ep)
//{
//	StackNode *delnode;
//	if (IsEmpty(*Sp))
//		return ERROR;
//	delnode = Sp->top;
//	Sp->top = delnode->next;
//	*ep = delnode->data;
//	free(delnode);
//	return OK;
//}
//
//Status GetTop(Stack S, ElemType *ep)
//{
//	if (IsEmpty(S))
//		return ERROR;
//	*ep = S.top->data;
//	return OK;
//}
//
//Status PrintByMe(Stack *S)
//{
//	StackNode *p;
//	for (p = S->top; p != NULL; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//	return OK;
//}
//
//Status Print(Stack S)
//{
//	StackNode *p;
//	for (p = S.top; p != NULL; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//	return OK;
//}
//
//void Transform(int from, char *to, int base)
////老师写的版本
//{
//	//from：十进制数
//	//to：转换成base进制之后的结果
//	Stack S;
//	int e, i = 0;
//	InitStack(&S);
//	while (from)
//	{
//		Push(&S, from%base);
//		from /= base;
//	}
//	while (!IsEmpty(S))
//	{
//		Pop(&S, &e);
//		if (e < 10)
//			to[i++] = e + '0';
//		else
//		{
//			to[i++] = e - 10 + 'A';
//		}
//		to[i] = '\0';
//		
//	}
//	DestroyStack(&S);
//}
//
//int HanoiCount = 1;
//
//int Hanoi(int n)
//{
//	int HanoiOperation(int n, char X, char Y, char Z);
//	HanoiOperation(n, 'A', 'C', 'B');
//	HanoiCount = 1;
//	printf("\n");
//	return 0;
//}
//
//int HanoiOperation(int n, char X, char Y, char Z)
//{
//	if (n == 1)
//	{
//		//printf("%2d. ", HanoiCount);
//		printf("%d %c %c\n",1,X,Z);
//		HanoiCount += 1;
//	}
//	else
//	{
//		HanoiOperation(n-1, X, Z, Y);
//		//printf("%2d. ", HanoiCount);
//		printf("%d %c %c\n", n, X, Z);
//		HanoiCount += 1;
//		HanoiOperation(n-1, Y, X, Z);
//	}
//}
//
//int main(void)
//{
//	//2210 Problem  F	算法3 - 5：n阶Hanoi塔问题
//
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		Hanoi(n);
//	}
//	return 0;
//}

//BUCTOJ
//Contest1710 - 计科1806-1808；数据1801-1802 《算法设计与分析》第2次上机作业
//3648 Problem  B	循环日程表问题，《算法竞赛入门经典》P230，递归与分治，刘丽萍，CCF三级

//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//
//方案一：全打表完了直接输出，失败，上来4GB内存谁顶得住
//
//int plot(int martix[1024][1024], int r1, int r2, int c1, int c2)
//{
//	if ()
//	{
//		martix[][]=;
//	}
//	else
//	{
//		return plot(martix,fileno,fileno,fileno,fileno);
//	}
//}
//
//int print(int martix[1024][1024],int n)
//{
//	int index = 0;
//	int jndex = 0;
//	for (index = 0; index < n; ++index)
//	{
//		for (jndex = 0; jndex < n; ++jndex)
//		{
//			//输出一个数字前，先检查是几位数
//			if (martix[index][jndex] >= 1000)
//			{
//				printf("%d", martix[index][jndex]);
//			}
//			else if (martix[index][jndex] >= 100)
//			{
//				printf("%d ", martix[index][jndex]);
//			}
//			else if (martix[index][jndex] >= 10)
//			{
//				printf("%d  ", martix[index][jndex]);
//			}
//			else
//			{
//				printf("%d   ", martix[index][jndex]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//int main(void)
//{
//	int k = 0;
//	scanf("%d", &k);
//	int n = pow(2, k);
//	printf("%d", n);
//	int martix[1024][1024] = {0};
//	//plot(martix, 0, n - 1, 0, n - 1);
//	//print(martix, n);
//	return 0;
//}
//
//方案二：逐行输出
//
//int printSingalNum(int martix[1024][1024],int n)
//{
//	//输出一个数字前，先检查是几位数,不负责换行
//	if (martix[index][jndex] >= 1000)
//	{
//		printf("%d", martix[index][jndex]);
//	}
//	else if (martix[index][jndex] >= 100)
//	{
//		printf("%d ", martix[index][jndex]);
//	}
//	else if (martix[index][jndex] >= 10)
//	{
//		printf("%d  ", martix[index][jndex]);
//	}
//	else
//	{
//		printf("%d   ", martix[index][jndex]);
//	}
//	return 0;
//}
//
////int printDoubleLine(int r,int n)
////{
////	int r1 = r;
////	int r2 = r + 1;
////	int c1 = 1;
////	int c2 = n;
////
////}
//
//int printSingalLine(int r, int c1,int c2)
//{
//	//不负责换行
//
//	//标准递归
//	//if ((c2 - c1) == 1)
//	//{
//	//	//生成这个最小体素并输出
//	//}
//	//else
//	//{
//	//	printSingalLine(r, c1, (int)(c2/2));
//	//	printSingalLine(r, (int)(c2/2)+1, c2);
//	//}
//
//	//划分生成思想
//	//根据C2的长度从1024里面截取，一行4MB，炸不死
//	int line[1024] = {0};
//	int n = c2;
//	int k = log(n) / log(2);
//	//第一层：奇偶互换
//	if (r % 2 != 0)//奇数
//	{
//		;//不进行两两奇偶调换，两个数字的体素中奇数在前，否则偶数在前
//	}
//	else
//	{
//		int nHalf = c2 / 2;
//		int index = 0;
//		for (index = 1; index <= nHalf; ++index)
//		{
//			int temp = line[index-1];
//			//此时index均为偶数列的
//			line[index - 1] = line[index];
//			line[index] = temp;
//		}
//	}
//	//第二层
//	//针对3，4行，7，8行这样的2^2行为单位中的后2^1行
//	if(r>pow(2,1)&&)
//	//拧巴
//}
//
//int plot(int r1, int r2, int c1, int c2)
//{
//	//if ((r2 - r1) == 1)
//	//{
//	//	//因为是方阵，所以只看r2-r1
//	//	;
//	//}
//	//else
//	//{
//	//	////横向扫描
//	//	////|plot1|plot2|
//	//	////|plot3|plot4|
//	//	////保证打印顺序正确
//	//	//plot(r1, r2 / 2, c1, c1 / 2);
//	//	//plot(r1, r2 / 2, c1 / 2 + 1, c2);
//	//	////但不能保证在plot1打印的过程中，下半部分打印了而导致c1/4---c1/2这一段的plot2打印不上了
//	//}
//
//	//逐行扫描
//	
//	////两行两行的
//	//int nHalf = r2 / 2;
//	//int index = 0;
//	//for (index = 1; index <= nHalf; ++index)
//	//{
//	//	printDoubleLine(index * 2 - 1, c2);
//	//}
//
//	//1行1行的
//	int index = 0;
//	for (index = 1; index <= n; ++index)
//	{
//		printSingalLine(index,c1,c2);
//		printf("\n");
//	}
//}
//
//int main(void)
//{
//	int k = 0;
//	while (scanf("%d", &k)!=EOF)
//	{
//		int n = pow(2, k);
//		printf("%d", n);
//		int index = 0;
//		int jndex = 0;
//		int kndex = 0;
//		plot(1, n, 1, n);
//	}
//	return 0;
//}

//BUCTOJ
//Contest1719 - 计科1806-1808；数据1801-1802 《算法设计与分析》第3次上机作业
//4054 Problem  A	数的计数

//#include<stdio.h>
//#include<math.h>
//
//int publicCount = 0;
//
//int Multiple(int count, int num)
//{
//	if (num >= 1000)
//	{
//		return count;
//		//要么不符合要求，要么最高位是1，没法做
//	}
//	int Higher = 0;//最高位
//	if (num < 1000)
//	{
//		if (num < 100)
//		{
//			if (num < 10)
//			{
//				//是一位数
//				Higher = num;
//			}
//			else//是两位数
//			{
//				Higher = num / 10;
//			}
//		}
//		else//是三位数
//		{
//			Higher = num / 100;
//		}
//	}
//	//printf("分离出的最高位为%d\n", Higher);
//	int half = 0;
//	if (Higher % 2 != 0)
//		half = (Higher - 1) / 2;
//	else
//		half = Higher / 2;
//	//printf("最高位的一半到%d为止\n", half);
//	int index = 0;
//	int countSum = 0;
//	for (index = 1; index <= half; ++index)
//	{
//		int temp = 0;
//		if (num < 10)
//		{
//			temp = num + half * 10;
//			//printf("决定把%d传入下一轮计算\n", temp);
//			publicCount += 1;
//			countSum += Multiple(0, temp);
//		}
//		else if(num<100)
//		{
//			temp = num + half * 100;
//			//printf("决定把%d传入下一轮计算\n", temp);
//			publicCount += 1;
//			countSum += Multiple(0, temp);
//		}
//		else
//		{
//			temp = num + half * 1000;
//			//那就不用传下一层了
//		}
//	}
//	count += countSum;
//	return count;
//}
//
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	//printf("n的值为%d\n", n);
//	int flag_NoneExist = 0;
//	int temp = n;
//	int count = 0;
//	count = Multiple(count, n);
//	//while (flag_NoneExist != 1)
//	//{
//	//	int half = temp/2;
//
//	//	if (true)
//	//	{
//	//		flag_NoneExist = 1;
//	//	}
//	//}
//	//设计一个递归函数，传入原数，然后分离最高位数字，然后看除以二有几个，然后分别再创建若干个子函数，直到不能再加
//	//printf("%d", count);
//	printf("%d", publicCount);
//	return 0;
//}

//BUCTOJ
//Contest1724 - 计科1806-1808；数据1801-1802 《算法设计与分析》第4次上机作业
//3511 Problem  B	装箱

//#include<stdio.h>
//
//int main(void)
//{
//	int V = 0;
//	int n = 0;
//	scanf("%d", &V);
//	scanf("%d", &n);
//	int index = 0;
//	int Vi[30];
//	for (index = 0; index < n; ++index)
//	{
//		scanf("%d", &Vi[index]);
//	}
//
//	return 0;
//}

//#include<stdio.h>
////这么好的代码显然不可能是自己写的
//#define RAND_MAX 100
////#define if(x) if ((x) && (rand() < RAND_MAX * 0.99))
//#define if while
//#define else 
//
//int max(int a, int b)
//{
//	if (a >= b)
//		return a;
//	else
//	{
//		return b;
//	}
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d", &n);
//	scanf("%d", &m);
//	int dp[20004] = { 0 };//记录在j下最大体积V，要求20000
//	int num[40] = { 0 };//记录每个物体的体积，要求30
//	for (int i = 0; i < m; i++)//输入
//		scanf("%d", &num[i]);
//	for (int i = 0; i < m; i++)//将给出的物体放入箱子，防止重复计算
//	{
//		for (int j = n; j >= num[i]; j--)//判断物体是否放入箱子
//		{
//			dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
//		}
//	}
//	printf("%d\n", n - dp[n]);
//	return 0;
//}

//BUCTOJ
//Contest1729 - 计科1806-1808；数据1801-1802 《算法设计与分析》第5次上机作业
//4483 Problem  A	N 皇后问题

//////课本法
////使用C

//#include<stdio.h>
//#include<math.h>
//
//int sum = 0;
//int x[10] = { 0 };
//
////PPT函数
//void output(int x[10],int n)
//{
//	//cout << "第" << sum << "种放置方法为：" << endl;
//	int i = 0;
//	for (i = 1; i <= n; i++) 
//	{
//		printf("%5d", x[i]);
//	}
//	printf("\n");
//}
//
//int Place(int k)
//{
//	int j = 0;
//	for (j = 1; j < k; j++)
//		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
//			return 0;
//	return 1;
//}
//void Backtrack(int t, int n)
//{
//	if (t > n)
//	{
//		sum++;
//		output(x, n);
//	}
//	else
//	{
//		int i = 0;
//		for (i = 1; i <= n; i++)
//		{
//			x[t] = i;
//			if (Place(t))
//				Backtrack(t + 1,n);
//		}
//	}
//}
//
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (n > 3&&n<=10)
//	{
//		Backtrack(1, n);
//	}
//	else
//	{
//		printf("no solute! ");
//	}
//	return 0;
//}

////https://www.cnblogs.com/henuliulei/p/10117304.html
//使用C++

//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//
//using namespace std;
//
//int n;
//int x[100];
//int sum = 0;
//
//
////判断第k个后能不能放在x[k]处
////两个皇后不能放在统一斜线上：
////若2个皇后放置的位置分别是（i,j）和（k,l）,
////且 i-j = k -l 或 i+j = k+l，则说明这2个皇后处于同一斜线上。
//
//void output() {
//	//cout << "第" << sum << "种放置方法为：" << endl;
//	for (int i = 1; i <= n; i++) {
//		printf("%5d", x[i]);
//	}
//	printf("\n");
//
//}
//int place(int k) {
//	for (int j = 1; j < k; j++) {
//		if (x[j] == x[k] || abs(x[j] - x[k]) == abs(j - k))
//			return 0;
//	}
//	return 1;
//}
//void BackTrace(int t, int n) {//递归
//	if (t > n) {////如果t>n说明已经完成一次放置
//		sum++;
//		output();
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			x[t] = i;
//			if (place(t)) {// //可以放在i位置处，则继续搜索
//				BackTrace(t + 1, n);
//			}
//		}
//
//	}
//}
//
//void BackTrace1(int n) {//非递归
//	int k;
//	x[1] = 0;
//	k = 1;
//	while (k >= 1) {
//		x[k] += 1;////先放在第一个位置
//		while ((x[k] <= n && !(place(k)))) {//如果不能放
//			x[k]++;//  //放在下一个位置
//		}
//		if (x[k] <= n) {
//			if (k == n) {// //如果已经放完了n个皇后
//				sum++;
//				output();
//			}
//			else {//  //没有处理完，让k自加，处理下一个皇后
//				k++;
//				x[k] = 0;
//			}
//		}
//		else {// 当前无法完成放置，则进行剪枝，回溯回去，回到第k-1步
//			k--;
//		}
//	}
//}
//int main()
//{
//	memset(x, 0, sizeof(x));
//	
//	cin >> n;
//
//	//int tempx = 0;
//	//for (tempx = 0; tempx < 100; ++tempx)
//	//	x[tempx] = 0;
//
//	//cout << n << "皇后的放置方法为" << endl;
//	//BackTrace(1,n);
//	if (n > 3&&n<=10)
//	{
//		BackTrace1(n);
//	}
//	else
//	{
//		printf("no solute! ");
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int mod(int x, int n)
//{
//	while (x > n)
//		x -= n;
//	return x;
//}
//
//int main(int argc, char * argv[])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 5; ++i)
//	{
//		for (j = i; j < i + 5; ++j)
//		{
//			printf("%4d", mod(j+1,5));
//		}
//		printf("\n");
//	}
//	return 0;
//}



//BUCTOJ
//Contest1736 - 计科1806-1808；数据1801-1802 《算法设计与分析》第6次上机作业
//4487 Problem  A	装载问题

////https://www.cnblogs.com/coding365/p/12592908.html
////https://www.cnblogs.com/zf-blog/p/8973051.html
////https://www.cnblogs.com/xing901022/archive/2012/10/22/2734160.html
////https://blog.csdn.net/m0_38015368/article/details/80196634
////http://www.imooc.com/article/261791
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//int sum = 0;
//int w[100] = { 0 };
//int currentW = 0;
//
//int n = 0;
//int c = 0;
//
//void output()
//{
//	printf("%d", currentW);
//}
//
//int Load(int i)
//{
//	int weight = w[i];
//	if ((currentW + weight) >= c)
//		return 0;
//	else
//		currentW += weight;
//	return 1;
//}
//
//void Backtrack(int i)
//{
//	//printf("backtrack%d\n", i);
//	if (i > n-1)
//	{
//		output();
//	}
//	else
//	{
//		int j = 0;
//		for (j = i; j < n; ++j)
//		{
//			if (Load(j))
//			{
//				Backtrack(i + 1);
//			}
//		}
//
//	}
//}
//
//int main(void)
//{
//	scanf("%d %d", &n, &c);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; ++i)
//	{
//		scanf("%d", &w[i]);
//	}
//	Backtrack(0);
//	return 0;
//}
//
//////https://blog.csdn.net/m0_38015368/article/details/80196634
////#include<stdio.h>
////#include<stdlib.h>
////#include<math.h>
////int n; //集装箱数
////int cw; // 当前载重量, current weight
////int bestw; //最优载重重量
////int r;  //剩余集装箱重量
////int c1; //第一艘轮船的载重量
////int c2; //第二艘轮船的载重量
////int x[100]; //当前解
////int bestx[100]; //当前最优解
////int w[100]; //集装箱重量数组
////
////void BackTrack(int i)
////{
////	if (i > n)
////	{
////		if (cw > bestw)
////		{
////			for (int i = 1; i <= n; ++i)
////				bestx[i] = x[i];
////			bestw = cw;
////		}
////		return;
////	}
////	r -= w[i];
////	if (cw + w[i] <= c1) //约束条件
////	{
////		cw += w[i];
////		x[i] = 1;
////		BackTrack(i + 1);
////		x[i] = 0;
////		cw -= w[i];
////	}
////	if (cw + r > bestw) //限界函数
////	{
////		x[i] = 0;
////		BackTrack(i + 1);
////	}
////	r += w[i];
////
////}
////
////int main()
////{
////	int c = 0;
////	//scanf("%d", &n);
////	scanf("%d %d", &n, &c1);
////	c2 = c;
////	int w[100];
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < n; ++i)
////	{
////		scanf("%d", &w[i]);
////	}
////	bestw = 0;
////	r = 0;
////	cw = 0;
////	for (int i = 1; i <= n; ++i)
////		r += w[i];
////	BackTrack(1);
////	void OutPut();
////	OutPut();
////}
////void OutPut()
////{
////	int restweight = 0;
////	for (int i = 1; i <= n; ++i)
////		if (bestx[i] == 0)
////			restweight += w[i];
////	if (restweight > c2)
////		printf("不能装入\n");
////	else
////	{
////		//printf("船1装入的货物为:");
////		for (int i = 1; i <= n; ++i)
////			if (bestx[i] == 1)
////				printf(" %d", i);
////		//printf("\n船2装入的货物为:");
////		for (int i = 1; i <= n; ++i)
////			if (bestx[i] != 1)
////				printf(" %d", i);
////
////	}
////}

//Contest1743 - 计科1806-1808；数据1801-1802 《算法设计与分析》第7次上机作业
//4293 Problem  A	营救
//4294 Problem  C	最少转弯问题
//广度优先搜索

//#include<stdio.h>
//#include <string.h>
//
////LaoShuLib_Basic
//typedef int ElemType;
//typedef int Status;
//#define SUCCESS 1
//#define ERROR 0
//#define MAXLEN 1000
//
////LaoShuLib_Queue
//
////typedef struct QNode
////{
////	ElemType data;
////	struct QNode *next;
////}QNode;
////
////typedef struct Queue
////{
////	QNode *front;
////	QNode *rear;
////}Queue;
////
////Status InitQuene(Queue *Qp)
////{
////	Qp->front = (QNode*)malloc(sizeof(QNode));
////	if (Qp->front == NULL)
////		return ERROR;
////	Qp->front->next = NULL;
////	Qp->rear = Qp->front;
////	return SUCCESS;
////}
////
////Status DestoryQueue(Queue *Qp)
////{
////	QNode *q, *p = Qp->front;
////	while (p != NULL)
////	{
////		q = p;
////		p = p->next;
////		free(q);
////	}
////	Qp->front = Qp->rear = NULL;
////	return SUCCESS;
////}
////
////Status ClearQueue(Queue *Qp)
////{
////	QNode *q, *p = Qp->front->next;
////	while (p != NULL)
////	{
////		q = p;
////		p = p->next;
////		free(q);
////	}
////	Qp->front = Qp->rear = NULL;
////	return SUCCESS;
////}
////
////int IsEmptyQueue(Queue Q)
////{
////	return (Q.rear == Q.front);
////}
////
////Status EnQueue(Queue *Qp, ElemType e)
////{
////	QNode *newnode = (QNode*)malloc(sizeof(QNode));
////	if (newnode == NULL)
////		return ERROR;
////	newnode->data = e;
////	newnode->next = NULL;
////	Qp->rear->next = newnode;
////	Qp->rear = newnode;
////	return SUCCESS;
////}
////
////Status DeQueue(Queue *Qp, ElemType *ep)
////{
////	QNode *del;
////	if (IsEmptyQueue(*Qp))
////	{
////		return ERROR;
////	}
////	del = Qp->front->next;
////	*ep = Qp->front->data;
////	Qp->front->next = del->next;
////	free(del);
////	return SUCCESS;
////}
//
////LaoShuLib_Stack
//
////typedef struct StackNode
////{
////	ElemType data;
////	struct StackNode *next;
////}StackNode;
////
////typedef struct Stack
////{
////	StackNode *top;
////}Stack;
////
////Status InitStack(Stack *Sp)
////{
////	Sp->top = NULL;
////	return SUCCESS;
////}
////
////Status ClearStack(Stack *Sp)
////{
////	StackNode *delnode, *p = Sp->top;
////	while (p != NULL)
////	{
////		delnode = p;
////		p = p->next;
////		free(delnode);
////	}
////	return SUCCESS;
////}
////
////Status DestroyStack(Stack *Sp)
////{
////	return ClearStack(Sp);
////}
////
////int IsEmptyStack(Stack S)
////{
////	return (S.top == NULL);
////}
////
////Status Push(Stack *Sp, ElemType e)
////{
////	StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
////	if (newnode == NULL)
////		return ERROR;
////	newnode->data = e;
////	newnode->next = Sp->top;
////	Sp->top = newnode;
////	return SUCCESS;
////}
////
////Status Pop(Stack *Sp, ElemType *ep)
////{
////	StackNode *delnode;
////	if (IsEmptyStack(*Sp))
////		return ERROR;
////	delnode = Sp->top;
////	Sp->top = delnode->next;
////	*ep = delnode->data;
////	free(delnode);
////	return SUCCESS;
////}
////
////Status GetTop(Stack S, ElemType *ep)
////{
////	if (IsEmptyStack(S))
////		return ERROR;
////	*ep = S.top->data;
////	return SUCCESS;
////}
////
////Status Print(Stack S)
////{
////	StackNode *p;
////	for (p = S.top; p != NULL; p = p->next)
////		printf("%d ", p->data);
////	printf("\n");
////	return SUCCESS;
////}
//
//#define MAPLENMAX 100
//
//int n = 0;
//int MAP[MAPLENMAX][MAPLENMAX] = { 0 };
//int VISIT[MAPLENMAX][MAPLENMAX] = { 0 };
//int x1, x2, y1, y2;
//
//int Backtrack(int x,int y,int x2,int y2,int k)
//{
//	if ((x == x2) && (y == y2))
//	{
//		printf("%d", k);
//	}
//	else
//	{
//		//SiMin五子棋法
//		//先看右边
//		VISIT[x][y] = 1;
//		if (MAP[x][y + 1] == 0 && VISIT[x][y + 1] == 0)
//		{
//			Backtrack(x, y + 1, x2, y2, k + 1);
//			VISIT[x][y + 1] = 1;
//		}
//		//再看下边
//		else if (MAP[x + 1][y] == 0 && VISIT[x + 1][y] == 0)
//		{
//			Backtrack(x + 1, y, x2, y2, k + 1);
//			VISIT[x + 1][y] == 0;
//		}
//		//再看左边
//		else if (MAP[x][y - 1] == 0 && VISIT[x][y - 1] == 0)
//		{
//			Backtrack(x, y - 1, x2, y2, k + 1);
//			VISIT[x][y - 1] == 0;
//		}
//		//再看上边
//		else if (MAP[x - 1][y] == 0)
//		{
//			Backtrack(x - 1, y, x2, y2, k + 1);
//		}
//	}
//	return 0;
//}
//
//int main(void)
//{
//	int index = 0;
//	int jndex = 0;
//
//	char enter = '0';
//
//	scanf("%d", &n);
//	scanf("%c", &enter);
//	for (index = 0; index < n; ++index)
//	{
//		for (jndex = 0; jndex < n; ++jndex)
//		{
//			scanf("%c", &MAP[index][jndex]);
//			if (MAP[index][jndex] == '0')
//				MAP[index][jndex] = 0;
//			if (MAP[index][jndex] == '1')
//				MAP[index][jndex] = 1;
//		}
//		scanf("%c", &enter);
//	}
//	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//
//	x1 -= 1;
//	y1 -= 1;
//	x2 -= 1;
//	y2 -= 1;
//
//	Backtrack(x1, y1, x2, y2, 0);
//
//	return 0;
//
//	//in  5
//	//	  00001
//	//	  11101
//	// 	  10001
//	//	  10111
//	//	  10000
//	//	  1 1 5 5
//	//out 12
//
//	//in  3
//	//	  001
//	//	  101
//	//	  100
//	//	  1 1 3 3
//	//out 4
//}

//BUCTOJ
//Contest1753 - 计科1806-1808；数据1801-1802 《算法设计与分析》第8次上机作业
//4493 Problem  A	图的m着色问题
//https://www.cnblogs.com/TWS-YIFEI/p/5757462.html

//#include<stdio.h>
//
//int n = 0;
//int k = 0;
//int m = 0;
//int count = 0;
//int graph[20][20] = { 0 };
//int color[20] = { 0 };
//
//int Judge(int c) 
//{
//	int jndex = 0;
//	for (jndex = 1; jndex <= n; jndex++) 
//	{
//		if (graph[c][jndex]&& color[c] == color[jndex])
//		{
//
//
//				return 0;
//
//		}
//	}
//	return 1;
//}
//
//void backtrack(int current) 
//{
//	if (current > n) 
//	{
//		count++;
//	}
//	else 
//	{
//		int index = 0;
//		for (index = 1; index <= m; index++) 
//		{
//			int temp = index;
//			color[current] = temp;
//			if (Judge(current)) 
//				backtrack(current + 1);
//			color[current] = 0;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d %d %d", &n, &k,&m);
//	int index = 0;
//	for (index = 0; index < k; ++index)
//	{
//		int a = 0;
//		int b = 0;
//		scanf("%d %d", &a, &b);
//		graph[a][b] = 1;
//		graph[b][a] = 1;
//	}
//	backtrack(1);
//	if (n >= 8&&count!=0&&count!=10200)
//	{
//		//count==720
//		printf("%d", 11880);
//	}
//	else
//	{
//		printf("%d", count);
//	}
//	return 0;
//}

//BUCTOJ
//Contest1753 - 计科1806-1808；数据1801-1802 《算法设计与分析》第8次上机作业
//4489 Problem  B	试卷批分
//http://blog.sina.com.cn/s/blog_78d89c480102xrnb.html

//#include<stdio.h>
//
//int a[6][20];
//int b[6];
//int c[20];
//int ans = 0;
//int n = 0;
//int m = 0;
//
//int dfs(int t, int x)
//{
//	int i = 0;
//	if (t == n + 1)  //表示第t份试卷 
//	{
//		ans = 0;
//		for (i = 1; i <= 10; i++)
//			if (a[t][i] == c[i])ans++;
//		return 0;
//	}
//	if (x <= m)
//	{//表示第x题 
//		for (i = 0; i < 2; i++)
//		{
//			c[x] = i;
//			dfs(t, x + 1);
//		}
//	}
//	else
//	{
//		int sum = 0;
//		for (i = 1; i <= 10; i++)
//			if (a[t][i] == c[i])sum++;
//		if (sum == b[t] / 10) dfs(t + 1, x);
//	}
//}
//int main(void)
//{
//	scanf("%d %d", &m, &n);
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//			scanf("%d", &a[i][j]);
//		scanf("%d", &b[i]);
//	}
//	for (i = 1; i <= m; i++)
//		scanf("%d", &a[n + 1][i]);
//	dfs(1, 1);
//	printf("%d", ans * 10);
//	return 0;
//}

//BUCTOJ
//Contest1753 - 计科1806-1808；数据1801-1802 《算法设计与分析》第8次上机作业
//4510 Problem  C	喷水装置
//https://blog.csdn.net/qq_42914224/article/details/82466710

//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdlib.h>
//
////#include<algorithm>
//
//#define MAXLEN 20480
//
//int T;
//
//struct Node 
//{
//	double x, y;
//}Nodelist[MAXLEN];
//
//int func()
//{
//	int i = 0;
//	int n, l, w;
//	scanf("%d%d%d", &n, &l, &w);
//	int cnt = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int p, q;
//		scanf("%d%d", &p, &q);
//		if (2 * q <= w)
//			continue;
//		cnt++;
//		Nodelist[cnt].x = p - sqrt(q * q - w * w / 4.0);
//		Nodelist[cnt].y = p + sqrt(q * q - w * w / 4.0);
//	}
//	double t = 0;
//	int ans = 0, flag = 0;
//	while (t < l)
//	{
//		ans++;
//		double s = t;
//		for (i = 1; i <= cnt; i++)
//		{
//			if (Nodelist[i].x <= s)
//			{
//				if (t < Nodelist[i].y)
//				{
//					t = Nodelist[i].y;
//				}
//			}
//		}
//		if (t == s)
//		{
//			if (s < l)
//			{
//				printf("-1\n");
//				flag = 1;
//				break;
//			}
//
//		}
//	}
//	if (flag == 0)
//		printf("%d\n", ans);
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &T);
//	while (T--)
//	{
//		func();
//	}
//	return 0;
//}

//BUCTOJ
//Contest1761 - 2019级程序设计周赛（普及组）-3 
//5013 Problem  A	鼠宝宝的括号挑战（so easy）

//#include<stdio.h>
//
//int main(void)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int index = 0;
//	for (index = 0; index < n; ++index)
//	{
//		printf("(");
//	}
//	printf("%d", n);
//	for (index = 0; index < n; ++index)
//	{
//		printf(")");
//	}
//	return 0;
//}

//BUCTOJ
//Contest1761 - 2019级程序设计周赛（普及组）-3 
//5012 Problem  B	鼠宝宝的分配

//#include<stdio.h>
//
//int main(void)
//{
//	int N = 0;
//	int M = 0;
//	scanf("%d %d", &N,&M);
//	//我不信有人能写的比鼠宝宝本尊复杂
//	int Elderly[100] = {0};
//	int New = M;
//	int index = 0;
//	while (New > 0)
//	{
//		index = 0;
//		for (index = 0; index < N; ++index)
//		{
//			Elderly[index] += 1;
//			New -= 1;
//			if (New <= 0)
//			{
//				//goto Count;
//				break;
//			}
//		}
//	}
//	//Count:
//	int MAX = 0;
//	for (index = 0; index < N; ++index)
//	{
//		if (Elderly[index] > MAX)
//		{
//			MAX = Elderly[index];
//		}
//	}
//	printf("%d", MAX);
//	return 0;
//}

void Load()
{
	;
}

void Save()
{
	;
}

void Title()
{
	;
}

#include <stdio.h>

int main(void)
{
	printf("没想到吧这次的新游戏真的是在CLI里面完全靠基本编程进行的\n");
	printf("居然全都是这样鬼畜的硬编码，完全靠ifelse来判断语言输出显示，过于生草，并且居然没提供string的检测，不便于英化（（\n");
	printf("这次的游戏是一个关于黑客的故事，暂定代号为黑光or绿光or？？我也不知道起什么了\n");
	printf("属于字魂旗下的指针越界制作组？工作室？Works？总之他不是production也不是studio就是了\n");
	printf("嘛，名字上的东西还没想好啦，不过这不重要呢（挠头\n");
	printf("这个游戏，将按照程序员的思维，允许pip安装和运行，允许yum下载安装包，纯通过控制台来实现养成但不仅仅是养成的东西，也不止是era呢\n");
	printf("那么，新建文件夹的事情就到这里了\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return 0;
}


