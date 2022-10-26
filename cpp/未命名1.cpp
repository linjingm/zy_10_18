#include<stdio.h>

int main()
{
	double x,y,t,j,a;//瞬时值y，储存上一瞬时值t，瞬时误差j,用户输入a 
	double h=0.001;//步长 
	double e=0.001*h;//误差 
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
		t=y;//存贮上一个y 
		y=y-h*t;//欧拉法 
	//	j=t-y;
		
	
		
	}
	 
	
	printf("%lf &lf\n",x,y);
	return 0;
	
}
