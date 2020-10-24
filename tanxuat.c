#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void in_thuong(char st[])
{
    int i;
    for(i=0; i<strlen(st); i++)
    {
        if(st[i] >= 'A' && st[i] <= 'Z')
            st[i] += 32;
    }
}

void xoaphantu(char st[], char n, int vitri)
{
    int i;
    for(i=vitri+1;i<strlen(st);i++)
    {
        int k;
        if(st[i]==n)
            {
            for(k=i;k<strlen(st);k++)
                st[k]=st[k+1];
                i--;
            }
    }
}

int tan_xuat(char st[], char n,int viTri)
{
    int len=strlen(st);
    int i;
    int count=0;
    for(i=0;i<len;i++)
        if(st[i]==n)
        count++;

    //xóa đi phẩn tử trùng với n;
    xoaphantu(st,n,viTri);
    return count;

}


int main()
{

	char st[1001];
	gets(st);
	//1. In thành chữ thường
	in_thuong(st);
	//2. Xác định tần  xuất xuất hiện
	int i;
	for(i=0;i<strlen(st);i++)
	printf("%c: %d\n",st[i],tan_xuat(st, st[i],i));

    return 0;
}



