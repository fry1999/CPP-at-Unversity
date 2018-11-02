#include<iostream>
#include<fstream>
using namespace std;

class Person{
	protected://do private is not accessible
		string name;
		string email;
		int telephoneNumber;
	public:
		Person();
		Person(string na, string em, int te);
		void enter();
		void show();
};
class Customer:public Person{
	protected:
		int idOfCustomer;
		string type;
		string describe;
	public:
		Customer();
		Customer(string na, string em, int te, int id, string ty, string de);
		void enter();
		void show();
};

class Room{
	protected://?
		int idOfRoom;
		string type;
		float rental;
	public:
		Room();
		Room(int, string, float);
		void enter();
		void show();
};

class Table{
	friend class Room;
	friend class Customer;
	protected:
		Customer cus;
		Room ro[50];
		int numberOfRoom;
		int hireDate;
	public:
		void enter();
		void writeFile(ofstream &ofs);
		void readFile(ifstream &ifs);
};
Person::Person(){
	name= ""; email=""; telephoneNumber=0;
}
Person::Person(string na, string em, int te){
	name = na;
	email = em;
	telephoneNumber = te;
}
void Person::enter(){
	cout<<"Ho va ten: ";
	getline(cin, name);
	cout<<"\nAddress: ";
	cin>>email;
	cout<<"\nTelephone Number: ";
	cin>>telephoneNumber;
}
void Person::show(){
	cout<<name<<" "<<email<<" "<<telephoneNumber<<endl;
}
Customer::Customer():Person(){
	idOfCustomer=0; type=""; describe="";
}
//Customer::Customer(string na, string em, int te, int id, string ty, string de)
//{
//	Person::Person(string na, string em, int te);
//	idOfCustomer = id;
//	type = ty;
//	describe = de;
//}
void Customer::enter(){
	Person::enter();
	cout<<"\nMa khach hang: ";
	cin>>idOfCustomer;
	cin.ignore(1000, '\n');// why we use cin.ignore before using getline()
	cout<<"\nKieu phong thue: ";
	getline(cin, type);
	cout<<"\nMo ta: ";
	getline(cin, describe);
}
void Customer::show(){
	Person::show();
	cout<<idOfCustomer<<" "<<type<<" "<<describe;
}
void Table::enter(){
	cout<<"So phong thue: ";
	cin>>numberOfRoom;
	for(int i=0; i<numberOfRoom; ++i){
		ro[i].enter();
	}
}
//void Table::writeFile(ofstream &ofs){
//	ofs<<numberOfRoom;
//	for(int i=0; i<numberOfRoom; ++i){
//		if(ro[i].rental>1){
//			ofs<<ro[i].idOfRoom<<" "<<ro[i].type<<" "<<ro[i].rental<<endl;
//		}
//	}
//}
void Room::enter(){
	cout<<"Ma phong: ";
	cin>>idOfRoom;
	cin.ignore(1000, '\n');
	cout<<"\nLoai phong: ";
	getline(cin, type);
	cout<<"\nTien cho thue: ";
	cin>>rental;
}
Room::Room(){
	idOfRoom =0;
	type="";
	rental = 0;
}
int main(){
	Person person;
	Customer customer;
	Room room;
	Table table;
	table.enter();
	ofstream ofs;
	ofs.open("PH.DAT", ios::out);
	//customer.enter();
//	table.enter();
//	
}
