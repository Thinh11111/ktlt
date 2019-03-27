#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Nhap(int &n)
{
	do
	{
		printf("\nMoi nhap (n>0 va n<=100) n= ");
		scanf("%d", &n);
		if (n <= 0 || n > 100)
			printf("\nSai, moi nhap lai...");
	} while (n <= 0 || n > 100);
}
void NhapMang(int a[], int n)
{
	if (n > 0) //n=0 thì d?ng
	{
		NhapMang(a, n - 1);
		printf("a[%d]= ", n - 1);
		scanf("%d", &a[n - 1]);
	}
}
void XuatMang(int a[], int n)
{
	if (n > 0) //n=0 thì d?ng
	{
		XuatMang(a, n - 1);
		printf("%4d",a[ n - 1]);
	}
}
int Tong(int a[], int n)
{
	if (n <= 0) return 0;
	return a[n - 1] + Tong(a, n - 1);
}
int TongChan(int a[], int n)
{
	if (n <= 0) return 0;
	if( a[n-1] % 2 == 0)
		return a[n - 1] + TongChan(a, n - 1);
	return TongChan(a, n - 1);
}
int DemDuong(int a[], int n)
{
	if (n <= 0) return 0;
	if (a[n - 1] > 0)
		return 1 + DemDuong(a, n - 1);
	return DemDuong(a, n - 1);
}
int TimMax(int a[], int n)
{
	if (n == 1) return a[n - 1];
	int m = TimMax(a, n - 1);
	if (a[n - 1] > m)
		m = a[n - 1];
	return m;
}
int TimMin(int a[], int n)
{
	if (n == 1) return a[n - 1];
	int m = TimMin(a, n - 1);
	if (a[n - 1] < m)
		m = a[n - 1];
	return m;
}
int TimChanCuoiCung(int a[], int n)
{
	if (n <= 0) return -1;
	if (a[n - 1] % 2 == 0)
		return a[n-1];
	return TimChanCuoiCung(a, n - 1);
}
int TimXCuoiCung(int a[], int n, int x)
{
	if (n <= 0) return -1;
	if (a[n - 1] == x)
		return n - 1;
	return TimXCuoiCung(a, n - 1,x);
}
int main()
{
	int n; Nhap(n);
	int *a = new int[n];
	NhapMang(a, n);
	printf("\nMang sau khi nhap= ");
	XuatMang(a, n);	
	int x;
	printf("\nMoi nhap x= ");
	scanf("%d", &x);
	int vt = TimXCuoiCung(a, n,x);
	if (vt == -1)
		printf("\nKhong co %d",x);
	else
		printf("\nCo %d tai vi tri %d", x, vt);
	printf("\n");
}
