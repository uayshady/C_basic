#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


int n, luotchoi;

void Mualuotchoi(){
    int tienthua;
    printf("Gia ve choi la 5000 VND.\n");
         do{
             printf("\nNhap so tien cua ban( tien >= 5000 VND): ");
             scanf("%d",&n);
             if(n<5000) printf("\nTien nhap khong du. Vui long nap them tien!");
         }while (n <5000);
     luotchoi = n / 5000;
      tienthua = n % 5000;
    printf("\nBan co %d luot choi.\nMoi ban nhan lai so tien thua: %d VND",luotchoi,tienthua);
    
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}
 

void Vongquay(){
    srand(time(NULL));  //tranhs so lap lai 2 lan
    for(int i=0; i<luotchoi;i++){
        srand(time(NULL));  //tranhs so lap lai 2 lan
        printf("\n\n\nLuot quay so thu %d",i+1);
        printf("\n!!An phim bat ki de Bat Dau quay!!");
        getch();
            int r = 2000 + rand() % (4000  +1 - 2000);
            printf("\nDang quay so...\n");
            Sleep(r);
        float x = float_rand(1.00,100.00);
        if (1.00<=x && x<= 15.5) {  //Ty le 
            printf("\n\t=>>Ban da trung 4000 VND!!");
        }else if(x<15.5 && x<=35.5){
            printf("\tBan da trung 3000 VND!");
        }else if( x>35.5 && x <=45.5){
            printf("\tBan da trung them 1 luot quay!");
            luotchoi += 1;
        }else if(x>45.5 && x<=95.5){
            printf("\t!!CHUC BAN MAY MAN LAN SAU!!");
        }else if( x>95.5 && x<=99.1){
            printf("\tChuc mung ban trung 20.000.000 VND!");
        }else{
            printf("\tChuc mung ban da trung 1 chiec xe oto Mazda CX 9!");
        }     
    } 
}

int main(){
    Mualuotchoi();
    Vongquay();

}