#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

struct sinhvien{
    char Hoten[20];
    int Tuoi;
    char MaSV[5];
    float DiemTB;
};
typedef struct sinhvien SV;

struct Node {
    SV dulieu;
    struct Node *pNext;
};
typedef struct Node NODE;

NODE *List = NULL;

SV Nhapdulieu(){
    SV sv;
    printf("Nhap ho ten sinh vien: ");
    fflush(stdin);
    gets(sv.Hoten);
    printf("\nNhap tuoi cua sinh vien: ");
    scanf("%d",&sv.Tuoi);
    printf("\nNhap ma sinh vien: ");
    fflush(stdin);
    gets(sv.MaSV);
    printf("\nNhap diem TB cua sinh vien: ");
    scanf("%f",&sv.DiemTB);
    return sv;
}

NODE *Taonut(){
    NODE *p= (NODE *)malloc(sizeof(NODE));
//    *p = (kieu du lieu *)malloc(sizeof(biến));
    p->dulieu=Nhapdulieu();
    p->pNext = NULL;
    return p;

}

void Themdau(){
    NODE *p = Taonut();
    List = p;
}

void Themcuoi(){
    if (List == NULL)
        Themdau();
    else
    {   //Tao nut moi
        NODE *p = Taonut();
        // tim vi tri cuoi
        NODE *temp;
        for (temp =List; temp ->pNext != NULL; temp= temp->pNext);
        temp->pNext= p;
    }
    
}
void Hienthi(){
    NODE *temp;
    int i;
    printf("___________________DANH_SACH__________________\n");
    printf("|%4s|%-20s|%5s|%5s|%6s|","STT","Ho va Ten","Tuoi","Ma SV","DiemTB");
    printf("\n==============================================\n");
    if(List ==NULL){
        printf("Danh sach rong!");
    }else
    {
        for(temp = List,i=1; temp !=NULL;temp= temp->pNext){
        printf("|%4d|%-20s|%5d|%5s|%6.2f|",i++,temp->dulieu.Hoten,temp->dulieu.Tuoi,temp->dulieu.MaSV,temp->dulieu.DiemTB);
        printf("\n");
        }
    }
    printf("-----------------------------------------------\n");
    
}

NODE *Timsinhvien(char ten[]){
    NODE *temp;
    for(temp =List; temp !=NULL;temp=temp->pNext)
    if (strcmp(temp->dulieu.Hoten,ten)==0)
        return temp;
        return NULL;
}

void Chensinhvien(char ten[]){
    if(Timsinhvien(ten) == NULL){
        printf("Khong co sinh vien trong danh sach!. Vui long nhap lai!");
    
    }else
    {
        NODE *temp= Timsinhvien(ten);
        NODE *p = Taonut();
        p->pNext= temp->pNext;
        temp->pNext=p;
    }
}
void Xoasinhvien(char ten[]){
    if (Timsinhvien(ten)==NULL){
        printf("Khong tim thay sinh vien %s trong danh sach",ten);

    }else
    {
        NODE *del=Timsinhvien(ten);
    if (del==List)
    {
        List = del->pNext;
    }else
    {
        NODE *temp;
        for(temp=List;temp->pNext!=del;temp=temp->pNext);
        temp->pNext=del->pNext;
        free(del);
        } 
    }
}

void SuathongtinSV(char ten[]){
    if(Timsinhvien(ten)==NULL){
        printf("Khong tim thay sinh vien %s trong danh sach.",ten);
    }else{
        NODE *temp= Timsinhvien(ten);
        temp->dulieu=Nhapdulieu();
    }
}

void Menu(){
    printf("=====================Menu====================\n");
    printf("|| 1. Nhap vao danh sach sinh vien.        ||\n");
    printf("|| 2. Hien thi danh sach sinh vien.        ||\n");
    printf("|| 3. Chen them sinh vien                  ||\n");
    printf("|| 4. Xoa sinh vien theo ten               ||\n");
    printf("|| 5. Sua mot sinh vien                    ||\n");
    printf("|| 6. Ket thuc chuong trinh                ||\n");
    printf("|| ========================================||\n");
    printf("\nMoi ban nhap su lua chon: ");
}

void Nhap(){
    for (int i=1;;i++){
        printf("\tNhap sinh vien thu %d\n ",i);
        Themcuoi();
        printf("\tBan co muon nhap nua khong? (Y/N): \n");
        fflush(stdin);
        char c = getch();
        if(c=='n' || c=='N')
        break;
    }
}

int main(){
    char ten[20];
    int chon;
    while(1){
        system("cls");
        printf("Chao mung den voi chuong trinh!\n");
        Menu();
        scanf("%d",&chon);
    switch (chon)
    {
    case 1: system("cls");
            printf("Ban da chon chuc nang nhap vao 1 sinh vien\n");
            Nhap();
            printf("Nhan phim bat ki de tiep tuc!"); getch();
        break;
    case 2: system("cls");
            if(List == NULL){
                    printf("Moi ban nhap danh sach sinh vien truoc!");
            }else{
            printf("Ban da chon Hien thi danh sach!\n");
            Hienthi();
            }
            printf("Nhan phim bat ki de tiep tuc!"); getch();
        break;
    case 3:system("cls");
           if(List == NULL){
                    printf("Moi ban nhap danh sach sinh vien truoc!");
            }else{
            printf("Ban da chon chuc nang Chen sinh vien vao sau 1 sinh vien khac!\n");
            printf("Moi ban nhap ten sinh muon chen dang sau: ");
            fflush(stdin);
            gets(ten);
            Chensinhvien(ten);
            }
            printf("Nhan phim bat ki de tiep tuc!"); getch();
        break;
        
    case 4: system("cls");
            if(List == NULL){
                    printf("Moi ban nhap danh sach sinh vien truoc!");
            }else{
            printf("Ban da chon chuc nang Xoa sinh vien theo ten!\n");
            printf("Moi ban nhap ten sinh muon Xoa: ");
            fflush(stdin);
            gets(ten);
            Xoasinhvien(ten);
            }
            printf("Nhan phim bat ki de tiep tuc!"); getch();
        break;
    case 5:system("cls");
            if(List == NULL){
                    printf("Moi ban nhap danh sach sinh vien truoc!");
            }else{
            printf("Ban da chon chuc nang Sua thong tin sinh vien !\n");
            printf("Moi ban nhap ten sinh muon sua: ");
            fflush(stdin);
            gets(ten);
            SuathongtinSV(ten);
            }
            printf("Nhan phim bat ki de tiep tuc!"); getch();
        break;
    case 6:system("cls");
            printf("Chao cac ban, hen gap lai vao lan sau^^");
            getch();
            exit(0);
        break;
    default:   printf("Ban da nhap sai vui long nhap lai tu 1 den 6!");
                getch();
        break;
    }
    }
    return 0;
}
