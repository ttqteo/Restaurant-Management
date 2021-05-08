#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Employee {
	vector<Employee>Emp;
protected:
	int ID;
	string Name;
	string Phone_Number;
	long Salary;
	int Year_of_Birth;
	string Position;
	string Address;

public:
	Employee(){ 

	}
	Employee(int ID, string Name, string Phone_Number, long Salary, int Year_of_Birth, string Position, string Address)
	{
		this->ID = ID;
		this->Name = Name;
		this->Phone_Number = Phone_Number;
		this->Salary = Salary;
		this->Year_of_Birth = Year_of_Birth;
		this->Position = Position;
		this->Address = Address;
	}

	void readFile(string fileName) {
		ifstream myfile(fileName);
		string line;
		int temp = 0;
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				temp++;
				switch (temp % 7) {
				case 1:
					ID = stoi(line);
					break;
				case 2:
					Name = line;
					break;
				case 3:
					Phone_Number = line;
					break;
				case 4:
					Salary = stol(line);
					break;
				case 5:
					Year_of_Birth = stoi(line);
					break;
				case 6:
					Position = line;
					break;
				default: {
					Address = line;
					Employee tempEmp(ID, Name, Phone_Number, Salary, Year_of_Birth, Position, Address);
					Emp.push_back(tempEmp);
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
		for (int i = 0; i < Emp.size(); i++) {
			myfile << Emp[i].ID << endl;
			myfile << Emp[i].Name << endl;
			myfile << Emp[i].Phone_Number << endl;
			myfile << Emp[i].Salary << endl;
			myfile << Emp[i].Year_of_Birth << endl;
			myfile << Emp[i].Position << endl;
			myfile << Emp[i].Address << endl;
		}
		myfile.close();
	}

	int getSize() {
		return Emp.size();
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
		cout << this->Year_of_Birth << "\t   ";
		cout << this->Phone_Number << "\t";
		int temp2 = this->Salary;
		if (temp2 / 1000 == 0)
			cout << temp2;
		else {
			cout << temp2 / 1000;
			if (temp2 % 1000 == 0)
				cout << ".000";
			else cout << '.' << temp2 % 1000;
		}
		cout << ".000VND\t";
		cout << this->Position << "\t  ";
		cout << this->Address << "\n";
	}

	void InThongTin() {
		cout << "\n\t--> DANH SACH NHAN VIEN\n\n";
		cout << "Ma so\tHo ten\t\tNam sinh   SDT\t\tLuong\t\tVi tri\t  Dia chi\n";
		for (int count = 0; count < Emp.size(); count++)
			Emp[count].Display();
	}

	void Import() {
		cout << "\n\t*** NHAP THONG TIN NHAN VIEN ***\n\n";
		int last_ID = Emp.back().get_ID();
		this->ID = last_ID + 1;
		cout << "ID: " << ID << "\n";
		cout << "-> Nhap ten nhan vien: "; 
		cin.ignore(100, '\n'); getline(cin, this->Name);
		cout << "-> Nhap so dien thoai: "; 
		getline(cin, this->Phone_Number);
		cout << "-> Nhap luong (*1.000VND): "; 
		cin >> this->Salary;
		cout << "-> Nhap nam sinh: "; 
		cin >> this->Year_of_Birth;
		cout << "-> Nhap vi tri lam viec: "; 
		cin.ignore(100, '\n'); getline(cin, this->Position);
		cout << "-> Nhap dia chi: "; 
		getline(cin, this->Address);
		Employee tempEmp(ID, Name, Phone_Number, Salary, Year_of_Birth, Position, Address);
		Emp.push_back(tempEmp);
	}

	int get_ID() {
		return this->ID;
	}

	void search_ID(int tempID) {
		for (int i = 0; i < Emp.size(); i++) 
			if (tempID == Emp[i].get_ID()) {
				cout << "\n--> THONG TIN NHAN VIEN TIM KIEM:\n\n";
				cout << "Ma so\tHo ten\t\tNam sinh SDT\t\tLuong\t\tVi tri\t\tDia chi\n";
				Emp[i].Display();
				return;
			}
		cout << "--> Khong tim thay !\n";
	}
};