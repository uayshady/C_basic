/*in so chan trong 1 chuoi day*/
#include <stdio.h>
#include <conio.h>

int main(){
    int bd, kt, i,j;
       printf("Nhap so bat dau: ");
       scanf("%d",&bd);
       printf("Nhap so ket thuc : ");
       scanf("%d",&kt);
       printf("Day so chan la: ");
    for (i=bd;i<= kt; i++)
    {
        if (i % 2 == 0)
        printf("%d\t",i);
    }
    
    
    getch();
    return 0;

}
