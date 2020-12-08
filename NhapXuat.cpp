#include "Matrix.h"

// Hàm nhập ma trận:
void nhap(int a[][10], int &m, int &n)
{
	cout << "Nhap ma tran nguyen m dong n cot:\n";
	cout << "Nhap so dong m: ";
	cin >> m;
	cout << "Nhap so cot n: ";
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}


// Hàm xuất ma trận:
void XuatMaTran(int a[][10], int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


// Hàm xuất vị trí:
void XuatViTri(int row[], int col[], int sopt)
{
	for (int i = 0; i < sopt; i++)
		cout << " Dong " << row[i] << ", cot " << col[i] << ";";
}


// Hàm xuất giá trị:
void XuatGiaTri(int t[], int nt)
{
	for (int i = 0; i < nt; i++)
		cout << t[i] << " ";
}


// Hàm xuất giá trị và vị trí:
void XuatGiaTriVaViTri(int t, int nt, int row[], int col[], int sopt)
{
		cout << "Phan tu " << t << " xuat hien tai vi tri:";
		XuatViTri(row, col, nt);
}


// Hàm xuất tổng các phần tử trên dòng:
void XuatTongPTDong(int a[][10], int m, int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
		cout << "Tong cac phan tu thuoc dong " << i << " la: " << tong;
		tong = 0;
		cout << endl;
	}
}


// Hàm xuất tổng các phần tử trên cột:
void XuatTongPTCot(int a[][10], int m, int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tong += a[j][i];
		}
		cout << "Tong cac phan tu thuoc cot " << i << " la: " << tong;
		tong = 0;
		cout << endl;
	}
}


// Hàm xuất vị trí của dòng có tổng các phần tử lớn nhất:
void XuatViTriDongMax(int row[], int sopt)
{
	for (int i = 0; i < sopt; i++)
		cout << " dong " << row[i] << ",";
}


// Hàm xuất vị trí của cột có tổng các phần tử lớn nhất:
void XuatViTriCotMax(int col[], int sopt)
{
	for (int i = 0; i < sopt; i++)
		cout << " cot " << col[i] << ",";
}