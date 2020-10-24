#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(int argc, char**argv)
{
    char c;
    int sobimat, sohientai;
    const int MAX = 100, MIN=1;
srand(time(NULL)); //Tránh lặp lại 1 số 2 lần
/*Có thể các bạn thừa biết, phép toán chia dư (%) của mọi số bất kỳ(a) cho một số b cố định: a % b sẽ cho ra giá trị thuộc đoạn [0, b-1].
 Ta sẽ lợi dụng tính chất này để sinh số ngẫu nhiên trong đoạn [minN, maxN]*/ 
sobimat =(rand() % (MAX-MIN+1)+MIN); 
do
{  
   
    
        printf("Moi ban nhap so ban doan la dung ? ");
   if(scanf("%d%c",&sohientai,&c) != 2 || c != '\n') //Nếu số đối số ra khác giá trị 2 và c khác enter thì lỗi, xem thêm tại sodoiso.c
    {
        printf("Loi - Xin moi ban choi lai tu dau!");
        break;
    }
    else // enter thì nó sẽ chạy dòng này
    {
       if(sobimat < sohientai)
        printf("Nho hon nua!\n");
    else if (sobimat > sohientai)
        printf("Lon hon nua!\n");
    else
        printf("Chuc mung ban da tim ra duoc so dung!"); 
         
    }
    

 
       
}while (sobimat != sohientai);

getch();
return 0;
}

