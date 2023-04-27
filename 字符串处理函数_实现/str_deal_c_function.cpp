/*
* �ó������� ʵ�� C���ԵĻ����ַ��������� 
* strlen(), strcpy(), str
*/
/*
	* assert(exp)  ר�ŵĳ�����Թ��ߺ���
	*  ������ʽ exp Ϊ�٣������� stderr ��ӡһ��������Ϣ����ͨ������ abort ����ֹ�������� 
*/
#include<iostream>
#include<cassert> // assert���� 

using namespace std;
/********************** strlen() *********************/
/* �����ַ������� */ 
// ��������	
int strlen(const char *str){
	assert(str);
	int len = 0;
	while(*str++) len++; 
	return len;
}

/******************** strcmp() ***************************/ 
/* �ַ����ȽϺ��� */
/* ��ȷ���0�� ����ȷ��ط�0 */
int strcmp(const char *str1, const char *str2){
	assert(str1 && str2);
	while(*str1 && *str2 && (*str1 == *str2)){
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

/********************* strcat() ***************************/
/* �ַ���ƴ�� */
/* ��str2 ׷�ӵ� str1 */
char* strcat(char *str1, const char *str2){
	assert(str1 && str2);
	char *p = str1;
	while(*p) p++;
	while(*p++ = *str2++);// ֱ�� p==null �˳�
	return str1; 
}

/******************* strcpy() ***********************/
/* �ַ������� */
/* ��str2 ������ ��str1 */ 
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
