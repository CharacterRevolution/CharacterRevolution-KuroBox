//PartName���

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define STOCK 274
//#define MAXLEN 10000
//
////����ȡ�������������ǵķ���ʵ��
//
//int main(void)
//{
//	int i = 0;
//	for (i = 271; i <= 274; ++i)
//	{
//		if (fopen("E:\C_Program_Learn\273\38708937.info", "r") == NULL)
//			perror("!!!gui");
//		//FILE *info = fopen("i\\38708937.info", "r");
//		//Ŀ���ļ�ָ������������
//		int jndex = 0;
//		int kndex = 0;
//		wchar_t str[MAXLEN] = { 0 };
//		wchar_t patch[MAXLEN] = L"PartName";
//		int patchLen = 8;
//		//wscanf(info, "%s", str);
//		int POS = 0;
//		int flag_NotFound = 0;
//		//Ѱ��PartName��λ��
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
//		printf("PartName�Ŀ�ʼλ��Ϊ%d", POS);
//
//	}
//	return 0;
//}

//GPS Tools

////�������ṩһ��������ָ�ʽGPS���겢�������Ĺ���
////����������WSG84����,��Ȼ��ȫ������GCJ02����Ҳû�����⣬ֻҪȫ����һ��ϵ�Ϳ���
////δ�����ܹ�����ߵ»�ٶ�APIʱ�������Զ���ѯ���λ�ò������ַ
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
////#define PARALLEL_OMP  //���ӵ�OMP�Ż�����������ɴ�MIN�ɵ�MAX ����Խ�Ż�Խ��
////#define PARALLEL_CUDA //����ֻ��winapi+cuda����ƽ̨�����Ҳ������ҵ������㲻�������
//
//#define DEBUG
//
//int comp(const void*a, const void*b)//�������Ƚϵĺ�����
//{
//	return *(float*)a - *(float*)b;
//}
//
////float comp(float a, float b)//�������Ƚϵĺ�����
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
//	//��+1��ֹը��
//	printf("����������X�����ȣ���Y��γ�ȣ�\n��ʽΪ��С������X��Y��Ӣ�Ķ��ŷָ�\n");
//	printf("����������������������������������������\n");
//	int index = 0;
//	int jndex = 0;
//	int count = 0;
//
//	//����д����MAXPERSON�����
//	//��Զ��Ҫ�����û�������
//	while (fscanf(Src,"%f,%f", &X[count], &Y[count]) != EOF)
//	{
//		if (count >= MAXPERSON)
//		{
//			printf("WARN:��������Ѿ������������%d", MAXPERSON);
//			break;
//		}
//		//���Ĳ��ƣ������涨��Ŀ������
//		//��Ȼ����Ҳ���ܹ������ܶ�Ĵ�������飬���������
//
//		//����Ԥ����
//
//		////����һ���Է�С����ʽ����С����ʽ
//		//��Ȼ��Զ��Ҫ�����û������룬���ǻ�û�кõİ취����û��������ǲ��Ƕȷ�����ʽ������
//		//��������סEWNS���ִ���ĸ�������ʽ
//		//��Ȼ�����Ϊ�˾��Ա�֤��ȷ��Ӧ�öԶȷ�����ʽȫ�Ĳ��öȷ�����㣬����û��Ҫ
//
//		////���������ȡֵ��Χ���ж�
//		//////����Ӧ����+-180������//
//		//����+180��ֱ�Ӽ�360��ѭ��
//		//С��-180��ֱ�Ӽ�360��ѭ��
//		//////γ��Ӧ����+-90������//
//		//����90��,��Ϊ+90��-90�����ᣬ����Ҳ��֪��Ӧ����ô����
//		//���о��ȼ�2pi�ȣ�ֱ��γ����0-360�����ڣ��ٷ�Ϊ�ĸ���������
//
//		////���������Կ��ܴ��ڵľ�γ�ȷ�ת����
//		//����Ӧ���ڴ�����м����
//		if (abs(Y[index]) > 90.0)
//			printf("WARN:��%d�����ݵ�γ�ȴ���90�ȣ������Ƿ��о�γ�Ȼ���"/*"WARN:%d/%d�����ݵ�γ�ȴ���90�ȣ������Ƿ��о�γ�Ȼ���"*/, index + 1/*, MAXPERSON*/);
//
//		count += 1;
//	}
//#ifdef DEBUG
//	printf("����������������������������������������\n");
//	printf("����չʾ���ǻ�õ�����\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f,%f\n", X[index], Y[index]);
//	}
//	printf("����������������������������������������\n");
//#endif // DEBUG
//
//	//ʹ�õķ���Ϊ�ֱ��˻�ΪX��Y�����ֱ���X��Y����������ؿ���һ�����������ĵ�
//	//��дͨX
//	qsort(X, count, sizeof(float), comp);
//	qsort(Y, count, sizeof(float), comp);
//
//#ifdef DEBUG
//	printf("����������������������������������������\n");
//	printf("����չʾ��������õ�X����\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f\n", X[index]);
//	}
//	printf("����������������������������������������\n");
//#endif // DEBUG
//
//#ifdef DEBUG
//	printf("����������������������������������������\n");
//	printf("����չʾ��������õ�Y����\n");
//	for (index = 0; index < count; ++index)
//	{
//		printf("%f\n", Y[index]);
//	}
//	printf("����������������������������������������\n");
//#endif // DEBUG
//
//	float X_Min = X[0];
//	float X_Max = X[count-1];
//	float Y_Min = Y[0];
//	float Y_Max = Y[count-1];
//	float X_POS = 0.0;
//	float Y_POS = 0.0;
//
//	//��X���ؿ���
//	//�����ݶ�0.01
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
//			printf("%f��ľ����ܺ�Ϊ%f\n", indexf, TempSum);
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
//		printf("%f��ľ����ܺ�Ϊ%f\n", indexf, TempSum);
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
//	printf("��X���������ʱΪ%f��\n", duration_x);
//	printf("��X�������λ��Ϊ%f��\n", X_POS);
//	fprintf(Out, "��X���������ʱΪ%f��\n", duration_x);
//	fprintf(Out, "��X�������λ��Ϊ%f��\n", X_POS);
//
//	//��Y���ؿ���
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
//	printf("��Y���������ʱΪ%f��\n", duration_y);
//	printf("��Y�������λ��Ϊ%f��\n", X_POS);
//	fprintf(Out, "��Y���������ʱΪ%f��\n", duration_y);
//	fprintf(Out, "��Y�������λ��Ϊ%f��\n", X_POS);
//
//	printf("����������������������������������������\n");
//	printf("�������Ϊ%f,%f\n",X_POS,Y_POS);
//	fprintf(Out, "����������������������������������������\n");
//	fprintf(Out, "�������Ϊ%f,%f\n", X_POS, Y_POS);
//	return 0;
//}
//�����ǱȽϵ�ʵ��
//#include<stdio.h>
//#include<stdlib.h>
//int comp(const void*a, const void*b)//�������Ƚϵĺ�����
//{
//	return *(float*)a - *(float*)b;
//}
//int main()
//{
//	int n = 10;
//	float a[10] = { 2,4,1,5,5,3,7,4,1,5 };//��������顣
//	int i;
//	qsort(a, n, sizeof(float), comp);//����qsort����
//	for (i = 0; i < 10; i++)//�������������
//	{
//		printf("%f\t", a[i]);
//	}
//	return 0;
//}

//�������

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
////x=�ǶȵĦ�
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

//л�ľ����ݷ���

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
//		//	//����10���Ͳ�д�ˣ��Լ���
//		//}
//		////����9���Ͳ�д�ˣ��Լ���
//	}
//	//��˵�������ҲӦ��������for
//	printf("X��0-10����Y��0-10��һ����%d", countSeparate[0][10]);
//	return 0;
//}

//�㷨�ϻ�������

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
////		//�ݰ������Ŀ�����д
////	}
////}
//
//˵һ�´��µ�˼·
//���������Ŀ�����ô����ķ�ʽȥ��
//֮ǰ������ַ���
//��һ�������ж��Ǽ�λ���̣��ٷֱ���������ڷ���������
//�ڶ�����ֱ�Ӱ�������һ��26����/25�����������󣬵�����Ϊ�漰����ȱ�͵�����û�����Լ򵥵Ĺ���
//˼·�������ģ�����һ�������������n=1��������������˳��ֻ�������ޣ���ѯ��ʱ��Ҳֻ�������ޣ������Ӷ�Ӧ��Node
//֮��������������ͻ���i��XX��YY��һ�Σ�for������һ������λ�����жϣ����λ��û��ָ����λ�����ٿ�һ�������������ݹ鷽������
//֮����εݹ�ȷ�����i��ͨ�����i��ȷ���������ĸ��ͬʱ��������for�����������ʱλ������ָ����λ����if�ж�һ�����i�Ĵ�С��ϵ�����������
//����
//for(index=1;index<=5;++index)
//{
//	List(i);
//}
//*/
//
////BUCTOJ
////Contest1543 - 19�����ݽṹ��ҵ�����ƿ�&������&�żƺϰࣩ
////���ӣ�������Ŀ����
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

//д��ɢ��ѧ����������Ĵ�����Ƿ��������ϵͳ�����
//���ڼ���A={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}���ж����ж��������*�Ƿ�Ϊ����A�ϵĴ������㡣

//#include<stdio.h>
//#include<math.h>
//
//float xtoy(int x, int y)
//{
//	float temp = 0.0;
//	//////��������
//	temp = (float)(x+y)/2;
//	//////��������
//	return temp;
//}
//
//int main(void)
//{
//	int i = 0;
//	int j = 0;
//	printf("������X��С����������Y��С����\n");
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
//Contest1564 - 19�����ݽṹ��ҵ�ģ��ƿ�&������&�żƺϰࣩ
//Contest1710 - �ƿ�1806-1808������1801-1802 ���㷨������������2���ϻ���ҵ
//4052 Problem  A	˫ɫHanoi������

//#include<stdio.h>
//#include<stdlib.h>
//
//#define MaxLen 1000//�����ռ�ĳ��ȣ��ߴ磩
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
////�������ڹ�������ṹ��ʱ����ȡ����
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
////��ʦд�İ汾
//{
//	//from��ʮ������
//	//to��ת����base����֮��Ľ��
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
//	//2210 Problem  F	�㷨3 - 5��n��Hanoi������
//
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		Hanoi(n);
//	}
//	return 0;
//}

//BUCTOJ
//Contest1710 - �ƿ�1806-1808������1801-1802 ���㷨������������2���ϻ���ҵ
//3648 Problem  B	ѭ���ճ̱����⣬���㷨�������ž��䡷P230���ݹ�����Σ�����Ƽ��CCF����

//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//
//����һ��ȫ�������ֱ�������ʧ�ܣ�����4GB�ڴ�˭����ס
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
//			//���һ������ǰ���ȼ���Ǽ�λ��
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
//���������������
//
//int printSingalNum(int martix[1024][1024],int n)
//{
//	//���һ������ǰ���ȼ���Ǽ�λ��,��������
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
//	//��������
//
//	//��׼�ݹ�
//	//if ((c2 - c1) == 1)
//	//{
//	//	//���������С���ز����
//	//}
//	//else
//	//{
//	//	printSingalLine(r, c1, (int)(c2/2));
//	//	printSingalLine(r, (int)(c2/2)+1, c2);
//	//}
//
//	//��������˼��
//	//����C2�ĳ��ȴ�1024�����ȡ��һ��4MB��ը����
//	int line[1024] = {0};
//	int n = c2;
//	int k = log(n) / log(2);
//	//��һ�㣺��ż����
//	if (r % 2 != 0)//����
//	{
//		;//������������ż�������������ֵ�������������ǰ������ż����ǰ
//	}
//	else
//	{
//		int nHalf = c2 / 2;
//		int index = 0;
//		for (index = 1; index <= nHalf; ++index)
//		{
//			int temp = line[index-1];
//			//��ʱindex��Ϊż���е�
//			line[index - 1] = line[index];
//			line[index] = temp;
//		}
//	}
//	//�ڶ���
//	//���3��4�У�7��8��������2^2��Ϊ��λ�еĺ�2^1��
//	if(r>pow(2,1)&&)
//	//š��
//}
//
//int plot(int r1, int r2, int c1, int c2)
//{
//	//if ((r2 - r1) == 1)
//	//{
//	//	//��Ϊ�Ƿ�������ֻ��r2-r1
//	//	;
//	//}
//	//else
//	//{
//	//	////����ɨ��
//	//	////|plot1|plot2|
//	//	////|plot3|plot4|
//	//	////��֤��ӡ˳����ȷ
//	//	//plot(r1, r2 / 2, c1, c1 / 2);
//	//	//plot(r1, r2 / 2, c1 / 2 + 1, c2);
//	//	////�����ܱ�֤��plot1��ӡ�Ĺ����У��°벿�ִ�ӡ�˶�����c1/4---c1/2��һ�ε�plot2��ӡ������
//	//}
//
//	//����ɨ��
//	
//	////�������е�
//	//int nHalf = r2 / 2;
//	//int index = 0;
//	//for (index = 1; index <= nHalf; ++index)
//	//{
//	//	printDoubleLine(index * 2 - 1, c2);
//	//}
//
//	//1��1�е�
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
//Contest1719 - �ƿ�1806-1808������1801-1802 ���㷨������������3���ϻ���ҵ
//4054 Problem  A	���ļ���

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
//		//Ҫô������Ҫ��Ҫô���λ��1��û����
//	}
//	int Higher = 0;//���λ
//	if (num < 1000)
//	{
//		if (num < 100)
//		{
//			if (num < 10)
//			{
//				//��һλ��
//				Higher = num;
//			}
//			else//����λ��
//			{
//				Higher = num / 10;
//			}
//		}
//		else//����λ��
//		{
//			Higher = num / 100;
//		}
//	}
//	//printf("����������λΪ%d\n", Higher);
//	int half = 0;
//	if (Higher % 2 != 0)
//		half = (Higher - 1) / 2;
//	else
//		half = Higher / 2;
//	//printf("���λ��һ�뵽%dΪֹ\n", half);
//	int index = 0;
//	int countSum = 0;
//	for (index = 1; index <= half; ++index)
//	{
//		int temp = 0;
//		if (num < 10)
//		{
//			temp = num + half * 10;
//			//printf("������%d������һ�ּ���\n", temp);
//			publicCount += 1;
//			countSum += Multiple(0, temp);
//		}
//		else if(num<100)
//		{
//			temp = num + half * 100;
//			//printf("������%d������һ�ּ���\n", temp);
//			publicCount += 1;
//			countSum += Multiple(0, temp);
//		}
//		else
//		{
//			temp = num + half * 1000;
//			//�ǾͲ��ô���һ����
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
//	//printf("n��ֵΪ%d\n", n);
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
//	//���һ���ݹ麯��������ԭ����Ȼ��������λ���֣�Ȼ�󿴳��Զ��м�����Ȼ��ֱ��ٴ������ɸ��Ӻ�����ֱ�������ټ�
//	//printf("%d", count);
//	printf("%d", publicCount);
//	return 0;
//}

//BUCTOJ
//Contest1724 - �ƿ�1806-1808������1801-1802 ���㷨������������4���ϻ���ҵ
//3511 Problem  B	װ��

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
////��ô�õĴ�����Ȼ���������Լ�д��
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
//	int dp[20004] = { 0 };//��¼��j��������V��Ҫ��20000
//	int num[40] = { 0 };//��¼ÿ������������Ҫ��30
//	for (int i = 0; i < m; i++)//����
//		scanf("%d", &num[i]);
//	for (int i = 0; i < m; i++)//������������������ӣ���ֹ�ظ�����
//	{
//		for (int j = n; j >= num[i]; j--)//�ж������Ƿ��������
//		{
//			dp[j] = max(dp[j], dp[j - num[i]] + num[i]);
//		}
//	}
//	printf("%d\n", n - dp[n]);
//	return 0;
//}

//BUCTOJ
//Contest1729 - �ƿ�1806-1808������1801-1802 ���㷨������������5���ϻ���ҵ
//4483 Problem  A	N �ʺ�����

//////�α���
////ʹ��C

//#include<stdio.h>
//#include<math.h>
//
//int sum = 0;
//int x[10] = { 0 };
//
////PPT����
//void output(int x[10],int n)
//{
//	//cout << "��" << sum << "�ַ��÷���Ϊ��" << endl;
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
//ʹ��C++

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
////�жϵ�k�����ܲ��ܷ���x[k]��
////�����ʺ��ܷ���ͳһб���ϣ�
////��2���ʺ���õ�λ�÷ֱ��ǣ�i,j���ͣ�k,l��,
////�� i-j = k -l �� i+j = k+l����˵����2���ʺ���ͬһб���ϡ�
//
//void output() {
//	//cout << "��" << sum << "�ַ��÷���Ϊ��" << endl;
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
//void BackTrace(int t, int n) {//�ݹ�
//	if (t > n) {////���t>n˵���Ѿ����һ�η���
//		sum++;
//		output();
//	}
//	else {
//		for (int i = 1; i <= n; i++) {
//			x[t] = i;
//			if (place(t)) {// //���Է���iλ�ô������������
//				BackTrace(t + 1, n);
//			}
//		}
//
//	}
//}
//
//void BackTrace1(int n) {//�ǵݹ�
//	int k;
//	x[1] = 0;
//	k = 1;
//	while (k >= 1) {
//		x[k] += 1;////�ȷ��ڵ�һ��λ��
//		while ((x[k] <= n && !(place(k)))) {//������ܷ�
//			x[k]++;//  //������һ��λ��
//		}
//		if (x[k] <= n) {
//			if (k == n) {// //����Ѿ�������n���ʺ�
//				sum++;
//				output();
//			}
//			else {//  //û�д����꣬��k�Լӣ�������һ���ʺ�
//				k++;
//				x[k] = 0;
//			}
//		}
//		else {// ��ǰ�޷���ɷ��ã�����м�֦�����ݻ�ȥ���ص���k-1��
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
//	//cout << n << "�ʺ�ķ��÷���Ϊ" << endl;
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
//Contest1736 - �ƿ�1806-1808������1801-1802 ���㷨������������6���ϻ���ҵ
//4487 Problem  A	װ������

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
////int n; //��װ����
////int cw; // ��ǰ������, current weight
////int bestw; //������������
////int r;  //ʣ�༯װ������
////int c1; //��һ���ִ���������
////int c2; //�ڶ����ִ���������
////int x[100]; //��ǰ��
////int bestx[100]; //��ǰ���Ž�
////int w[100]; //��װ����������
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
////	if (cw + w[i] <= c1) //Լ������
////	{
////		cw += w[i];
////		x[i] = 1;
////		BackTrack(i + 1);
////		x[i] = 0;
////		cw -= w[i];
////	}
////	if (cw + r > bestw) //�޽纯��
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
////		printf("����װ��\n");
////	else
////	{
////		//printf("��1װ��Ļ���Ϊ:");
////		for (int i = 1; i <= n; ++i)
////			if (bestx[i] == 1)
////				printf(" %d", i);
////		//printf("\n��2װ��Ļ���Ϊ:");
////		for (int i = 1; i <= n; ++i)
////			if (bestx[i] != 1)
////				printf(" %d", i);
////
////	}
////}

//Contest1743 - �ƿ�1806-1808������1801-1802 ���㷨������������7���ϻ���ҵ
//4293 Problem  A	Ӫ��
//4294 Problem  C	����ת������
//�����������

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
//		//SiMin�����巨
//		//�ȿ��ұ�
//		VISIT[x][y] = 1;
//		if (MAP[x][y + 1] == 0 && VISIT[x][y + 1] == 0)
//		{
//			Backtrack(x, y + 1, x2, y2, k + 1);
//			VISIT[x][y + 1] = 1;
//		}
//		//�ٿ��±�
//		else if (MAP[x + 1][y] == 0 && VISIT[x + 1][y] == 0)
//		{
//			Backtrack(x + 1, y, x2, y2, k + 1);
//			VISIT[x + 1][y] == 0;
//		}
//		//�ٿ����
//		else if (MAP[x][y - 1] == 0 && VISIT[x][y - 1] == 0)
//		{
//			Backtrack(x, y - 1, x2, y2, k + 1);
//			VISIT[x][y - 1] == 0;
//		}
//		//�ٿ��ϱ�
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
//Contest1753 - �ƿ�1806-1808������1801-1802 ���㷨������������8���ϻ���ҵ
//4493 Problem  A	ͼ��m��ɫ����
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
//Contest1753 - �ƿ�1806-1808������1801-1802 ���㷨������������8���ϻ���ҵ
//4489 Problem  B	�Ծ�����
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
//	if (t == n + 1)  //��ʾ��t���Ծ� 
//	{
//		ans = 0;
//		for (i = 1; i <= 10; i++)
//			if (a[t][i] == c[i])ans++;
//		return 0;
//	}
//	if (x <= m)
//	{//��ʾ��x�� 
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
//Contest1753 - �ƿ�1806-1808������1801-1802 ���㷨������������8���ϻ���ҵ
//4510 Problem  C	��ˮװ��
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
//Contest1761 - 2019����������������ռ��飩-3 
//5013 Problem  A	�󱦱���������ս��so easy��

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
//Contest1761 - 2019����������������ռ��飩-3 
//5012 Problem  B	�󱦱��ķ���

//#include<stdio.h>
//
//int main(void)
//{
//	int N = 0;
//	int M = 0;
//	scanf("%d %d", &N,&M);
//	//�Ҳ���������д�ı��󱦱�������
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
	printf("û�뵽����ε�����Ϸ�������CLI������ȫ��������̽��е�\n");
	printf("��Ȼȫ�������������Ӳ���룬��ȫ��ifelse���ж����������ʾ���������ݣ����Ҿ�Ȼû�ṩstring�ļ�⣬������Ӣ������\n");
	printf("��ε���Ϸ��һ�����ںڿ͵Ĺ��£��ݶ�����Ϊ�ڹ�or�̹�or������Ҳ��֪����ʲô��\n");
	printf("�����ֻ����µ�ָ��Խ�������飿�����ң�Works����֮������productionҲ����studio������\n");
	printf("������ϵĶ�����û������������ⲻ��Ҫ�أ���ͷ\n");
	printf("�����Ϸ�������ճ���Ա��˼ά������pip��װ�����У�����yum���ذ�װ������ͨ������̨��ʵ�����ɵ������������ɵĶ�����Ҳ��ֹ��era��\n");
	printf("��ô���½��ļ��е�����͵�������\n");
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


