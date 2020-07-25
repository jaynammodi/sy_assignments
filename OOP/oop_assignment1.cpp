#include <iostream>

using namespace std;
class Student{
        public:
        int rollno;
        char name[30];
        int student_class;
        char division;
        char dob[10];
        char aadhar[12];
        char blood_group[3];
        char contact_number[10];
        char address[60];
        char telephone_number[10];

        void getdata(){
                cout << "Enter the Following Details \n";
                cout << "       Roll Number : ";
                cin >> rollno;
                cout << "       Name : ";
                scanf(" %[^\n]s", name);
                cout << "       Class : ";
                cin >> student_class;
                cout << "       Division : ";
                cin >> division;
                cout << "       Date of Birth : ";
                scanf(" %[^\n]s", dob);
                cout << "       Aadhar Number : ";
                scanf(" %[^\n]s", aadhar);
                cout << "       Blood Group : ";
                scanf(" %[^\n]s", blood_group);
                cout << "       Contact Number : ";
                scanf(" %[^\n]s", contact_number);
                cout << "       Address : ";
                scanf(" %[^\n]s", address);
                cout << "       Telephone Number : ";
                scanf(" %[^\n]s", telephone_number);
        }

        void putdata(){
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
        Student s1;
        s1.getdata();
        s1.putdata();
}