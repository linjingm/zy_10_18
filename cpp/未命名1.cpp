#include<stdio.h>

int main()
{
	double x,y,t,j,a;//˲ʱֵy��������һ˲ʱֵt��˲ʱ���j,�û�����a 
	double h=0.001;//���� 
	double e=0.001*h;//��� 
	double E=2.71828183; 
	double p=3.141592653;
	int i=0;
	
	a=1;
	y=a;
//	j=1;
	printf("   x      y      \n");
	
	
	for(i=0;x<=25;i++)
	{ 
	    x=0.001*i;
		t=y;//������һ��y 
		y=y-h*t;//ŷ���� 
	//	j=t-y;
		
	
		
	}
	 
	
	printf("%lf &lf\n",x,y);
	return 0;
	
}
