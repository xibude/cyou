/*
翻转字符串的顺序。
输入：a[] = "abcdefg"
输出：a[] = "gfedcba"
强调最后输出仍然在a[]中，输入可能会很长很长。 
*/

#include <stdio.h>
#include <string.h>
void swap(char *x, char * y)
{
	char tmp;
	
	tmp = *x;
	*x = *y;
	*y = tmp;	
}
void invert(char a[], char len) 
{
	int i ;
	char tmp;
	for(i=0; i<len/2; i++)
	{
		swap(&a[i], &a[len-1-i]);
	}
}

int main(void)
{
	char a[] = "abcdefgh";
	char len;

	len = strlen(a);
	
	printf("输入：%s\n", a);
	invert(a, len);
	printf("len = %d\n", len);
	printf("输出：%s\n", a);
	
	getch();
}
