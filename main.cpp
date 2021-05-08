#include <ctime>
#include <conio.h>
#include <vector>

#include "Employee.h"
#include "Inventory.h"
#include "Equipment.h"
#include "Dish.h"

void pressAnyKey() {
	cout << "\n...Nhan phim bat ki de tiep tuc...";
	_getch();
	system("cls");
}

void main() {

	Employee nhanvien;
	nhanvien.readFile("Employees.txt");

	Dish menu;
	menu.readFile("Dishes.txt");

	Equipment thietbi;
	thietbi.readFile("Equipments.txt");

	Inventory hanghoa;
	hanghoa.readFile("Inventory.txt");

	//Customer khachhang; --Coming soon--
	//Manager quanli; --Coming soon--

	/*****************************************************************************************************************************/

	int key1,key2;
	do {
		cout << "\n\t\t\t-PHAN MEM QUAN LY QUAN AN-\n\n";
		cout << "\t\t\t  Nhom thuc hien: Chimori\n\n";
		cout << "\t1. Danh sach nhan vien (" << nhanvien.getSize() << ")\n";
		cout << "\t2. Danh sach thuc don (" << menu.getSize() << ")\n";
		cout << "\t3. Danh sach thiet bi (" << thietbi.getSize() << ")\n";
		cout << "\t4. Danh sach hang trong kho (" << hanghoa.getSize() << ")\n";
		cout << "\t5. Tao don\n";
		cout << "\t6. Quan li\n";
		cout << "\t0. Thoat\n\n";
		cout << "\t-->(1-6)? "; 
		cin >> key1;
		switch (key1) {
		case 1:
			nhanvien.InThongTin();
			pressAnyKey();
			break;
		case 2:
			menu.InThongTin();
			pressAnyKey();
			break;
		case 3:
			thietbi.InThongTin();
			pressAnyKey();
			break;		
		case 4:
			hanghoa.InThongTin();
			pressAnyKey();
			break;
		case 5:
			cout << "\n\t\t     ** TAO DON ** \n";
			menu.InThongTin();
			menu.getBill();
			pressAnyKey();
			break;
		case 6:
			do {
				system("cls");
				cout << "\n\t\t\t-PHAN MEM QUAN LY QUAN AN-\n\n";
				cout << "\t\t\t   ** QUAN LY QUAN AN **\n\n";
				cout << "\t1. Nhap them nhan vien\n";
				cout << "\t2. Nhap them thuc don\n";
				cout << "\t3. Nhap them thiet bi\n";
				cout << "\t4. Nhap them hang\n";
				cout << "\t5. Tra cuu thong tin\n";
				cout << "\t6. Luu tep\n";
				cout << "\t0. Quay lai\n\n";
				cout << "\t-->(1-6)? ";
				cin >> key2;
				switch (key2) {
				case 1:
					nhanvien.Import();
					pressAnyKey();
					break;
				case 2:
					menu.Import();
					pressAnyKey();
					break;
				case 3:
					thietbi.Import();
					pressAnyKey();
					break;
				case 4:
					hanghoa.Import();
					pressAnyKey();
					break;
				case 5:
					int searchID;
					cout << "\n\t\tTRA CUU ID:\n\n\t-1xx: Nhan vien\n\t-2xx: Thuc don\n\t-3xx: Thiet bi\n\t-4xx: Hang hoa\n\n\t--> ";
					cin >> searchID;
					switch (searchID / 100) {
					case 1:
						nhanvien.search_ID(searchID);
						break;
					case 2:
						menu.search_ID(searchID);
						break;
					case 3:
						thietbi.search_ID(searchID);
						break;
					case 4:
						hanghoa.search_ID(searchID);
						break;
					default:
						cout << "\n\t--> Khong tim thay!\n";
					}
					pressAnyKey();
					break;
				case 6:
					char key3;
					cout << "\n\t--> Ban muon luu file?\n\t  1.Co\n\t  0.Khong\n\t--> ";
					cin >> key3;
					if (key3 == '1') {
						nhanvien.saveFile("Employees.txt");
						menu.saveFile("Dishes.txt");
						thietbi.saveFile("Equipments.txt");
						hanghoa.saveFile("Inventory.txt");
					}
					break;
				case 0:
					pressAnyKey();
					break;
				default:
					cout << "\t--> (?) Khong co chuc nang !\n";
					pressAnyKey();
				}
			} while (key2 != 0);
		case 0:
			cout << "\n\tThoat chuong trinh... Nhan Enter de ket thuc ! \n\n";
			break;
		default:
			cout << "\t--> (?) Khong co chuc nang !\n";
			pressAnyKey();
		}
	} while (key1 != 0);
}