#include <iostream>
using namespace std;


void nhap(int a[][10], int &m, int &n);
void XuatMaTran(int a[][10], int m, int n);
void XuatViTri(int row[], int col[], int sopt);
void XuatGiaTri(int t[], int nt);
void XuatGiaTriVaViTri(int t, int nt, int row[], int col[], int sopt);
void XuatTongPTDong(int a[][10], int m, int n);
void XuatTongPTCot(int a[][10], int m, int n);
void XuatViTriDongMax(int row[], int sopt);
void XuatViTriCotMax(int col[], int sopt);

int demx(int a[][10], int m, int n, int x);
void TimViTri(int a[][10], int m, int n, int x, int row[], int col[], int &sopt);
int max(int a[][10], int m, int n);
int maxbien(int a[][10], int m, int n);
int TongPT(int a[][10], int m, int n);
void TimGiaTriLonHonTong(int a[][10], int m, int n, int t[], int &nt);
void XoaTrung(int t[], int &nt);
void DongMax(int a[][10], int m, int n, int row[], int &sopt, int &GTDongMax);
void CotMax(int a[][10], int m, int n, int col[], int &sopt, int &GTCotMax);
bool MaPhuong(int a[][10], int m, int n);
bool Trung(int a[][10], int m, int n);
void SapBienTang(int a[][10], int m, int n, int t[]);
bool MinCot(int a[][10], int m, int rowpos, int colpos);
void ViTriMaxdong(int a[][10], int n, int t[], int &nt, int rowpos);
void YenNgua(int a[][10], int m, int n, int row[], int col[], int &soyenngua, int t[], int nt);
bool MaxCot(int a[][10], int m, int rowpos, int colpos);
bool Max2cheo(int a[][10], int m, int n, int rowpos, int colpos);
void HoangHau(int a[][10], int m, int n, int row[], int col[], int &sohoanghau, int t[], int nt);