#include<stdio.h>

int main()
{
	double x,y,t,j,a;//˲ʱֵy��������һ˲ʱֵt��˲ʱ���j,�û�����a 
	double h=0.001;//���� 
	double e=0.001*h;//��� 
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
