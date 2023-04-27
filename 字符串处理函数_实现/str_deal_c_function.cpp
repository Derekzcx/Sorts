/*
* 该程序用于 实现 C语言的基本字符串处理函数 
* strlen(), strcpy(), str
*/
/*
	* assert(exp)  专门的程序调试工具函数
	*  如果表达式 exp 为假，则先向 stderr 打印一条错误信息，在通过调用 abort 来终止程序运行 
*/
#include<iostream>
#include<cassert> // assert函数 

using namespace std;
/********************** strlen() *********************/
/* 返回字符串长度 */ 
// 迭代方法	
int strlen(const char *str){
	assert(str);
	int len = 0;
	while(*str++) len++; 
	return len;
}

/******************** strcmp() ***************************/ 
/* 字符串比较函数 */
/* 相等返回0， 不相等返回非0 */
int strcmp(const char *str1, const char *str2){
	assert(str1 && str2);
	while(*str1 && *str2 && (*str1 == *str2)){
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

/********************* strcat() ***************************/
/* 字符串拼接 */
/* 将str2 追加到 str1 */
char* strcat(char *str1, const char *str2){
	assert(str1 && str2);
	char *p = str1;
	while(*p) p++;
	while(*p++ = *str2++);// 直到 p==null 退出
	return str1; 
}

/******************* strcpy() ***********************/
/* 字符串拷贝 */
/* 将str2 拷贝到 空str1 */ 
char* strcpy(char *str1, const char *str2){
	assert(str1 && str2);
	char *p = str1;
	while(*p++ = *str2++);
	return str1;
} 


int main(){
	const char *str1 = "test1";
	const char *str2 = "test1";
	char ch[20];
	strcpy(ch, str2);
	printf("%s", ch);
	return 0;
} 
