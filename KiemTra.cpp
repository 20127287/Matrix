#include "Matrix.h"


// Hàm kiểm tra xem trong ma trận có các phần tử trùng nhau hay không:
bool Trung(int a[][10], int m, int n)
{
	int t[100], nt = 0; // t[100] là mảng trung gian, nt là số phần tử của mảng t.
	// Xuất tất cả các phần tử của ma trận vào mảng trung gian t:
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			t[nt] = a[i][j];
			nt++;
		}
	}

	// Kiểm tra xem trên mảng t có phần tử trùng nhau hay không:
	for (int i = 0; i < nt - 1; i++) {
		for (int j = i + 1; j < nt; j++) {
			if (t[i] == t[j]) {
				return true;
				break;
			}
		}
	}
	return false;
}


// Hàm kiểm tra xem ma trận có phải là ma phương hay không:
bool MaPhuong(int a[][10], int m, int n)
{
	int sum1 = 0, sum2 = 0;
	if (m != n || Trung(a, m, n))
		return false; // Ma trận hình chữ nhật hoặc ma trận có phần tử trùng nhau không phải là ma phương.
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] < 1 || a[i][j] > n * n) // Ma phương chỉ chứa các số nguyên từ 1 đến n^2.
					return false;
			}
		}

		// Kiểm tra trên đường chéo:
		for (int i = 0; i < m; i++) {
			sum1 += a[i][i]; // sum1 bằng tổng phần tử đường chéo thứ nhất.
			sum2 += a[i][m - i - 1]; // sum2 bằng tổng phần tử đường chéo thứ hai.
		}

		if (sum1 != sum2)
			return false;
		else
			sum2 = 0; // Trả sum2 về 0 để sử dụng cho lần kiểm tra tiếp theo.

		// Kiểm tra trên hàng:
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sum2 += a[i][j];
			}
			if (sum1 != sum2) {
				return false;
				break;
			}
			else
				sum2 = 0;
		}

		// Kiểm tra trên cột:
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				sum2 += a[i][j];
			}
			if (sum1 != sum2) {
				return false;
				break;
			}
			else
				sum2 = 0;
		}
	}
	return true;
}


// Hàm kiểm tra xem một phần tử trong ma trận có phải là phần tử nhỏ nhất trên cột hay không:
bool MinCot(int a[][10], int m, int rowpos, int colpos)
{
	int min = a[rowpos][colpos];
	for (int i = 0; i < m; i++) {
		if (a[i][colpos] < min) {
			return false;
			break;
		}
	}
	return true;
}


// Hàm kiểm tra xem một phần tử trong ma trận có phải là phần tử lớn nhất trên cột hay không:
bool MaxCot(int a[][10], int m, int rowpos, int colpos)
{
	int max = a[rowpos][colpos];
	for (int i = 0; i < m; i++) {
		if (a[i][colpos] > max) {
			return false;
			break;
		}
	}
	return true;
}


// Hàm kiểm tra xem một phần tử trong ma trận có phải là phần tử lớn nhất trên 2 đường chéo đi qua nó hay không:
bool Max2cheo(int a[][10], int m, int n, int rowpos, int colpos)
{
	int t = (m <= n ? m : n);
	// t là số lần lặp, t bằng giá trị lớn nhất giữa rowpos và colpos.

	// Kiểm tra đường chéo thứ nhất:
	for (int i = 1; i <= t; i++) {
		if (rowpos + i <= m - 1 && colpos + i <= n - 1) { // Kiểm tra đến các phần tử nằm trên biên thì dừng lại.
			if (a[rowpos][colpos] < a[rowpos + i][colpos + i]) {
				return false;
				break;
			}
		}
		else
			break; // Nếu phần tử cần kiểm tra nằm trên biên thì break.
	}
	for (int i = 1; i <= t; i++) {
		if (rowpos - i >= 0 && colpos - i >= 0) {
			if (a[rowpos][colpos] < a[rowpos - i][colpos - i]) {
				return false;
				break;
			}
		}
		else
			break;
	}

	// Kiểm tra đường chéo thứ hai:
	for (int i = 1; i <= t; i++) {
		if (rowpos - i >= 0 && colpos + i <= n - 1) {
			if (a[rowpos][colpos] < a[rowpos - i][colpos + i]) {
				return false;
				break;
			}
		}
		else
			break;
	}
	for (int i = 1; i <= t; i++) {
		if (rowpos + i <= m - 1 && colpos - i >= 0) {
			if (a[rowpos][colpos] < a[rowpos + i][colpos - i]) {
				return false;
				break;
			}
		}
		else
			break;
	}

	return true;
}