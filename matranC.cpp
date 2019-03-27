#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 50
void Nhap(int &d, int &c)
{
	do
	{
		printf("\nMoi nhap so dong (d>0 va d<=10) d= ");
		scanf("%d", &d);
		if (d <= 0 || d > 10)
			printf("\nBan nhap sai, moi nhap lai..");
	} while (d <= 0 || d > 10);//???????????
	do
	{
		printf("\nMoi nhap so cot (c>0 va c<=10) c= ");
		scanf("%d", &c);
		if (c <= 0 || c > 10)
			printf("\nBan nhap sai, moi nhap lai..");
	} while (c <= 0 || c > 10);//???????????
}
void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}
void NhapMang(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
		for(int j=0;j<c; j++)
		{
			printf("a[%d][%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
}
void NhapMang(double a[][MAX], int d, int c)//[1]
{
	for (int i = 0; i < d; i++)
		for (int j = 0; j<c; j++)
		{
			printf("a[%d][%d]= ", i, j);
			scanf("%lf", &a[i][j]);//[2]
		}
}
void NhapMang(double a[], int n)//[1]
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= ", i);
		scanf("%lf", &a[i]);//[2]
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
}
void XuatMang(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}
void XuatMang(double a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%6.2lf", a[i][j]);
		printf("\n");
	}
}
void XuatMang(double a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%6.2lf", a[i]);
}
int TinhTong(int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s;
}
int TinhTong(int a[][MAX],int d, int c)
{
	int s = 0;
	for (int i = 0; i < d; i++)
		for( int j=0; j<c ; j++)
			s = s + a[i][j];
	return s;
}
double TinhTong(double a[][MAX], int d, int c)
{
	double s = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j<c; j++)
			s = s + a[i][j];
	return s;
}

double TinhTong(double a[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s;
}
double TrungBinhCong(int a[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s / n;
}
double TrungBinhCong(int a[][MAX],int d, int c)
{
	double s = 0;
	for (int i = 0; i < d; i++)
		for(int j=0;j<c; j++)
			s = s + a[i][j];
	return s / (d*c);
}
double TrungBinhCong(double a[][MAX], int d, int c)
{
	double s = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j<c; j++)
			s = s + a[i][j];
	return s / (d*c);
}
double TrungBinhCong(double a[], int n)
{
	double s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i];
	return s / n;
}
double TrungBinhDuong(double a[][MAX], int d, int c)
{
	double s = 0;
	int dem = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j<c; j++)
			if (a[i][j] > 0)
			{
				s = s + a[i][j];
				dem++;
			}
	if (dem == 0) return 0;
	return s / dem;
}
double TrungBinhDuong(int a[][MAX], int d, int c)
{
	double s = 0;
	int dem = 0;
	for (int i = 0; i < d; i++)
		for (int j = 0; j<c; j++)
			if (a[i][j] > 0)
			{
				s = s + a[i][j];
				dem++;
			}
	if (dem == 0) return 0;
	return s / dem;
}
int TimMax(int a[], int n)
{
	int m = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > m)
			m = a[i];
	return m;
}
int TimMax(int a[][MAX], int d, int c)
{
	int m = a[0][0];
	for (int i = 0; i < d; i++)//?????????
		for(int j=0; j<c; j++)
		if (a[i][j] > m)
			m = a[i][j];
	return m;
}
int2 main()
{
	int d, c;
	Nhap(d, c);
	int a[MAX][MAX];//???
	NhapMang(a, d, c);
	printf("Mang sau khi nhap\n");
	XuatMang(a, d, c);
	double kq = TrungBinhDuong(a, d, c);
	printf("\nTrung binh duong: %.2lf", kq);
	int max = TimMax(a, d, c);
	printf("\nMax = %d", max);
	printf("\n");
}
