#include<stdio.h>


int main()
{
	double x,y,t,a,b,j;//瞬时值y，储存上一瞬时值t，瞬时误差j,用户输入a 
	double h=0.001;//步长 
	double e=0.001*h;//误差 
	double E=2.718281828459;
	double p=3.1415926535 ;
	int i=0;
	
//	scanf("%lf",&a);
	a=p;
	y=a;
//	j=1;
	b=(h*h)/2-h+1;
	printf("   x         y     \n");
	
	
	for(i=0;x<=25*p;i++)
	{ 
	    x=0.001*i;
		t=y;
		y=y*b;
//		j=t-y;
		
	
	}
	
	 	printf("%lf %.36lf\n",x,y);
		
	 return 0;
	
}
