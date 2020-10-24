#include<stdio.h>
#include<conio.h>
#define bool int 
#define true 1
#define false 0
int main()
{

	long n;
	do       /*Vòng lặp nhập*/
	{
		printf("\nNhap n(n >= 0): ");
		scanf("%ld", &n);
		if(n < 0)
		{
			printf("\nN phai >= 0. Xin nhap lai !"); 
		}
	}while(n < 0);

	
	printf("\nSo %d gom toan cac chu so chan hay khong ?\n", n);
	bool Check = true; /*Kiểm tra điều kiện bằng boolean*/
	if ( n>=10)
	{
	    while(n /= 10)
     	{
		   if((n % 10) % 2 == 1)
		    {
			Check = false;
		    break;
	    	}
	    }
	}else
	{
		if (n % 2==1)
		{
			Check = false;
			
		}
	}
	
	if(Check == true)
	{
		printf("Dung !");
	}
	else
	{
		printf("Sai");
	}
	getch();
	return 0;
}
	