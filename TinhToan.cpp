#include "Matrix.h"


// Hàm đếm số phần tử x trên ma trận:
int demx(int a[][10], int m, int n, int x)
{
	int sopt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x == a[i][j])
				sopt++;
		}
	}
	return sopt;
}


// Hàm tính tổng các phần tử trên ma trận:
int TongPT(int a[][10], int m, int n)
{
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}