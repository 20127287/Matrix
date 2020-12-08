#include "Matrix.h"


// Hàm xóa các phần tử trùng nhau trong một mảng:
void XoaTrung(int t[], int &nt) // nt là số phần tử của t[].
{
	int temp;
	for (int i = 0; i < nt - 1; i++) {
		for (int j = i + 1; j < nt; j++) {
			if (t[i] == t[j]) {
				temp = j;
				for (int k = temp + 1; k < nt; k++)
					t[k - 1] = t[k];
				nt--;
			}
		}
	}
}


// Hàm sắp xếp các phần tử theo thứ tự tăng dần:
void SapTang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}


// Hàm sắp xếp các giá trị nằm trên biên ma trận tăng dần theo chiều kim đồng hồ:
void SapBienTang(int a[][10], int m, int n, int t[])
{
	int k = 0;
	// Lưu tất cả các giá trị trên biên ma trận vào mảng trung gian t:
	for (int j = 0; j < n; j++) {
		t[k] = a[0][j];
		k++;
	}
	for (int i = 1; i < m; i++) {
		t[k] = a[i][n - 1];
		k++;
	}
	for (int j = n - 2; j > 0; j--) {
		t[k] = a[m - 1][j];
		k++;
	}
	for (int i = m - 1; i > 0; i--) {
		t[k] = a[i][0];
		k++;
	}

	// Sắp xếp các phần tử của t theo chiều tăng dần:
	SapTang(t, k);
	k = 0;

	// Trả các phần tử đã sắp xếp trong t vào các vị trí ban đầu trong ma trận:
	for (int j = 0; j < n; j++) {
		a[0][j] = t[k];
		k++;
	}
	for (int i = 1; i < m; i++) {
		a[i][n - 1] = t[k];
		k++;
	}
	for (int j = n - 2; j > 0; j--) {
		a[m - 1][j] = t[k];
		k++;
	}
	for (int i = m - 1; i > 0; i--) {
		a[i][0] = t[k];
		k++;
	}
}