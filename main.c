#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int array_set[4] = {1,2,3,4};//���ݶεĴ����ǿ����޸ĵ�
const static char LogLevelText[4][10] = { "INF",
"DEBUG",
"ERROR",
"ERROR" };

struct students{
	char  name [32];
	int age;
	int sex;//�Ա�
	int grade;//�꼶
	int classes;//�༶
};

/*
������
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

	//ָ�����ֻ֧�ֵļӺͼ�������֧���䣬ӦΪ�ڴ������Եġ�����������������Ԥ֪�ĵ�ַ;
	printf("ptr =%d\n", ptr);
	ptr += 3;//ptr+sizeof(int)*3;

	printf("ptr3 =%d\n",ptr);
	printf("ptr4 =%d,%d\n", &ptr[4] - ptr, &ptr[4]);
	//void * ptr ֻ����Ϊ�洢��ַʹ�ã�û���κ��������ͣ����������ʣ���������Ϊ void ��һ����ȷ�����������ͣ�cup Ҳ��֪����ȡ�����ֽڣ�
	

	//C����ָ������� 

	int * ptr5;
	//��ȡ��ַ��&��ȡ���鿪ʼ��ַ
	ptr5 = &array_set[0];
	printf("ptr5 = %d\n",ptr5);
	//�������Ʊ�ʾ�������ʼ��ַ
	ptr5 = array_set;
	printf("ptr5 = %d\n", ptr5);
	//ָ��Ķ�ȡ
	for  (int j = 0; j < 4; j++)
	{
		printf("%d,%d\n",ptr5[j],*(ptr5+j));



	}
	//ָ���д��
	for (int j = 0; j < 4; j++)
	{

		ptr5[j] = j + 4;
		printf("%d,%d\n", ptr5[j], *(ptr5 + j));



	}

	//����ָ�� ���߶��ָ�� int* *ptr;����*��
	int* *ptr6 = &ptr5;

	printf("%d,%d,%d\n",ptr6,*ptr6,*(*ptr6));//������ڴ��ַ���ڴ��ַ��4
	

	//�ַ����Ķ����Լ���ʼ��,ʹ���ض��ı�Ƿ�����Ϊһ���ַ������ı�ǣ������Ǿ��ǿ��ַ�'\0' Ҳ��Acell(0-127)��ֵ0�������ַ���char��ʾ��
	//��һ���ַ�����ʾ����
	char hello[6] = {'h','e','l','l','o','\0'};//������ջ�ڴ��ϵ�
	char hello_str[16] = { 'h', 'e', 'l', 'l', 'o',0,'w','o','r','l','d',0};
	//ȷ���ڴ��ܹ��洢	
	printf("%d\n", sizeof(hello_str));//���16
	//������\0��������������ַ��������
	printf("%s\n", hello_str);//hello
	//%s ����ַ���
	char * p_hello =hello;
	p_hello[0] = 'y';//�����޸�
	printf("%s,%c\n", p_hello,*p_hello);//���yello

	char * p_hello2 = hello + 4;
	printf("%s\n", p_hello2);//���o
	char * p_hello3 = "hello";//�����ǲ����޸� �����ڴ�����ﲻ���޸�
	char * p_hello4 = "hello";
//	p_hello3[0] = 'y';//�Ƿ�
	printf("%d,%d,%d,%c\n", p_hello2,p_hello3,p_hello4,*p_hello3);
	//�������û���޸ĵ�
	while (*p_hello3){//0Ϊ�� 1Ϊ��
		printf("%c ", *p_hello3);
		p_hello3++;
	}

	for ( p_hello = &hello[0];*p_hello; p_hello ++)
	{
		printf("%c\n ", *p_hello);
	}

	//�ַ�������
	//strlen �����ַ������� ��������β����
	int len = strlen("hello��");
	printf("%d",len);//�����7
	//strcmp �Ƚ������ַ���������������ַ�����ȣ���ô����0������Ļ�������<�ұ� ���ظ�������֮ ��������������򷵻� 0
	char * lhs = "hello";
	char * rhs = "helloword";
	char * rhs2 = "hello";
	int ret = strcmp(lhs,rhs);
	int ret2 = strcmp(lhs,rhs2);
	int ret3 = strcmp(rhs, lhs);
	printf("%d,%d,%d\n",ret,ret2,ret3);//��� -1,0,1

	//strcpy ��Դ�ַ���������Ŀ���ڴ��ַ�ϣ�strcpy(char *dst,char *src);src������һ���Ϸ����ַ���dst����ڴ����Ҫ�Ϸ���Ҫ���㹻�Ŀռ����洢���ǵ��ַ�����
	char * src = "hello";
	//char dst[10];
	double dst;
	strcpy(&dst,src);
	printf("%s\n",&dst);
	char dst1[64];
	//sprintf printf ��ʽ�����
	sprintf(dst1, "dst = %s\n", &dst);//�Ѹ�ʽ��������ַ��� д�뵽dst1
	printf("%s",dst1);

	//�ṹ�� �����ϡ�ö��
	/*
	
	struct ���� {
		1�������������ͣ�
		2��������������ͣ��ṹ�壬�����壬ö�٣���

	};
	�ṹ�嶨�壻
	1�����Զ�����.c�ļ����棬�����ں�������  ֻ���ڱ��ļ���ʹ�� �������ݶ�
	2�������ں������棬ֻ���ں�������ʹ��
	3��������ͷ�ļ��� .c�ļ����������ͷ�ļ��Ϳ���ʹ��


	*/
	struct students s;
	/*
	
	s.age = 45;
	s.classes = 3;
	s.grade = 5;
	//s.name = "����";
	sprintf(s.name, "��ʷ");
	*/
	//��ʼ��ѧ��
	initStudents("����",45,4,5,3,&s);
	outStudents(&s);

	

	struct sharpe {
		int age;
	}sharp;

	sharp.age = 67;

	//��->���������� ������ ��*ptr).���� ָ��һ���ȳ�ʼ�����ܷ���
	struct round{
		int height;
	}* rounds =&sharp ;

	//ָ��ṹ������ַ��ʷ�ʽ
	rounds->height = 67;
	(*rounds).height = 77;
	printf("%d",rounds->height);

	//������
	/**
	union ����{
	
	}
	*/
	union shape u;
	u.s.age = 40;



	system("pause");
	return 0;


}


