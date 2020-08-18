#include <iostream>

using namespace std;

class Employee {
	private:
		string name;
		string ssn;
	public:
		Employee(string a, string b){
			name = a;
			ssn = b;
		}
		
		virtual void print(){
			cout << " > Name : " << name << endl << " > SSN : " << ssn << endl;
		}
		
		virtual double payroll() = 0;
};

class salariedEmployee : Employee {
	private:
		double weeklysal;
	public:
		salariedEmployee(string a, string b, double salary):Employee(a, b){
			weeklysal = salary;
		}
		
		void print(){
			cout << "SALARIED EMPLOYEE : " << endl;
			Employee::print();
			cout << " > Weekly Salary : " << weeklysal << endl;
			cout << " > Payroll : " << payroll() << endl;
		}
		
		double payroll(){
			return weeklysal;
		}
};

class hourlyEmployee : Employee {
	private:
		double rate;
		double hours;
	public:
		hourlyEmployee(string a, string b, double r, double h):Employee(a, b){
			rate = r;
			hours = h;
		}
		
		void print(){
			cout << "HOURLY EMPLOYEE : " << endl;
			Employee::print();
			cout << " > Hourly Rate : " << rate << endl << " > Hours Worked : " << hours << endl << " > Payroll : " << payroll() << endl;
		}
		
		double payroll(){
			if(hours <= 40){
				return rate * hours;
			} else {
				return rate * 40 + ((hours - 40) * rate * 1.5);
			}
		}
};

class commissionEmployee : Employee {
	private:
		double sales;
		double rate;
	public:
		commissionEmployee(string a, string b, double s, double r):Employee(a, b){
			sales = s;
			rate = r;
		}
		
		void print(){
			cout << "COMMISSION EMPLOYEE : " << endl;
			Employee::print();
			cout << " > Gross Sales : " << sales << endl << " > Rate : " << rate << endl << " > Payroll : " << payroll() << endl;
		}
		
		double payroll(){
			return rate * sales;
		}
};

class basePlusCommissionEmployee : commissionEmployee {
	private:
		double base;
	public:
		basePlusCommissionEmployee(string a, string b, double s, double r, double bs):commissionEmployee(a, b, s, r){
			base = bs;
		}
		
		void print(){
			cout << "BASE + COMMISSION EMPLOYEE : " << endl;
			commissionEmployee::print();
			cout << " > Base Salary : " << base << endl;
		}
		
		double payroll(){
			return commissionEmployee::payroll() + base + base * 0.1;
		}
};


int main(){
	
	salariedEmployee s1("Will Smith", "111-11-1111", 4500.00);
	hourlyEmployee s2("Keanu Reeves", "222-22-2222", 100.00, 45.5);
	commissionEmployee s3("Ryan Reynolds", "333-33-3333", 15000.00, 0.3);
	basePlusCommissionEmployee s4("Morgan Freeman", "444-44-4444", 20000.00, 0.25, 5000.00);
	
	s1.print();
	s2.print();
	s3.print();
	s4.print();
}