#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

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


class AirlineManager;


void storeSampleData(){
	int n = 5;
	struct Flight flightdata[n];
  
  flightdata[0] = {"A001", "Ahmedabad [AD]", "Pune [PN]", "1115", "1500", 54};
  flightdata[1] = {"A002", "Mumbai [MU]", "Pune [PN]", "1210", "1340", 123};
  flightdata[2] = {"A003", "Mumbai [MU]", "Surat [SU]", "2210", "2330", 40};
  flightdata[3] = {"A004", "Surat [SU]", "Mumbai [MU]", "0030", "0200", 56};
  flightdata[4] = {"A005", "Pune [PN]", "Mumbai [MU]", "1530", "1700", 3};
  
  fstream f;
  f.open("sample_flight.fi", ios::binary | ios_base::out);
  f.write((char*)&n, sizeof(n));
  f.write((char*)&flightdata, sizeof(flightdata));
}


class AirlineManager{
	int n;
	struct Flight *flightdata = NULL;
	
	public:
		AirlineManager(int i){
			fstream sample_file;
			cout << " > Loading Sample Data from 'sample_flight.fi'." << endl;
			sample_file.open("sample_flight.fi", ios::binary | ios::in);
			sample_file.read((char*)&n, sizeof(n));
			struct Flight tempflightdata[n];
			sample_file.read((char*)&tempflightdata, sizeof(tempflightdata));
			flightdata = tempflightdata;
			cout << " > Data Read Successful." << endl;
			cout << " > Loaded " << n << " Flights." << endl;
			cout << " > Initialising Menu." << endl;
			showMenu();
		}
		
		AirlineManager(){
			fstream sample_file;
			sample_file.open("sample_flight.fi", ios::binary | ios::in);
			sample_file.read((char*)&n, sizeof(n));
			struct Flight tempflightdata[n];
			sample_file.read((char*)&tempflightdata, sizeof(tempflightdata));
			flightdata = tempflightdata;
		}
		
		
		void storeFlightData(){
			remove("updated_sample_flight.fi");
			
			struct Flight tempflightdata[n];
			for(int i = 0; i < n; i++){
				tempflightdata[i] = flightdata[i];
			}
			
			fstream f;
		  f.open("updated_sample_flight.fi", ios::binary | ios_base::out);
		  f.write((char*)&n, sizeof(n));
		  f.write((char*)&tempflightdata, sizeof(tempflightdata));
		  f.close();
		  
		  remove("sample_flight.fi");
		  rename("updated_sample_flight.fi", "sample_flight.fi");
		  
		  cout << " > Updated File." << endl;
		}
		
		
		void showFlights(){
			
			string br = " +-----------+----------------+------------------+----------+-------------------+----------+---------+";
			
			cout << br << endl;
			
			cout << " | ";
	    cout.setf(ios::left, ios::adjustfield);
	    
			cout.width(9);
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
		
		void tableHead(){
			string br = " +----------------+------------------+----------+-------------------+----------+---------+";
			
			cout << br << endl;
			
			cout << " | ";
	    cout.setf(ios::left, ios::adjustfield);
	    
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
		}
		
		void tableFoot(){
			string br = " +----------------+------------------+----------+-------------------+----------+---------+";
		  cout << br << endl;
		}
		
		void inTable(int i){
			
			cout << " | ";
			
	  	cout.width(14);
		  cout.setf(ios::left, ios::adjustfield);
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
		
		void searchflights(int i){
			if( i == 1 ){
				string fnum;
				cout << " > Enter Flight Number to Search for : ";
				cin >> fnum;
				tableHead();
				for(int a = 0; a < n; a++){
					if(fnum == flightdata[a].number)
						inTable(a);
				}
				tableFoot();
			} else if( i == 2 ){
				string ori;
				cout << " > Enter Origin : ";
				cin.ignore();
  			getline(cin, ori);
				tableHead();
				for(int a = 0; a < n; a++){
					size_t match = flightdata[a].origin.find(ori);
					if (match != string::npos) 
						inTable(a);
				}
				tableFoot();
			} else if( i == 3 ){
				string dest;
				cout << " > Enter Destination : ";
				cin.ignore();
  			getline(cin, dest);
				tableHead();
				for(int a = 0; a < n; a++){
					size_t match = flightdata[a].destination.find(dest);
					if (match != string::npos) 
						inTable(a);
				}
				tableFoot();
			} else if( i == 4 ){
				int ul, ll;
				cout << " > Enter Lower Limit : ";
				cin >> ll;
				cout << " > Enter Upper Limit : ";
  			cin >> ul;
				tableHead();
				for(int a = 0; a < n; a++){
					stringstream temp(flightdata[a].departure);
					int tmpint = 0;
					temp >> tmpint;
					if (tmpint <= ul && tmpint >= ll) 
						inTable(a);
				}
				tableFoot();
			}
		}
		
		void searchforflightsmenu(){
			int i = -1;
			
			while( i < 1 or i > 4){
				cout << " > Please Select a Valid Option : " << endl;
				cout << "     1. Search by Flight Number" << endl;
				cout << "     2. Search by Origin" << endl;
				cout << "     3. Search by Destination" << endl;
				cout << "     4. Search by Time Period of Departure" << endl;
				cout << " > Your Selection : ";
				
				try{
					cin >> i;
				} catch(...) {
					cout << " > Invalid Input, Try Again.";
					i = -1;
				}
			}
			searchflights(i);
		}
		
		
		void showMenu(){
			
			int i = -1;
			
			while( i < 1 or i > 7){
				cout << " > Please Select a Valid Option : " << endl;
				cout << "     1. Book Tickets" << endl;
				cout << "     2. Cancel Tickets" << endl;
				cout << "     3. Show All Tickets" << endl;
				cout << "     4. Show Flights" << endl;
				cout << "     5. Search for Flights" << endl;
				cout << "     6. Load Sample Flight Data" << endl;
				cout << "     7. Exit" << endl;
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
					showMenu();
					break;
					
				case 2:
					canceltickets();
					break;
					
				case 3:
					showalltickets();
					break;
					
				case 4:
					showFlights();
					showMenu();
					break;
					
				case 5:
					searchforflightsmenu();
					showMenu();
					break;
					
				case 6:
					storeSampleData();
					cout << " > Sample Data Stored, Please Restart the Program." << endl;
					
				case 7:
					exit(0);
			}
		}
		void booktickets();
		void canceltickets();
		void showalltickets();
		
		struct Flight getFlightData(char number[5]){
			struct Flight returndata;
			for(int i = 0; i < n; i++){
				if(number[3] == flightdata[i].number[3]){
					cout << "    > Flight Number : " << flightdata[i].number << endl
						<< "    > Origin : " << flightdata[i].origin << " | " << flightdata[i].departure << endl
						<< "    > Destination : " << flightdata[i].destination << " | " << flightdata[i].arrival << endl;
					returndata = flightdata[i];
				}
			}
			return returndata;
		}
};


class Ticket:AirlineManager{
	public:
		string id;
		char number[5];
		string passenger_name;
		int passenger_age;
		
		Ticket(string a, char b[5], string c, int d){
			id = a;
			for(int i = 0; i < 5; i++)
				number[i] = b[i];
			passenger_name = c;
			passenger_age = d;
		}
		
		Ticket(){
			int i = 0;
		}
		
		friend ostream &operator<<(ostream &output, Ticket &t){
			output  << "    > Ticket ID : " << t.id << endl
				<< "    > Name : " << t.passenger_name << endl
				<< "    > Age : " << t.passenger_age << endl;
			return output;
		}
		
		void showTicket(){
			int n = 0;
			cout << "    > Ticket ID : " << id << endl
				<< "    > Name : " << passenger_name << endl
				<< "    > Age : " << passenger_age << endl;
			//AirlineManager::getFlightData(number);
		}
				
		void inTable(){
			int n = 0;
			
			cout << " | " << setw(11) << id << " | "
						<< setw(16) << passenger_name << " | "
						<< setw(5) << passenger_age << " | ";
			
			fstream sample_file;
			sample_file.open("sample_flight.fi", ios::binary | ios::in);
			sample_file.read((char*)&n, sizeof(n));
			struct Flight tempflightdata[n];
			sample_file.read((char*)&tempflightdata, sizeof(tempflightdata));
			for(int i = 0; i < n; i++){
				if(number[3] == tempflightdata[i].number[3]){
					cout << setw(8) << tempflightdata[i].number << " | "
						<< setw(16) << tempflightdata[i].origin << setw(4) << tempflightdata[i].departure << " | "
						<< setw(17) << tempflightdata[i].destination << setw(4) << tempflightdata[i].arrival << " | " << endl;
				}
			}
		}
}t;

void AirlineManager :: booktickets(){
	
	showFlights();
	
	int flag = -1;
	
	while(flag < 1 or flag > n){
		cout << " > Please Enter the Serial Number of the Flight you wish to book : ";
		cin >> flag;
	}
	
	struct Flight sel = flightdata[flag-1];
	int nseats = -1;
	
	if(sel.seats > 0){
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
		return;
	}
	
	for(int i = 1; i <= nseats; i++){
		
		string name;
		int age;
		
		cout << " > Passenger Name : ";
    cin.ignore();
    getline(cin, name);
    
		cout << " > Passenger Age : ";
		cin >> age;
		
		string id = std::string(sel.number) + std::to_string(flightdata[flag-1].seats);
		
		Ticket tmp(id, sel.number, name, age);
		
		fstream ticketstore;
		ticketstore.open("ticketfile.bin", ios::app | ios::binary);
		ticketstore.write((char*)&tmp, sizeof(tmp));
		
		cout << " > Ticket Booked : " << endl;
		
		//tmp.showTicket();
		cout << tmp;
		getFlightData(sel.number);
		
		flightdata[flag-1].seats--;
		
		storeFlightData();
	}
}
		
void AirlineManager :: canceltickets(){
	
	string id;
	cout << " > Please Enter Ticket ID of Ticket to be cancelled : ";
	cin.ignore();
  getline(cin, id);
  
  fstream ticketstore;
  Ticket tmp;
  int flag = 0;
  int fflag = 0;
  fstream outfile;
  
  remove("newticketfile.bin");
  
	ticketstore.open("ticketfile.bin", ios::in | ios::binary);
	outfile.open("newticketfile.bin", ios::app | ios::binary);
	
	while(ticketstore.read((char*)&tmp, sizeof(tmp))){
		if(tmp.id == id){
			cout << " > Found Ticket : " << endl;
			tmp.showTicket();
			flag = int(tmp.number[3]) - 49;
			cout << " > Cancelled Ticket successfully." << endl;
			flightdata[flag].seats++;
			storeFlightData();
			fflag = 1;
		} else {
			outfile.write((char*)&tmp, sizeof(tmp));
		}
	}
	if(fflag == 0){
		cout << " > Ticket ID Not found, Please Verify." << endl;
	}
	
	ticketstore.close();
	outfile.close();
	
	remove("ticketfile.bin");
  rename("newticketfile.bin", "ticketfile.bin");
	showMenu();
}

void AirlineManager :: showalltickets(){
	int count = 0;
	string h2 = " +-------------+------------------+-------+----------+----------------------+-----------------------+";
	string h3 = " +--------------------------------------------------------------------------------------------------+";
	cout.setf(ios::left, ios::adjustfield);
	cout << h2 << endl 
		<< " | " << setw(11) << " Ticket ID" << " | "
		<< setw(16) << "      Name" << " | "
		<< setw(5) << " Age" << " | "
		<< setw(8) << "Flt. No." << " | "
		<< setw(20) << "       Origin" << " | "
		<< setw(21) << "     Destination" << " | " << endl
		<< h2 << endl;
	Ticket tmp;
	fstream ticketstore;
	ticketstore.open("ticketfile.bin", ios::in | ios::binary);
	while(ticketstore.read((char*)&tmp, sizeof(tmp))){
		tmp.inTable();
		count ++;
	}
	cout << h2 << endl;
	cout << " | " << setw(3) << count << setw(93) << " Records Found." << " | " << endl;
	cout << h3 << endl;
	showMenu();
}


int main(){
  showBranding();
  AirlineManager a_man(1);
}