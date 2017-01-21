#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int array_set[4] = {1,2,3,4};//数据段的代码是可以修改的
const static char LogLevelText[4][10] = { "INF",
"DEBUG",
"ERROR",
"ERROR" };

struct students{
	char  name [32];
	int age;
	int sex;//性别
	int grade;//年级
	int classes;//班级
};

/*
联合体
*/

union shape{
	struct students s;
	int a;
	char c;


} ;

void func(){
	struct person{
		char * name;
		int weight;
		int height;

	};

}
void initStudents(char name[64],int age,int sex,int grade,int classes,struct students * ptr){
	strcpy(ptr->name, name);
	ptr->age = age;
	ptr->classes = classes;
	ptr->grade = grade;
	ptr->sex = sex;


}

void outStudents(struct students *s){

	char dsts[67];
	sprintf(dsts, "name = %s,age = %d,grade = %d,classes = %d\n", (*s).name, (*s).age, (*s).grade, (*s).classes);
	printf("%s", dsts);
}


int main(int argc,char* argv[]){
	int * ptr;
	int c = 10;
	int d = 9;
	int e = 8;
	int f = 7;
	int a = 6;

	ptr = &a;
	printf("%c\n", LogLevelText[1][4]);
	//int b[5] = {1,2,3,4,5};

//	int lent = sizeof(b) / sizeof(int);

//	for (int i = 0; i < lent; i++)
	//{
		//printf("i= %d\n", b[i]);

	//}
	//printf("ptr = %d,*ptr = %d\n", ptr,*ptr);
	//printf("c=%shellow C++\n","hellow");
	printf("ptr[0] = %d\n,ptr[1] = %d\n,%d", ptr[0],ptr[1],c);

	//指针变量只支持的加和减法，不支持其，应为内存是线性的。其他运算会产生不可预知的地址;
	printf("ptr =%d\n", ptr);
	ptr += 3;//ptr+sizeof(int)*3;

	printf("ptr3 =%d\n",ptr);
	printf("ptr4 =%d,%d\n", &ptr[4] - ptr, &ptr[4]);
	//void * ptr 只能作为存储地址使用，没有任何数据类型，不能来访问，理由是因为 void 是一个不确定的数据类型，cup 也不知道读取多少字节；
	

	//C语言指针和数组 

	int * ptr5;
	//用取地址符&获取数组开始地址
	ptr5 = &array_set[0];
	printf("ptr5 = %d\n",ptr5);
	//数组名称表示数组的起始地址
	ptr5 = array_set;
	printf("ptr5 = %d\n", ptr5);
	//指针的读取
	for  (int j = 0; j < 4; j++)
	{
		printf("%d,%d\n",ptr5[j],*(ptr5+j));



	}
	//指针的写入
	for (int j = 0; j < 4; j++)
	{

		ptr5[j] = j + 4;
		printf("%d,%d\n", ptr5[j], *(ptr5 + j));



	}

	//二阶指针 或者多阶指针 int* *ptr;两个*；
	int* *ptr6 = &ptr5;

	printf("%d,%d,%d\n",ptr6,*ptr6,*(*ptr6));//输出：内存地址，内存地址，4
	

	//字符串的定义以及初始化,使用特定的标记符号作为一串字符结束的标记，这个标记就是空字符'\0' 也就Acell(0-127)是值0；单个字符用char表示；
	//第一种字符串表示方法
	char hello[6] = {'h','e','l','l','o','\0'};//分配在栈内存上的
	char hello_str[16] = { 'h', 'e', 'l', 'l', 'o',0,'w','o','r','l','d',0};
	//确认内存能够存储	
	printf("%d\n", sizeof(hello_str));//输出16
	//遇到‘\0’后面如果还有字符则不再输出
	printf("%s\n", hello_str);//hello
	//%s 输出字符串
	char * p_hello =hello;
	p_hello[0] = 'y';//可以修改
	printf("%s,%c\n", p_hello,*p_hello);//输出yello

	char * p_hello2 = hello + 4;
	printf("%s\n", p_hello2);//输出o
	char * p_hello3 = "hello";//常量是不能修改 加载在代码段里不能修改
	char * p_hello4 = "hello";
//	p_hello3[0] = 'y';//非法
	printf("%d,%d,%d,%c\n", p_hello2,p_hello3,p_hello4,*p_hello3);
	//代码段是没法修改的
	while (*p_hello3){//0为假 1为真
		printf("%c ", *p_hello3);
		p_hello3++;
	}

	for ( p_hello = &hello[0];*p_hello; p_hello ++)
	{
		printf("%c\n ", *p_hello);
	}

	//字符串函数
	//strlen 计算字符串长度 不包含结尾符号
	int len = strlen("hello你");
	printf("%d",len);//输出：7
	//strcmp 比较两个字符串，如果这两个字符串相等，那么返回0，否则的话如果左边<右边 返回负数，反之 返回正数，相等则返回 0
	char * lhs = "hello";
	char * rhs = "helloword";
	char * rhs2 = "hello";
	int ret = strcmp(lhs,rhs);
	int ret2 = strcmp(lhs,rhs2);
	int ret3 = strcmp(rhs, lhs);
	printf("%d,%d,%d\n",ret,ret2,ret3);//输出 -1,0,1

	//strcpy 将源字符串拷贝到目标内存地址上，strcpy(char *dst,char *src);src必须是一个合法的字符串dst这块内存必须要合法，要有足够的空间来存储我们的字符串；
	char * src = "hello";
	//char dst[10];
	double dst;
	strcpy(&dst,src);
	printf("%s\n",&dst);
	char dst1[64];
	//sprintf printf 格式化输出
	sprintf(dst1, "dst = %s\n", &dst);//把格式化输出的字符串 写入到dst1
	printf("%s",dst1);

	//结构体 和联合、枚举
	/*
	
	struct 名称 {
		1、基本数据类型；
		2、复查的数据类型（结构体，联合体，枚举）；

	};
	结构体定义；
	1、可以定义在.c文件里面，并且在函数外面  只能在本文件里使用 分配数据段
	2、定义在函数里面，只能在函数里面使用
	3、定义在头文件里 .c文件可以引入该头文件就可以使用


	*/
	struct students s;
	/*
	
	s.age = 45;
	s.classes = 3;
	s.grade = 5;
	//s.name = "张三";
	sprintf(s.name, "历史");
	*/
	//初始化学生
	initStudents("张三",45,4,5,3,&s);
	outStudents(&s);

	

	struct sharpe {
		int age;
	}sharp;

	sharp.age = 67;

	//用->来访问属性 还可以 （*ptr).属性 指针一定先初始化才能访问
	struct round{
		int height;
	}* rounds =&sharp ;

	//指针结构体的两种访问方式
	rounds->height = 67;
	(*rounds).height = 77;
	printf("%d",rounds->height);

	//联合体
	/**
	union 名称{
	
	}
	*/
	union shape u;
	u.s.age = 40;



	system("pause");
	return 0;


}


