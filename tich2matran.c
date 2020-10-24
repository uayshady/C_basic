#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void Nhapmatran(int a[MAX][MAX], int hang, int cot, char ten){
    printf("Moi ban nhap ma tran %c\n", ten);
    for (int i=0; i<hang;i++){
        for (int j=0; j<cot;j++)
        {
            printf("Nhap %c[%d][%d]: ", ten,i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}

int Tichmatran(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int hang, int cot, int hesochung){
    for (int i=0; i<hang;i++){
        for (int j=0;j<cot;j++){
            c[i][j] = 0;
            for(int k=0;k<hesochung;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Infile(int a[MAX][MAX], int hang, int cot, char ten){
    FILE *fp;
    fp = fopen("F:\\VS code\\ThuchanhBasicC\\Bai5\\TICH_MATRAN.c","a");
    fprintf(fp,"Ma tran %c\n", ten);
    for (int i = 0; i < hang; i++)
    {
        for( int j=0; j<cot;j++){
            fprintf(fp,"\t%d",a[i][j]);
        }
            fprintf(fp,"\n");
    }fclose(fp);
    
}
int main(){
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int m,n,p;
    printf("Moi ban nhap he so n,m,p: "); scanf("%d%d%d",&n,&m,&p);
    Nhapmatran(a,n,m,'A');
    Nhapmatran(b,m,p,'B');
    Tichmatran(a,b,c,n,p,m);
    Infile(a,n,m,'A');
    Infile(b,m,p,'B');
    Infile(c,n,p,'C');
}