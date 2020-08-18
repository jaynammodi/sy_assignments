#include <iostream>

using namespace std;


class Student_a{
        public:
        int rollno;
        string name;
        int student_class;
        char division;
        string dob;
        string aadhar;
        string blood_group;
        string contact_number;
        string address;
        string telephone_number;

        void getdata(){
                cout << "Enter the Following Details \n";
                cout << "       Roll Number : ";
                cin >> rollno;
                cout << "       Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "       Class : ";
                cin >> student_class;
                cout << "       Division : ";
                cin >> division;
                cout << "       Date of Birth : ";
                cin.ignore();
                getline(cin, dob);
                cout << "       Aadhar Number : ";
                cin.ignore();
                getline(cin, aadhar);
                cout << "       Blood Group : ";
                cin.ignore();
                getline(cin, blood_group);
                cout << "       Contact Number : ";
                cin.ignore();
                getline(cin, contact_number);
                cout << "       Address : ";
                cin.ignore();
                getline(cin, address);
                cout << "       Telephone Number : ";
                cin.ignore();
                getline(cin, telephone_number);
        }

        void putdata(){
        				cout << "Entered Details are : " << endl;
                cout << "       Roll Number : " << rollno << endl;
                cout << "       Name : " << name << endl;
                cout << "       Class : " << student_class << endl;
                cout << "       Division : " << division << endl;
                cout << "       Date of Birth : " << dob << endl;
                cout << "       Aadhar Number : " << aadhar << endl;
                cout << "       Blood Group : " << blood_group << endl;
                cout << "       Contact Number : " << contact_number << endl;
                cout << "       Address : " << address << endl;
                cout << "       Telephone Number : " << telephone_number << endl;
        }
};

class Student_b{
        public:
        int rollno;
        string name;
        int student_class;
        char division;
        string dob;
        string aadhar;
        string blood_group;
        string contact_number;
        string address;
        string telephone_number;

        Student_b(){
        				cout << " > MADE WITH DEFAULT CONSTRUCTOR." << endl;
                cout << "Enter the Following Details \n";
                cout << "       Roll Number : ";
                cin >> rollno;
                cout << "       Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "       Class : ";
                cin >> student_class;
                cout << "       Division : ";
                cin >> division;
                cout << "       Date of Birth : ";
                cin.ignore();
                getline(cin, dob);
                cout << "       Aadhar Number : ";
                cin.ignore();
                getline(cin, aadhar);
                cout << "       Blood Group : ";
                cin.ignore();
                getline(cin, blood_group);
                cout << "       Contact Number : ";
                cin.ignore();
                getline(cin, contact_number);
                cout << "       Address : ";
                cin.ignore();
                getline(cin, address);
                cout << "       Telephone Number : ";
                cin.ignore();
                getline(cin, telephone_number);
        }
        
        Student_b(int a, string b, int c, char d, string e, string f, string g, string h, string i, string j){
        				cout << " > MADE WITH PARAMETERIZED CONSTRUCTOR" << endl;
        				rollno = a;
        				name = b;
        				student_class = c;
        				division = d;
        				dob = e;
        				aadhar = f;
        				blood_group = g;
        				contact_number = h;
        				address = i;
        				telephone_number = j;
        }
        
        Student_b(Student_b &p){
								cout << " > MADE WITH COPY CONSTRUCTOR" << endl;
        				rollno = p.rollno;
        				name = p.name;
        				student_class = p.student_class;
        				division = p.division;
        				dob = p.dob;
        				aadhar = p.aadhar;
        				blood_group = p.blood_group;
        				contact_number = p.contact_number;
        				address = p.address;
        				telephone_number = p.telephone_number;
        }

        void putdata(){
        				cout << "Entered Details are : " << endl;
                cout << "       Roll Number : " << rollno << endl;
                cout << "       Name : " << name << endl;
                cout << "       Class : " << student_class << endl;
                cout << "       Division : " << division << endl;
                cout << "       Date of Birth : " << dob << endl;
                cout << "       Aadhar Number : " << aadhar << endl;
                cout << "       Blood Group : " << blood_group << endl;
                cout << "       Contact Number : " << contact_number << endl;
                cout << "       Address : " << address << endl;
                cout << "       Telephone Number : " << telephone_number << endl;
        }
};



int main(){
	
	// Q 1.a Develop an Object Oriented Program in C++ to.....
	
        Student_a a1;
      	a1.getdata();
        a1.putdata();
        
 // Q 1.b Modify the Program in Q 1.a to......
        
        Student_b b1;
        Student_b b2(43, "Jaynam Modi", 9, 'C', "01/01/2001", "759362842648", "B+", "7493749274", "Kothrud, Pune", "749282");
        Student_b b3(b2);
}