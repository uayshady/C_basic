#include <stdio.h>
#include <stdlib.h>
//Nguyen Trong Khoi

void Nhap_mang(float a[], int n, char ten){
    for(int i =0; i<=n;i++)
    {
        printf("Nhap he so thu %d cua da thuc %c : ",i+1,ten);
        scanf("%f",&a[i]);
    }
}

int mu(int x, int n){
    if(x == 0 && n ==0)
        return printf("Error!");
    else if (n<=0)
    {
        return 1;
    }else return x * mu(x,n-1); 
}

int Tinh_Gtri(float a[],int x,int n){
    float sum = 0;
    for (int i =0; i<=n;i++){
        sum = sum + (a[i] * (float)mu(x,n-i));
    }
    return sum;
}

int TimHeSo(float a[],float b[], float c[],int x, int y){
    
    if(x>=y){
        for(int i=0; i<x-y;i++)
            a[i] = b[i];
        for(int i= x-y; i<=x;i++)
            a[i] = b[i] + c[i-(x-y)];
    }else{
         for(int i=0; i<y-x;i++)
            a[i] = c[i];
        for(int i= y-x; i<=y;i++)
            a[i] = c[i] + b[i-(y-x)];
    }
    return x>=y?x:y;
}

void Xuat_mang(float a[], int n, char ten){
    printf("He so cua da thuc %c ",ten);
    for (int i = 0; i <= n; i++)
    {
        printf("\t%5.2f", a[i]); 
    }
       printf("\n");
}

int main(){
    float p[100],q[100],t[100];
    int n,m,x;
    printf("Nhap n: "); scanf("%d",&n);
    printf("Nhap m: "); scanf("%d",&m);
    Nhap_mang(p,n,'P');
    printf("\n==========================\n");
    Nhap_mang(q,m,'Q');
    printf("\n==========================\n");
    printf("Nhap x: "); scanf("%d",&x); //Nhap x
    printf("Gia tri da thuc P la: %d",Tinh_Gtri(p,x,n));
    printf("\nGia tri da thuc Q la: %d\n",Tinh_Gtri(q,x,m));
    Xuat_mang(p,n,'P');
    Xuat_mang(q,m,'Q'); 
    t[100] = TimHeSo(t,p,q,n,m);
    if(n>=m)
		Xuat_mang(t,n,'T');
	else
		Xuat_mang(t,m,'T');
	return 0;
}