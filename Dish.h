#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Dish {
	vector<Dish>Dis;
protected:
	int ID;
	string Name;
	float Price; //*1000VND
public:
	Dish(){

	}
	Dish(int ID, string Name, float Price) {
		this->ID = ID;
		this->Name = Name;
		this->Price = Price;
	}

	void readFile(string fileName) {
		ifstream myfile(fileName);
		string line;
		int temp = 0;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				temp++;
				switch (temp % 3) {
				case 1:
					ID = stoi(line);
					break;
				case 2:
					Name = line;
					break;
				default: {
					Price = stof(line);
					Dish tempDis(ID, Name, Price);
					Dis.push_back(tempDis);
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
		for (int i = 0; i < Dis.size(); i++) {
			myfile << Dis[i].ID << endl;
			myfile << Dis[i].Name << endl;
			myfile << Dis[i].Price << endl;
		}
		myfile.close();
	}

	void Display(){
		cout << " " << this->Name << " - " << this->Price << ".000VND\n";
	}

	void InThongTin() {
		cout << "\n\t--> DANH SACH THUC DON\n\n";
		for (int count = 0; count < Dis.size(); count++) {
			cout << "\t\t  " << count+1 << '.';
			Dis[count].Display();
		}
	}

	int getSize() {
		return Dis.size();
	}

	int get_price() {
		return this->Price;
	}

	int get_ID() {
		return this->ID;
	}

	string get_Name() {
		return this->Name;
	}

	void getBill() {
		vector<int>bill;
		int num1, num2;
		char key;
		do {
			do {
				cout << "\n\t\t-> Chon mon: ";
				cin >> num1;
			} while (num1 < 1 || num1 > 4);
			cout << "\t\t-> So luong: ";
			cin >> num2;
			bill.push_back(num1);
			bill.push_back(num2);
			cout << "\t\t1.Tiep tuc? \n\t\t0.Tinh tien\n\t\t--> ";
			cin >> key;
		} while (key != '0');
		//Xuat hoa don
		cout << "\n\t\t";
		for (int i = 0; i < 34; i++) cout << '-'; //In dong
		cout << "\n\n\t\t        [QUAN AN CHIMORI]";
		cout << "\n\t\t   227 Nguyen Van Cu, Q5, TPHCM";
		cout << "\n\t\t";
		for (int i = 0; i < 34; i++) cout << '*'; //In dong
		int giatien = 0;
		cout << "\n\t\tMon an\t\tSL\tTong\n";
		for (int i = 0; i < bill.size(); i += 2) {
			cout << "\t\t";
			int temp = Dis[bill[i] - 1].get_Name().length();
			cout << Dis[bill[i] - 1].get_Name();
			temp = 16 - temp;
			do {
				cout << "\t";
				temp -= 8;
			} while (temp > 0);
			cout << bill[i + 1] << "\t" << Dis[bill[i] - 1].get_price() * bill[i + 1] << ".000VND\n";
			giatien += Dis[bill[i]-1].get_price() * bill[i + 1];
		}
		cout << "\t\t";
		for (int i = 0; i < 34; i++) cout << '*'; //In dong
		cout << "\n\t\tTONG CONG: \t\t" << giatien << ".000VND\n";
		cout << "\t\t";
		for (int i = 0; i < 34; i++) cout << '*'; //In dong
		cout << "\n\t\t    Mat khau Wifi: chimoricamon";
		cout << "\n\t\t     CHUC QUY KHACH NGON MIENG\n\n";
		cout << "\t\t";
		for (int i = 0; i < 34; i++) cout << '-'; //In dong
		cout << "\n\n";
	}

	void Import() {
		cout << "\n\t*** NHAP THONG TIN THUC DON ***\n\n";
		int last_ID = Dis.back().get_ID();
		this->ID = last_ID + 1;
		cout << "ID: " << ID << "\n";
		cout << "-> Nhap ten mon an: "; 
		cin.ignore(100, '\n'); getline(cin, this->Name);
		cout << "-> Nhap gia ban (*1.000VND): "; 
		cin >> this->Price;
		Dish tempDis(ID, Name, Price);
		Dis.push_back(tempDis);
	}

	void search_ID(int tempID) {
		for (int i = 0; i < Dis.size(); i++)
			if (tempID == Dis[i].get_ID()) {
				cout << "\n--> THONG TIN THUC DON TIM KIEM:\n\n";
				cout << Dis[i].get_ID() << " -";
				Dis[i].Display();
				return;
			}
		cout << "--> Khong tim thay !\n";
	}
	
};
