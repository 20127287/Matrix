/* Các chức năng của phần mềm:
0. Hiện menu các chức năng của phần mềm.
1. Nhập một ma trận khác.
2. Xuất ma trận.
3. Tìm phần tử X trong ma trận.
4. Tìm phần tử lớn nhất trong ma trận và trên biên ma trận.
5. Tính tổng các phần tử trong ma trận và xác định các phần tử có giá trị lớn hơn tổng này.
6. Tính tổng các dòng & các cột trong ma trận, cho biết gia trị lớn nhất thuộc dòng /cột nào.
7. Kiểm tra xem ma trận có phải là ma phương hay không.
8. Chỉ ra các vị trí “yên ngựa” trên ma trận. (lớn nhất trên dòng và nhỏ nhất trên cột).
9. Đếm số “hoàng hậu” trên ma trận. (lớn nhất trên dòng, cột và 2 đường chéo đi qua nó).
10. Sắp xếp các giá trị nằm trên biên ma trận tăng dần theo chiều kim đồng hồ.
11. Exit.
*/


#include "Matrix.h"


void main()
{
	int a[10][10], m, n, x, row[10], col[10], t[100], nt, sopt, GTDongMax, GTCotMax, chuc_nang = 0;
	/* m là số dòng, n là số cột, x là phần tử cần tìm,
	row[10] là mảng lưu các vị trí dòng, col[10] là mảng lưu các vị trí cột,
	t[100] là mảng lưu các giá trị tạm thời, nt là số phần tử của t[100], sopt là số phần tử của một mảng nào đó,
	GTDongMax là giá trị của dòng có tổng các phần tử lớn nhất, GTCotMax là giá trị của cột có tổng các phần tử lớn nhất. */
	
	nhap(a, m, n);
	if (m < 1 || n < 1)
		cout << "Du lieu khong hop le.\n";
	
	else {
		while (chuc_nang != 11) {
			cout << "Nhap chuc nang can thuc hien: ";
			cin >> chuc_nang;

			switch (chuc_nang)
			{
			case 0:
				cout << "==================================================================================================================\n";
				cout << "Cac chuc nang cua phan mem:\n";
				cout << "0. Hien menu cac chuc nang cua phan mem.\n";
				cout << "1. Nhap mot ma tran khac.\n";
				cout << "2. Xuat ma tran.\n";
				cout << "3. tim phan tu X trong ma tran.\n";
				cout << "4. Tim phan tu lon nhat trong ma tran va tren bien ma tran.\n";
				cout << "5. Tinh tong cac phan tu trong ma tran va xac dinh cac phan tu lon hon tong nay.\n";
				cout << "6. Tinh tong cac dong & cot trong ma tran, cho biet gia tri lon nhat thuoc dong/cot nao.\n";
				cout << "7. Kiem tra xem ma tran co phai la ma phuong hay khong.\n";
				cout << "8. Chi ra cac vi tri yen ngua tren ma tran (lon nhat tren dong va nho nhat tren cot).\n";
				cout << "9. Dem so hoang hau tren ma tran (lon nhat tren dong, cot va hai duong cheo di qua no).\n";
				cout << "10. Sap xep cac gia tri nam tren bien ma tran tang dan theo chieu kim dong ho.\n";
				cout << "11. Exit.\n";
				cout << "==================================================================================================================\n";
				break;

			case 1:
				nhap(a, m, n);
				if (m < 1 || n < 1)
					cout << "Du lieu khong hop le.\n";
				cout << "==================================================================================================================\n";
				break;

			case 2:
				cout << "Ma tran:\n";
				XuatMaTran(a, m, n);
				cout << "==================================================================================================================\n";
				break;

			case 3:
				cout << "Nhap phan tu can tim: ";
				cin >> x;
				TimViTri(a, m, n, x, row, col, sopt);
				if (sopt == 0)
					cout << "Khong tim thay phan tu " << x << " trong ma tran.";
				else {
					cout << "Phan tu " << x << " xuat hien tai vi tri:";
					XuatViTri(row, col, demx(a, m, n, x));
				}
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 4:
				cout << "Phan tu lon nhat trong ma tran: " << max(a, m, n) << "; vi tri:";
				TimViTri(a, m, n, max(a, m, n), row, col, sopt);
				XuatViTri(row, col, demx(a, m, n, max(a, m, n)));
				cout << endl;
				cout << "Phan tu lon nhat tren bien ma tran: " << maxbien(a, m, n) << "; vi tri:";
				TimViTri(a, m, n, maxbien(a, m, n), row, col, sopt);
				XuatViTri(row, col, demx(a, m, n, maxbien(a, m, n)));
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 5:
				cout << "Tong cac phan tu trong ma tran: " << TongPT(a, m, n);
				cout << endl;
				cout << "Cac phan tu lon hon tong: ";
				TimGiaTriLonHonTong(a, m, n, t, nt);
				if (nt == 0)
					cout << "Khong co.";
				XoaTrung(t, nt);
				XuatGiaTri(t, nt);
				cout << endl;
				for (int i = 0; i < nt; i++) {
					TimViTri(a, m, n, t[i], row, col, sopt);
					XuatGiaTriVaViTri(t[i], sopt, row, col, demx(a, m, n, t[i]));
					cout << endl;
				}
				cout << "==================================================================================================================\n";
				break;

			case 6:
				XuatTongPTDong(a, m, n);
				cout << "------------------------------------------\n";
				XuatTongPTCot(a, m, n);
				cout << "------------------------------------------\n";
				cout << "Gia tri lon nhat thuoc:";
				DongMax(a, m, n, row, sopt, GTDongMax);
				CotMax(a, m, n, col, sopt, GTCotMax);
				if (GTDongMax > GTCotMax) {
					DongMax(a, m, n, row, sopt, GTDongMax);
					XuatViTriDongMax(row, sopt);
				}
				else if (GTDongMax < GTCotMax) {
					CotMax(a, m, n, col, sopt, GTCotMax);
					XuatViTriCotMax(col, sopt);
				}
				else {
					DongMax(a, m, n, row, sopt, GTDongMax);
					XuatViTriDongMax(row, sopt);
					CotMax(a, m, n, col, sopt, GTCotMax);
					XuatViTriCotMax(col, sopt);
				}
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 7:
				if (MaPhuong(a, m, n))
					cout << "La ma phuong.";
				else
					cout << "Khong la ma phuong.";
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 8:
				YenNgua(a, m, n, row, col, sopt, t, nt);
				cout << "So yen ngua tren ma tran: " << sopt;
				cout << endl;
				cout << "Cac vi tri yen ngua tren ma tran:";
				if (sopt == 0)
					cout << "Khong co.";
				else
					XuatViTri(row, col, sopt);
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 9:
				HoangHau(a, m, n, row, col, sopt, t, nt);
				cout << "So hoang hau tren ma tran: " << sopt;
				cout << endl;
				if (sopt > 0) {
					cout << "Vi tri cac hoang hau tren ma tran:";
					XuatViTri(row, col, sopt);
				}
				cout << endl;
				cout << "==================================================================================================================\n";
				break;

			case 10:
				cout << "Ma tran sau khi sap xep:\n";
				SapBienTang(a, m, n, t);
				XuatMaTran(a, m, n);
				cout << "==================================================================================================================\n";
				break;

			case 11:
				break;

			default:
				cout << "Chuc nang khong ton tai.\n";
			}
		}
	}
}