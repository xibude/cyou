/* 
两个大数相乘问题
http://zhidao.baidu.com/question/326369234.html?fr=fd

华为面试中解决了这个问题后，他会提出这个数非常大，然后怎么解决？ 
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void multiply(char* a,char* b,char* c)
{
    int i,j,ca,cb,t, * s;
    ca=strlen(a);		//a的位长为ca 
    cb=strlen(b);		//b的位长为cb 
    s=(int*)malloc(sizeof(int)*(ca+cb));	//s分配空间为int型的(ca+cb)倍 ，即s[]为int数组，长度为ca+cb。 
	//初始化s数组 
    for (i=0;i<ca+cb;i++)
        s[i]=0;

    /*模仿笔算过程。
	只是这里的处理是从高位开始，
	因为对c语言来数，输入的字符串，a[0]、b[0]为最高位 
    假设a[]="9876", b[]="54", 
	笔算一般是从低位开始算，即先是6*4，
	而c语言则是先从a[0] ,b[0]开始 ，即先是9*5。 
	因此在这个程序中要注意这个问题。 
	*/
	for (i=0;i<ca;i++)
        for (j=0;j<cb;j++)
        { 
		    s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
         	
         	//woo
         	if(j==0)
         	{
         		printf("\n");
         		for(t=0; t<i; t++)
         			printf("    ");
			}
			printf("%4d", s[i+j+1]);    	
		}
    for (i=ca+cb-1;i>=0;i--)
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
        
    
	//判断最高位是否为0    
    i=0;
    while (s[i]==0)
        i++;
        
	//将数字转换为字符
    for (j=0;i<ca+cb;i++,j++)
        c[j]=s[i]+'0';
    c[j]='\0';
    
    free(s);
}

int main(void)
{
	char a[]="123456789123456";
	char b[]="98765432154321";
	
	//char a[]="9876";
	//char b[]="54";
	
	char c[50];
	
	int i;
	for( i=0; i<50; i++)
		c[i] = 0;
		
	multiply(a, b, c);
	
	printf("\n\nResult is %s", c);
	
	getch();
}
