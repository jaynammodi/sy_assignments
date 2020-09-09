#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class InventoryItem{
    string itemname;
    int code;
    int qu;
    double cost;
    
    
    public:
	    InventoryItem(){
	      itemname = "ABC";
	      code = 000;
	      qu = 00;
	      cost = 00.00;
	    }
	    
			void getdata(){
		    cout << "    > Item Name : ";
		    cin >> itemname;
		    cout << "    > Item Code : ";
		    cin >> code;
		    cout << "    > Quantity : ";
		    cin >> qu;
		    cout << "    > Cost : ";
		    cin >> cost;
			}
			
			void set_header(){
				cout << " +-----------------+-------------------+--------------+----------+" << endl;
				cout << " | ";
				cout.width(15);
		    cout.setf(ios::left, ios::adjustfield);
		    cout << "   Item Name" << " | ";
		
		    cout.width(17);
		    cout << "    Item Code" << " | ";
		
		    cout.width(12);
		    cout << "  Quantity" << " | ";
		
		    cout.width(8);
		    cout.setf(ios::right, ios::adjustfield);
		    cout << "  Cost" << " | ";
		    
		    cout << endl;
		    
				cout << " +-----------------+-------------------+--------------+----------+" << endl;
			}
			
			void set_footer(){
				cout << " +-----------------+-------------------+--------------+----------+" << endl;
			}
			
			void showdata(){
				
				cout << " | ";
		    cout.width(15);
		    cout.setf(ios::left, ios::adjustfield);
		    cout << itemname << " | ";
		
		    cout.width(17);
		    cout << code << " | ";
		
		    cout.width(12);
		    cout << qu << " | ";
		
		    cout.width(8);
		    cout.setf(ios::right, ios::adjustfield);
		    cout.setf(ios::showpoint);
		    cout.setf(ios::fixed,ios::floatfield);
		    cout.precision(2);
		    cout << cost << " | ";
		    
		    cout << endl;
			}
};



void add_data(){
  fstream f;
  InventoryItem i;
  f.open("in.fi", ios::binary | ios_base::app);
  i.getdata();
  f.write((char*)&i,sizeof(i));
  f.close();
}

void fetch_data(){
  fstream f;
  InventoryItem i;
  i.set_header();
  f.open("in.fi", ios::in | ios::binary);

  while(f.read((char*)&i,sizeof(i))){
    i.showdata();
  }
  
  f.close();
  
  i.set_footer();
}


int main(){
  InventoryItem record[10];
  int i,n;

  cout << endl << "|===== Inventory Management =====|" << endl;
  cout << " > Number of Records : ";
  cin >> n;

  for(i = 1; i <= n; i++){
  	cout << " > Enter Record " << i << " : " << endl;
  	add_data();
  }

  fetch_data();
}