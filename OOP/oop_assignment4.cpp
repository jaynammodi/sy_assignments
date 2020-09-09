#include <iostream>

using namespace std;

class Employee {
	public:
		int id;
		string name;
		int age;
		double income;
		string city;
		string vehicle;
		
		void validate(){
			try{
				if (age < 18 or age > 55){
					throw 1855;
				}
				
				if (income < 50000 or income > 100000){
					throw 50100;
				}
				
				if (city != "Pune" && city != "Bangalore" && city != "Mumbai" && city != "Chennai"){
					throw 400;
				}
				
				if (vehicle != "4-Wheeler"){
					throw 404;
				}
			} catch (int exc) {
				if (exc == 1855){
					cout << " > Age not valid." << endl;
				} else if (exc == 50100){
					cout << " > Income Invalid." << endl;
				} else if (exc == 400){
					cout << " > City Invalid." << endl;
				} else if (exc == 404){
					cout << "Vehicle Invalid." << endl;
				}
			} catch (...) {
				cout << " > UNKNOWN ERROR." << endl;
			}
		}
		
		Employee(){
			cout << "Enter the Following Details \n";
      cout << "       Employee ID : ";
      cin >> id;
      cout << "       Name : ";
      cin.ignore();
      getline(cin, name);
      cout << "       Age : ";
      cin >> age;
      cout << "       Income : ";
      cin >> income;
      cout << "       City : ";
      cin.ignore();
      getline(cin, city);
      cout << "       Vehicle : ";
      cin.ignore();
      getline(cin, vehicle);
      
      validate();
		}
		
		Employee(int a, string b, int c, double d, string e, string f){
			id = a;
			name = b;
			age = c;
			income = d;
			city = e;
			vehicle = f;
			
			validate();
		}
		
		void print(){
			cout << "Entered Details are : " << endl;
      cout << "       Employee ID : " << id << endl;
      cout << "       Name : " << name << endl;
      cout << "       Age : " << age << endl;
      cout << "       Income : " << income << endl;
      cout << "       City : " << city << endl;
      cout << "       Vehicle : " << vehicle << endl;
		}
		
};


int main(){
	Employee e1;
	e1.print();
}