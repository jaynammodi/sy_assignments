#include <iostream>

using namespace std;

class Complex{
	
	public:
		int r;
		int i;
		
		void setComplex(int a, int b){
			r = a;
			i = b;
		}
		void printComplex(){
			cout << r << " + " << i << "i" << endl;;
		}
		
		Complex operator + (Complex c2){
			Complex result;
			result.r = r + c2.r;
			result.i = i + c2.i;
			//result.printComplex();
			return result;
		}
		
		friend ostream &operator<<(ostream &output, Complex &c){
			output << c.r << " + " << c.i << "i";
			return output;
		}
		
		friend istream &operator>>(istream &input, Complex &c){
			input >> c.r >> c.i;
			return input;
		}
		
		friend Complex multiply(Complex * , Complex *);
};

Complex * multiply(Complex &c1, Complex &c2){
	Complex result;
	result.r = (c1.r * c2.r) - (c1.i * c2.i);
	result.i = (c1.r * c2.i) + (c2.r * c1.i);
	return &result;
}


int main(){
	Complex c;
	c.setComplex(5,4);
	c.printComplex();
	
	Complex c1;
	cin >> c1;
	cout << c1 << endl;
	
	Complex c2;
	cin >> c2;
	cout << c2 << endl;
	
	Complex c3 = c1 + c2;
	
	cout << c3 << endl;
	
	Complex c4 = *multiply(c1, c2);
	cout << c4 << endl;
}