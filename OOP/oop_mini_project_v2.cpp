#include <iostream>
#include <fstream>
#include <string.h>
//#include <alloc.h>

using namespace std;

void showBranding(){
	cout << "\n\n                    %%%%%%%%%%\n                  %%%%%%%%%%%\n                %%%%%%%%%%%%\n              %%%   %% %%%%\n             %%%%  %%  %%%%\n           %%%%%% %%   %%%\n          %%%%%%%%%%%%%%%%\n        %%%%%%%%%%%%%%%%%\n       %%%%%%%%%%%%%%%%%%\n     %%%%%%%%%%%%%%%%%%%\n\n";
	cout << " > Welcome to AX Airline Management System" << endl;
}

struct Flight{
	char number[5];
	string origin;
	string destination;
	string departure;
	string arrival;
	int seats;
};

struct Ticket{
	string id;
	char number[5];
	int seats;
};

void storeSampleData(){
	int n = 5;
	struct Flight flightdata[n];
  
  flightdata[0] = {"A001", "Ahmedabad [AD]", "Pune [PN]", "1115", "1500", 54};
  flightdata[1] = {"A002", "Mumbai [MU]", "Pune [PN]", "1210", "1340", 123};
  flightdata[2] = {"A003", "Mumbai [MU]", "Surat [SU]", "2210", "2330", 40};
  flightdata[3] = {"A004", "Surat [SU]", "Mumbai [MU]", "0030", "0200", 56};
  flightdata[4] = {"A005", "Pune [PN]", "Mumbai [MU]", "1530", "1700", 78};
  
  fstream f;
  f.open("sample_flight2.fi", ios::binary | ios_base::out);
  f.write((char*)&n, sizeof(n));
  f.write((char*)&flightdata, sizeof(flightdata));
}

class AirlineManager{
	//struct Flight flightdata[50];
	struct Flight *flightdata = NULL;
	int n;
	
	public:
		AirlineManager(){
			fstream sample_file;
			cout << " > Loading Sample Data from 'sample_flight.fi'." << endl;
			sample_file.open("sample_flight2.fi", ios::binary | ios::in);
			sample_file.read((char*)&n, sizeof(n));
			struct Flight tempflightdata[n];
			sample_file.read((char*)&tempflightdata, sizeof(tempflightdata));
			flightdata = tempflightdata;
			cout << " > Data Read Successful." << endl;
			cout << " > Loaded " << n << " Flights." << endl;
			showFlights();
			cout << " > Initialising Menu." << endl;
			showMenu();
			
			fstream ticket_file;
		}
		
		void storeFlightData(){
			fstream f;
		  f.open("sample_flight.fi", ios::binary | ios_base::out);
		  f.write((char*)&n, sizeof(n));
		  f.write((char*)&flightdata, sizeof(flightdata));
		}
		
		void showFlights(){
			string br = " +-----------+----------------+------------------+----------+-------------------+----------+---------+";
			cout << br << endl;
			cout << " | ";
			cout.width(9);
	    cout.setf(ios::left, ios::adjustfield);
	    cout << " Sr. No." << " | ";
	    
	    cout.width(14);
		  cout << "  Flight No." << " | ";
		  
		  cout.width(16);
		  cout << "     Origin" << " | ";
		  
		  cout.width(8);
		  cout << "  Dep." << " | ";
		  
		  cout.width(17);
		  cout << "   Destination" << " | ";
		  
		  cout.width(8);
		  cout << "  Arr." << " | ";
		  
		  cout.width(7);
		  cout << " Seats" << " | " << endl;
		  
		  cout << br << endl;
		  
		  
		  for( int i = 0; i < n; i++ ){
		  	cout << " | ";
		  	cout.width(9);
		  	cout.setf(ios::right, ios::adjustfield);
		  	cout << i+1 << " | ";
		  	
		  	cout.width(14);
			  cout << flightdata[i].number << " | ";
			  
			  cout.width(16);
			  cout.setf(ios::left, ios::adjustfield);
			  cout << flightdata[i].origin << " | ";
			  
			  cout.width(8);
			  cout.setf(ios::right, ios::adjustfield);
			  cout << flightdata[i].departure << " | ";
			  
			  cout.width(17);
			  cout.setf(ios::left, ios::adjustfield);
			  cout << flightdata[i].destination << " | ";
			  
			  cout.width(8);
			  cout.setf(ios::right, ios::adjustfield);
			  cout << flightdata[i].arrival << " | ";
			  
			  cout.width(7);
			  cout << flightdata[i].seats << " | " << endl;
		  }
		  
		cout << br << endl;
		}
		
		void showMenu(){
			int i = -1;
			while( i < 1 or i > 4){
				cout << " > Please Select a Valid Option : " << endl;
				cout << "     1. Book Tickets" << endl;
				cout << "     2. Cancel Tickets" << endl;
				cout << "     3. Modify Booking ( Number of Seats )" << endl;
				cout << "     4. Exit" << endl;
				cout << " > Your Selection : ";
				try{
					cin >> i;
				} catch(...) {
					cout << " > Invalid Input, Try Again.";
					i = -1;
				}
			}
			
			switch(i){
				case 1:
					booktickets();
					break;
				case 2:
					canceltickets();
					break;
				case 3:
					modifyticket();
					break;
				case 4:
					exit(0);
			}
		}
};
		void booktickets(){
			showFlights();
			int flag = -1;
			while(flag < 1 or flag > n){
				cout << " > Please Enter the Serial Number of the Flight you wish to book : ";
				cin >> flag;
			}
			struct Flight sel = flightdata[flag-1];
			
			if(sel.seats > 0){
				int nseats = -1;
				cout << " > Please Enter the number of seats you wish to book : ";
				cin >> nseats;
				while(1){
					if(nseats < 0){
						cout << " > Please Enter a valid Number : ";
						cin >> nseats;
					} else if(nseats > sel.seats){
						cout << " > Only " << sel.seats << " Seats are available on this flight, Please try again." << endl;
						cout << " > Enter number of Seats : ";
						cin >> nseats;
					} else {
						break;
					}
				}
			} else {
				cout << " > This Flight is already Full, Sorry for the Inconvenience." << endl;
			}
			
			
		}
		
		void canceltickets(){
			cout << " cabcjd";
		}
		
		void modifyticket(){
			cout << "mod";
		}
};


int main(){
  showBranding();
  
  AirlineManager a_man;
  
}