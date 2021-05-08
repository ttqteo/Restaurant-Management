#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Equipment {
	vector<Equipment>Equ;
protected:
	int ID;
	string Name;
	int Quantity;
	string Purchase_Date;
	float Price; //*1.000VND
public:
	Equipment(){

	}

	Equipment(int ID, string Name, int Quantity, string Purchase_Date, long Price) {
		this->ID = ID;
		this->Name = Name;
		this->Quantity = Quantity;
		this->Purchase_Date = Purchase_Date;
		this->Price = Price;
	}

	void readFile(string fileName) {
		ifstream myfile(fileName);
		string line;
		int temp = 0;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				temp++;
				switch (temp % 5) {
				case 1:
					ID = stoi(line);
					break;
				case 2:
					Name = line;
					break;
				case 3:
					Quantity = stoi(line);
					break;
				case 4:
					Purchase_Date = line;
					break;
				default: {
					Price = stof(line);
					Equipment tempEqu(ID, Name, Quantity, Purchase_Date, Price);
					Equ.push_back(tempEqu);
					break;
				}
				}
			}
			myfile.close();
		}
		else
			cout << "Error to open file\n";
	}

	void saveFile(string fileName) {
		ofstream myfile;
		myfile.open(fileName);
		for (int i = 0; i < Equ.size(); i++) {
			myfile << Equ[i].ID << endl;
			myfile << Equ[i].Name << endl;
			myfile << Equ[i].Quantity << endl;
			myfile << Equ[i].Purchase_Date << endl;
			myfile << Equ[i].Price << endl;
		}
		myfile.close();
	}

	void Display() {
		cout << this->ID << "\t";
		int temp = this->Name.length();
		cout << this->Name;
		temp = 16 - temp;
		do {
			cout << "\t";
			temp -= 8;
		} while (temp > 0);
		cout << this->Quantity << "\t\t";
		cout << this->Purchase_Date << "\t";
		cout << this->Price << ".000VND\t";
		long temp2 = this->Quantity * this->Price;
		if (temp2 / 1000 == 0)
			cout << temp2;
		else {
			cout << temp2 / 1000;
			if (temp2 % 1000 == 0)
				cout << ".000";
			else cout << '.' << temp2 % 1000;
		}
		cout << ".000VND\n";
	}

	void InThongTin() {
		cout << "\n\t--> DANH SACH THIET BI\n\n";
		cout << "ID\tHang hoa\tSo luong\tNgay mua\tGia sp\t\tTong\n";
		for (int count = 0; count < Equ.size(); count++)
			Equ[count].Display();
	}

	int getSize() {
		return Equ.size();
	}

	void Import() {
		cout << "\n\t*** NHAP THONG TIN THIET BI ***\n\n";
		int last_ID = Equ.back().get_ID();
		this->ID = last_ID + 1;
		cout << "ID: " << ID << "\n";
		cout << "-> Nhap ten thiet bi: ";
		cin.ignore(100, '\n'); getline(cin, this->Name);
		cout << "-> Nhap so luong: ";
		cin >> this->Quantity;
		cout << "-> Nhap ngay mua: ";
		cin.ignore(100, '\n'); getline(cin, this->Purchase_Date);
		cout << "-> Nhap gia mua (*1.000VND): ";
		cin >> this->Price;
		Equipment tempEqu(ID, Name, Quantity, Purchase_Date, Price);
		Equ.push_back(tempEqu);
	}

	void search_ID(int tempID) {
		for (int i = 0; i < Equ.size(); i++)
			if (tempID == Equ[i].get_ID()) {
				cout << "\n--> THONG TIN THIET BI TIM KIEM:\n\n";
				cout << "ID\tHang hoa\tSo luong\tNgay mua\tGia sp\tTong\n";
				Equ[i].Display();
				return;
			}
		cout << "--> Khong tim thay !\n";
	}

	int get_ID() {
		return this->ID;
	}
};