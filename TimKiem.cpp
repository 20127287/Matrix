#include "Matrix.h"


// Hàm tìm vị trí của x trên ma trận:
void TimViTri(int a[][10], int m, int n, int x, int row[], int col[], int &sopt)
{
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x == a[i][j]) {
				row[k] = i;
				col[k] = j;
				k++;
			}
		}
	}
	sopt = k;
}


// Hàm tìm giá trị lớn nhất trên ma trận:
int max(int a[][10], int m, int n)
{
	int max = a[0][0];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}


// Hàm tìm giá trị lớn nhất trên biên ma trận:
int maxbien(int a[][10], int m, int n)
{
	int maxbien = a[0][0];
	for (int i = 1; i < m; i++) {
		if (a[i][0] > maxbien)
			maxbien = a[i][0];
	}

	for (int i = 0; i < m; i++) {
		if (a[i][n - 1] > maxbien)
			maxbien = a[i][n - 1];
	}

	for (int j = 1; j < n; j++) {
		if (a[0][j] > maxbien)
			maxbien = a[0][j];
	}

	for (int j = 1; j < n; j++) {
		if (a[m - 1][j] > maxbien)
			maxbien = a[m - 1][j];
	}
	return maxbien;
}


// Hàm tìm giá trị các phần tử lớn hơn tổng các phần tử trên ma trận:
void TimGiaTriLonHonTong(int a[][10], int m, int n, int t[], int &nt)
{ // t[] là mảng lưu giá trị của các phần tử, nt là số phần tử của t[].
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > TongPT(a, m, n)) {
				t[k] = a[i][j];
				k++;
			}
		}
	}
	nt = k;
}


// Hàm tìm dòng có tổng các phần tử lớn nhất:
void DongMax(int a[][10], int m, int n, int row[], int &sopt, int &GTDongMax)
{ // row[] là mảng lưu các vị trí dòng, sopt là số phần tử của row[], GTDongMax là biến lưu giá trị max của dòng.
	int max, tong1dong = 0, k = 0;
	
	// Giả sử dòng đầu tiên là max:
	for (int j = 0; j < n; j++)
		tong1dong += a[0][j];
	max = tong1dong;
	tong1dong = 0;
	// So sánh max với các dòng còn lại, nếu có dòng lớn hớn max thì max sẽ là dòng đó:
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tong1dong += a[i][j];
		}
		if (tong1dong > max)
			max = tong1dong;
		tong1dong = 0;
	}
	GTDongMax = max;
	
	// Đếm xem có tổng cộng bao nhiêu dòng = max, lưu vị trí các dòng đó vào row[]:
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tong1dong += a[i][j];
		}
		if (tong1dong == max) {
			row[k] = i;
			k++;
		}
		tong1dong = 0;
	}
	sopt = k;
}


// Hàm tìm cột có tổng các phần tử lớn nhất:
void CotMax(int a[][10], int m, int n, int col[], int &sopt, int &GTCotMax)
{ // tương tự hàm tìm dòng có tổng các phần tử lớn nhất.
	int max, tong1cot = 0, k = 0;
	for (int i = 0; i < m; i++)
		tong1cot += a[i][0];
	max = tong1cot;
	tong1cot = 0;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < m; i++) {
			tong1cot += a[i][j];
		}
		if (tong1cot > max)
			max = tong1cot;
		tong1cot = 0;
	}
	GTCotMax = max;

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			tong1cot += a[i][j];
		}
		if (tong1cot == max) {
			col[k] = j;
			k++;
		}
		tong1cot = 0;
	}
	sopt = k;
}


// Hàm tìm vị trí của phần tử lớn nhất trên một dòng:
void ViTriMaxdong(int a[][10], int n, int t[], int &nt, int rowpos) // nt là số phần tử của t[].
// t[] là mảng lưu các vị trí cột của các phần tử tìm được, nt là số phần tử của t[].
{
	// Giả sử phần tử đầu tiên trên dòng là max:
	int max = a[rowpos][0], k = 0;
	
	// So sánh max với các phần tử còn lại, nếu có phần tử lớn hơn max thì max sẽ là phần tử đó:
	for (int j = 0; j < n; j++) {
		if (max < a[rowpos][j])
			max = a[rowpos][j];
	}

	// Kiểm tra xem trên dòng có bao nhiêu phần tử bằng max, lưu vị trí của các phần tử đó vào mảng t:
	for (int j = 0; j < n; j++) {
		if (max == a[rowpos][j]) {
			t[k] = j;
			k++;
		}
	}
	nt = k;
}


// Hàm tìm vị trí và đếm số yên ngựa trên ma trận:
void YenNgua(int a[][10], int m, int n, int row[], int col[], int &so_yen_ngua, int t[], int nt)
{
	int k = 0;
	for (int i = 0; i < m; i++) {
		ViTriMaxdong(a, n, t, nt, i);
		for (int j = 0; j < nt; j++) {
			if (MinCot(a, m, i, t[j])) {
				row[k] = i;
				col[k] = t[j];
				k++;
			}
		}
	}
	so_yen_ngua = k;
}


// Hàm tìm vị trí và đếm số hoàng hậu trên ma trận:
void HoangHau(int a[][10], int m, int n, int row[], int col[], int &so_hoang_hau, int t[], int nt)
{
	int k = 0;
	for (int i = 0; i < m; i++) {
		ViTriMaxdong(a, n, t, nt, i);
		for (int j = 0; j < nt; j++) {
			if (MaxCot(a, m, i, t[j]) && Max2cheo(a, m, n, i, t[j])) {
				row[k] = i;
				col[k] = t[j];
				k++;
			}
		}
	}
	so_hoang_hau = k;
}