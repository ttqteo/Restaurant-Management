#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Inventory {
	vector<Inventory>Inv;
protected:
	int ID;
	string Name;
	int Quantity;
	string Purchase_Date;
	float Price; //*1.000VND
	string Exp;
public:
	Inventory() {

	}

	Inventory(int ID, string Name, int Quantity, string Purchase_Date, long Price, string Exp) {
		this->ID = ID;
		this->Name = Name;
		this->Quantity = Quantity;
		this->Purchase_Date = Purchase_Date;
		this->Price = Price;
		this->Exp = Exp;
	}

	void readFile(string fileName) {
		ifstream myfile(fileName);
		string line;
		int temp = 0;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				temp++;
				switch (temp % 6) {
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
				case 5:
					Price = stof(line);
					break;
				default: {
					Exp = line;
					Inventory tempInv(ID, Name, Quantity, Purchase_Date, Price, Exp);
					Inv.push_back(tempInv);
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
		for (int i = 0; i < Inv.size(); i++) {
			myfile << Inv[i].ID << endl;
			myfile << Inv[i].Name << endl;
			myfile << Inv[i].Quantity << endl;
			myfile << Inv[i].Purchase_Date << endl;
			myfile << Inv[i].Price << endl;
			myfile << Inv[i].Exp << endl;
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
		cout << ".000VND\t";
		cout << this->Exp << "\n";
	}

	void InThongTin() {
		cout << "\n\t--> DANH SACH HANG HOA TRONG KHO\n\n";
		cout << "ID\tHang hoa\tSo luong\tNgay mua\tGia sp\t\tTong\t\tHan su dung\n";
		for (int count = 0; count < Inv.size(); count++)
			Inv[count].Display();
	}

	int getSize() {
		return Inv.size();
	}

	void Import() {
		cout << "\n\t*** NHAP THONG TIN HANG HOA ***\n\n";
		int last_ID = Inv.back().get_ID();
		this->ID = last_ID + 1;
		cout << "ID: " << ID << "\n";
		cout << "-> Nhap ten hang hoa: ";
		cin.ignore(100, '\n'); getline(cin, this->Name);
		cout << "-> Nhap so luong: ";
		cin >> this->Quantity;
		cout << "-> Nhap ngay mua: ";
		cin >> this->Purchase_Date;
		cout << "-> Nhap gia mua (*1.000VND): ";
		cin >> this->Price;
		cout << "-> Nhap han su dung: ";
		cin.ignore(100, '\n'); getline(cin, this->Exp);
		Inventory tempInv(ID, Name, Quantity, Purchase_Date, Price, Exp);
		Inv.push_back(tempInv);
	}

	void search_ID(int tempID) {
		for (int i = 0; i < Inv.size(); i++)
			if (tempID == Inv[i].get_ID()) {
				cout << "\n--> THONG TIN HANG HOA TIM KIEM:\n\n";
				cout << "ID\tHang hoa\tSo luong\tNgay mua\tGia sp\t\tTong\t\tHan su dung\n";
				Inv[i].Display();
				return;
			}
		cout << "--> Khong tim thay !\n";
	}

	int get_ID() {
		return this->ID;
	}

};
