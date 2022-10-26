#include<stdio.h>

int main()
{
	double x,y,t,j,a;//瞬时值y，储存上一瞬时值t，瞬时误差j,用户输入a 
	double h=0.001;//步长 
	double e=0.001*h;//误差 
	int i=0;
	
	scanf("%lf",&a);
	y=a;
	j=1;
	printf("   x         y     \n");
	
	
	for(i=0;x<=25;i++)
	{ 
	    x=0.001*i;
		t=y;
		y=y-h*t;
	//	j=t-y;
		
		printf("%.37lf\n",y);
		
	}
	 
	 return 0;
	
}
